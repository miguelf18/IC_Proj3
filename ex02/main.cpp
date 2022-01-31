#include "fcm.hpp"
#include <iostream>
#include <fstream>
#include <math.h> 

using namespace std;

int main(int argc, char **argv)
{
    if(argc != 5)
    {
        cout << "Usage: ./mainRun <reference file> <text file> <k parameter> <smoothing parameter>" << endl;
        return -1;
    }

    string ref_file = argv[1];
    string text_file = argv[2];
    int k = atoi(argv[3]);
    float alpha = atof(argv[4]);
    double numBits = 0;

    FCM f(k, alpha);
    // f.read_model_context_from_file(ref_file); // função não criada
    f.build(ref_file);
    f.close();

    ifstream ifs(text_file);
    if(!ifs.good()) return -2;

    char character;
    int count = 0;
    while(ifs.get(character))
    {
        if(isalpha(character) == 0) continue;
        character = tolower(character);
        // string context(1, character);
        // cout << "character: " << character << endl;

        double prob = f.get_probability(character);
        // cout << "prob " << prob << endl;
        if(prob == 0) continue;
        // numBits -= floor(log2(prob)); // numBits como int
        numBits -= log2(prob);
        count++;
    }
    ifs.close();

    cout << numBits / count << endl;

    return 0;
}