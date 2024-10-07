#ifndef SKLAD_H
#define SKLAD_H

#include "Zbozi.h"
#include <map>

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
};

#endif
