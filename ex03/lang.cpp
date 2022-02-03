#include "lang.hpp"

// constructor
LANG::LANG(int k, float alpha)
{
    this->k = k;
    this->alpha = alpha;
    fcm = new FCM(k, alpha);
}

// build a model from a given text file
// returns false if there are errors, returns true otherwise
bool LANG::build(string file_path)
{
    bool error = fcm->build(file_path);
    fcm->close();
    return error;
}

// compares given text file with built model
// returns false if there are errors, returns true otherwise
bool LANG::compare(string file_path)
{
    bool error = open(file_path);
    if(!error)
        return error;
    string buffer = "";
    char character;
    int character_count = 0;
    double bits = 0;
    // start reading file
    while(input_file >> noskipws >> character)
    {
        // only consider letters and space
        if(isalpha(character) || character == ' ')
        {
            character = tolower(character);
            if(character_count < k)
            {
                // initial context
                buffer += character;
            }
            else
            {
                // compute bits based on model
                bits -= log2(fcm->get_character_probability(buffer, character));
                buffer = buffer.substr(1, k);
                buffer += character;
            }
            character_count++;
        }
    }
    bits /= character_count;
    cout << "Total characters read from model: " << character_count << endl;
    cout << "Bits / Symbol (Target): " << bits << endl;
    bits_symbol = bits;
    close();
    return true;
}

// files
bool LANG::open(string file_path)
{
    if(input_file.is_open())
        close();
    input_file.open(file_path);
    if(input_file.bad())
        return false;
    return true;
}

bool LANG::close()
{
    if(!input_file.is_open())
        return 1;
    input_file.close();
    return true;
}