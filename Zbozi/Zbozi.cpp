#include "Zbozi.h"
#include <iostream>

Zbozi::Zbozi() : id(0), nazev(""), cena(0.0), pocetKs(0) {}

Zbozi::Zbozi(int id, std::string nazev, double cena, int pocetKs)
    : id(id), nazev(nazev), cena(cena), pocetKs(pocetKs) {}

int Zbozi::getId() const { return id; }
std::string Zbozi::getNazev() const { return nazev; }
double Zbozi::getCena() const { return cena; }
int Zbozi::getPocetKs() const { return pocetKs; }

void Zbozi::setPocetKs(int pocetKs) { this->pocetKs = pocetKs; }

double Zbozi::celkovaCena() const { return cena * pocetKs; }

void Zbozi::vypisZbozi() const {
    std::cout << "ID: " << id << ", Nazev: " << nazev
        << ", Cena: " << cena << ", Pocet ks: " << pocetKs << std::endl;
}
