#include "Sklad.h"
#include <iostream>

int main() {
    Sklad sklad;
    int volba;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Pridat zbozi\n";
        std::cout << "2. Odebrat zbozi\n";
        std::cout << "3. Vyhledat zbozi\n";
        std::cout << "4. Vypsat vsechno zbozi\n";
        std::cout << "5. Vypocitat celkovou cenu zbozi\n";
        std::cout << "6. Ulozit do souboru\n";
        std::cout << "7. Nacist ze souboru\n";
        std::cout << "0. Konec\n";
        std::cin >> volba;

        if (volba == 0) {
            break;
        }

        switch (volba) {
        case 1: {
            int id, pocetKs;
            double cena;
            std::string nazev;
            std::cout << "Zadejte ID zbozi: ";
            std::cin >> id;
            std::cout << "Zadejte nazev zbozi: ";
            std::cin >> nazev;
            std::cout << "Zadejte cenu zbozi: ";
            std::cin >> cena;
            std::cout << "Zadejte pocet ks: ";
            std::cin >> pocetKs;
            Zbozi zbozi(id, nazev, cena, pocetKs);
            sklad.pridatZbozi(zbozi);
            break;
        }
        case 2: {
            int id;
            std::cout << "Zadejte ID zbozi k odebrani: ";
            std::cin >> id;
            sklad.odebratZbozi(id);
            break;
        }
        case 3: {
            int id;
            std::cout << "Zadejte ID zbozi k vyhledani: ";
            std::cin >> id;
            Zbozi* zbozi = sklad.vyhledatZbozi(id);
            if (zbozi) {
                zbozi->vypisZbozi();
            }
            else {
                std::cout << "Zbozi nenalezeno." << std::endl;
            }
            break;
        }
        case 4:
            sklad.vypsatVsechnoZbozi();
            break;
        case 5:
            std::cout << "Celková cena zbozi: " << sklad.vypocetCelkoveCeny() << std::endl;
            break;
        case 6: {
            std::string fileName;
            std::cout << "Zadejte nazev souboru: ";
            std::cin >> fileName;
            sklad.ulozitDoSouboru(fileName);
            break;
        }
        case 7: {
            std::string fileName;
            std::cout << "Zadejte nazev souboru: ";
            std::cin >> fileName;
            sklad.nacistZeSouboru(fileName);
            break;
        }
        default:
            std::cout << "Neplatna volba." << std::endl;
        }
    }

    return 0;
}
