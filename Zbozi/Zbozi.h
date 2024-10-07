#ifndef ZBOZI_H
#define ZBOZI_H

#include <string>

class Zbozi {
private:
    int id;
    std::string nazev;
    double cena;
    int pocetKs;

public:
    Zbozi();
    Zbozi(int id, std::string nazev, double cena, int pocetKs);

    int getId() const;
    std::string getNazev() const;
    double getCena() const;
    int getPocetKs() const;
    void setPocetKs(int pocetKs);
    double celkovaCena() const;
    void vypisZbozi() const;
};

#endif
