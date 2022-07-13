#ifndef AdresatMenedzer_H
#define AdresatMenedzer_H

#include <iostream>
#include <vector>
#include <fstream>



#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
string nazwaPlikuZAdresatami;

int idOstatniegoAdresata;
vector <Adresat> adresaci;


int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
void dopiszAdresataDoPliku(Adresat adresat);
string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
bool czyPlikJestPusty(fstream &plikTekstowy);

public:
AdresatMenedzer();

int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
void ustawIdOstatniegoAdresata(int noweId);
int pobierzIdOstaniegoAdresata();
int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
void wyswietlWszystkichAdresatow();
void wyswietlDaneAdresata(Adresat adresat);
void wyczyscDaneZWektoraAdresatow();
bool czyWektorAdresatowJestPusty();
};

#endif
