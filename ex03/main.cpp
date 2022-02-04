#include "lang.hpp"

template <typename T>
double min_of(T val1, T val2) 
{
    return min(val1,val2);
}

template<typename T, typename... Args>
double min_of(T val1, T val2, Args... args)
{
    return min_of(min(val1,val2),args...) ;
}

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        cerr << "Invalid parameters. Use: mainRun <k parameter> <smoothing parameter> <text file>" << endl;
        exit(1);
    }
    int k = atoi(argv[1]);
    float alpha = stof(argv[2]);
    string text_file = argv[3];

    cout << "Given k parameter: " << k << endl;
    cout << "Given smoothing parameter: " << alpha << endl;
    cout << "Given text file: " << text_file << endl;

    LANG pt(k, alpha);
    LANG en(k, alpha);
    LANG fr(k, alpha);
    LANG bg(k, alpha);
    LANG cs(k, alpha);
    LANG de(k, alpha);
    LANG es(k, alpha);
    LANG et(k, alpha);
    LANG it(k, alpha);
    LANG nl(k, alpha);
    LANG pl(k, alpha);
    LANG ro(k, alpha);
    LANG da(k, alpha);
    LANG el(k, alpha);
    LANG fi(k, alpha);
    LANG hu(k, alpha);
    LANG sv(k, alpha);
    LANG lv(k, alpha);
    LANG sk(k, alpha);
    LANG sl(k, alpha);

    cout << "\nbuild models" << endl;
    cout << "pt" << endl;
    pt.build("../files/reference/ref.pt");
    cout << "en" << endl;
    en.build("../files/reference/ref.en");
    cout << "fr" << endl;
    fr.build("../files/reference/ref.fr");
    cout << "bg" << endl;
    bg.build("../files/reference/ref.bg");
    cout << "cs" << endl;
    cs.build("../files/reference/ref.cs");
    cout << "de" << endl;
    de.build("../files/reference/ref.de");
    cout << "es" << endl;
    es.build("../files/reference/ref.es");
    cout << "et" << endl;
    et.build("../files/reference/ref.et");
    cout << "it" << endl;
    it.build("../files/reference/ref.it");
    cout << "nl" << endl;
    nl.build("../files/reference/ref.nl");
    cout << "pl" << endl;
    pl.build("../files/reference/ref.pl");
    cout << "ro" << endl;
    ro.build("../files/reference/ref.ro");
    cout << "da" << endl;
    da.build("../files/reference/ref.da");
    cout << "el" << endl;
    el.build("../files/reference/ref.el");
    cout << "fi" << endl;
    fi.build("../files/reference/ref.fi");
    cout << "hu" << endl;
    hu.build("../files/reference/ref.hu");
    cout << "sv" << endl;
    sv.build("../files/reference/ref.sv");
    cout << "lv" << endl;
    lv.build("../files/reference/ref.lv");
    cout << "sk" << endl;
    sk.build("../files/reference/ref.sk");
    cout << "sl" << endl;
    sl.build("../files/reference/ref.sl");

    cout << "\ncomparations" << endl;
    cout << "pt" << endl;
    pt.compare(text_file);
    cout << "en" << endl;
    en.compare(text_file);
    cout << "fr" << endl;
    fr.compare(text_file);
    cout << "bg" << endl;
    bg.compare(text_file);
    cout << "cs" << endl;
    cs.compare(text_file);
    cout << "de" << endl;
    de.compare(text_file);
    cout << "es" << endl;
    es.compare(text_file);
    cout << "et" << endl;
    et.compare(text_file);
    cout << "it" << endl;
    it.compare(text_file);
    cout << "nl" << endl;
    nl.compare(text_file);
    cout << "pl" << endl;
    pl.compare(text_file);
    cout << "ro" << endl;
    ro.compare(text_file);
    cout << "da" << endl;
    da.compare(text_file);
    cout << "el" << endl;
    el.compare(text_file);
    cout << "fi" << endl;
    fi.compare(text_file);
    cout << "hu" << endl;
    hu.compare(text_file);
    cout << "sv" << endl;
    sv.compare(text_file);
    cout << "lv" << endl;
    lv.compare(text_file);
    cout << "sk" << endl;
    sk.compare(text_file);
    cout << "sl" << endl;
    sl.compare(text_file);

    double min_bits_symbol = min_of(pt.bits_symbol, en.bits_symbol, fr.bits_symbol,
                                    bg.bits_symbol, cs.bits_symbol, de.bits_symbol,
                                    es.bits_symbol, et.bits_symbol, it.bits_symbol,
                                    nl.bits_symbol, pl.bits_symbol, ro.bits_symbol,
                                    da.bits_symbol, el.bits_symbol, fi.bits_symbol,
                                    hu.bits_symbol, sv.bits_symbol, lv.bits_symbol,
                                    sk.bits_symbol, sl.bits_symbol);

    cout << "\nThe text is written in ";

    if(min_bits_symbol == pt.bits_symbol) cout << "portuguese";
    else if (min_bits_symbol == en.bits_symbol) cout << "english";
    else if (min_bits_symbol == fr.bits_symbol) cout << "french";
    else if (min_bits_symbol == bg.bits_symbol) cout << "bulgarian";
    else if (min_bits_symbol == cs.bits_symbol) cout << "czech";
    else if (min_bits_symbol == de.bits_symbol) cout << "german";
    else if (min_bits_symbol == es.bits_symbol) cout << "spanish";
    else if (min_bits_symbol == et.bits_symbol) cout << "estonian";
    else if (min_bits_symbol == it.bits_symbol) cout << "italian";
    else if (min_bits_symbol == nl.bits_symbol) cout << "dutch";
    else if (min_bits_symbol == pl.bits_symbol) cout << "polish";
    else if (min_bits_symbol == ro.bits_symbol) cout << "romanian";
    else if (min_bits_symbol == da.bits_symbol) cout << "danish";
    else if (min_bits_symbol == el.bits_symbol) cout << "greek";
    else if (min_bits_symbol == fi.bits_symbol) cout << "finnish";
    else if (min_bits_symbol == hu.bits_symbol) cout << "hungarian";
    else if (min_bits_symbol == sv.bits_symbol) cout << "swedish";
    else if (min_bits_symbol == lv.bits_symbol) cout << "latvian";
    else if (min_bits_symbol == sk.bits_symbol) cout << "slovak";
    else if (min_bits_symbol == sl.bits_symbol) cout << "slovenian";

    return 0;
}