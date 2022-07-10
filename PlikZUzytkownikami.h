#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"

using namespace std;

class PlikZUzytkownikami
{
    string nazwaPlikuZUzytkownikami;
        fstream plikTekstowy;
Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    bool czyPlikJestPusty();
string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    PlikZUzytkownikami();
    vector <Uzytkownik> wczytajUzytkownikowZPliku();

};
