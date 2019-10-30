#ifndef PERSOANA_HPP_INCLUDED
#define PERSOANA_HPP_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Persoana
{

private:
    string nume;
    int an_nastere;
    char sex;

public:
    Persoana(); //constructor pentru initializare la null
    Persoana(string, int, char); //constructor adaugat persoana
    ~Persoana(); //destructor

    void setNume(string n);
    void setAnNastere(int an);
    void setSex(char s);

    string getNume();
    int getAnNastere();
    char getSex();

    friend istream& operator>>(istream& in, Persoana& ob);
    friend ostream& operator<<(ostream& out, Persoana& ob);
};

#endif
