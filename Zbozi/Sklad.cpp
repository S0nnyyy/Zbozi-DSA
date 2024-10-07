#include "Sklad.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Sklad::pridatZbozi(const Zbozi& zbozi) {
    zboziMap[zbozi.getId()] = zbozi;
}

void Sklad::odebratZbozi(int id) {
    zboziMap.erase(id);
}

Zbozi* Sklad::vyhledatZbozi(int id) {
    auto it = zboziMap.find(id);
    if (it != zboziMap.end()) {
        return &(it->second);
    }
    else {
        return nullptr;
    }
}

void Sklad::vypsatVsechnoZbozi() const {
    if (zboziMap.empty()) {
        std::cout << "Sklad je prazdny." << std::endl;
        return;
    }

    for (const auto& pair : zboziMap) {
        pair.second.vypisZbozi();
    }
}

double Sklad::vypocetCelkoveCeny() const {
    double total = 0;
    for (const auto& pair : zboziMap) {
        total += pair.second.celkovaCena();
    }
    return total;
}

void Sklad::ulozitDoSouboru(const std::string& fileName) const {
    std::string fileWithExtension = fileName;
    if (fileWithExtension.find(".txt") == std::string::npos) {
        fileWithExtension += ".txt";
    }

    std::ofstream file(fileWithExtension);
    if (file.is_open()) {
        for (const auto& pair : zboziMap) {
            file << pair.first << "," << pair.second.getNazev() << ","
                << pair.second.getCena() << "," << pair.second.getPocetKs() << std::endl;
        }
        file.close();
        std::cout << "Data byla uspesne ulozena do souboru: " << fileWithExtension << std::endl;
    }
    else {
        std::cout << "Nepodarilo se otevrit soubor pro zapis: " << fileWithExtension << std::endl;
    }
}

void Sklad::nacistZeSouboru(const std::string& fileName) {
    // Ovìøení, že soubor má pøíponu .txt
    std::string fileWithExtension = fileName;
    if (fileWithExtension.find(".txt") == std::string::npos) {
        fileWithExtension += ".txt";
    }

    std::ifstream file(fileWithExtension);
    if (file.is_open()) {
        zboziMap.clear();
        std::string line;
        bool success = false;

        std::cout << "Nacitani ze souboru: " << fileWithExtension << std::endl;
        while (std::getline(file, line)) {
            std::cout << "Zpracovavam radek: " << line << std::endl;
            std::stringstream ss(line);
            int id;
            std::string nazev;
            double cena;
            int pocetKs;

            // Pøeètení dat a oddìlení èárkami
            if (ss >> id && ss.ignore(1) && // Získání id a ignorování èárky
                std::getline(ss, nazev, ',') && // Získání názvu
                ss >> cena && ss.ignore(1) && // Získání ceny a ignorování èárky
                ss >> pocetKs) { // Získání poètu ks
                Zbozi zbozi(id, nazev, cena, pocetKs);
                zboziMap[id] = zbozi;
                success = true;

                std::cout << "Nacteno: ID=" << id << ", Nazev=" << nazev
                    << ", Cena=" << cena << ", PocetKs=" << pocetKs << std::endl;
            }
            else {
                std::cout << "Chyba pri nacteni radku: " << line << std::endl;
            }
        }

        file.close();
        if (success) {
            std::cout << "Data byla uspesne nactena ze souboru: " << fileWithExtension << std::endl;
        }
        else {
            std::cout << "Nepodarilo se nactit zadna data ze souboru: " << fileWithExtension << std::endl;
        }
    }
    else {
        std::cout << "Nepodarilo se otevrit soubor pro cteni: " << fileWithExtension << std::endl;
    }
}


