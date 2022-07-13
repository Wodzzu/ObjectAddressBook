#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include <iostream>
#include <vector>
#include <fstream>



#include "Adresat.h"
#include "MetodyPomocnicze.h"


class PlikZAdresatami
{
int idOstatniegoAdresata;
string nazwaPlikuZAdresatami = "Adresaci.txt";
public:
void dopiszAdresataDoPliku(Adresat adresat);
int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika,vector <Adresat> &adresaci);
string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
bool czyPlikJestPusty(fstream &plikTekstowy);
int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
int ustawIdOstatniegoAdresata(int noweId);
int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
int pobierzIdOstaniegoAdresata();

};

#endif
