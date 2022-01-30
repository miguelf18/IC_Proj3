#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;

// interface for a finite-context moddel
class FCM
{

    private:

        // container for holding symbol info belonging to a context
        struct Symbols
        {
            // total number of symbols counted in context
            int count = 0;
            // map of counts for each symbol in context
            unordered_map<char, int> map;
        };

        // parameters
        int k;
        float alpha;
        // files
        ifstream input_file;
        // model
        unordered_map<string, Symbols> *context_model;
        unordered_map<string, unordered_map<char, double>> *probability_distribution;
        int character_count;
        int alphabet_size;

    public:

        // constructor
        FCM(int k, float alpha);
        // returns the current probability distribution for context model
        unordered_map<string, unordered_map<char, double>> get_context_probability();
        // computes entropy distribution from probability table
        void entropy();
        // computes probability distribution from context model
        void probability();
        // build a model from a given text file
        // returns false if there are errors, returns true otherwise
        bool build(string file_path);
        // prints current built context model
        void print_context_model();
        // prints current built model probability distribution
        void print_probability_distribution();
        // open/closes the file
        // returns false if there are errors, returns true otherwise
        bool open(string file_path);
        bool close();

};