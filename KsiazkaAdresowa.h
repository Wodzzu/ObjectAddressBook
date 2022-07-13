#include <iostream>
#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    char wybor;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void menuGlowne();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wypiszWszystkichAdresatow();
    void ustawIdZalogowanegoUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dodajAdresata();
    void zmianaHaslaUzytkownika();
    void wylogujUzytkownika();
    bool czyWektorAdresatowJestPusty();
};
