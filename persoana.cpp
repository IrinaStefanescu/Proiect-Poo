#include "persoana.hpp"

void Persoana::setNume(string n)
{
    nume = n;
}

void Persoana::setAnNastere(int an)
{
    an_nastere = an;
}

void Persoana::setSex(char s)
{
    sex = s;
}

string Persoana::getNume()
{
    return nume;
}

int Persoana::getAnNastere()
{
    return an_nastere;
}

char Persoana::getSex()
{
    return sex;
}

Persoana::Persoana()  //constructor null
{
    nume = "";
    an_nastere = 0;
    sex = 0;
}

Persoana::Persoana(string nume, int an_nastere, char sex):nume(nume), an_nastere(an_nastere), sex(sex) {}  //constructor pt adaugat persoana

Persoana::~Persoana(){}  //destructor pt dezalocare


istream& operator>>(istream& in, Persoana& ob)
{
    in>>ob.nume>>ob.an_nastere>>ob.sex;

    return in;
}

ostream& operator<<(ostream& out, Persoana& ob)
{
    out<<ob.nume<<" ";
    out<<ob.an_nastere<<" ";
    out<<ob.sex<<endl;

    return out;
}
