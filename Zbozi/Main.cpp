#include "Sklad.h"
#include <iostream>
#include <limits> // Pro použití std::numeric_limits

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
        std::cout << "8. Seradit zbozi\n";
        std::cout << "0. Konec\n";
        std::cin >> volba;

        // Kontrola na špatný vstup u volby
        if (std::cin.fail()) {
            std::cin.clear(); // Vyčistí chybový stav vstupu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignoruje neplatný vstup
            std::cout << "Neplatny vstup, zadejte cislo." << std::endl;
            continue;
        }

        if (volba == 0) {
            break;
        }

        switch (volba) {
        case 1: {
            int id, pocetKs;
            double cena;
            std::string nazev;

            // Vstup pro ID s validací
            while (true) {
                std::cout << "Zadejte ID zbozi: ";
                std::cin >> id;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Chyba: Musite zadat cislo pro ID." << std::endl;
                }
                else {
                    break;
                }
            }

            std::cout << "Zadejte nazev zbozi: ";
            std::cin >> nazev;

            // Vstup pro cenu s validací
            while (true) {
                std::cout << "Zadejte cenu zbozi: ";
                std::cin >> cena;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Chyba: Musite zadat cislo pro cenu." << std::endl;
                }
                else {
                    break;
                }
            }

            // Vstup pro počet kusů s validací
            while (true) {
                std::cout << "Zadejte pocet ks: ";
                std::cin >> pocetKs;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Chyba: Musite zadat cislo pro pocet ks." << std::endl;
                }
                else {
                    break;
                }
            }

            Zbozi zbozi(id, nazev, cena, pocetKs);
            sklad.pridatZbozi(zbozi);
            break;
        }
        case 2: {
            int id;

            // Vstup pro ID s validací
            while (true) {
                std::cout << "Zadejte ID zbozi k odebrani: ";
                std::cin >> id;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Chyba: Musite zadat cislo pro ID." << std::endl;
                }
                else {
                    break;
                }
            }

            sklad.odebratZbozi(id);
            break;
        }
        case 3: {
            int id;

            // Vstup pro ID s validací
            while (true) {
                std::cout << "Zadejte ID zbozi k vyhledani: ";
                std::cin >> id;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Chyba: Musite zadat cislo pro ID." << std::endl;
                }
                else {
                    break;
                }
            }

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
        case 8: {
            std::string kriterium;
            std::cout << "Zadejte kriterium pro serazeni (id, nazev, cena, pocet): ";
            std::cin >> kriterium;
            sklad.seraditZbozi(kriterium);
            break;
        }
        default:
            std::cout << "Neplatna volba." << std::endl;
        }
    }

    return 0;
}
