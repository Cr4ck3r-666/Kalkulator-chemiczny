#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

// ######### Dane dla parsera ###################
int numbers[100];   // każda liczba w osobnym int
int numIndex = 0;   // licznik zapisanych liczb
int ilosc_A[118];   // 
int ilosc_B[118];   //
const string pierwiastek_A[118];
const string pierwiastek_B[118];
// ##############################################
int substraty = 0;
int produkty = 0;

string substancja_A = "";
string substancja_B = "";
string substancja_C = "";
string substancja_D = "";
string substancja_E = "";
string substancja_F = "";

float masa_molowa_substancji_A = 0;
float masa_molowa_substancji_B = 0;
float masa_molowa_substancji_C = 0;
float masa_molowa_substancji_D = 0;
float masa_molowa_substancji_E = 0;
float masa_molowa_substancji_F = 0;


map<string, int> parseFormula(const string& s, size_t& i);

int parseNumber(const string& s, size_t& i) {
    int num = 0;
    while (i < s.size() && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        i++;
    }

    if (num == 0) num = 1;

    numbers[numIndex++] = num;   // ZAPISUJEMY LICZBĘ DO OSOBNEGO INTA

    return num;
}

map<string, int> parseGroup(const string& s, size_t& i) {
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

map<string, int> parseFormula(const string& s, size_t& i) {
    return parseGroup(s, i);
}

map<string, int> parseFormula(const string& s) {
    size_t i = 0;
    return parseFormula(s, i);
}

void identyfikacja_zwiazku(string zwiazek_A ,string zwiazek_B)
{
    // Obliczanie masy molowej substancji A:
    string formula_A = substancja_A;

    auto result_A = parseFormula(formula_A);
    cout<<" "<<endl;
    cout<<"Substancja A: "<<endl;
    for (auto& p : result_A) 
    {
        cout << "pierwiastek : " << p.first << endl;
        cout << "ilość : " << p.second << endl;
        ilosc_A[numIndex]== p.second;
        pierwiastek_A[numIndex] == p.first;
    }

    // Obliczanie masy molowej substancji B:
    string formula_B = substancja_B;

    auto result_B = parseFormula(formula_B);
    cout<<" "<<endl;
    cout<<"Substancja B: "<<endl;
    for (auto& p : result_B) 
    {
        cout << "pierwiastek : " << p.first << endl;
        cout << "ilość : " << p.second << endl;
        ilosc_B[numIndex] = p.second;
        pierwiastek_B[numIndex] == p.first;
    }        
    
    cout<<"Masa molowa substancji A: "<<masa_molowa_substancji_A<<"g/mol"<<endl;
    cout<<"Masa molowa substancji B: "<<masa_molowa_substancji_B<<"g/mol"<<endl;
    cout<<" "<<endl;
}

int main()
{
    struct
    {
        string symbol;
        string nazwa;
        float masa_atomowa;
        //string wartosciowosc;
        //float elektroujemnosc;
    } Wodor,Lit,Sod,Potas,Rubid,Cez,Frans,Beryl,Magnez,Wapn,Stront,Bar,
    Rad,Scand,Itr,Lantan,Aktyn,Cyrkon,Hafn,Ruteford,Wanad,Niob,Tantal,
    Dubn,Chrom,Molibden,Wolfram,Seaborg,Mangan,Technet,Ren,Bohr,Zelazo,Ruten,Osm,Has,
    Kobalt,Rod,Iryd,Meitner,Nikiel,Pallad,Platyna,Darmsztadt,Miedz,Srebro,Zloto,Rentgen,
    Cynk,Kadm,Rtec,Kopernik,Glin,Gal,Ind,Tytan,Nihon,Wegiel,Krzem,German,Cyna,Olow,Flerow,
    Azot,Fosfor,Arsen,Antymon,Bizmut,Moskow,Tlen,Siarka,Selen,Telleur,Polon,Liwemor,Fluor,Chlor,
    Bor,Jod,Astat,Tenes,Hel,Neon,Argon,Krypton,Xenon,Radon,Oganeson,Cer,Prazeodym,Neodym,
    Promet,Samar,Europ,Gadolin,Terb,Dysproz,Holm,Erb,Tull,Iterb,Lutet,Tor,Proaktyn,Uran,Neptun,Pluton,
    Ameryk,Kiur ,Berkel,Kaliforn,Einstein,Ferm,Mendelew,Brom,Nobel,Lorens,Tall;

    Wodor.symbol="H";
    Wodor.nazwa="Wodór";
    Wodor.masa_atomowa=1.008;

    Lit.symbol="Li";
    Lit.nazwa="Lit";
    Lit.masa_atomowa=6.94;

    Sod.symbol="Na";
    Sod.nazwa="Sód";
    Sod.masa_atomowa=22.99;

    Potas.symbol="K";
    Potas.nazwa="Potas";
    Potas.masa_atomowa=39.098;

    Rubid.symbol="Rb";
    Rubid.nazwa="Rubid";
    Rubid.masa_atomowa=85.468;

    Cez.symbol="Ce";
    Cez.nazwa="Cez";
    Cez.masa_atomowa=132.905;

    Frans.symbol="Fr";
    Frans.nazwa="Frans";
    Frans.masa_atomowa=223.020;

    Beryl.symbol="Be";
    Beryl.nazwa="Beryl";
    Beryl.masa_atomowa=9.012;

    Magnez.symbol="Mg";
    Magnez.nazwa="Magnez";
    Magnez.masa_atomowa=24.305;

    Wapn.symbol="Ca";
    Wapn.nazwa="Wapń";
    Wapn.masa_atomowa=40.078;

    Stront.symbol="Sr";
    Stront.nazwa="Stront";
    Stront.masa_atomowa=87.62;

    Bar.symbol="Ba";
    Bar.nazwa="Bar";
    Bar.masa_atomowa=137.327;

    Rad.symbol="Ra";
    Rad.nazwa="Rad";
    Rad.masa_atomowa=226.025;

    Scand.symbol="Sc";
    Scand.nazwa="Scand";
    Scand.masa_atomowa=44.956;

    Itr.symbol="Y";
    Itr.nazwa="Itr";
    Itr.masa_atomowa=89.906;

    Lantan.symbol="La";
    Lantan.nazwa="Lantan";
    Lantan.masa_atomowa=138.905;

    Aktyn.symbol="Ac";
    Aktyn.nazwa="Aktyn";
    Aktyn.masa_atomowa=227.028;

    Tytan.symbol="Ti";
    Tytan.nazwa="Tytan";
    Tytan.masa_atomowa=47.867;

    Cyrkon.symbol="Zr";
    Cyrkon.nazwa="Cyrkon";
    Cyrkon.masa_atomowa=91.224;

    Hafn.symbol="Hf";
    Hafn.nazwa="Hafn";
    Hafn.masa_atomowa=178.49;

    Ruteford.symbol="Rf";
    Ruteford.nazwa="Ruteford";
    Ruteford.masa_atomowa=261.11;

    Wanad.symbol="V";
    Wanad.nazwa="Wanad";
    Wanad.masa_atomowa=50.942;

    Niob.symbol="Nb";
    Niob.nazwa="Niob";
    Niob.masa_atomowa=92.206;

    Tantal.symbol="Ta";
    Tantal.nazwa="Tantal";
    Tantal.masa_atomowa=180.948;

    Dubn.symbol="Db";
    Dubn.nazwa="Dubn";
    Dubn.masa_atomowa=261.11;

    Chrom.symbol="Cr";
    Chrom.nazwa="Chrom";
    Chrom.masa_atomowa=51.996;

    Molibden.symbol="Mo";
    Molibden.nazwa="Molibden";
    Molibden.masa_atomowa=95.94;

    Wolfram.symbol="W";
    Wolfram.nazwa="Wolfram";
    Wolfram.masa_atomowa=183.84;

    Seaborg.symbol="Sg";
    Seaborg.nazwa="Seaborg";
    Seaborg.masa_atomowa=265.12;

    Mangan.symbol="Mn";
    Mangan.nazwa="Rutheford";
    Mangan.masa_atomowa=54.938;

    Technet.symbol="Tc";
    Technet.nazwa="Technet";
    Technet.masa_atomowa=97.905;

    Ren.symbol="Re";
    Ren.nazwa="Rhen";
    Ren.masa_atomowa=186.207;

    Bohr.symbol="Bh";
    Bohr.nazwa="Bohr";
    Bohr.masa_atomowa=264.10;

    Zelazo.symbol="Fe";
    Zelazo.nazwa="Żelazo";
    Zelazo.masa_atomowa=55.845;

    Ruten.symbol="Ru";
    Ruten.nazwa="Ruten";
    Ruten.masa_atomowa=101.07;

    Osm.symbol="Os";
    Osm.nazwa="Osm";
    Osm.masa_atomowa=190.23;

    Has.symbol="Hs";
    Has.nazwa="Has";
    Has.masa_atomowa=269.10;

    Kobalt.symbol="Co";
    Kobalt.nazwa="Kobalt";
    Kobalt.masa_atomowa=58.933;

    Rod.symbol="Rh";
    Rod.nazwa="Rod";
    Rod.masa_atomowa=102.906;

    Iryd.symbol="Ir";
    Iryd.nazwa="Iryd";
    Iryd.masa_atomowa=192.117;

    Meitner.symbol="Mt";
    Meitner.nazwa="Meitner";
    Meitner.masa_atomowa=268.10;

    Nikiel.symbol="Ni";
    Nikiel.nazwa="Nikiel";
    Nikiel.masa_atomowa=58.693;

    Pallad.symbol="Pa";
    Pallad.nazwa="Pallad";
    Pallad.masa_atomowa=106.42;

    Platyna.symbol="Pt";
    Platyna.nazwa="Platyna";
    Platyna.masa_atomowa=195.084;

    Darmsztadt.symbol="Ds";
    Darmsztadt.nazwa="Darmsztadt";
    Darmsztadt.masa_atomowa=281.10;

    Miedz.symbol="Cu";
    Miedz.nazwa="Miedź";
    Miedz.masa_atomowa=63.546;

    Srebro.symbol="Ag";
    Srebro.nazwa="Srebro";
    Srebro.masa_atomowa=107.868;

    Zloto.symbol="Au";
    Zloto.nazwa="Złoto";
    Zloto.masa_atomowa=196.967;

    Rentgen.symbol="Rg";
    Rentgen.nazwa="Rentgen";
    Rentgen.masa_atomowa=280;

    Cynk.symbol="Zn";
    Cynk.nazwa="Cynk";
    Cynk.masa_atomowa=65.39;

    Kadm.symbol="Cd";
    Kadm.nazwa="Kadm";
    Kadm.masa_atomowa=112.411;

    Rtec.symbol="Hg";
    Rtec.nazwa="Rtęć";
    Rtec.masa_atomowa=200.59;

    Kopernik.symbol="Cn";
    Kopernik.nazwa="Kopernik";
    Kopernik.masa_atomowa=285;

    Bor.symbol="B";
    Bor.nazwa="Bor";
    Bor.masa_atomowa=10.811;

    Glin.symbol="Al";
    Glin.nazwa="Glin";
    Glin.masa_atomowa=26.982;

    Gal.symbol="Ga";
    Gal.nazwa="Gal";
    Gal.masa_atomowa=69.723;

    Ind.symbol="In";
    Ind.nazwa="Ind";
    Ind.masa_atomowa=114.818;

    Tall.symbol="Tl";
    Tall.nazwa="Tal";
    Tall.masa_atomowa=204.38;

    Nihon.symbol="Nh";
    Nihon.nazwa="Nihon";
    Nihon.masa_atomowa=284;

    Wegiel.symbol="C";
    Wegiel.nazwa="Węgiel";
    Wegiel.masa_atomowa=12.011;

    Krzem.symbol="Si";
    Krzem.nazwa="Krzem";
    Krzem.masa_atomowa=28.085;

    German.symbol="Ge";
    German.nazwa="German";
    German.masa_atomowa=72.61;

    Cyna.symbol="Sn";
    Cyna.nazwa="Cyna";
    Cyna.masa_atomowa=118.610;

    Olow.symbol="Pb";
    Olow.nazwa="Ołów";
    Olow.masa_atomowa=207.2;

    Flerow.symbol="Fl";
    Flerow.nazwa="Flerow";
    Flerow.masa_atomowa=289;

    Azot.symbol="N";
    Azot.nazwa="Azot";
    Azot.masa_atomowa=14.007;

    Fosfor.symbol="P";
    Fosfor.nazwa="Fosfor";
    Fosfor.masa_atomowa=30.974;

    Arsen.symbol="As";
    Arsen.nazwa="Arsen";
    Arsen.masa_atomowa=74.922;

    Antymon.symbol="Sb";
    Antymon.nazwa="Antymon";
    Antymon.masa_atomowa=121.760;

    Bizmut.symbol="Bi";
    Bizmut.nazwa="Bizmut";
    Bizmut.masa_atomowa=208.98;

    Moskow.symbol="Mc";
    Moskow.nazwa="Moskow";
    Moskow.masa_atomowa=288;

    Tlen.symbol="O";
    Tlen.nazwa="Tlen";
    Tlen.masa_atomowa=15.999;

    Siarka.symbol="S";
    Siarka.nazwa="Siarka";
    Siarka.masa_atomowa=32.065;

    Selen.symbol="Se";
    Selen.nazwa="Selen";
    Selen.masa_atomowa=78.96;

    Telleur.symbol="Te";
    Telleur.nazwa="Telleur";
    Telleur.masa_atomowa=127.60;

    Polon.symbol="Po";
    Polon.nazwa="Polon";
    Polon.masa_atomowa=208.98;

    Liwemor.symbol="Lv";
    Liwemor.nazwa="Liwemor";
    Liwemor.masa_atomowa=292;

    Fluor.symbol="F";
    Fluor.nazwa="Fluor";
    Fluor.masa_atomowa=18.998;

    Chlor.symbol="Cl";
    Chlor.nazwa="Chlor";
    Chlor.masa_atomowa=35.453;

    Brom.symbol="Br";
    Brom.nazwa="Brom";
    Brom.masa_atomowa=79.904;

    Jod.symbol="I";
    Jod.nazwa="Jod";
    Jod.masa_atomowa=126.904;

    Astat.symbol="At";
    Astat.nazwa="Astat";
    Astat.masa_atomowa=209.99;

    Tenes.symbol="Ts";
    Tenes.nazwa="Tenes";
    Tenes.masa_atomowa=294;

    Hel.symbol="He";
    Hel.nazwa="Hel";
    Hel.masa_atomowa=4.003;

    Neon.symbol="Ne";
    Neon.nazwa="Neon";
    Neon.masa_atomowa=20.180;

    Argon.symbol="Ar";
    Argon.nazwa="Argon";
    Argon.masa_atomowa=39.948;

    Krypton.symbol="Kr";
    Krypton.nazwa="Krypton";
    Krypton.masa_atomowa=83.798;

    Xenon.symbol="Xe";
    Xenon.nazwa="Ksenon";
    Xenon.masa_atomowa=131.293;

    Radon.symbol="Rn";
    Radon.nazwa="Radon";
    Radon.masa_atomowa=222.02;

    Oganeson.symbol="Og";
    Oganeson.nazwa="Oganeson";
    Oganeson.masa_atomowa=294;

    Cer.symbol="Ce";
    Cer.nazwa="Cer";
    Cer.masa_atomowa=140.12;

    Prazeodym.symbol="Pr";
    Prazeodym.nazwa="Prazeodym";
    Prazeodym.masa_atomowa=140.09;

    Neodym.symbol="Nd";
    Neodym.nazwa="Neodym";
    Neodym.masa_atomowa=144.24;

    Promet.symbol="Pm";
    Promet.nazwa="Promet";
    Promet.masa_atomowa=144.91;

    Samar.symbol="Sm";
    Samar.nazwa="Samar";
    Samar.masa_atomowa=150.36;

    Europ.symbol="Eu";
    Europ.nazwa="Europ";
    Europ.masa_atomowa=151.96;

    Gadolin.symbol="Gd";
    Gadolin.nazwa="Gadolin";
    Gadolin.masa_atomowa=157.25;

    Terb.symbol="Tb";
    Terb.nazwa="Terb";
    Terb.masa_atomowa=158.93;

    Dysproz.symbol="Dy";
    Dysproz.nazwa="Dysproz";
    Dysproz.masa_atomowa=165.5;

    Holm.symbol="Ho";
    Holm.nazwa="Holm";
    Holm.masa_atomowa=164.93;

    Erb.symbol="Er";
    Erb.nazwa="Erb";
    Erb.masa_atomowa=167.26;

    Tull.symbol="Tm";
    Tull.nazwa="Tul";
    Tull.masa_atomowa=168.93;

    Iterb.symbol="Yb";
    Iterb.nazwa="Iterb";
    Iterb.masa_atomowa=173.04;

    Lutet.symbol="Lu";
    Lutet.nazwa="Lutet";
    Lutet.masa_atomowa=174.97;

    Tor.symbol="Th";
    Tor.nazwa="Tor";
    Tor.masa_atomowa=232.0337;

    Proaktyn.symbol="Pa";
    Proaktyn.nazwa="Proaktyn";
    Proaktyn.masa_atomowa=231.03;

    Uran.symbol="U";
    Uran.nazwa="Uran";
    Uran.masa_atomowa=238.02;

    Neptun.symbol="Np";
    Neptun.nazwa="Neptun";
    Neptun.masa_atomowa=237;

    Pluton.symbol="Pu";
    Pluton.nazwa="Pluton";
    Pluton.masa_atomowa=244;

    Ameryk.symbol="Am";
    Ameryk.nazwa="Ameryk";
    Ameryk.masa_atomowa=243;

    Kiur.symbol="Cm";
    Kiur.nazwa="Kiur";
    Kiur.masa_atomowa=247;

    Berkel.symbol="Bk";
    Berkel.nazwa="Berkel";
    Berkel.masa_atomowa=247;

    Kaliforn.symbol="Cf";
    Kaliforn.nazwa="Kaliforn";
    Kaliforn.masa_atomowa=251;

    Einstein.symbol="Es";
    Einstein.nazwa="Einstein";
    Einstein.masa_atomowa=252;

    Ferm.symbol="Fm";
    Ferm.nazwa="Ferm";
    Ferm.masa_atomowa=257;

    Mendelew.symbol="Md";
    Mendelew.nazwa="Mendelew";
    Mendelew.masa_atomowa=258;

    Nobel.symbol="No";
    Nobel.nazwa="Nobel";
    Nobel.masa_atomowa=259;

    Lorens.symbol="Lr";
    Lorens.nazwa="Lorens";
    Lorens.masa_atomowa=266;


    string symbol[119] = {"H" ,"Li" ,"Na" ,"K" ,"Rb" ,"Cs" ,"Fr" ,
                        "Be" ,"Mg" ,"Ca" ,"Sr" ,"Ba" ,"Ra" ,
                        "Sc" ,"Y" ,"La" ,"Ac",
                        "Ti" ,"Zr" ,"Hf" ,"Rf",
                        "V" ,"Nb" ,"Ta" ,"Db" ,
                        "Cr" ,"Mo" ,"W" ,"Sg" ,
                        "Mn" ,"Tc" ,"Re" ,"Bh",
                        "Fe" ,"Ru" ,"Os" ,"Hs",
                        "Co" ,"Rh" ,"Ir" ,"Mt",
                        "Ni" ,"Pd" ,"Pt" ,"Ds",
                        "Cu" ,"Ag" ,"Au" ,"Rg",
                        "Zn" ,"Cd" ,"Hg" ,"Cn",
                        "B" ,"Al" ,"Ga" ,"In" ,"Ti" ,"Nh" ,
                        "C" ,"Si" ,"Ge" ,"Sn" ,"Pb" ,"Fl" ,
                        "N" ,"P" ,"As" ,"Sb" ,"Bi" ,"Mc" ,
                        "O" ,"S" ,"Se" ,"Te" ,"Po" ,"Lv" ,
                        "F" ,"Cl" ,"Br" ,"I" ,"At" ,"Ts" ,
                        "He" ,"Ne" ,"Ar" ,"Kr" ,"Xe" ,"Rn" ,"Og",
                        "Ce" ,"Pr" ,"Nd" ,"Pm" ,"Sm" ,"Eu" ,"Gd" ,"Tb" ,"Dy" ,"Ho" ,"Er" ,"Tm" ,"Yb" ,"Lu" ,
                        "Th" ,"Ph" ,"U" ,"Np" ,"Pu" ,"Am" ,"Cm" ,"Bk" ,"Cf" ,"Es" ,"Fm" ,"Md" ,"No" ,"Lr"};

    string pierwiastek[119] = {Wodor.nazwa ,Lit.nazwa ,Sod.nazwa,Potas.nazwa ,Rubid.nazwa ,Cez.nazwa ,Frans.nazwa ,
                            Beryl.nazwa ,Magnez.nazwa ,Wapn.nazwa ,Stront.nazwa ,Bar.nazwa ,Rad.nazwa ,
                            Scand.nazwa ,Itr.nazwa ,Lantan.nazwa ,Aktyn.nazwa ,
                            Tytan.nazwa ,Cyrkon.nazwa ,Hafn.nazwa ,Ruteford.nazwa ,
                            Wanad.nazwa ,Niob.nazwa ,Tantal.nazwa ,Dubn.nazwa ,
                            Chrom.nazwa ,Molibden.nazwa ,Wolfram.nazwa ,Seaborg.nazwa ,
                            Mangan.nazwa ,Technet.nazwa ,Ren.nazwa ,Bohr.nazwa ,
                            Zelazo.nazwa ,Ruten.nazwa ,Osm.nazwa ,Has.nazwa ,
                            Kobalt.nazwa ,Rod.nazwa ,Iryd.nazwa ,Meitner.nazwa ,
                            Nikiel.nazwa ,Pallad.nazwa ,Platyna.nazwa ,Darmsztadt.nazwa ,
                            Miedz.nazwa ,Srebro.nazwa ,Zloto.nazwa ,Rentgen.nazwa ,
                            Cynk.nazwa ,Kadm.nazwa ,Rtec.nazwa ,Kopernik.nazwa,
                            Bor.nazwa ,Glin.nazwa ,Gal.nazwa ,Ind.nazwa ,Tytan.nazwa ,Nihon.nazwa ,
                            Wegiel.nazwa ,Krzem.nazwa ,German.nazwa ,Cyna.nazwa ,Olow.nazwa ,Flerow.nazwa ,
                            Azot.nazwa ,Fosfor.nazwa ,Arsen.nazwa ,Antymon.nazwa ,Bizmut.nazwa ,Moskow.nazwa ,
                            Tlen.nazwa ,Siarka.nazwa ,Selen.nazwa ,Telleur.nazwa ,Polon.nazwa ,Liwemor.nazwa ,
                            Fluor.nazwa ,Chlor.nazwa ,Bor.nazwa ,Jod.nazwa ,Astat.nazwa ,Tenes.nazwa ,
                            Hel.nazwa ,Neon.nazwa ,Argon.nazwa ,Krypton.nazwa ,Xenon.nazwa ,Radon.nazwa ,Oganeson.nazwa ,
                            Cer.nazwa ,Prazeodym.nazwa ,Neodym.nazwa ,Promet.nazwa ,Samar.nazwa ,Europ.nazwa ,Gadolin.nazwa ,Terb.nazwa ,Dysproz.nazwa ,Holm.nazwa ,Erb.nazwa ,Tull.nazwa ,Iterb.nazwa ,Lutet.nazwa ,
                            Tor.nazwa ,Proaktyn.nazwa ,Uran.nazwa ,Neptun.nazwa ,Pluton.nazwa ,Ameryk.nazwa ,Kiur.nazwa ,Berkel.nazwa ,Kaliforn.nazwa ,Einstein.nazwa ,Ferm.nazwa ,Mendelew.nazwa ,Nobel.nazwa ,Lorens.nazwa};

    float masa_atomowa[119] = {Wodor.masa_atomowa,Lit.masa_atomowa,Sod.masa_atomowa,Potas.masa_atomowa,Rubid.masa_atomowa,Cez.masa_atomowa,Frans.masa_atomowa,
                            Beryl.masa_atomowa,Magnez.masa_atomowa,Wapn.masa_atomowa,Stront.masa_atomowa,Bar.masa_atomowa,Rad.masa_atomowa,
                            Scand.masa_atomowa,Itr.masa_atomowa,Lantan.masa_atomowa,Aktyn.masa_atomowa,
                            Tytan.masa_atomowa,Cyrkon.masa_atomowa,Hafn.masa_atomowa,Ruteford.masa_atomowa,
                            Wanad.masa_atomowa,Niob.masa_atomowa,Tantal.masa_atomowa,Dubn.masa_atomowa,
                            Chrom.masa_atomowa,Molibden.masa_atomowa,Wolfram.masa_atomowa,Seaborg.masa_atomowa,
                            Mangan.masa_atomowa,Technet.masa_atomowa,Ren.masa_atomowa,Bohr.masa_atomowa,
                            Zelazo.masa_atomowa,Ruten.masa_atomowa,Osm.masa_atomowa,Has.masa_atomowa,
                            Kobalt.masa_atomowa,Rod.masa_atomowa,Iryd.masa_atomowa,Meitner.masa_atomowa,
                            Nikiel.masa_atomowa,Pallad.masa_atomowa,Platyna.masa_atomowa,Darmsztadt.masa_atomowa,
                            Miedz.masa_atomowa,Srebro.masa_atomowa,Zloto.masa_atomowa,Rentgen.masa_atomowa,
                            Cynk.masa_atomowa,Kadm.masa_atomowa,Rtec.masa_atomowa,Kopernik.masa_atomowa,
                            Bor.masa_atomowa,Glin.masa_atomowa,Ind.masa_atomowa,Tytan.masa_atomowa,Nihon.masa_atomowa,
                            Wegiel.masa_atomowa,Krzem.masa_atomowa,German.masa_atomowa,Cyna.masa_atomowa,Olow.masa_atomowa,Flerow.masa_atomowa,
                            Azot.masa_atomowa,Fosfor.masa_atomowa,Arsen.masa_atomowa,Antymon.masa_atomowa,Bizmut.masa_atomowa,Moskow.masa_atomowa,
                            Tlen.masa_atomowa,Siarka.masa_atomowa,Selen.masa_atomowa,Telleur.masa_atomowa,Polon.masa_atomowa,Liwemor.masa_atomowa,
                            Fluor.masa_atomowa,Chlor.masa_atomowa,Bor.masa_atomowa,Jod.masa_atomowa,Astat.masa_atomowa,Tenes.masa_atomowa,
                            Hel.masa_atomowa,Neon.masa_atomowa,Argon.masa_atomowa,Krypton.masa_atomowa,Xenon.masa_atomowa,Radon.masa_atomowa,Oganeson.masa_atomowa,
                            Lantan.masa_atomowa,Cer.masa_atomowa,Prazeodym.masa_atomowa,Neodym.masa_atomowa,Promet.masa_atomowa,Samar.masa_atomowa,Europ.masa_atomowa,Gadolin.masa_atomowa,Terb.masa_atomowa,Dysproz.masa_atomowa,Holm.masa_atomowa,Erb.masa_atomowa,Tull.masa_atomowa,Iterb.masa_atomowa,Lutet.masa_atomowa,
                            Aktyn.masa_atomowa,Tor.masa_atomowa,Proaktyn.masa_atomowa,Uran.masa_atomowa,Neptun.masa_atomowa,Pluton.masa_atomowa,Ameryk.masa_atomowa,Kiur.masa_atomowa,Berkel.masa_atomowa,Kaliforn.masa_atomowa,Einstein.masa_atomowa,Ferm.masa_atomowa,Mendelew.masa_atomowa,Nobel.masa_atomowa,Lorens.masa_atomowa};

    cout<<" "<<endl;
    cout<<"                     LOGO   "<<endl;
    cout<<" "<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<" Witaj W kalkulatorze chemicznym ,wybierz jedną z opcji."<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<" 1) Układ okresowy"<<endl;
    cout<<" 2) Kalkulator masy molowej"<<endl;
    cout<<" 3) Opcja pusta"<<endl;
    cout<<" 4) Opcja pusta"<<endl;
    cout<<" 5) Wyjście"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    int i;
    cin>>i;
    switch(i)
    {
        case 1:
        {
            cout<<"-----------------------------------------------"<<endl;
            cout<<"| index | Pierwiastek | Symbol | Masa atomowa |"<<endl;
            cout<<"|-------|-------------|--------|--------------|"<<endl;
            cout<<"| 1     | "<<pierwiastek[0]<<"       | "<<symbol[0]<<"      | "<<masa_atomowa[0]<<"        |"<<endl;
            cout<<"| 2     | "<<pierwiastek[1]<<"         | "<<symbol[1]<<"     | "<<masa_atomowa[1]<<"         |"<<endl;
            cout<<"| 3     | "<<pierwiastek[2]<<"         | "<<symbol[2]<<"     | "<<masa_atomowa[2]<<"        |"<<endl;
            cout<<"| 4     | "<<pierwiastek[3]<<"       | "<<symbol[3]<<"      | "<<masa_atomowa[3]<<"       |"<<endl;
            cout<<"| 5     | "<<pierwiastek[4]<<"       | "<<symbol[4]<<"     | "<<masa_atomowa[4]<<"       |"<<endl;
            cout<<"| 6     | "<<pierwiastek[5]<<"         | "<<symbol[5]<<"     | "<<masa_atomowa[5]<<"      |"<<endl;
            cout<<"| 7     | "<<pierwiastek[6]<<"       | "<<symbol[6]<<"     | "<<masa_atomowa[6]<<"       |"<<endl;
            cout<<"| 8     | "<<pierwiastek[7]<<"       | "<<symbol[7]<<"     | "<<masa_atomowa[7]<<"        |"<<endl;
            cout<<"| 9     | "<<pierwiastek[8]<<"      | "<<symbol[8]<<"     | "<<masa_atomowa[8]<<"       |"<<endl;
            cout<<"| 10    | "<<pierwiastek[9]<<"        | "<<symbol[9]<<"     | "<<masa_atomowa[9]<<"       |"<<endl;
            cout<<"| 11    | "<<pierwiastek[10]<<"      | "<<symbol[10]<<"     | "<<masa_atomowa[10]<<"        |"<<endl;
            cout<<"| 12    | "<<pierwiastek[11]<<"         | "<<symbol[11]<<"     | "<<masa_atomowa[11]<<"      |"<<endl;
            cout<<"| 13    | "<<pierwiastek[12]<<"         | "<<symbol[12]<<"     | "<<masa_atomowa[12]<<"      |"<<endl;
            cout<<"| 14    | "<<pierwiastek[13]<<"       | "<<symbol[13]<<"     | "<<masa_atomowa[13]<<"       |"<<endl;
            cout<<"| 15    | "<<pierwiastek[14]<<"         | "<<symbol[14]<<"      | "<<masa_atomowa[14]<<"       |"<<endl;
            cout<<"| 16    | "<<pierwiastek[15]<<"      | "<<symbol[15]<<"     | "<<masa_atomowa[15]<<"      |"<<endl;
            cout<<"| 17    | "<<pierwiastek[16]<<"       | "<<symbol[16]<<"     | "<<masa_atomowa[16]<<"      |"<<endl;
            cout<<"| 18    | "<<pierwiastek[17]<<"       | "<<symbol[17]<<"     | "<<masa_atomowa[17]<<"       |"<<endl;
            cout<<"| 19    | "<<pierwiastek[18]<<"      | "<<symbol[18]<<"     | "<<masa_atomowa[18]<<"       |"<<endl;
            cout<<"| 20    | "<<pierwiastek[19]<<"        | "<<symbol[19]<<"     | "<<masa_atomowa[19]<<"       |"<<endl;
            cout<<"| 21    | "<<pierwiastek[20]<<"    | "<<symbol[20]<<"     | "<<masa_atomowa[20]<<"       |"<<endl;
            cout<<"| 22    | "<<pierwiastek[21]<<"       | "<<symbol[21]<<"      | "<<masa_atomowa[21]<<"       |"<<endl;
            cout<<"| 23    | "<<pierwiastek[22]<<"        | "<<symbol[22]<<"     | "<<masa_atomowa[22]<<"       |"<<endl;
            cout<<"| 24    | "<<pierwiastek[23]<<"      | "<<symbol[23]<<"     | "<<masa_atomowa[23]<<"      |"<<endl;
            cout<<"| 25    | "<<pierwiastek[24]<<"        | "<<symbol[24]<<"     | "<<masa_atomowa[24]<<"       |"<<endl;
            cout<<"| 26    | "<<pierwiastek[25]<<"       | "<<symbol[25]<<"     | "<<masa_atomowa[25]<<"       |"<<endl;
            cout<<"| 27    | "<<pierwiastek[26]<<"    | "<<symbol[26]<<"     | "<<masa_atomowa[26]<<"        |"<<endl;
            cout<<"| 28    | "<<pierwiastek[27]<<"     | "<<symbol[27]<<"      | "<<masa_atomowa[27]<<"       |"<<endl;
            cout<<"| 29    | "<<pierwiastek[28]<<"     | "<<symbol[28]<<"     | "<<masa_atomowa[28]<<"       |"<<endl;
            cout<<"| 30    | "<<pierwiastek[29]<<"   | "<<symbol[29]<<"     | "<<masa_atomowa[29]<<"       |"<<endl;
            cout<<"| 31    | "<<pierwiastek[30]<<"     | "<<symbol[30]<<"     | "<<masa_atomowa[30]<<"       |"<<endl;
            cout<<"| 32    | "<<pierwiastek[31]<<"        | "<<symbol[31]<<"     | "<<masa_atomowa[31]<<"      |"<<endl;
            cout<<"| 33    | "<<pierwiastek[32]<<"        | "<<symbol[32]<<"     | "<<masa_atomowa[32]<<"        |"<<endl;
            cout<<"| 34    | "<<pierwiastek[33]<<"      | "<<symbol[33]<<"     | "<<masa_atomowa[33]<<"       |"<<endl;
            cout<<"| 35    | "<<pierwiastek[34]<<"       | "<<symbol[34]<<"     | "<<masa_atomowa[34]<<"       |"<<endl;
            cout<<"| 36    | "<<pierwiastek[35]<<"         | "<<symbol[35]<<"     | "<<masa_atomowa[35]<<"       |"<<endl;
            cout<<"| 37    | "<<pierwiastek[36]<<"         | "<<symbol[36]<<"     | "<<masa_atomowa[36]<<"        |"<<endl;
            cout<<"| 38    | "<<pierwiastek[37]<<"      | "<<symbol[37]<<"     | "<<masa_atomowa[37]<<"       |"<<endl;
            cout<<"| 39    | "<<pierwiastek[38]<<"         | "<<symbol[38]<<"     | "<<masa_atomowa[38]<<"      |"<<endl;
            cout<<"| 40    | "<<pierwiastek[39]<<"        | "<<symbol[39]<<"     | "<<masa_atomowa[39]<<"      |"<<endl;
            cout<<"| 41    | "<<pierwiastek[40]<<"     | "<<symbol[40]<<"     | "<<masa_atomowa[40]<<"        |"<<endl;
            cout<<"| 42    | "<<pierwiastek[41]<<"      | "<<symbol[41]<<"     | "<<masa_atomowa[41]<<"       |"<<endl;
            cout<<"| 43    | "<<pierwiastek[42]<<"      | "<<symbol[42]<<"     | "<<masa_atomowa[42]<<"       |"<<endl;
            cout<<"| 44    | "<<pierwiastek[43]<<"     | "<<symbol[43]<<"     | "<<masa_atomowa[43]<<"      |"<<endl;
            cout<<"| 45    | "<<pierwiastek[44]<<"  | "<<symbol[44]<<"     | "<<masa_atomowa[44]<<"        |"<<endl;
            cout<<"| 46    | "<<pierwiastek[45]<<"       | "<<symbol[45]<<"     | "<<masa_atomowa[45]<<"       |"<<endl;
            cout<<"| 47    | "<<pierwiastek[46]<<"      | "<<symbol[46]<<"     | "<<masa_atomowa[46]<<"      |"<<endl;
            cout<<"| 48    | "<<pierwiastek[47]<<"       | "<<symbol[47]<<"     | "<<masa_atomowa[47]<<"      |"<<endl;
            cout<<"| 49    | "<<pierwiastek[48]<<"     | "<<symbol[48]<<"     | "<<masa_atomowa[48]<<"          |"<<endl;
            cout<<"| 50    | "<<pierwiastek[49]<<"        | "<<symbol[49]<<"     | "<<masa_atomowa[49]<<"        |"<<endl;
            cout<<"| 51    | "<<pierwiastek[50]<<"        | "<<symbol[50]<<"     | "<<masa_atomowa[50]<<"      |"<<endl;
            cout<<"| 52    | "<<pierwiastek[51]<<"        | "<<symbol[51]<<"     | "<<masa_atomowa[51]<<"       |"<<endl;
            cout<<"| 53    | "<<pierwiastek[52]<<"    | "<<symbol[52]<<"     | "<<masa_atomowa[52]<<"          |"<<endl;
            cout<<"| 54    | "<<pierwiastek[53]<<"         | "<<symbol[53]<<"      | "<<masa_atomowa[53]<<"       |"<<endl;
            cout<<"| 55    | "<<pierwiastek[54]<<"        | "<<symbol[54]<<"     | "<<masa_atomowa[54]<<"       |"<<endl;
            cout<<"| 56    | "<<pierwiastek[55]<<"         | "<<symbol[55]<<"     | "<<masa_atomowa[55]<<"      |"<<endl;
            cout<<"| 57    | "<<pierwiastek[56]<<"         | "<<symbol[56]<<"     | "<<masa_atomowa[56]<<"       |"<<endl;
            cout<<"| 58    | "<<pierwiastek[57]<<"       | "<<symbol[57]<<"     | "<<masa_atomowa[57]<<"          |"<<endl;
            cout<<"| 59    | "<<pierwiastek[58]<<"       | "<<symbol[58]<<"     | "<<masa_atomowa[58]<<"       |"<<endl;
            cout<<"| 60    | "<<pierwiastek[59]<<"      | "<<symbol[59]<<"      | "<<masa_atomowa[59]<<"       |"<<endl;
            cout<<"| 61    | "<<pierwiastek[60]<<"       | "<<symbol[60]<<"     | "<<masa_atomowa[60]<<"        |"<<endl;
            cout<<"| 62    | "<<pierwiastek[61]<<"      | "<<symbol[61]<<"     | "<<masa_atomowa[61]<<"       |"<<endl;
            cout<<"| 63    | "<<pierwiastek[62]<<"        | "<<symbol[62]<<"     | "<<masa_atomowa[62]<<"        |"<<endl;
            cout<<"| 64    | "<<pierwiastek[63]<<"        | "<<symbol[63]<<"     | "<<masa_atomowa[63]<<"          |"<<endl;
            cout<<"| 65    | "<<pierwiastek[64]<<"      | "<<symbol[64]<<"     | "<<masa_atomowa[64]<<"       |"<<endl;
            cout<<"| 66    | "<<pierwiastek[65]<<"        | "<<symbol[65]<<"      | "<<masa_atomowa[65]<<"       |"<<endl;
            cout<<"| 67    | "<<pierwiastek[66]<<"      | "<<symbol[66]<<"      | "<<masa_atomowa[66]<<"       |"<<endl;
            cout<<"| 68    | "<<pierwiastek[67]<<"       | "<<symbol[67]<<"     | "<<masa_atomowa[67]<<"       |"<<endl;
            cout<<"| 69    | "<<pierwiastek[68]<<"     | "<<symbol[68]<<"     | "<<masa_atomowa[68]<<"       |"<<endl;
            cout<<"| 70    | "<<pierwiastek[69]<<"      | "<<symbol[69]<<"     | "<<masa_atomowa[69]<<"          |"<<endl;
            cout<<"| 71    | "<<pierwiastek[70]<<"      | "<<symbol[70]<<"     | "<<masa_atomowa[70]<<"       |"<<endl;
            cout<<"| 72    | "<<pierwiastek[71]<<"        | "<<symbol[71]<<"      | "<<masa_atomowa[71]<<"       |"<<endl;
            cout<<"| 73    | "<<pierwiastek[72]<<"      | "<<symbol[72]<<"      | "<<masa_atomowa[72]<<"        |"<<endl;
            cout<<"| 74    | "<<pierwiastek[73]<<"       | "<<symbol[73]<<"     | "<<masa_atomowa[73]<<"        |"<<endl;
            cout<<"| 75    | "<<pierwiastek[74]<<"     | "<<symbol[74]<<"     | "<<masa_atomowa[74]<<"       |"<<endl;
            cout<<"| 76    | "<<pierwiastek[75]<<"       | "<<symbol[75]<<"     | "<<masa_atomowa[75]<<"          |"<<endl;
            cout<<"| 77    | "<<pierwiastek[76]<<"     | "<<symbol[76]<<"     | "<<masa_atomowa[76]<<"       |"<<endl;
            cout<<"| 78    | "<<pierwiastek[77]<<"       | "<<symbol[77]<<"      | "<<masa_atomowa[77]<<"       |"<<endl;
            cout<<"| 79    | "<<pierwiastek[78]<<"       | "<<symbol[78]<<"     | "<<masa_atomowa[78]<<"       |"<<endl;
            cout<<"| 80    | "<<pierwiastek[79]<<"         | "<<symbol[79]<<"     | "<<masa_atomowa[79]<<"      |"<<endl;
            cout<<"| 81    | "<<pierwiastek[80]<<"         | "<<symbol[80]<<"      | "<<masa_atomowa[80]<<"       |"<<endl;
            cout<<"| 82    | "<<pierwiastek[81]<<"       | "<<symbol[81]<<"     | "<<masa_atomowa[81]<<"          |"<<endl;
            cout<<"| 83    | "<<pierwiastek[82]<<"       | "<<symbol[82]<<"     | "<<masa_atomowa[82]<<"        |"<<endl;
            cout<<"| 84    | "<<pierwiastek[83]<<"         | "<<symbol[83]<<"     | "<<masa_atomowa[83]<<"        |"<<endl;
            cout<<"| 85    | "<<pierwiastek[84]<<"        | "<<symbol[84]<<"     | "<<masa_atomowa[84]<<"       |"<<endl;
            cout<<"| 86    | "<<pierwiastek[85]<<"       | "<<symbol[85]<<"     | "<<masa_atomowa[85]<<"       |"<<endl;
            cout<<"| 87    | "<<pierwiastek[86]<<"     | "<<symbol[86]<<"     | "<<masa_atomowa[86]<<"      |"<<endl;
            cout<<"| 88    | "<<pierwiastek[87]<<"      | "<<symbol[87]<<"     | "<<masa_atomowa[87]<<"       |"<<endl;
            cout<<"| 89    | "<<pierwiastek[88]<<"       | "<<symbol[88]<<"     | "<<masa_atomowa[88]<<"          |"<<endl;
            cout<<"| 90    | "<<pierwiastek[89]<<"    | "<<symbol[89]<<"     | "<<masa_atomowa[89]<<"      |"<<endl;
            cout<<"| 91    | "<<pierwiastek[90]<<"         | "<<symbol[90]<<"     | "<<masa_atomowa[90]<<"       |"<<endl;
            cout<<"| 92    | "<<pierwiastek[91]<<"   | "<<symbol[91]<<"     | "<<masa_atomowa[91]<<"       |"<<endl;
            cout<<"| 93    | "<<pierwiastek[92]<<"      | "<<symbol[92]<<"     | "<<masa_atomowa[92]<<"       |"<<endl;
            cout<<"| 94    | "<<pierwiastek[93]<<"      | "<<symbol[93]<<"     | "<<masa_atomowa[93]<<"       |"<<endl;
            cout<<"| 95    | "<<pierwiastek[94]<<"       | "<<symbol[94]<<"     | "<<masa_atomowa[94]<<"       |"<<endl;
            cout<<"| 96    | "<<pierwiastek[95]<<"       | "<<symbol[95]<<"     | "<<masa_atomowa[95]<<"       |"<<endl;
            cout<<"| 97    | "<<pierwiastek[96]<<"     | "<<symbol[96]<<"     | "<<masa_atomowa[96]<<"       |"<<endl;
            cout<<"| 98    | "<<pierwiastek[97]<<"        | "<<symbol[97]<<"     | "<<masa_atomowa[97]<<"       |"<<endl;
            cout<<"| 99    | "<<pierwiastek[98]<<"     | "<<symbol[98]<<"     | "<<masa_atomowa[98]<<"        |"<<endl;
            cout<<"| 100   | "<<pierwiastek[99]<<"        | "<<symbol[99]<<"     | "<<masa_atomowa[99]<<"       |"<<endl;
            cout<<"| 101   | "<<pierwiastek[100]<<"         | "<<symbol[100]<<"     | "<<masa_atomowa[100]<<"       |"<<endl;
            cout<<"| 102   | "<<pierwiastek[101]<<"         | "<<symbol[101]<<"     | "<<masa_atomowa[101]<<"       |"<<endl;
            cout<<"| 103   | "<<pierwiastek[102]<<"       | "<<symbol[102]<<"     | "<<masa_atomowa[102]<<"       |"<<endl;
            cout<<"| 104   | "<<pierwiastek[103]<<"       | "<<symbol[103]<<"     | "<<masa_atomowa[103]<<"       |"<<endl;
            cout<<"| 105   | "<<pierwiastek[104]<<"         | "<<symbol[104]<<"     | "<<masa_atomowa[104]<<"      |"<<endl;
            cout<<"| 106   | "<<pierwiastek[105]<<"    | "<<symbol[105]<<"     | "<<masa_atomowa[105]<<"      |"<<endl;
            cout<<"| 107   | "<<pierwiastek[106]<<"        | "<<symbol[106]<<"      | "<<masa_atomowa[106]<<"       |"<<endl;
            cout<<"| 108   | "<<pierwiastek[107]<<"      | "<<symbol[107]<<"     | "<<masa_atomowa[107]<<"       |"<<endl;
            cout<<"| 109   | "<<pierwiastek[108]<<"      | "<<symbol[108]<<"     | "<<masa_atomowa[108]<<"          |"<<endl;
            cout<<"| 110   | "<<pierwiastek[109]<<"      | "<<symbol[109]<<"     | "<<masa_atomowa[109]<<"          |"<<endl;
            cout<<"| 111   | "<<pierwiastek[110]<<"        | "<<symbol[110]<<"     | "<<masa_atomowa[110]<<"          |"<<endl;
            cout<<"| 112   | "<<pierwiastek[111]<<"      | "<<symbol[111]<<"     | "<<masa_atomowa[111]<<"          |"<<endl;
            cout<<"| 113   | "<<pierwiastek[112]<<"    | "<<symbol[112]<<"     | "<<masa_atomowa[112]<<"          |"<<endl;
            cout<<"| 114   | "<<pierwiastek[113]<<"    | "<<symbol[113]<<"     | "<<masa_atomowa[113]<<"          |"<<endl;
            cout<<"| 115   | "<<pierwiastek[114]<<"        | "<<symbol[114]<<"     | "<<masa_atomowa[114]<<"          |"<<endl;
            cout<<"| 116   | "<<pierwiastek[115]<<"    | "<<symbol[115]<<"     | "<<masa_atomowa[115]<<"          |"<<endl;
            cout<<"| 117   | "<<pierwiastek[116]<<"       | "<<symbol[116]<<"     | "<<masa_atomowa[116]<<"          |"<<endl;
            cout<<"| 118   | "<<pierwiastek[117]<<"      | "<<symbol[117]<<"     | "<<masa_atomowa[117]<<"          |"<<endl;
            cout<<"|---------------------------------------------|"<<endl;
            break;
        }

        case 2:
        {
            cout<<" Podaj ilość substratów ,maksymalna ilość to 5:"<<endl;
            int wybor;
            cin>>wybor;
            switch(wybor)
            {
                case 1:
                {
                    substraty = 1;
                    break;
                }
                    
                case 2:
                {
                    substraty = 2;
                    break;
                }

                case 3:
                {
                    substraty = 3;
                    break;
                }

                case 4:
                {
                    substraty = 4;
                    break;
                }

                case 5:
                {
                    substraty = 5;
                    break;
                }

                default:
                {
                    cout<<" Podana liczba znajduje się poza zakresem"<<endl;
                }
            }

            cout<<" Podaj ilość produktów ,maksymalna ilość to 5:"<<endl;
            int wybory;
            cin>>wybory;
            switch(wybory)
            {
                case 1:
                {
                    produkty = 1;
                    break;
                }
                    
                case 2:
                {
                    produkty = 2;
                    break;
                }

                case 3:
                {
                    produkty = 3;
                    break;
                }

                case 4:
                {
                    produkty = 4;
                    break;
                }

                case 5:
                {
                    produkty = 5;
                    break;
                }

                default:
                {
                    cout<<" Podana liczba znajduje się poza zakresem"<<endl;
                }
            }

            if(substraty == 1)
            {
                if(produkty == 1)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B"<<endl;
                    cout<<" "<<endl;   
                    cout<<" Podaj wzór substancji A:"<<endl; 
                    cin>> substancja_A;  
                    cout<<" Podaj wzór substancji B:"<<endl; 
                    cin>> substancja_B; 
                    cout<<" "<<endl;

                    // Obliczanie masy molowej
                    identyfikacja_zwiazku(substancja_A ,substancja_B);
                    for(int i=0;i<=118;i++)
                    {
                        if(pierwiastek_A[i] == symbol[i])
                        {
                            cout<<i<<" Pierwiastek A jest równy jego symbolowi"<<endl;
                            if(numbers[i]>0)
                            {
                                cout<<ilosc_A[i]*masa_atomowa[i]<<"\n";
                            }
                            
                        }
                        if(pierwiastek_B[i] == symbol[i])
                        {
                            cout<<i<<" Pierwiastek B jest równy jego symbolowi"<<endl;
                            if(numbers[i]>0)
                            {
                                cout<<ilosc_A[i]*masa_atomowa[i]<<"\n";
                            }
                            
                        }  
                    }  
                }

                else if(produkty == 2)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 3)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 4)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 5)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E + F"<<endl;
                    cout<<" "<<endl;
                }        
            }

            if(substraty == 2)
            {
                if(produkty == 1)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A + B ---> C"<<endl;
                    cout<<" "<<endl;   
                    cout<<" Podaj wzór substancji A:"<<endl; 
                    cin>> substancja_A;  
                    cout<<" Podaj wzór substancji B:"<<endl; 
                    cin>> substancja_B; 
                    cout<<" Podaj masę molową substancji A:"<<endl;
                    cin>> masa_molowa_substancji_A;     
                    cout<<" Podaj masę molową substancji B:"<<endl;
                    cin>> masa_molowa_substancji_B;
                    cout<<" "<<endl; 
                    cout<<substancja_A<<" ---> "<<substancja_B<<endl; 
                    cout<<" "<<endl;
                    cout<<" Masa molowa substancji A: "<< masa_molowa_substancji_A <<" g/mol"<<endl;
                    cout<<" Masa molowa substancji B: "<< masa_molowa_substancji_B <<" g/mol"<<endl;
                    cout<<" "<<endl;
                    cout<<" 0.5M substancji A to:"<< masa_molowa_substancji_A/2 <<" g"<<endl;
                    cout<<" 0.5M substancji B to:"<< masa_molowa_substancji_B/2 <<" g"<<endl;
                }

                else if(produkty == 2)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 3)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A + B ---> B + C + D"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 4)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 5)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E + F"<<endl;
                    cout<<" "<<endl;
                }        
            }

            if(substraty == 3)
            {
                if(produkty == 1)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A + B ---> C"<<endl;
                    cout<<" "<<endl;   
                    cout<<" Podaj wzór substancji A:"<<endl; 
                    cin>> substancja_A;  
                    cout<<" Podaj wzór substancji B:"<<endl; 
                    cin>> substancja_B; 
                    cout<<" Podaj masę molową substancji A:"<<endl;
                    cin>> masa_molowa_substancji_A;     
                    cout<<" Podaj masę molową substancji B:"<<endl;
                    cin>> masa_molowa_substancji_B;
                    cout<<" "<<endl; 
                    cout<<substancja_A<<" ---> "<<substancja_B<<endl; 
                    cout<<" "<<endl;
                    cout<<" Masa molowa substancji A: "<< masa_molowa_substancji_A <<" g/mol"<<endl;
                    cout<<" Masa molowa substancji B: "<< masa_molowa_substancji_B <<" g/mol"<<endl;
                    cout<<" "<<endl;
                    cout<<" 0.5M substancji A to:"<< masa_molowa_substancji_A/2 <<" g"<<endl;
                    cout<<" 0.5M substancji B to:"<< masa_molowa_substancji_B/2 <<" g"<<endl;
                }

                else if(produkty == 2)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 3)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A + B ---> B + C + D"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 4)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 5)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E + F"<<endl;
                    cout<<" "<<endl;
                }        
            }

            if(substraty == 4)
            {
                if(produkty == 1)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A + B ---> C"<<endl;
                    cout<<" "<<endl;   
                    cout<<" Podaj wzór substancji A:"<<endl; 
                    cin>> substancja_A;  
                    cout<<" Podaj wzór substancji B:"<<endl; 
                    cin>> substancja_B; 
                    cout<<" Podaj masę molową substancji A:"<<endl;
                    cin>> masa_molowa_substancji_A;     
                    cout<<" Podaj masę molową substancji B:"<<endl;
                    cin>> masa_molowa_substancji_B;
                    cout<<" "<<endl; 
                    cout<<substancja_A<<" ---> "<<substancja_B<<endl; 
                    cout<<" "<<endl;
                    cout<<" Masa molowa substancji A: "<< masa_molowa_substancji_A <<" g/mol"<<endl;
                    cout<<" Masa molowa substancji B: "<< masa_molowa_substancji_B <<" g/mol"<<endl;
                    cout<<" "<<endl;
                    cout<<" 0.5M substancji A to:"<< masa_molowa_substancji_A/2 <<" g"<<endl;
                    cout<<" 0.5M substancji B to:"<< masa_molowa_substancji_B/2 <<" g"<<endl;
                }

                else if(produkty == 2)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 3)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A + B ---> B + C + D"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 4)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 5)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E + F"<<endl;
                    cout<<" "<<endl;
                }        
            }

            if(substraty == 5)
            {
                if(produkty == 1)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A + B ---> C"<<endl;
                    cout<<" "<<endl;   
                    cout<<" Podaj wzór substancji A:"<<endl; 
                    cin>> substancja_A;  
                    cout<<" Podaj wzór substancji B:"<<endl; 
                    cin>> substancja_B; 
                    cout<<" Podaj masę molową substancji A:"<<endl;
                    cin>> masa_molowa_substancji_A;     
                    cout<<" Podaj masę molową substancji B:"<<endl;
                    cin>> masa_molowa_substancji_B;
                    cout<<" "<<endl; 
                    cout<<substancja_A<<" ---> "<<substancja_B<<endl; 
                    cout<<" "<<endl;
                    cout<<" Masa molowa substancji A: "<< masa_molowa_substancji_A <<" g/mol"<<endl;
                    cout<<" Masa molowa substancji B: "<< masa_molowa_substancji_B <<" g/mol"<<endl;
                    cout<<" "<<endl;
                    cout<<" 0.5M substancji A to:"<< masa_molowa_substancji_A/2 <<" g"<<endl;
                    cout<<" 0.5M substancji B to:"<< masa_molowa_substancji_B/2 <<" g"<<endl;
                }

                else if(produkty == 2)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 3)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A + B ---> B + C + D"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 4)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E"<<endl;
                    cout<<" "<<endl;
                }

                else if(produkty == 5)
                {
                    cout<<" Wzór ogólny reakcji:"<<endl;
                    cout<<" "<<endl;
                    cout<<" A ---> B + C + D + E + F"<<endl;
                    cout<<" "<<endl;
                }        
            }
            break;
        }

        case 3:
        {
            break;
        }

        case 4:
        {
            break;
        }

        case 5:
        {
            return 0;
            break;
        }
    }
    return 0;
}