
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "PlikZUzytkownikami.h"
#include "Uzytkownik.h"
#include "AdresatMenedzer.h"

using namespace std;

class UzytkownikMenedzer
{
 PlikZUzytkownikami plikZUzytkownikami;

    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);


public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
    idZalogowanegoUzytkownika=0;};
    void zmianaHaslaZalogowanegoUzytkownika();
    int logowanieUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweId);
    int pobierzIdZalogowanegoUzytkownika();
    void rejestracjaUzytkownika();
   void wypiszWszystkichUzytkownikow();
   void wczytajUzytkownikowZPliku();
};
