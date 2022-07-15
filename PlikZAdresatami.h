#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include <iostream>
#include <vector>
#include <fstream>



#include "Adresat.h"
#include "MetodyPomocnicze.h"


class PlikZAdresatami {
    int idOstatniegoAdresata;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

    bool czyPlikJestPusty(fstream &plikTekstowy);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : NAZWA_PLIKU_Z_ADRESATAMI(NAZWAPLIKUZADRESATAMI) {
        idOstatniegoAdresata =0;
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika,vector <Adresat> &adresaci);
    int ustawIdOstatniegoAdresata(int noweId);
    int pobierzIdOstaniegoAdresata();

};

#endif
