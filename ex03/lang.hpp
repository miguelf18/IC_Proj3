#include "fcm.hpp"

// interface for testing a language based on a finite-context model
class LANG
{

    private:

        // parameters
        int k;
        float alpha;
        // files
        ifstream input_file;
        // model
        FCM *fcm;

    public:

        // constructor
        LANG(int k, float alpha);
        // build a model from a given text file
        // returns false if there are errors, returns true otherwise
        bool build(string file_path);
        // compares given text file with built model
        // returns false if there are errors, returns true otherwise
        bool compare(string file_path);
        // open/closes the file
        // returns false if there are errors, returns true otherwise
        bool open(string file_path);
        bool close();
        double bits_symbol;

};