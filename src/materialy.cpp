#include "include/materialy.h"
using namespace std;

// Konstruktor klasy Material
Material::Material(int id, string nazwa, float cena, int ilosc)
{
    this->nazwa = nazwa; // Inicjalizacja prywatnego pola nazwa
    this->cena = cena;   // Inicjalizacja prywatnego pola cena
    this->ilosc = ilosc; // Inicjalizacja prywatnego pola ilosc
    this->id = id;
}

// Metoda zwracająca nazwę materialu
string Material::pobierzNazwe()
{
    return nazwa;
}

// Metoda zwracająca cenę materialu
float Material::pobierzCene()
{
    return cena;
}

// Metoda zwracająca ilość materialu
int Material::pobierzIlosc()
{
    return ilosc;
}

// Metoda ustawiająca ilość materialu
void Material::ustawIlosc(int ilosc)
{
    this->ilosc = ilosc;
}
int Material::pobierzId()
{
    return id;
}
