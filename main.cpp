#include <iostream>

#include "KsiazkaAdresowa.h"
using namespace std;

int main() {

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresaci.txt");
    ksiazkaAdresowa.menuGlowne();

    return 0;
}
