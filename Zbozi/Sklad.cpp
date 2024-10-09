#include "Sklad.h"
#include "Zbozi.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>       // Pro použití std::vector
#include <algorithm>    // Pro použití std::sort

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
            std::stringstream ss(line);
            int id;
            std::string nazev;
            double cena;
            int pocetKs;

            if (ss >> id && ss.ignore(1) &&
                std::getline(ss, nazev, ',') &&
                ss >> cena && ss.ignore(1) &&
                ss >> pocetKs) {
                Zbozi zbozi(id, nazev, cena, pocetKs);
                zboziMap[id] = zbozi;
                success = true;
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

void Sklad::seraditZbozi(const std::string& kriterium) {
    // Pøevést mapu na vektor párù
    std::vector<std::pair<int, Zbozi>> zboziList(zboziMap.begin(), zboziMap.end());

    // Podle zadaného kritéria provést øazení
    if (kriterium == "id") {
        std::sort(zboziList.begin(), zboziList.end(),
            [](const std::pair<int, Zbozi>& a, const std::pair<int, Zbozi>& b) {
                return a.first < b.first; // Øazení podle ID
            });
    }
    else if (kriterium == "nazev") {
        std::sort(zboziList.begin(), zboziList.end(),
            [](const std::pair<int, Zbozi>& a, const std::pair<int, Zbozi>& b) {
                return a.second.getNazev() < b.second.getNazev(); // Øazení podle názvu
            });
    }
    else if (kriterium == "cena") {
        std::sort(zboziList.begin(), zboziList.end(),
            [](const std::pair<int, Zbozi>& a, const std::pair<int, Zbozi>& b) {
                return a.second.getCena() < b.second.getCena(); // Øazení podle ceny
            });
    }
    else if (kriterium == "pocet") {
        std::sort(zboziList.begin(), zboziList.end(),
            [](const std::pair<int, Zbozi>& a, const std::pair<int, Zbozi>& b) {
                return a.second.getPocetKs() < b.second.getPocetKs(); // Øazení podle poètu ks
            });
    }
    else {
        std::cout << "Neplatne kriterium pro serazeni." << std::endl;
        return;
    }

    // Vypsat seøazená data
    for (const auto& pair : zboziList) {
        pair.second.vypisZbozi();
    }

    // Automaticky uložit do souboru podle kritéria
    ulozitSerazeneDoSouboru(kriterium, zboziList);
}

void Sklad::ulozitSerazeneDoSouboru(const std::string& kriterium, const std::vector<std::pair<int, Zbozi>>& zboziList) {
    // Název souboru podle kritéria
    std::string fileName = "serazeno_podle_" + kriterium + ".txt";

    std::ofstream file(fileName);
    if (file.is_open()) {
        for (const auto& pair : zboziList) {
            file << pair.first << "," << pair.second.getNazev() << ","
                << pair.second.getCena() << "," << pair.second.getPocetKs() << std::endl;
        }
        file.close();
        std::cout << "Data byla uspesne ulozena do souboru: " << fileName << std::endl;
    }
    else {
        std::cout << "Nepodarilo se otevrit soubor pro zapis: " << fileName << std::endl;
    }
}

