#include <iostream>
#include <string>
//#include <fstream>

#include <Tablica_Mendelejwa.hpp>

using namespace std;

char string[10];

    table[0] = Wodor.symbol;
    tablica[1] = Lit.symbol;
    tablica[2] = Sod.symbol;
    tablica[3] = Potas.symbol;
    tablica[4] = Rubid.symbol;
    tablica[5] = Cez.symbol;
    tablica[6] = Frans.symbol;
    tablica[7] = Beryl.symbol;
    tablica[8] = Magnez.symbol;
    tablica[9] = Wapn.symbol;
    tablica[10] = Stront.symbol;
    tablica[11] = Bar.symbol;
    tablica[12] = Rad.symbol;
    tablica[13] = Scand.symbol;
    tablica[14] = Itr.symbol;
    tablica[15] = Lantan.symbol;
    tablica[16] = Aktyn.symbol;
    tablica[17] = Tytan.symbol;
    tablica[18] = Cyrkon.symbol;
    tablica[19] = Hafn.symbol;
    tablica[20] = Rutheford.symbol;
    tablica[21] = Vanad.symbol;
    tablica[22] = Niob.symbol;
    tablica[23] = Tantal.symbol;
    tablica[24] = Dubn.symbol;
    tablica[25] = Chrom.symbol;
    tablica[26] = Molibden.symbol;
    tablica[27] = Tungsten.symbol;
    tablica[28] = Seaborg.symbol;
    tablica[29] = Mangan.symbol;
    tablica[30] = Technet.symbol;
    tablica[31] = Ren.symbol;
    tablica[32] = Bohr.symbol;
    tablica[33] = Zelazo.symbol;
    tablica[34] = Ruten.symbol;
    tablica[35] = Osm.symbol;
    tablica[36] = Hasm.symbol;
    tablica[37] = Kobalt.symbol;
    tablica[38] = Rhod.symbol;
    tablica[39] = Iryd.symbol;
    tablica[40] = Meitner.symbol;
    tablica[41] = Nikiel.symbol;
    tablica[42] = Pallad.symbol;
    tablica[43] = Platyna.symbol;
    tablica[44] = Darmstad.symbol;
    tablica[45] = Miedz.symbol;
    tablica[46] = Srebro.symbol;
    tablica[47] = Zloto.symbol;
    tablica[48] = Rentgen.symbol;
    tablica[49] = Cynk.symbol;
    tablica[50] = Kadm.symbol;
    tablica[51] = Rtec.symbol;
    tablica[52] = Kopernik.symbol;
    tablica[53] = Bor.symbol;
    tablica[54] = Glin.symbol;
    tablica[55] = Gal.symbol;
    tablica[56] = Ind.symbol;
    tablica[57] = Tal.symbol;
    tablica[58] = Nion.symbol;
    tablica[59] = Wegiel.symbol;
    tablica[60] = Krzem.symbol;
    tablica[61] = German.symbol;
    tablica[62] = Cyna.symbol;
    tablica[63] = Olow.symbol;
    tablica[64] = Flerow.symbol;
    tablica[65] = Azot.symbol;
    tablica[66] = Fosfor.symbol;
    tablica[67] = Arsen.symbol;
    tablica[68] = Antymon.symbol;
    tablica[69] = Bizmut.symbol;
    tablica[70] = Moskow.symbol;
    tablica[71] = Tlen.symbol;
    tablica[72] = Siarka.symbol;
    tablica[73] = Selen.symbol;
    tablica[74] = Telleur.symbol;
    tablica[75] = Polon.symbol;
    tablica[76] = Liwermor.symbol;
    tablica[77] = Fluor.symbol;
    tablica[78] = Chlor.symbol;
    tablica[79] = Brom.symbol;
    tablica[80] = Jod.symbol;
    tablica[81] = Astat.symbol;
    tablica[82] = Tenness.symbol;
    tablica[83] = Hel.symbol;
    tablica[84] = Neon.symbol;
    tablica[85] = Argon.symbol;
    tablica[86] = Krypton.symbol;
    tablica[87] = Ksenon.symbol;
    tablica[88] = Radon.symbol;
    tablica[89] = Oganes.symbol;
    tablica[90] = Cer.symbol;
    tablica[91] = Praseodym.symbol;
    tablica[92] = Neodym.symbol;
    tablica[93] = Promet.symbol;
    tablica[94] = Samar.symbol;
    tablica[95] = Europ.symbol;
    tablica[96] = Gadolin.symbol;
    tablica[97] = Terb.symbol;
    tablica[98] = Dyspors.symbol;
    tablica[99] = Holm.symbol;
    tablica[100] = Erb.symbol;
    tablica[101] = Tul.symbol;
    tablica[102] = Iterb.symbol;
    tablica[103] = Lutet.symbol;
    tablica[104] = Tor.symbol;
    tablica[105] = Proaktyn.symbol;
    tablica[106] = Uran.symbol;
    tablica[107] = Neptun.symbol;
    tablica[108] = Pluton.symbol;
    tablica[109] = Ameryk.symbol;
    tablica[110] = Kiur.symbol;
    tablica[111] = Berkl.symbol;
    tablica[112] = Kaliforn.symbol;
    tablica[113] = Einshtein.symbol;
    tablica[114] = Ferm.symbol;
    tablica[115] = Mendelew.symbol;
    tablica[116] = Nobel.symbol;
    tablica[117] = Lorentz.symbol;

void identyfikacja_zwiazku(string zwiazek)
{
    int i;

    for(i=0;i=118;i++)
    {
        if(zwiazek==tablica[i])
        {
            cout<<"test"<<endl;
        }  

        cout<<tablica[i]<<endl;
    }

}

int main()
{
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
            cout<<" Podaj masę molową substancji A:"<<endl;
            cin>> masa_molowa_substancji_A;     
            cout<<" Podaj masę molową substancji B:"<<endl;
            cin>> masa_molowa_substancji_B;
            identyfikacja_zwiazku(substancja_A);
            identyfikacja_zwiazku(substancja_B);
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

    return 0;
}