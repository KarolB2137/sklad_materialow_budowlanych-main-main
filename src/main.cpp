/**
 * @file main.cpp
 * @author Paweł Dobrowolski, Karol Błoniarz
 * @brief // Ten kod jest programem w C++, który symuluje system zarządzania magazynem materiałów budowlanych.
// Użytkownik ma kilka opcji do wyboru w menu, takich jak dodawanie, usuwanie, sprawdzanie stanu magazynu i zapisywanie danych do pliku.
// Wewnątrz każdej opcji użytkownik jest pytany o odpowiednie dane, takie jak nazwa, cena i ilość materiału.
// Klasy 'Magazyn' i 'Material' są używane do przechowywania i manipulowania danymi magazynu.
// Program kończy działanie, gdy użytkownik wybierze opcję "Wyjdź".
 * @version 1.0
 * @date 2023-01-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <fstream>
#include "include/magazyn.h"
#include "include/materialy.h"
using namespace std;

void menu();
void dodajMaterial(Magazyn &magazyn);
void usunMaterial(Magazyn &magazyn);
void sprawdzStan(Magazyn &magazyn);
void zapiszDoPliku(Magazyn &magazyn);
void Wyszukaj(Magazyn &magazyn);

int main()
{
  
    Magazyn magazyn;
    int wybor;
    do
    {
        menu();
        cin >> wybor;
        switch (wybor)
        {
        case 1:
            dodajMaterial(magazyn);
            break;
        case 2:
            usunMaterial(magazyn);
            break;
        case 3:
            sprawdzStan(magazyn);
            break;
        case 4:
            Wyszukaj(magazyn);
            break;

        case 5:
            zapiszDoPliku(magazyn);
            break;
        case 6:
            cout << "Wychodzenie..." << endl
                 << endl;
            break;
        default:
            cout << "Niepoprawny wybor. Sprobuj ponownie." << endl
                 << endl;
        }
    } while (wybor != 6);
}
/**
 * @brief Funkcja menu() wyswietla menu glowne programu,
 * pozwalajace na wybor opcji: dodawanie materialu, usuwanie materialu, sprawdzanie stanu magazynu,
 * zapis materialow do pliku oraz wyjscie z programu.
 */
void menu()
{
    cout << endl
         << "                   SYSTEM ZARZADZANIA SKLADEM MATERIALOW BUDOWLANYCH " << endl;
    cout << "=======================================================================================" << endl
         << endl;
    cout << " 1. Dodaj Material" << endl;     // wyswietla opcje dodawania materialu
    cout << " 2. Usun Material" << endl;      // wyswietla opcje usuwania materialu
    cout << " 3. Sprawdz magazyn" << endl;    // wyswietla opcje sprawdzenia stanu magazynu
    cout << " 4. Wyszukaj material " << endl; // wyswietla opcje sprawdzenia stanu magazynu
    cout << " 5. Zapisz zmiany" << endl;      // wyswietla opcje zapisu materialow do pliku
    cout << " 6. Wyjdz" << endl
         << endl; // wyswietla opcje wyjscia z programu
    cout << "=======================================================================================" << endl
         << endl;
    cout << "Wprowadz swoj wybor: ";
}
/**
 * @brief Funkcja dodajMaterial() pozwala na dodanie nowego materialu do magazynu,
 * wymagajac podania nazwy, ceny i ilosci materialu.
 */
void dodajMaterial(Magazyn &magazyn)
{
    string nazwa;
    double cena;
    int ilosc;
    int id;
    for (unsigned int i = 1; i < magazyn.materialy.size(); i++)
    {
       id=i;
    }
    cout << "Wprowadz nazwe materialu: ";
    cin >> nazwa;
    cout << "Wprowadz cene materialu: ";
    cin >> cena;
    cout << "Wprowadz ilosc materialu: ";
    cin >> ilosc;
    Material material(id, nazwa, cena, ilosc);
    magazyn.dodajMaterial(material);
}
/**
 * @brief Funkcja usunMaterial() pozwala na usuniecie materialu z magazynu, wymagajac podania nazwy materialu.
 */
void usunMaterial(Magazyn &magazyn)
{
    string nazwa;
    cout << "Wprowadz nazwe materialu: ";
    cin >> nazwa;
    magazyn.usunMaterial(nazwa);
}
/**
 * @brief Funkcja sprawdzStan() pozwala na wyswietlenie stanu magazynu, wyswietlajac nazwe, cene i ilosc wszystkich materialow w magazynie.
 */
void sprawdzStan(Magazyn &magazyn)
{

    magazyn.sprawdzStan();
}
/**
 * @brief Funkcja zapiszDoPliku() pozwala na zapisanie stanu magazynu do pliku tekstowego
 * "magazyn.txt", zapisujac nazwe, cene i ilosc wszystkich materialow w magazynie.
 */
void zapiszDoPliku(Magazyn &magazyn)
{
    ofstream outfile("magazyn.txt");
    for (unsigned int i = 0; i < magazyn.materialy.size(); i++)
    {
        outfile <<"id: "<<magazyn.materialy[i].pobierzId() <<" " <<"Nazwa: " << magazyn.materialy[i].pobierzNazwe() << " Cena: " << magazyn.materialy[i].pobierzCene() << " Ilosc: " << magazyn.materialy[i].pobierzIlosc() << endl
        ;
    }
    outfile.close();

    cout << "Zmiany zostaly zapisane do magazyn.txt" << endl;
}
void Wyszukaj(Magazyn &magazyn)
{
    string nazwa;
    cout << "Wprowadz nazwe materialu: ";
    cin >> nazwa;
    magazyn.Wyszukaj(nazwa);
}