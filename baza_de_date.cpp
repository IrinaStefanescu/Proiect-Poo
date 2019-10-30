#include "baza_de_date.hpp"
#include <fstream>
#include <algorithm>
#include <fstream>

void baza_de_date::adauga_persoana(string nume, int an_nastere, char sex)
{
    Persoana p(nume, an_nastere, sex);
    persoane.push_back(p);   //adaugare la finalul vectorului
}


void baza_de_date::sterge(string nume)
{
    vector<Persoana>::iterator it = persoane.begin();
    while (it != persoane.end())
    {
        if ((*it).getNume() == nume)
        {
            it = persoane.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void baza_de_date::sterge(int an_nastere)
{
    vector<Persoana>::iterator it = persoane.begin();
    while (it != persoane.end())
    {
        if ((*it).getAnNastere() == an_nastere)
        {
            it = persoane.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void baza_de_date::sterge(char sex)
{
    vector<Persoana>::iterator it = persoane.begin();
    while (it != persoane.end())
    {
        if ((*it).getSex() == sex)
        {
            it = persoane.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void baza_de_date::afisare()
{
    vector<Persoana>::iterator it;
    int i = 1;

    for(it = persoane.begin(); it != persoane.end(); ++it)
    {
        cout<<"Persoana "<<i<<": ";
        cout << *it;

        i++;
    }
}

bool cmp(Persoana a, Persoana b)  //comparator pt frunctie de afisare dupa nume in ordine alfabetica
{
    return a.getNume() < b.getNume();
}

void baza_de_date::afisare_dupa_nume()
{
    sort(persoane.begin(), persoane.end(), cmp);
}

bool cmp1(Persoana a, Persoana b)  //comparator pt functie afisare dupa varsta in ordine crescatoare
{
    return a.getAnNastere() < b.getAnNastere();
}

void baza_de_date::afisare_dupa_varsta()
{
    sort(persoane.begin(), persoane.end(), cmp1);

}

void baza_de_date::salvare()  //salvare in fisier text a bazei de date
{
	ofstream fisier;
	fisier.open("baza_de_date.txt", ios_base::app);

	for (auto& persoana : persoane)
	{
		fisier << persoana;
	}
}

baza_de_date::baza_de_date() {}

baza_de_date::baza_de_date(int nr):nr_persoane(nr), persoane(nr) {} //initializare la null

baza_de_date::~baza_de_date() {} //dezalocare


