#include <iostream>
#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
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
};
