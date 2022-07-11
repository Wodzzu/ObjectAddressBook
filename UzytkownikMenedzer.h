
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "PlikZUzytkownikami.h"
#include "Uzytkownik.h"


using namespace std;

class UzytkownikMenedzer
{
 PlikZUzytkownikami plikZUzykownikami;

    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);


public:
    void zmianaHaslaZalogowanegoUzytkownika();
    int logowanieUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweId);
    int pobierzIdZalogowanegoUzytkownika();
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzykownikami(nazwaPlikuZUzytkownikami) {
    idZalogowanegoUzytkownika=0;};
       void rejestracjaUzytkownika();
   void wypiszWszystkichUzytkownikow();
   void wczytajUzytkownikowZPliku();
};
