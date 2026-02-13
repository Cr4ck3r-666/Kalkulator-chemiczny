#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <iomanip>
#include <stdexcept>
#include <math.h>

using namespace std;

string substancja_A, substancja_B ,substancja_C, substancja_D, substancja_E, substancja_F, substancja_G, substancja_H ,substancja_I ,substancja_J;

struct Pierwiastek 
{
    string symbol;
    string nazwa;
    float masa_atomowa;
};

constexpr int LICZBA_PIERWIASTKOW = 118;
Pierwiastek pierwiastki[LICZBA_PIERWIASTKOW] = {
    {"H", "Wodór", 1.008f}, {"He", "Hel", 4.003f}, {"Li", "Lit", 6.94f}, {"Be", "Beryl", 9.012f},
    {"B", "Bor", 10.811f}, {"C", "Węgiel", 12.011f}, {"N", "Azot", 14.007f}, {"O", "Tlen", 15.999f},
    {"F", "Fluor", 18.998f}, {"Ne", "Neon", 20.180f}, {"Na", "Sód", 22.99f}, {"Mg", "Magnez", 24.305f},
    {"Al", "Glin", 26.982f}, {"Si", "Krzem", 28.085f}, {"P", "Fosfor", 30.974f}, {"S", "Siarka", 32.065f},
    {"Cl", "Chlor", 35.453f}, {"Ar", "Argon", 39.948f}, {"K", "Potas", 39.098f}, {"Ca", "Wapń", 40.078f},
    {"Sc", "Scand", 44.956f}, {"Ti", "Tytan", 47.867f}, {"V", "Wanad", 50.942f}, {"Cr", "Chrom", 51.996f},
    {"Mn", "Mangan", 54.938f}, {"Fe", "Żelazo", 55.845f}, {"Co", "Kobalt", 58.933f}, {"Ni", "Nikiel", 58.693f},
    {"Cu", "Miedź", 63.546f}, {"Zn", "Cynk", 65.39f}, {"Ga", "Gal", 69.723f}, {"Ge", "German", 72.61f},
    {"As", "Arsen", 74.922f}, {"Se", "Selen", 78.96f}, {"Br", "Brom", 79.904f}, {"Kr", "Krypton", 83.798f},
    {"Rb", "Rubid", 85.468f}, {"Sr", "Stront", 87.62f}, {"Y", "Itr", 89.906f}, {"Zr", "Cyrkon", 91.224f},
    {"Nb", "Niob", 92.206f}, {"Mo", "Molibden", 95.94f}, {"Tc", "Technet", 97.905f}, {"Ru", "Ruten", 101.07f},
    {"Rh", "Rod", 102.906f}, {"Pd", "Pallad", 106.42f}, {"Ag", "Srebro", 107.868f}, {"Cd", "Kadm", 112.411f},
    {"In", "Ind", 114.818f}, {"Sn", "Cyna", 118.610f}, {"Sb", "Antymon", 121.760f}, {"Te", "Telleur", 127.60f},
    {"I", "Jod", 126.904f}, {"Xe", "Ksenon", 131.293f}, {"Cs", "Cez", 132.905f}, {"Ba", "Bar", 137.327f},
    {"La", "Lantan", 138.905f}, {"Ce", "Cer", 140.12f}, {"Pr", "Prazeodym", 140.09f}, {"Nd", "Neodym", 144.24f},
    {"Pm", "Promet", 144.91f}, {"Sm", "Samar", 150.36f}, {"Eu", "Europ", 151.96f}, {"Gd", "Gadolin", 157.25f},
    {"Tb", "Terb", 158.93f}, {"Dy", "Dysproz", 165.5f}, {"Ho", "Holm", 164.93f}, {"Er", "Erb", 167.26f},
    {"Tm", "Tul", 168.93f}, {"Yb", "Iterb", 173.04f}, {"Lu", "Lutet", 174.97f}, {"Hf", "Hafn", 178.49f},
    {"Ta", "Tantal", 180.948f}, {"W", "Wolfram", 183.84f}, {"Re", "Ren", 186.207f}, {"Os", "Osm", 190.23f},
    {"Ir", "Iryd", 192.117f}, {"Pt", "Platyna", 195.084f}, {"Au", "Złoto", 196.967f}, {"Hg", "Rtęć", 200.59f},
    {"Tl", "Tal", 204.38f}, {"Pb", "Ołów", 207.2f}, {"Bi", "Bizmut", 208.98f}, {"Po", "Polon", 208.98f},
    {"At", "Astat", 209.99f}, {"Rn", "Radon", 222.02f}, {"Fr", "Frans", 223.020f}, {"Ra", "Rad", 226.025f},
    {"Ac", "Aktyn", 227.028f}, {"Th", "Tor", 232.0337f}, {"Pa", "Proaktyn", 231.03f}, {"U", "Uran", 238.02f},
    {"Np", "Neptun", 237.0f}, {"Pu", "Pluton", 244.0f}, {"Am", "Ameryk", 243.0f}, {"Cm", "Kiur", 247.0f},
    {"Bk", "Berkel", 247.0f}, {"Cf", "Kaliforn", 251.0f}, {"Es", "Einstein", 252.0f}, {"Fm", "Ferm", 257.0f},
    {"Md", "Mendelew", 258.0f}, {"No", "Nobel", 259.0f}, {"Lr", "Lorens", 266.0f}, {"Rf", "Ruteford", 261.11f},
    {"Db", "Dubn", 261.11f}, {"Sg", "Seaborg", 265.12f}, {"Bh", "Bohr", 264.10f}, {"Hs", "Has", 269.10f},
    {"Mt", "Meitner", 268.10f}, {"Ds", "Darmsztadt", 281.10f}, {"Rg", "Rentgen", 280.0f}, {"Cn", "Kopernik", 285.0f},
    {"Nh", "Nihon", 284.0f}, {"Fl", "Flerow", 289.0f}, {"Mc", "Moskow", 288.0f}, {"Lv", "Liwemor", 292.0f},
    {"Ts", "Tenes", 294.0f}, {"Og", "Oganeson", 294.0f}
};

int parseNumber(const string& s, size_t& i) 
{
    int num = 0;
    while (i < s.size() && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num == 0 ? 1 : num;
}

map<string, int> parseFormula(const string& s, size_t& i) 
{
    map<string, int> result;

    while (i < s.size()) {
        if (s[i] == '(') {
            i++;
            auto inner = parseFormula(s, i);

            if (i >= s.size() || s[i] != ')')
                throw runtime_error("Missing closing parenthesis");

            i++;
            int mult = parseNumber(s, i);

            for (auto& p : inner)
                result[p.first] += p.second * mult;

        } else if (isupper(s[i])) {
            string element;
            element += s[i++];
            if (i < s.size() && islower(s[i]))
                element += s[i++];

            int count = parseNumber(s, i);
            result[element] += count;

        } else if (s[i] == ')') {
            return result;
        } else {
            throw runtime_error("Invalid character in formula");
        }
    }

    return result;
}

map<string, int> parseFormula(const string& s) 
{
    size_t i = 0;
    return parseFormula(s, i);
}

void obliczMaseMolowa(const string& substancja, float& masa_molowa) 
{
    auto result = parseFormula(substancja);
    masa_molowa = 0.0f;

    for (auto& p : result) {
        string symbol = p.first;
        int ilosc = p.second;

        float masa_atomowa = 0.0f;
        bool znaleziono = false;
        for (int i = 0; i < LICZBA_PIERWIASTKOW; ++i) {
            if (pierwiastki[i].symbol == symbol) {
                masa_atomowa = pierwiastki[i].masa_atomowa;
                znaleziono = true;
                break;
            }
        }

        if (znaleziono) {
            masa_molowa += masa_atomowa * ilosc;
        }
    }
}

void identyfikacja_zwiazku_2(const string& substancja_A, const string& substancja_B) 
{
    float masa_molowa_A = 0.0f;
    float masa_molowa_B = 0.0f;

    obliczMaseMolowa(substancja_A, masa_molowa_A);
    obliczMaseMolowa(substancja_B, masa_molowa_B);

    cout<<" "<<endl;
    cout << "Substancja A: " << substancja_A << endl;
    auto result_A = parseFormula(substancja_A);
    for (auto& p : result_A) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji A: " << masa_molowa_A << " g/mol" << endl;
    cout<<" "<<endl;

    cout << "Substancja B: " << substancja_B << endl;
    auto result_B = parseFormula(substancja_B);
    for (auto& p : result_B) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji B: " << masa_molowa_B << "g/mol"<< endl;
}

void identyfikacja_zwiazku_3(const string& substancja_A, const string& substancja_B, const string& substancja_C) 
{
    float masa_molowa_A = 0.0;
    float masa_molowa_B = 0.0;
    float masa_molowa_C = 0.0;

    obliczMaseMolowa(substancja_A, masa_molowa_A);
    obliczMaseMolowa(substancja_B, masa_molowa_B);
    obliczMaseMolowa(substancja_C, masa_molowa_C);

    cout<<" "<<endl;
    cout << "Substancja A: " << substancja_A << endl;
    auto result_A = parseFormula(substancja_A);
    for (auto& p : result_A) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji A: " << masa_molowa_A << " g/mol" << endl;
    cout<<" "<<endl;

    cout << "Substancja B: " << substancja_B << endl;
    auto result_B = parseFormula(substancja_B);
    for (auto& p : result_B) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji B: " << masa_molowa_B << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja C: " << substancja_C << endl;
    auto result_C = parseFormula(substancja_C);
    for (auto& p : result_C) 
    {
        cout << " Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji C: " << masa_molowa_C << "g/mol"<< endl;
    cout<<" "<<endl;
}

void identyfikacja_zwiazku_4(const string& substancja_A, const string& substancja_B, const string& substancja_C, const string& substancja_D) 
{
    float masa_molowa_A = 0.0f;
    float masa_molowa_B = 0.0f;
    float masa_molowa_C = 0.0f;
    float masa_molowa_D = 0.0f;

    obliczMaseMolowa(substancja_A, masa_molowa_A);
    obliczMaseMolowa(substancja_B, masa_molowa_B);
    obliczMaseMolowa(substancja_C, masa_molowa_C);
    obliczMaseMolowa(substancja_D, masa_molowa_D);

    cout<<" "<<endl;
    cout << "Substancja A: " << substancja_A << endl;
    auto result_A = parseFormula(substancja_A);
    for (auto& p : result_A) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji A: " << masa_molowa_A << " g/mol" << endl;
    cout<<" "<<endl;

    cout << "Substancja B: " << substancja_B << endl;
    auto result_B = parseFormula(substancja_B);
    for (auto& p : result_B) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji B: " << masa_molowa_B << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja C: " << substancja_C << endl;
    auto result_C = parseFormula(substancja_C);
    for (auto& p : result_C) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji C: " << masa_molowa_C << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja D: " << substancja_D << endl;
    auto result_D = parseFormula(substancja_D);
    for (auto& p : result_D) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji D: " << masa_molowa_D << "g/mol"<< endl;
}

void identyfikacja_zwiazku_5(const string& substancja_A, const string& substancja_B, const string& substancja_C, const string& substancja_D, const string& substancja_E) 
{
    float masa_molowa_A = 0.0f;
    float masa_molowa_B = 0.0f;
    float masa_molowa_C = 0.0f;
    float masa_molowa_D = 0.0f;
    float masa_molowa_E = 0.0f;

    obliczMaseMolowa(substancja_A, masa_molowa_A);
    obliczMaseMolowa(substancja_B, masa_molowa_B);
    obliczMaseMolowa(substancja_C, masa_molowa_C);
    obliczMaseMolowa(substancja_D, masa_molowa_D);
    obliczMaseMolowa(substancja_E, masa_molowa_E);

    cout<<" "<<endl;
    cout << "Substancja A: " << substancja_A << endl;
    auto result_A = parseFormula(substancja_A);
    for (auto& p : result_A) {
        cout << "  Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji A: " << masa_molowa_A << " g/mol" << endl;
    cout<<" "<<endl;

    cout << "Substancja B: " << substancja_B << endl;
    auto result_B = parseFormula(substancja_B);
    for (auto& p : result_B) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji B: " << masa_molowa_B << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja C: " << substancja_C << endl;
    auto result_C = parseFormula(substancja_C);
    for (auto& p : result_C) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji C: " << masa_molowa_C << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja D: " << substancja_D << endl;
    auto result_D = parseFormula(substancja_D);
    for (auto& p : result_D) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji D: " << masa_molowa_D << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja E: " << substancja_E << endl;
    auto result_E = parseFormula(substancja_E);
    for (auto& p : result_E) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji E: " << masa_molowa_E << "g/mol"<< endl;
}

void identyfikacja_zwiazku_6(const string& substancja_A, const string& substancja_B, const string& substancja_C, const string& substancja_D, const string& substancja_E ,const string& substancja_F) 
{
    float masa_molowa_A = 0.0f;
    float masa_molowa_B = 0.0f;
    float masa_molowa_C = 0.0f;
    float masa_molowa_D = 0.0f;
    float masa_molowa_E = 0.0f;
    float masa_molowa_F = 0.0f;

    obliczMaseMolowa(substancja_A, masa_molowa_A);
    obliczMaseMolowa(substancja_B, masa_molowa_B);
    obliczMaseMolowa(substancja_C, masa_molowa_C);
    obliczMaseMolowa(substancja_D, masa_molowa_D);
    obliczMaseMolowa(substancja_E, masa_molowa_E);
    obliczMaseMolowa(substancja_F, masa_molowa_F);

    cout<<" "<<endl;
    cout << "Substancja A: " << substancja_A << endl;
    auto result_A = parseFormula(substancja_A);
    for (auto& p : result_A) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji A: " << masa_molowa_A << " g/mol" << endl;
    cout<<" "<<endl;

    cout << "Substancja B: " << substancja_B << endl;
    auto result_B = parseFormula(substancja_B);
    for (auto& p : result_B) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji B: " << masa_molowa_B << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja C: " << substancja_C << endl;
    auto result_C = parseFormula(substancja_C);
    for (auto& p : result_C) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji C: " << masa_molowa_C << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja D: " << substancja_D << endl;
    auto result_D = parseFormula(substancja_D);
    for (auto& p : result_D) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji D: " << masa_molowa_D << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja E: " << substancja_E << endl;
    auto result_E = parseFormula(substancja_E);
    for (auto& p : result_E) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji E: " << masa_molowa_E << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja F: " << substancja_F << endl;
    auto result_F = parseFormula(substancja_F);
    for (auto& p : result_F) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji F: " << masa_molowa_F << "g/mol"<< endl;
}

void identyfikacja_zwiazku_7(const string& substancja_A, const string& substancja_B, const string& substancja_C, const string& substancja_D, const string& substancja_E ,const string& substancja_F, const string& substancja_G) 
{
    float masa_molowa_A = 0.0f;
    float masa_molowa_B = 0.0f;
    float masa_molowa_C = 0.0f;
    float masa_molowa_D = 0.0f;
    float masa_molowa_E = 0.0f;
    float masa_molowa_F = 0.0f;
    float masa_molowa_G = 0.0f;

    obliczMaseMolowa(substancja_A, masa_molowa_A);
    obliczMaseMolowa(substancja_B, masa_molowa_B);
    obliczMaseMolowa(substancja_C, masa_molowa_C);
    obliczMaseMolowa(substancja_D, masa_molowa_D);
    obliczMaseMolowa(substancja_E, masa_molowa_E);
    obliczMaseMolowa(substancja_F, masa_molowa_F);
    obliczMaseMolowa(substancja_G, masa_molowa_G);

    cout<<" "<<endl;
    cout << "Substancja A: " << substancja_A << endl;
    auto result_A = parseFormula(substancja_A);
    for (auto& p : result_A) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji A: " << masa_molowa_A << " g/mol" << endl;
    cout<<" "<<endl;

    cout << "Substancja B: " << substancja_B << endl;
    auto result_B = parseFormula(substancja_B);
    for (auto& p : result_B) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji B: " << masa_molowa_B << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja C: " << substancja_C << endl;
    auto result_C = parseFormula(substancja_C);
    for (auto& p : result_C) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji C: " << masa_molowa_C << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja D: " << substancja_D << endl;
    auto result_D = parseFormula(substancja_D);
    for (auto& p : result_D) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji D: " << masa_molowa_D << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja E: " << substancja_E << endl;
    auto result_E = parseFormula(substancja_E);
    for (auto& p : result_E) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji E: " << masa_molowa_E << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja F: " << substancja_F << endl;
    auto result_F = parseFormula(substancja_F);
    for (auto& p : result_F) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji F: " << masa_molowa_F << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja G: " << substancja_G << endl;
    auto result_G = parseFormula(substancja_G);
    for (auto& p : result_G) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji G: " << masa_molowa_G << "g/mol"<< endl;
}

void identyfikacja_zwiazku_8(const string& substancja_A, const string& substancja_B, const string& substancja_C, const string& substancja_D, const string& substancja_E ,const string& substancja_F, const string& substancja_G, const string& substancja_H) 
{
    float masa_molowa_A = 0.0f;
    float masa_molowa_B = 0.0f;
    float masa_molowa_C = 0.0f;
    float masa_molowa_D = 0.0f;
    float masa_molowa_E = 0.0f;
    float masa_molowa_F = 0.0f;
    float masa_molowa_G = 0.0f;
    float masa_molowa_H = 0.0f;

    obliczMaseMolowa(substancja_A, masa_molowa_A);
    obliczMaseMolowa(substancja_B, masa_molowa_B);
    obliczMaseMolowa(substancja_C, masa_molowa_C);
    obliczMaseMolowa(substancja_D, masa_molowa_D);
    obliczMaseMolowa(substancja_E, masa_molowa_E);
    obliczMaseMolowa(substancja_F, masa_molowa_F);
    obliczMaseMolowa(substancja_G, masa_molowa_G);
    obliczMaseMolowa(substancja_G, masa_molowa_H);

    cout<<" "<<endl;
    cout << "Substancja A: " << substancja_A << endl;
    auto result_A = parseFormula(substancja_A);
    for (auto& p : result_A) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji A: " << masa_molowa_A << " g/mol" << endl;
    cout<<" "<<endl;

    cout << "Substancja B: " << substancja_B << endl;
    auto result_B = parseFormula(substancja_B);
    for (auto& p : result_B) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji B: " << masa_molowa_B << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja C: " << substancja_C << endl;
    auto result_C = parseFormula(substancja_C);
    for (auto& p : result_C) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji C: " << masa_molowa_C << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja D: " << substancja_D << endl;
    auto result_D = parseFormula(substancja_D);
    for (auto& p : result_D) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji D: " << masa_molowa_D << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja E: " << substancja_E << endl;
    auto result_E = parseFormula(substancja_E);
    for (auto& p : result_E) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji E: " << masa_molowa_E << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja F: " << substancja_F << endl;
    auto result_F = parseFormula(substancja_F);
    for (auto& p : result_F) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji F: " << masa_molowa_F << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja G: " << substancja_G << endl;
    auto result_G = parseFormula(substancja_G);
    for (auto& p : result_G) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji G: " << masa_molowa_G << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja H: " << substancja_H << endl;
    auto result_H = parseFormula(substancja_H);
    for (auto& p : result_H) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji H: " << masa_molowa_H << "g/mol"<< endl;
}

void identyfikacja_zwiazku_9(const string& substancja_A, const string& substancja_B, const string& substancja_C, const string& substancja_D, const string& substancja_E ,const string& substancja_F, const string& substancja_G, const string& substancja_H, const string& substancja_I) 
{
    float masa_molowa_A = 0.0f;
    float masa_molowa_B = 0.0f;
    float masa_molowa_C = 0.0f;
    float masa_molowa_D = 0.0f;
    float masa_molowa_E = 0.0f;
    float masa_molowa_F = 0.0f;
    float masa_molowa_G = 0.0f;
    float masa_molowa_H = 0.0f;
    float masa_molowa_I = 0.0f;

    obliczMaseMolowa(substancja_A, masa_molowa_A);
    obliczMaseMolowa(substancja_B, masa_molowa_B);
    obliczMaseMolowa(substancja_C, masa_molowa_C);
    obliczMaseMolowa(substancja_D, masa_molowa_D);
    obliczMaseMolowa(substancja_E, masa_molowa_E);
    obliczMaseMolowa(substancja_F, masa_molowa_F);
    obliczMaseMolowa(substancja_G, masa_molowa_G);
    obliczMaseMolowa(substancja_G, masa_molowa_H);
    obliczMaseMolowa(substancja_G, masa_molowa_I);

    cout<<" "<<endl;
    cout << "Substancja A: " << substancja_A << endl;
    auto result_A = parseFormula(substancja_A);
    for (auto& p : result_A) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji A: " << masa_molowa_A << " g/mol" << endl;
    cout<<" "<<endl;

    cout << "Substancja B: " << substancja_B << endl;
    auto result_B = parseFormula(substancja_B);
    for (auto& p : result_B) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji B: " << masa_molowa_B << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja C: " << substancja_C << endl;
    auto result_C = parseFormula(substancja_C);
    for (auto& p : result_C) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji C: " << masa_molowa_C << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja D: " << substancja_D << endl;
    auto result_D = parseFormula(substancja_D);
    for (auto& p : result_D) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji D: " << masa_molowa_D << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja E: " << substancja_E << endl;
    auto result_E = parseFormula(substancja_E);
    for (auto& p : result_E) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji E: " << masa_molowa_E << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja F: " << substancja_F << endl;
    auto result_F = parseFormula(substancja_F);
    for (auto& p : result_F) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji F: " << masa_molowa_F << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja G: " << substancja_G << endl;
    auto result_G = parseFormula(substancja_G);
    for (auto& p : result_G) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji G: " << masa_molowa_G << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja H: " << substancja_H << endl;
    auto result_H = parseFormula(substancja_H);
    for (auto& p : result_H) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji H: " << masa_molowa_H << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja I: " << substancja_I << endl;
    auto result_I = parseFormula(substancja_I);
    for (auto& p : result_I) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji I: " << masa_molowa_I << "g/mol"<< endl;
}

void identyfikacja_zwiazku_10(const string& substancja_A, const string& substancja_B, const string& substancja_C, const string& substancja_D, const string& substancja_E ,const string& substancja_F, const string& substancja_G, const string& substancja_H, const string& substancja_I, const string& substancja_J) 
{
    float masa_molowa_A = 0.0f;
    float masa_molowa_B = 0.0f;
    float masa_molowa_C = 0.0f;
    float masa_molowa_D = 0.0f;
    float masa_molowa_E = 0.0f;
    float masa_molowa_F = 0.0f;
    float masa_molowa_G = 0.0f;
    float masa_molowa_H = 0.0f;
    float masa_molowa_I = 0.0f;
    float masa_molowa_J = 0.0f;

    obliczMaseMolowa(substancja_A, masa_molowa_A);
    obliczMaseMolowa(substancja_B, masa_molowa_B);
    obliczMaseMolowa(substancja_C, masa_molowa_C);
    obliczMaseMolowa(substancja_D, masa_molowa_D);
    obliczMaseMolowa(substancja_E, masa_molowa_E);
    obliczMaseMolowa(substancja_F, masa_molowa_F);
    obliczMaseMolowa(substancja_G, masa_molowa_G);
    obliczMaseMolowa(substancja_G, masa_molowa_H);
    obliczMaseMolowa(substancja_G, masa_molowa_I);
    obliczMaseMolowa(substancja_G, masa_molowa_J);

    cout<<" "<<endl;
    cout << "Substancja A: " << substancja_A << endl;
    auto result_A = parseFormula(substancja_A);
    for (auto& p : result_A) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji A: " << masa_molowa_A << " g/mol" << endl;
    cout<<" "<<endl;

    cout << "Substancja B: " << substancja_B << endl;
    auto result_B = parseFormula(substancja_B);
    for (auto& p : result_B) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji B: " << masa_molowa_B << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja C: " << substancja_C << endl;
    auto result_C = parseFormula(substancja_C);
    for (auto& p : result_C) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji C: " << masa_molowa_C << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja D: " << substancja_D << endl;
    auto result_D = parseFormula(substancja_D);
    for (auto& p : result_D) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji D: " << masa_molowa_D << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja E: " << substancja_E << endl;
    auto result_E = parseFormula(substancja_E);
    for (auto& p : result_E) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji E: " << masa_molowa_E << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja F: " << substancja_F << endl;
    auto result_F = parseFormula(substancja_F);
    for (auto& p : result_F) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji F: " << masa_molowa_F << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja G: " << substancja_G << endl;
    auto result_G = parseFormula(substancja_G);
    for (auto& p : result_G) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji G: " << masa_molowa_G << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja H: " << substancja_H << endl;
    auto result_H = parseFormula(substancja_H);
    for (auto& p : result_H) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji H: " << masa_molowa_H << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja I: " << substancja_I << endl;
    auto result_I = parseFormula(substancja_I);
    for (auto& p : result_I) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji I: " << masa_molowa_I << "g/mol"<< endl;
    cout<<" "<<endl;

    cout << "Substancja J: " << substancja_J << endl;
    auto result_J = parseFormula(substancja_J);
    for (auto& p : result_J) 
    {
        cout << "Pierwiastek: " << p.first << ", Ilość: " << p.second << endl;
    }
    cout<<" "<<endl;
    cout << "Masa molowa substancji J: " << masa_molowa_J << "g/mol"<< endl;
}

int main() 
{
        cout<<" "<<endl;
        cout<<" ##### ####  #### #####  #### #####  ###### ##### ###### #####   "<<endl;
        cout<<"   #   ##  ##  ## ##  ## ##   ##  ## ##  ##   #   ##  ## ##  ##  "<<endl;
        cout<<"   #   ##      ## #####  #### ####   ######   #   ##  ## #####   "<<endl;
        cout<<"   #   ##      ## ##     ##   ## ##  ##  ##   #   ##  ## ## ##   "<<endl;
        cout<<" ##### ##      ## ##     #### ##  ## ##  ##   #   ###### ##  ##  "<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<" Witaj w kalkulatorze chemicznym, wybierz jedną z opcji.         "<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"1) Kalkulator masy molowej"<<endl; 
        cout<<"2) Kalkulator stężenia procentowego"<<endl;
        cout<<"3) Kalkulator stężenia molowego"<<endl;
        cout<<"4) Równanie Nersta"<<endl;
        cout<<"5) Wydajność reakcji chemicznej"<<endl;
        cout<<"6) Bilansowanie reakcji chemicznych"<<endl;
        cout<<"7) Energia aktywacji(z równania Arrcheniusa)"<<endl;
        cout<<"8) Stała szybkości reakcji(z równania Arrcheniusa)"<<endl;
        cout<<"9) Szybkość reakcji chemicznej"<<endl; 
        cout<<"10) Kalkulator pH"<<endl;
        cout<<"11) Wyjście"<<endl;
        cout<<"----------------------------------------------------------"<<endl;
        int i;
        cin >> i;
        switch (i) 
        {
            case 1: 
            {
                cout << "Podaj ilość substratów, maksymalna ilość to 5:" << endl;
                int substraty;
                cin >> substraty;

                cout << "Podaj ilość produktów, maksymalna ilość to 5:" << endl;
                int produkty;
                cin >> produkty;

                if (substraty == 1) 
                {
                    if (produkty == 1) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A ---> B" << endl;                    
                        cout << " " << endl;
                        identyfikacja_zwiazku_2(substancja_A, substancja_B);
                    }
                    else if (produkty == 2) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_C;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A ---> B + C" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_3(substancja_A, substancja_B, substancja_C);
                    }
                    else if (produkty == 3) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_D;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A ---> B + C + D" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_4(substancja_A, substancja_B, substancja_C, substancja_D);
                    }
                    else if (produkty == 4) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_E;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A ---> B + C + D + E" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_5(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E);
                    }
                    else if (produkty == 5) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_F;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A ---> B + C + D + E + F" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_6(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F);
                    }
                }

                else if (substraty == 2) 
                {
                    if (produkty == 1) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "A + B ---> C" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_3(substancja_A, substancja_B, substancja_C);
                    }

                    else if (produkty == 2) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B ---> C + D" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_4(substancja_A, substancja_B, substancja_C, substancja_D);
                    }

                    else if (produkty == 3) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B ---> C + D + E" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_5(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E);
                    }

                    else if (produkty == 4) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B ---> C + D + E + F" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_6(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F);
                    }

                    else if (produkty == 5) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_G;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B ---> C + D + E + F + G" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_7(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G);
                    }
                }

                else if (substraty == 3) 
                {
                    if (produkty == 1) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C ---> D" << endl;
                        identyfikacja_zwiazku_4(substancja_A, substancja_B, substancja_C, substancja_D);
                    }

                    else if (produkty == 2) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C ---> D + E" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_5(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E);
                    }

                    else if (produkty == 3) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C ---> D + E + F" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_6(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F);
                    }

                    else if (produkty == 4) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji G:" << endl;
                        cin >> substancja_G;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C ---> D + E + F + G" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_7(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G);
                    }
                    else if (produkty == 5) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji G:" << endl;
                        cin >> substancja_G;
                        cout << "Podaj wzór substancji H:" << endl;
                        cin >> substancja_H;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C ---> D + E + F + G + H" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_8(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G, substancja_H);
                    }
                }

                else if (substraty == 4) 
                {
                    if (produkty == 1) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C + D ---> E" << endl;
                        identyfikacja_zwiazku_5(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E);
                    }

                    else if (produkty == 2) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_F;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C + D ---> E + F" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_6(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F);
                    }

                    else if (produkty == 3) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji G:" << endl;
                        cin >> substancja_G;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C  + D ---> E + F + G" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_7(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G);
                    }

                    else if (produkty == 4) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji G:" << endl;
                        cin >> substancja_G;
                        cout << "Podaj wzór substancji H:" << endl;
                        cin >> substancja_H;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C + D ---> E + F + G + H" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_8(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G, substancja_H);
                    }
                    else if (produkty == 5) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji G:" << endl;
                        cin >> substancja_G;
                        cout << "Podaj wzór substancji H:" << endl;
                        cin >> substancja_H;
                        cout << "Podaj wzór substancji I:" << endl;
                        cin >> substancja_I;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C + D ---> E + F + G + H + I" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_9(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G, substancja_H ,substancja_I);
                    }
                }
                            
                else if (substraty == 5) 
                {
                    if (produkty == 1) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C + D + E ---> F" << endl;
                        identyfikacja_zwiazku_6(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F);
                    }

                    else if (produkty == 2) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji G:" << endl;
                        cin >> substancja_G;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C + D + E---> F + G" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_7(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G);
                    }

                    else if (produkty == 3) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji G:" << endl;
                        cin >> substancja_G;
                        cout << "Podaj wzór substancji H:" << endl;
                        cin >> substancja_H;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C  + D + E ---> F + G + H" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_8(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G, substancja_H);
                    }

                    else if (produkty == 4) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji G:" << endl;
                        cin >> substancja_G;
                        cout << "Podaj wzór substancji H:" << endl;
                        cin >> substancja_H;
                        cout << "Podaj wzór substancji I:" << endl;
                        cin >> substancja_I;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C + D + E ---> F + G + H + I" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_9(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G, substancja_H, substancja_I);
                    }
                    else if (produkty == 5) 
                    {
                        cout << " " << endl;
                        cout << "Podaj wzór substancji A:" << endl;
                        cin >> substancja_A;
                        cout << "Podaj wzór substancji B:" << endl;
                        cin >> substancja_B;
                        cout << "Podaj wzór substancji C:" << endl;
                        cin >> substancja_C;
                        cout << "Podaj wzór substancji D:" << endl;
                        cin >> substancja_D;
                        cout << "Podaj wzór substancji E:" << endl;
                        cin >> substancja_E;
                        cout << "Podaj wzór substancji F:" << endl;
                        cin >> substancja_F;
                        cout << "Podaj wzór substancji G:" << endl;
                        cin >> substancja_G;
                        cout << "Podaj wzór substancji H:" << endl;
                        cin >> substancja_H;
                        cout << "Podaj wzór substancji I:" << endl;
                        cin >> substancja_I;
                        cout << "Podaj wzór substancji J:" << endl;
                        cin >> substancja_J;
                        cout << "Wzór ogólny reakcji:" << endl;
                        cout << " " << endl;
                        cout << "A + B + C + D + E ---> F + G + H + I + J" << endl;
                        cout << " " << endl;
                        identyfikacja_zwiazku_10(substancja_A, substancja_B, substancja_C, substancja_D, substancja_E, substancja_F, substancja_G, substancja_H, substancja_I, substancja_J);
                    }
                }
                break;
            }
            case 2: 
            {          
                double ms;
                double mr;

                cout<<"#----------------------------------------#"<<endl;
                cout<<"# Dane proszę wprowadzać w formacie x.x, #"<<endl;
                cout<<"# np. 1.0 ,45.9873 ,0.450092 ,itp.       #"<<endl;
                cout<<"#----------------------------------------#"<<endl;
                cout<<" "<<endl;
                cout<<"Podaj masę substancji w gramach:"<<endl;
                cin>>ms;
                cout<<"Podaj masę roztworu w gramach:"<<endl;
                cin>>mr;

                double Cp = ms/mr;
                double result = Cp * 100;

                cout<<" "<<endl;
                cout<<"Stężenie procentowe wynosi: "<<result<<" %"<<endl;
                break;
            }
            case 3: 
            {
                cout<<"#----------------------------------------#"<<endl;
                cout<<"# Dane proszę wprowadzać w formacie x.x, #"<<endl;
                cout<<"# np. 1.0 ,45.9873 ,0.450092 ,itp.       #"<<endl;
                cout<<"#----------------------------------------#"<<endl;
                cout<<" "<<endl;
                cout<<" Wybierz wersję:"<<endl;
                cout<<" 1) Z liczby moli i objętości"<<endl;
                cout<<" 2) Z liczby moli i gęstości roztworu"<<endl;
                cout<<" 3) Związek pomiędzy Cm a Cp"<<endl;
                cout<<" "<<endl;  
                int i;
                cin>>i;
                switch(i)
                {
                    case 1:
                    {
                        float n;
                        float Vr;
                        
                        cout<<"Podaj liczbę moli substancji rozpuszczanej:"<<endl;
                        cin>>n;
                        cout<<"Podaj objętość roztworu w dm3:"<<endl;
                        cin>>Vr;

                        float Cm = n/Vr;
                        float result = Cm*100;

                        cout<<" "<<endl;
                        cout<<"Stężenie molowe wynosi: "<<result<<"mol/dm3"<<endl;
                        break;
                    }

                    case 2:
                    {
                        float ms;
                        float mr;
                        float dr;
                        float n;

                        cout<<"Podaj masę substancji rozpuszczanej:"<<endl;
                        cin>>ms;
                        cout<<"Podaj masę roztworu:"<<endl;
                        cin>>mr;
                        cout<<"Podaj gęstość roztworu:"<<endl;
                        cin>>dr;
                        cout<<"Podaj masę molową substancji rozpuszczanej:"<<endl;
                        cin>>n;

                        float podstawa = n*mr;
                        float pietro = ms*dr;
                        float Cm = pietro/podstawa;
                        float result = Cm*100;

                        cout<<" "<<endl;
                        cout<<"Stężenie molowe wynosi: "<<result<<"mol/dm3"<<endl;
                        break;
                    }

                    case 3:
                    {
                        float Cp;
                        float dr;
                        float M;

                        cout<<"Podaj stężenie procentowe:"<<endl;
                        cin>>Cp;
                        cout<<"Podaj gęstość roztworu:"<<endl;
                        cin>>dr;
                        cout<<"Podaj masę molową substancji rozpuszczonej:"<<endl;
                        cin>>M;

                        float podstawa = 100*M;
                        float pietro = Cp*dr;
                        float Cm = pietro/podstawa;
                        float result = Cm*100;

                        cout<<" "<<endl;
                        cout<<"Stężenie molowe jest równe: "<<result<<"mol/dm3"<<endl;
                        break;
                    }
                    default:
                    {
                        cout<<"Liczba poza zakresem"<<endl;
                        break;
                    }
                }
                break;
            }
            case 4: 
            {
                float Eo;
                float n;
                float Me;
                float R = 8.31447;
                float T;
                float F = 96500.0;

                cout<<"#----------------------------------------#"<<endl;
                cout<<"# Dane proszę wprowadzać w formacie x.x, #"<<endl;
                cout<<"# np. 1.0 ,45.9873 ,0.450092 ,itp.       #"<<endl;
                cout<<"#----------------------------------------#"<<endl;
                cout<<" "<<endl;
                cout<<"Podaj standardowy potencjał elektrody w voltach:"<<endl;
                cin>>Eo;
                cout<<"Podaj liczbę elektronów wymienianych w reakcji połówkowej:"<<endl;
                cin>>n;
                cout<<"Podaj stężenie molowe jonów metalu w półogniwie:"<<endl;
                cin>>Me;
                cout<<"Podaj temperaturę w stopniach Kelvina:"<<endl;
                cin>>T;

                float a = R*T;
                float b = n*F;
                float x = a/b;
                float y = log(pow(Me ,n));
                float E = Eo + x*y;

                cout<<" "<<endl;
                cout<<"Potencjał elektrody wynosi: "<<E<<"V"<<endl;
                break;
            }
            case 5:
            {
                float mr;
                float mt;

                cout<<"#----------------------------------------#"<<endl;
                cout<<"# Dane proszę wprowadzać w formacie x.x, #"<<endl;
                cout<<"# np. 1.0 ,45.9873 ,0.450092 ,itp.       #"<<endl;
                cout<<"#----------------------------------------#"<<endl;
                cout<<" "<<endl;
                cout<<"Podaj ilość otrzymanego produktu w gramach:"<<endl;
                cin>>mr;
                cout<<"Podaj teorytyczną masę produktu do otrzymania w gramach:"<<endl;
                cin>>mt;

                float x = mr/mt;
                float W = x*100;

                cout<<" "<<endl;
                cout<<"Wydajność reakcji Arrheniusa wynosi: "<<W<<"%"<<endl;
                break;
            }
            case 6:
            {
                cout<<"#----------------------------------------#"<<endl;
                cout<<"# Dane proszę wprowadzać w formacie x.x, #"<<endl;
                cout<<"# np. 1.0 ,45.9873 ,0.450092 ,itp.       #"<<endl;
                cout<<"#----------------------------------------#"<<endl;
                cout<<"Obliczam"<<endl;
                cout<<"1) Bilans masy"<<endl;
                cout<<"2) Bilans mas molowych"<<endl;
                int i;
                cin>>i;
                switch(i)
                {
                    case 1:
                    {
                        float masa_substratow;
                        float masa_produktow;

                        cout<<"Podaj masę substratów w gramach:"<<endl;
                        cin>> masa_substratow;
                        cout<<"Podaj masę produktów w gramach:"<<endl;
                        cin>>masa_produktow;

                        if(masa_substratow>masa_produktow)
                        {
                            cout<<"Masa substratów jest większa od masy produktów"<<endl;
                        }
                        else if(masa_substratow<masa_produktow)
                        {
                            cout<<"Masa produktów jest większa od masy substratów"<<endl;
                        }
                        else if(masa_substratow=masa_produktow)
                        {
                            cout<<"Masa produktów jest równa masie substratów"<<endl;
                            cout<<"Reakcja została zbilansowana poprawnie"<<endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        float masa_A;
                        float masa_B;

                        cout<<"Podaj masę molową substratów w gramach na mol:"<<endl;
                        cin>> masa_A;
                        cout<<"Podaj masę molową produktów w gramach na mol:"<<endl;
                        cin>>masa_B;

                        if(masa_A>masa_B)
                        {
                            cout<<"Masa substratów jest większa od masy produktów"<<endl;
                        }
                        else if(masa_A<masa_B)
                        {
                            cout<<"Masa produktów jest większa od masy substratów"<<endl;
                        }
                        else if(masa_A=masa_B)
                        {
                            cout<<"Masa produktów jest równa masie substratów"<<endl;
                            cout<<"Reakcja została zbilansowana poprawnie"<<endl;
                        }
                        break;
                    }
                    default:
                    {
                        cout<<"Liczba poza zakresem"<<endl;
                    }
                }
                break;
            }
            case 7:
            {
                float A;
                float R = 8.31447;
                float T;
                float k;

                cout<<"#----------------------------------------#"<<endl;
                cout<<"# Dane proszę wprowadzać w formacie x.x, #"<<endl;
                cout<<"# np. 1.0 ,45.9873 ,0.450092 ,itp.       #"<<endl;
                cout<<"#----------------------------------------#"<<endl;
                cout<<" "<<endl;
                cout<<"Podaj temperaturę w stopniach Kelvina:"<<endl;
                cin>>T;
                cout<<"Podaj czynnik przedwykładniczy:"<<endl;
                cin>>A;
                cout<<"Podaj stałą szybkość reakcji:"<<endl;
                cin>>k;

                float x = k/A;
                float Ea = R*T*log(x);

                cout<<" "<<endl;
                cout<<"Energia aktywacji wynosi: "<<Ea<<endl;
                break;
            }
            case 8:
            {
                float A;
                float Ea = -1;
                float R = 8.31447;
                float T = -1;

                cout<<"#----------------------------------------#"<<endl;
                cout<<"# Dane proszę wprowadzać w formacie x.x, #"<<endl;
                cout<<"# np. 1.0 ,45.9873 ,0.450092 ,itp.       #"<<endl;
                cout<<"# Wartość temperatury proszę podać jako  #"<<endl;
                cout<<"# ujemną.                                #"<<endl;
                cout<<"#----------------------------------------#"<<endl;
                cout<<" "<<endl;
                cout<<"Podaj czynnik przedwykładniczy Arrheniusa:"<<endl;
                cin>>A;
                cout<<"Podaj energię aktywacji Arrheniusa:"<<endl;
                cin>>Ea;
                cout<<"Podaj temperaturę w stopniach Kelvina:"<<endl;
                cin>>T;

                float x = R*T;
                float y = Ea/x;
                float k = A*exp(-y);

                cout<<" "<<endl;
                cout<<"Stała szybkości reakcji wynosi: "<<k<<endl;
                break;
            }
            case 9:
            {
                cout<<"#----------------------------------------#"<<endl;
                cout<<"# Dane proszę wprowadzać w formacie x.x, #"<<endl;
                cout<<"# np. 1.0 ,45.9873 ,0.450092 ,itp.       #"<<endl;
                cout<<"#----------------------------------------#"<<endl;
                cout<<" "<<endl;
                cout<<" Wybierz wersję:"<<endl;
                cout<<" 1) Z uwzględnieniem objętości przestrzeni reakcyjnej"<<endl;
                cout<<" 2) Z uwzględnieniem masy katalizatora"<<endl;
                cout<<" 3) Z uwzględnieniem powierzchni kontaktu międzyfazowego"<<endl;
                cout<<" "<<endl;  
                int i;
                cin>>i;
                switch(i)
                {
                    case 1:
                    {
                        cout<<"Obliczam"<<endl;
                        cout<<"1) Produkt"<<endl;
                        cout<<"2) Substrat"<<endl;
                        int i;
                        cin>>i;
                        switch(i)
                        {
                            case 1:
                            {
                                float V;
                                float dnA;
                                float dt;
                                
                                cout<<" "<<endl;
                                cout<<"Podaj objętość przestrzeni reakcyjnej w dm3:"<<endl;
                                cin>>V;
                                cout<<"Podaj liczbę moli składnika odniesienia:"<<endl;
                                cin>>dnA;
                                cout<<"Podaj czas w sekundach:"<<endl;
                                cin>>dt;
                                cout<<" "<<endl;

                                float x = 1/V;
                                float y = dnA/dt;
                                float rA = x*y;

                                cout<<"Szybkość reakcji wynosi: "<<rA<<" mol/dm3 na sekundę"<<endl;
                                break;
                            }
                            case 2:
                            {
                                float V;
                                float dnA;
                                float dt;
                                
                                cout<<" "<<endl;
                                cout<<"Podaj objętość przestrzeni reakcyjnej w dm3:"<<endl;
                                cin>>V;
                                if(V>=0)
                                {
                                    cout<<"Wartość musi być ujemna"<<endl;
                                }
                                cout<<"Podaj liczbę moli składnika odniesienia:"<<endl;
                                cin>>dnA;
                                if(dnA>=0)
                                {
                                    cout<<"Wartość musi być ujemna"<<endl;
                                }
                                cout<<"Podaj czas w sekundach:"<<endl;
                                cin>>dt;
                                if(dt>=0)
                                {
                                    cout<<"Wartość musi być ujemna"<<endl;
                                }

                                float x = 1/V;
                                float y = dnA/dt;
                                float rA = x*y;

                                cout<<" "<<endl;
                                cout<<"Szybkość reakcji wynosi: "<<rA<<" mol/dm3 na sekundę"<<endl;
                                break;
                            }
                            default:
                            {
                                cout<<"Liczba poza zakresem"<<endl;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        cout<<"Obliczam"<<endl;
                        cout<<"1) Produkt"<<endl;
                        cout<<"2) Substrat"<<endl;
                        int i;
                        cin>>i;
                        switch(i)
                        {
                            case 1:
                            {
                                float m;
                                float dnA;
                                float dt;
                                
                                cout<<" "<<endl;
                                cout<<"Podaj masę katalizatora:"<<endl;
                                cin>>m;
                                cout<<"Podaj liczbę moli składnika odniesienia:"<<endl;
                                cin>>dnA;
                                cout<<"Podaj czas w sekundach:"<<endl;
                                cin>>dt;

                                float x = 1/m;
                                float y = dnA/dt;
                                float rA = x*y;

                                cout<<" "<<endl;
                                cout<<"Szybkość reakcji wynosi: "<<rA<<" mol/dm3 na sekundę"<<endl;
                                break;
                            }
                            case 2:
                            {
                                float m;
                                float dnA;
                                float dt;
                                
                                cout<<" "<<endl;
                                cout<<"Podaj masę katalizatora:"<<endl;
                                cin>>m;
                                if(m>=0)
                                {
                                    cout<<"Wartość musi być ujemna"<<endl;
                                }
                                cout<<"Podaj liczbę moli składnika odniesienia:"<<endl;
                                cin>>dnA;
                                if(dnA>=0)
                                {
                                    cout<<"Wartość musi być ujemna"<<endl;
                                }
                                cout<<"Podaj czas w sekundach:"<<endl;
                                cin>>dt;
                                if(dt>=0)
                                {
                                    cout<<"Wartość musi być ujemna"<<endl;
                                }

                                float x = 1/m;
                                float y = dnA/dt;
                                float rA = x*y;

                                cout<<" "<<endl;
                                cout<<"Szybkość reakcji wynosi: "<<rA<<" mol/dm3 na sekundę"<<endl;
                                break;
                            }
                            default:
                            {
                                cout<<"Liczba poza zakresem"<<endl;
                            }
                            break;
                        }
                    }
                    case 3:
                    {
                        cout<<"Obliczam"<<endl;
                        cout<<"1) Produkt"<<endl;
                        cout<<"2) Substrat"<<endl;
                        int i;
                        cin>>i;
                        switch(i)
                        {
                            case 1:
                            {
                                float S;
                                float dnA;
                                float dt;
                                
                                cout<<" "<<endl;
                                cout<<"Podaj powierzchnię kontaktu międzyfazowego:"<<endl;
                                cin>>S;
                                cout<<"Podaj liczbę moli składnika odniesienia:"<<endl;
                                cin>>dnA;
                                cout<<"Podaj czas w sekundach:"<<endl;
                                cin>>dt;

                                float x = 1/S;
                                float y = dnA/dt;
                                float rA = x*y;

                                cout<<" "<<endl;
                                cout<<"Szybkość reakcji wynosi: "<<rA<<" mol/dm3 na sekundę"<<endl;
                                break;
                            }
                            case 2:
                            {
                                float S;
                                float dnA;
                                float dt;
                                
                                cout<<" "<<endl;
                                cout<<"Podaj powierzchnię kontaktu międzyfazowego:"<<endl;
                                cin>>S;
                                if(S>=0)
                                {
                                    cout<<"Wartość musi być ujemna"<<endl;
                                }
                                cout<<"Podaj liczbę moli składnika odniesienia:"<<endl;
                                cin>>dnA;
                                if(dnA>=0)
                                {
                                    cout<<"Wartość musi być ujemna"<<endl;
                                }
                                cout<<"Podaj czas w sekundach:"<<endl;
                                cin>>dt;
                                if(dt>=0)
                                {
                                    cout<<"Wartość musi być ujemna"<<endl;
                                }

                                float x = 1/S;
                                float y = dnA/dt;
                                float rA = x*y;

                                cout<<" "<<endl;
                                cout<<"Szybkość reakcji wynosi: "<<rA<<" mol/dm3 na sekundę"<<endl;
                                break;
                            }
                            default:
                            {
                                cout<<"Liczba poza zakresem"<<endl;
                            }
                        }
                    }
                }
                break;
            }
            case 10:
            {
                double stezenie;

                cout<<"Podaj stężenie jonów [H+] w molach na litr: "<<endl;
                cin>>stezenie;
                double pH = -log10(stezenie);
                cout<<"pH = "<<pH<<endl;
                break;
            }
            case 11:
            {
                return 0;
            }
            default:
            {
                cout<<"Wartość poza zakresem"<<endl;
            }
        }
    return 0;
}
