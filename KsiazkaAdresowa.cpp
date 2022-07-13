#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa::ustawIdZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.logowanieUzytkownika());
}
void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresatMenedzer.ustawIdOstatniegoAdresata(adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()));
}
void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer.ustawIdOstatniegoAdresata(adresatMenedzer.dodajAdresata(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika(), adresatMenedzer.pobierzIdOstaniegoAdresata()));
}
void KsiazkaAdresowa::zmianaHaslaUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::wylogujUzytkownika()
{
    int idUzytkownikaPoWylogowaniu =0;
     uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(idUzytkownikaPoWylogowaniu);
     adresatMenedzer.wyczyscDaneZWektoraAdresatow();
}
bool KsiazkaAdresowa::czyWektorAdresatowJestPusty()
{
    adresatMenedzer.czyWektorAdresatowJestPusty();
}

void KsiazkaAdresowa::menuGlowne()
{
     while (true)
    {
        if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
               ustawIdZalogowanegoUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

           if (czyWektorAdresatowJestPusty())
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
                wczytajAdresatowZalogowanegoUzytkownikaZPliku();
            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                dodajAdresata();
                break;
            case '2':
               // wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
               // wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                 wypiszWszystkichAdresatow();
                break;
            case '5':
                //idUsunietegoAdresata = usunAdresata(adresaci);
               // idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
               // edytujAdresata(adresaci);
                break;
            case '7':
                zmianaHaslaUzytkownika();
                break;
            case '8':
               wylogujUzytkownika();
                break;
            }
        }
    }

}


char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
