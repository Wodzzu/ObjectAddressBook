#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include <iostream>
#include <vector>
#include <fstream>


#include "PlikTekstowy.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"


class PlikZAdresatami: public PlikTekstowy {
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void ustawIdUsuwanegoAdresata(int noweId);
    int pobierzIdUsuwanegoAdresata();
    int podajIdWybranegoAdresata();
    int pobierzZPlikuIdOstatniegoAdresata();
    char wybierzOpcjeZMenuEdycja();
    void usunAdresataZPliku(int idAdresata);
    void edytujAdresataWPliku(Adresat adresat);

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {
        idOstatniegoAdresata =0;
    };
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika,vector <Adresat> &adresaci);
    int pobierzIdOstaniegoAdresata();
    void ustawIdOstatniegoAdresata(int noweId);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int usunAdresata(vector <Adresat> &adresaci);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata();
    void edytujAdresata(vector <Adresat> &adresaci);
};

#endif
