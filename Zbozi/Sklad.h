#pragma once
#include <map>
#include <string>
#include <vector>
#include "Zbozi.h"

class Sklad {
private:
    std::map<int, Zbozi> zboziMap;

public:
    void pridatZbozi(const Zbozi& zbozi);
    void odebratZbozi(int id);
    Zbozi* vyhledatZbozi(int id);
    void vypsatVsechnoZbozi() const;
    double vypocetCelkoveCeny() const;
    void ulozitDoSouboru(const std::string& fileName) const;
    void nacistZeSouboru(const std::string& fileName);
    void seraditZbozi(const std::string& kriterium);
    void ulozitSerazeneDoSouboru(const std::string& kriterium, const std::vector<std::pair<int, Zbozi>>& zboziList);
};
