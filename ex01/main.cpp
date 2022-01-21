#include "fcm.hpp"

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        cerr << "Invalid parameters. Use: mainRun <k parameter> <smoothing parameter> <text file>" << endl;
        exit(1);
    }
    int k = atoi(argv[1]);
    float alpha = stof(argv[2]);
    string file_path = argv[3];
    cout << "Given k parameter: " << k << endl;
    cout << "Given smoothing parameter: " << alpha << endl;
    cout << "Given text file path: " << file_path << endl;
    FCM fcm(k, alpha);
    fcm.build(file_path);
    fcm.print();
    fcm.close();
    return 0;
}