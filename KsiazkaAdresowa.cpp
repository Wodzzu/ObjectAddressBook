#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::wypiszWszystkichAdresatow() {
    adresatMenedzer->wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}
void KsiazkaAdresowa::dodajAdresata() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer->dodajAdresata();
    } else {
        cout << "Aby dodac Adresata, nalezy sie najpierw zalogowac" <<endl;
        system("pause");
    }
}
void KsiazkaAdresowa::zmianaHaslaUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::wylogujUzytkownika() {
    int idUzytkownikaPoWylogowaniu =0;
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(idUzytkownikaPoWylogowaniu);
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}
bool KsiazkaAdresowa::czyWektorAdresatowJestPusty() {
    return adresatMenedzer->czyWektorAdresatowJestPusty();
}
int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}
int KsiazkaAdresowa::pobierzIdOstatniegoAdresata() {

    return adresatMenedzer->pobierzIdOstaniegoAdresata();
}
void KsiazkaAdresowa::ustawIdOstatniegoAdresata(int noweId) {
    adresatMenedzer->ustawIdOstatniegoAdresata(noweId);
}
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu() {
    adresatMenedzer->wyszukajAdresatowPoImieniu();
}
void KsiazkaAdresowa:: wyszukajAdresatowPoNazwisku() {
    adresatMenedzer->wyszukajAdresatowPoNazwisku();
}
void KsiazkaAdresowa::usunAdresata() {
    adresatMenedzer->usunAdresata();
}
void KsiazkaAdresowa::edytujAdresata() {
    adresatMenedzer->edytujAdresata();
}

void KsiazkaAdresowa::menuGlowne() {
    while (true) {
        if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0) {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                dodajAdresata();
                break;
            case '2':
                wyszukajAdresatowPoImieniu();
                break;
            case '3':
                wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                wypiszWszystkichAdresatow();
                break;
            case '5':
                usunAdresata();
                break;
            case '6':
                edytujAdresata();
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


char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {

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
char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
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
