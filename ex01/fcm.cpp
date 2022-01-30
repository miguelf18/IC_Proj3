#include "fcm.hpp"

// constructor
FCM::FCM(int k, float alpha)
{
    this->k = k;
    this->alpha = alpha;
    context_model = new unordered_map<string, Symbols>();
    probability_distribution = new unordered_map<string, unordered_map<char, double>>();
    character_count = 0;
    alphabet_size = 26;
}

// returns the current probability distribution for context model
unordered_map<string, unordered_map<char, double>> FCM::get_context_probability()
{
    return *probability_distribution;
}

// computes entropy distribution from probability table
void FCM::entropy()
{
    double total_entropy = 0;
    for(auto key : *probability_distribution)
    {
        for(auto value : key.second)
        {
            total_entropy -= log2(value.second);
        }
    }
    total_entropy /= character_count;
    cout << "Total entropy: " << total_entropy << endl;
}

// computes probability distribution from context model
void FCM::probability()
{
    if(character_count == 0)
    {
        cerr << "Context model is empty." << endl;
        return;
    }
    // loop all keys
    for(auto key : *context_model)
    {
        // loop all maps in every Symbols struct
        for(auto value : key.second.map)
        {
            double probability = ((double) value.second + alpha) / (key.second.count + alphabet_size * alpha);
            (*probability_distribution)[key.first][value.first] = probability;
        }
    }
    entropy();
}

// build model
bool FCM::build(string file_path)
{
    bool error = open(file_path);
    if(!error)
        return error;
    string buffer = "";
    char character;
    // start reading file
    while(input_file >> noskipws >> character)
    {
        // only consider letters
        if(!isalpha(character))
            continue; 
        character = tolower(character);
        if(character_count < k)
        {
            // initial context
            buffer += character;
        }
        else
        {
            // add symbol to context
            (*context_model)[buffer].map[character]++;
            (*context_model)[buffer].count++;
            buffer = buffer.substr(1, k);
            buffer += character;
        }
        character_count++;
    }
    cout << "Total characters read: " << character_count << endl;
    probability();
    return true;
}

// prints current built context model
void FCM::print_context_model()
{
    for(auto key : *context_model)
    {
        cout << key.first << " (" << key.second.count << " items)" << ": { ";
        for(auto value : key.second.map)
        {
            cout << value.first << " : " << value.second << "; ";
        }
        cout << "}" << endl;
    }
}

// prints current built model probability distribution
void FCM::print_probability_distribution()
{
    for(auto key : *probability_distribution)
    {
        cout << key.first << ": { ";
        for(auto value : key.second)
        {
            cout << value.first << " : " << value.second << "; ";
        }
        cout << "}" << endl;
    }
}

// files
bool FCM::open(string file_path)
{
    if(input_file.is_open())
        close();
    input_file.open(file_path);
    if(input_file.bad())
        return false;
    return true;
}

bool FCM::close()
{
    if(!input_file.is_open())
        return 1;
    input_file.close();
    return true;
}

