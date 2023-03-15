#ifndef MATERIALS_H
#define MATERIALS_H

#include <string>
using namespace std;

class Material
{
    string nazwa; // nazwa materialu
    float cena;   // cena materialu
    int ilosc;    // ilosc materialu
    int id;

public:
    Material(int, string, float, int); // konstruktor
    string pobierzNazwe();        // zwraca nazwe materialu
    float pobierzCene();          // zwraca cene materialu
    int pobierzIlosc();           // zwraca ilosc materialu
    void ustawIlosc(int);         // ustawia ilosc materialu
    int pobierzId();
};

#endif