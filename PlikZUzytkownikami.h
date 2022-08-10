#ifndef PlikZUzytkownikami_H
#define PlikZUzytkownikami_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZUzytkownikami: public PlikTekstowy {

    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
    PlikZUzytkownikami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {
    };
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();

};

#endif
