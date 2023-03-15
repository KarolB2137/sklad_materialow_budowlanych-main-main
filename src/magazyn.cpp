#include "include/magazyn.h"
#include <iostream>
#include <fstream>
using namespace std;

void Magazyn::dodajMaterial(Material material) // dodaje material do magazynu
{
    materialy.push_back(material);
    cout << endl
         << "                   ========== - " << material.pobierzNazwe() << " dodany do magazynu - ==========" << endl
         << endl;
}

void Magazyn::usunMaterial(string nazwa) // usuwa material o podanej nazwie z magazynu
{
    for (auto it = materialy.begin(); it != materialy.end(); it++)
    {
        if (it->pobierzNazwe() == nazwa)
        {
            materialy.erase(it);
            cout << endl
                 << "                   ========== - " << nazwa << " usuniety z magazynu - ==========" << endl
                 << endl;
            return;
        }
    }
    cout << endl
         << "                   ========== - " << nazwa << " nie znaleziony w magazynie - ==========" << endl
         << endl;
}

void Magazyn::sprawdzStan() // wyswietla stan magazynu
{

    cout << endl
         << "Sklad magazynu:" << endl;
    ifstream plik;
    plik.open("magazyn.txt");
    if (plik.is_open())
    {
        for (auto it = materialy.begin(); it != materialy.end(); it++)
        {
            cout << endl
                 << "Nazwa: " << it->pobierzNazwe() << " Ilosc: " << it->pobierzIlosc() << endl;
        }
    }
}

void Magazyn::zapiszDoPliku(ofstream &outfile) // zapisuje stan magazynu do pliku
{
    for (auto it = materialy.begin(); it != materialy.end(); it++)
    {
        outfile.write(it->pobierzNazwe().c_str(), it->pobierzNazwe().length());
        outfile << " " << it->pobierzCene() << " " << it->pobierzIlosc() << endl;
    }
    outfile.close();
}

void Magazyn::Wyszukaj(string nazwa) // usuwa material o podanej nazwie z magazynu
{
    for (auto it = materialy.begin(); it != materialy.end(); it++)
    {
        for (auto it = materialy.begin(); it != materialy.end(); it++)
        {
            if (it->pobierzNazwe() == nazwa)
            {
                cout << endl
                     << "Znaleziono: " << it->pobierzNazwe() << " Ilosc: " << it->pobierzIlosc() << endl
                     << endl;
                return;
            }
        }
        cout << endl
             << "                   ========== - " << nazwa << " nie znaleziony w magazynie - ==========" << endl
             << endl;
    }
}