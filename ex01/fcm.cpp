#include "fcm.hpp"

// constructor
FCM::FCM(int k, float alpha)
{
    this->k = k;
    this->alpha = alpha;
    model = new unordered_map<string, unordered_map<char, int>>();
    character_count = 0;
    alphabet_size = 26;
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
            if(model->find(buffer) == model->end())
            {
                // initialize symbol map count
                unordered_map<char, int> map;
                (*model)[buffer] = map;
            }
            // add symbol to context
            (*model)[buffer][character]++;
            buffer = buffer.substr(1, k);
            buffer += character;
        }
        character_count++;
    }
    cout << "Total characters read: " << character_count << endl;
    return true;
}

// prints current built model
void FCM::print()
{
    cout << "printing" << endl;
    for(auto key : *model)
    {
        cout << key.first << ": { ";
        for(auto value : key.second)
        {
            cout << value.first << " : " << value.second << "; ";
        }
        cout << "}" << endl;
    }
}

// computes probability and average entropy of given file
double FCM::entropy()
{
    /* TODO */
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

