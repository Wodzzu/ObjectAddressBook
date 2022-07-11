
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
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzykownikami(nazwaPlikuZUzytkownikami) {};
       void rejestracjaUzytkownika();
   void wypiszWszystkichUzytkownikow();
   void wczytajUzytkownikowZPliku();
};
