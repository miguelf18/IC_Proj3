#include "lang.hpp"

int main(int argc, char **argv)
{
    if(argc != 5)
    {
        cerr << "Invalid parameters. Use: mainRun <k parameter> <smoothing parameter> <source file> <target file>" << endl;
        exit(1);
    }
    int k = atoi(argv[1]);
    float alpha = stof(argv[2]);
    string source_file = argv[3];
    string target_file = argv[4];
    cout << "Given k parameter: " << k << endl;
    cout << "Given smoothing parameter: " << alpha << endl;
    cout << "Given text file for model: " << source_file << endl;
    cout << "Given text file to compare: " << target_file << endl;
    LANG lang(k, alpha);
    lang.build(source_file);
    lang.compare(target_file);
    return 0;
}