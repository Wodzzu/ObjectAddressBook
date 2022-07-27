#include <iostream>
#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    char wybor;

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wypiszWszystkichAdresatow();
    void logowanieUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dodajAdresata();
    void zmianaHaslaUzytkownika();
    void wylogujUzytkownika();
    bool czyWektorAdresatowJestPusty();
    int pobierzIdZalogowanegoUzytkownika();
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int noweId);
    int dodawanieAdresataZPobranymiId();
    int wczytanieAdresatowDlaZalogowanegoUzytkownika();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    void edytujAdresata();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adresatMenedzer = NULL;
    };
    ~KsiazkaAdresowa() {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }
    void menuGlowne();

};
