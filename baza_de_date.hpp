#ifndef BAZA_DE_DATE_HPP_INCLUDED
#define BAZA_DE_DATE_HPP_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "persoana.hpp"

using namespace std;

class baza_de_date
{

private:
    int nr_persoane;
    vector<Persoana> persoane;

public:
    baza_de_date(); //constructor fara parametru
    baza_de_date(int nr);  //initializare vector null
    ~baza_de_date(); //destructor care dealoca toate persoanele


	void salvare();
    void adauga_persoana(string, int, char);
    void afisare();

    void sterge(string nume);
    void sterge(int an_nastere);
    void sterge(char sex);

    void afisare_dupa_nume();
    void afisare_dupa_varsta();

    friend istream& operator>>(istream& in, Persoana& ob);
    friend ostream& operator<<(ostream& out, Persoana& ob);

};

#endif // BAZA_DE_DATE_HPP_INCLUDED
