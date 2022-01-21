#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

// interface for a finite-context moddel
class FCM
{

    private:

        // parameters
        int k;
        float alpha;
        // files
        ifstream input_file;
        // model
        unordered_map<string, unordered_map<char, int>> *model;
        int character_count;
        int alphabet_size;

    public:

        // constructor
        FCM(int k, float alpha);
        // build a model from a given text file
        // returns false if there are errors, returns true otherwise
        bool build(string file_path);
        // prints current built model
        void print();
        // computes probability and average entropy of given file
        double entropy();
        // open/closes the file
        // returns false if there are errors, returns true otherwise
        bool open(string file_path);
        bool close();

};