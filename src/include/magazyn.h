#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <vector>
#include "materialy.h"
using namespace std;

class Magazyn
{
public:
    vector<Material> materialy;     // vector przechowujacy obiekty klasy Material
    void dodajMaterial(Material);   // dodaje material do magazynu
    void usunMaterial(string);      // usuwa material z magazynu
    void sprawdzStan();             // wyswietla stan magazynu
    void zapiszDoPliku(ofstream &); // zapisuje materialy do pliku
    void Wyszukaj(string);
};

#endif
