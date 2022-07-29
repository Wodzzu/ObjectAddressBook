#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include <iostream>
#include <vector>
#include <fstream>



#include "Adresat.h"
#include "MetodyPomocnicze.h"


class PlikZAdresatami {
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";

    bool czyPlikJestPusty(fstream &plikTekstowy);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : NAZWA_PLIKU_Z_ADRESATAMI(NAZWAPLIKUZADRESATAMI) {
        idOstatniegoAdresata =0;
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika,vector <Adresat> &adresaci);
    void ustawIdOstatniegoAdresata(int noweId);
    int pobierzIdOstaniegoAdresata();
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void ustawIdUsuwanegoAdresata(int noweId);
    int pobierzIdUsuwanegoAdresata();
    int podajIdWybranegoAdresata();
    int usunAdresata(vector <Adresat> &adresaci);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata();
    int pobierzZPlikuIdOstatniegoAdresata();
    void edytujAdresata(vector <Adresat> &adresaci);
    char wybierzOpcjeZMenuEdycja();
    void usunAdresataZPliku(int idAdresata);
    void edytujAdresataWPliku(Adresat adresat);
};

#endif
