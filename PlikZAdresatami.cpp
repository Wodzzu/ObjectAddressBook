#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good()) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (PlikTekstowy::czyPlikJestPusty()) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}
int PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika,vector <Adresat> &adresaci) {
    Adresat adresat;

    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good()) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    } else
        return 0;
}
string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}
Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
void PlikZAdresatami::ustawIdOstatniegoAdresata(int noweId) {
    if(noweId>=0)
        idOstatniegoAdresata=noweId;
}
int PlikZAdresatami::pobierzIdOstaniegoAdresata() {
    return idOstatniegoAdresata;
}
int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}
void PlikZAdresatami::usunAdresataZPliku(int idAdresata) {
    int numerLiniiWPlikuTekstowym = 1, numerUsuwanejLinii = 0;
    string wczytanaLiniaZPliku = "";
    fstream plikTekstowy,tymczasowyPlikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() && idAdresata != 0) {
        while(getline(plikTekstowy, wczytanaLiniaZPliku)) {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLiniaZPliku)) {
                numerUsuwanejLinii = numerLiniiWPlikuTekstowym;
                numerLiniiWPlikuTekstowym++;
            } else {
                if (numerLiniiWPlikuTekstowym == numerUsuwanejLinii) {}
                else if (numerLiniiWPlikuTekstowym == 1 && numerLiniiWPlikuTekstowym != numerUsuwanejLinii)
                    tymczasowyPlikTekstowy << wczytanaLiniaZPliku;
                else if (numerLiniiWPlikuTekstowym == 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLiniaZPliku;
                else if (numerLiniiWPlikuTekstowym > 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLiniaZPliku;
                else if (numerLiniiWPlikuTekstowym > 1 && numerUsuwanejLinii != 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLiniaZPliku;
                numerLiniiWPlikuTekstowym++;
            }
        }
    }
    plikTekstowy.close();
    tymczasowyPlikTekstowy.close();
    usunPlik(pobierzNazwePliku());
    zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());


}
void PlikZAdresatami::usunWybranaLinieWPliku(int numerUsuwanejLinii) {

    fstream plikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    int numerLiniiWPlikuTekstowym = 1;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true && numerUsuwanejLinii != 0) {
        while (getline(plikTekstowy, wczytanaLinia)) {
            // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
            // aby na koncu pliku nie bylo pustej linii
            if (numerLiniiWPlikuTekstowym == numerUsuwanejLinii) {}
            else if (numerLiniiWPlikuTekstowym == 1 && numerLiniiWPlikuTekstowym != numerUsuwanejLinii)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerLiniiWPlikuTekstowym == 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerLiniiWPlikuTekstowym > 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            else if (numerLiniiWPlikuTekstowym > 1 && numerUsuwanejLinii != 1)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            numerLiniiWPlikuTekstowym++;
        }
        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
}


void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem) {
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa) {
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}
int PlikZAdresatami::usunAdresata(vector <Adresat> &adresaci) {

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    ustawIdUsuwanegoAdresata(podajIdWybranegoAdresata());

    char znak;
    bool czyIstniejeAdresat = false;

    for (int i = 0 ; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == pobierzIdUsuwanegoAdresata()) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
                usunAdresataZPliku(pobierzIdUsuwanegoAdresata());

                adresaci.erase(adresaci.begin()+i);

                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return 0;////
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }

    return 0;
}
void PlikZAdresatami::ustawIdUsuwanegoAdresata(int idAdresataDoUsuniecia) {
    if(idAdresataDoUsuniecia>0)
        idUsunietegoAdresata=idAdresataDoUsuniecia;

}
int PlikZAdresatami::podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}
int PlikZAdresatami::pobierzIdUsuwanegoAdresata() {
    return idUsunietegoAdresata;
}

void PlikZAdresatami::podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata() {
    if ( pobierzIdUsuwanegoAdresata() == pobierzIdOstaniegoAdresata())
        ustawIdOstatniegoAdresata(pobierzZPlikuIdOstatniegoAdresata());
}
int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata() {
    //int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good()) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}
void PlikZAdresatami::edytujAdresata(vector <Adresat> &adresaci) {
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
                edytujAdresataWPliku(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
                edytujAdresataWPliku(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                edytujAdresataWPliku(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                edytujAdresataWPliku(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                edytujAdresataWPliku(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}
char PlikZAdresatami::wybierzOpcjeZMenuEdycja() {
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
void PlikZAdresatami::edytujAdresataWPliku(Adresat adresat) {

    int numerLiniiWPlikuTekstowym = 1;
    string wczytanaLinia = "",liniaZDanymiAdresata = "";
    fstream plikTekstowy,tymczasowyPlikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() && adresat.pobierzId() != 0) {
        while(getline(plikTekstowy, wczytanaLinia)) {
            if(adresat.pobierzId() == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)) {
                liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

                if (numerLiniiWPlikuTekstowym == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresata;
                else if (numerLiniiWPlikuTekstowym > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;

            } else {
                if (numerLiniiWPlikuTekstowym == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerLiniiWPlikuTekstowym > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;

            }
            numerLiniiWPlikuTekstowym++;
        }

    }
    plikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    usunPlik(pobierzNazwePliku());
    zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}
