#ifndef AdresatMenedzer_H
#define AdresatMenedzer_H

#include <iostream>
#include <vector>


#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
PlikZAdresatami plikZAdresatami;
vector <Adresat> adresaci;
Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);

public:
int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int noweId);
void ustawIdOstatniegoAdresata(int noweId);
int pobierzIdOstaniegoAdresata();
int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
void wyswietlWszystkichAdresatow();
void wyswietlDaneAdresata(Adresat adresat);
void wyczyscDaneZWektoraAdresatow();
bool czyWektorAdresatowJestPusty();
};

#endif
