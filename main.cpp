#include "persoana.hpp"
#include "baza_de_date.hpp"
#include <fstream>


using namespace std;

int main()
{
	baza_de_date b;
	Persoana p;

	bool ok = true;
	while (ok) {
		int c;

		cout << "Introduceti optiunea dorita: 1 - adaugare persoana; 2 - stergere persoana; 3 - afisare; 0 - exit"
			<< endl;
		cin >> c;


		if (c != 1 && c != 2 && c != 3 && c != 0)
		{
			system("cls");
			cout << "Invalid!" << endl;

			ok = false;
			cin.get();
		}

		else if (c == 1) 
		{
			system("cls");
			string nume;
			int an_nastere;
			char sex;
			cout << "Introduceti numele persoanei pe care doriti sa o adaugati: ";
			cin >> nume;cout << endl;
			cout << "Introduceti anul nasterii persoanei: ";
			cin >> an_nastere;cout << endl;
			cout << "Introduceti sexul: ";
			cin >> sex;cout << endl;
			b.adauga_persoana(nume, an_nastere, sex);

		}

		else if (c == 3) 
		{
			int contor1;
			system("cls");
			cout << "1 - afisare; 2 - afisare dupa nume; 3 - afisare dupa varsta" << endl;
			cin >> contor1;

			switch (contor1) 
			{
			case 1:
				b.afisare();
				break;

			case 2:
				b.afisare_dupa_nume();
				break;

			case 3:
				b.afisare_dupa_varsta();
				break;

			default:
				cout << "Invalid";

			}

			cout << endl;
		}

		else if (c == 2) 
		{

			int contor2;
			system("cls");
			cout << "1 - sterge dupa nume; 2 - sterge dupa varsta; 3 - sterge dupa sex" << endl;
			cin >> contor2;

			cout << endl << "1 - sterge din baza de date; 2 - sterge din sesiunea activa" << endl;
			int opt;
			cin >> opt;

			if (opt == 2) 
			{
				switch (contor2) 
				{

				case 1: {
					string nume;
					cout << "Introduceti numele dupa care doriti sa stergeti: ";cout << endl;
					cin >> nume;
					b.sterge(nume);
					break;
				}

				case 2: {
					int an_nastere;
					cout << "Introduceti anul nasterii dupa care doriti sa stergeti: ";cout << endl;
					cin >> an_nastere;
					b.sterge(an_nastere);
					break;
				}

				case 3: {
					char sex;
					cout << "Introduceti sexul dupa care doriti sa stergeti: ";cout << endl;
					cin >> sex;
					b.sterge(sex);
					break;
				}
				default: {
					cout << "Invalid!" << endl;
				}

				}
			}


			else if (opt == 1) 
			{
				ifstream file("baza_de_date.txt");

				if (file.is_open())
				{
					switch (contor2)
					{
					case 1: {
						string nume;
						cout << "Introduceti numele dupa care doriti sa stergeti: ";cout << endl;
						cin >> nume;
						string line;

						vector<string> intermediar;

						while (getline(file, line)) {
							intermediar.push_back(line);
						}

						ofstream fisier;
						fisier.open("baza_de_date.txt", ofstream::out);
						for (auto& it : intermediar) {
							size_t found = it.find(nume);
							if (found != string::npos)
								continue;
							else
								fisier << it << endl;
						}

						break;
					}


					case 2:
					{
						string an_nastere;
						cout << "Introduceti anul dupa care doriti sa stergeti: ";cout << endl;
						cin >> an_nastere;
						string line;

						vector<string> intermediar;

						while (getline(file, line)) {
							intermediar.push_back(line);
						}

						ofstream fisier;
						fisier.open("baza_de_date.txt", ofstream::out);
						for (auto& it : intermediar) {
							size_t found = it.find(an_nastere);
							if (found != string::npos)
								continue;
							else
								fisier << it << endl;
						}

						break;
					}

					case 3: {

						string _sex;
						string sex;
						cout << "Introduceti sexul dupa care doriti sa stergeti: ";cout << endl;
						cin >> sex;
						string line;

						_sex.append(" ");
						_sex.append(sex);

						vector<string> intermediar;

						while (getline(file, line)) {
							intermediar.push_back(line);
						}


						ofstream fisier;
						fisier.open("baza_de_date.txt", ofstream::out);
						for (auto& it : intermediar) {
							size_t found = it.find(_sex);
							if (found != string::npos)
								continue;
							else
								fisier << it << endl;
						}

						break;
					}

					default: {
						cout << "Invalid!" << endl;
					}

					}
				}

			}
		}
		else {
			int contor3;
			system("cls");
			cout << "Doriti sa salvati ce ati lucrat pana acum? 1 - da; 0 - nu" << endl;
			cin >> contor3;

			switch (contor3) {
			case 0: {
				cout << "Proces terminat" << endl;
				ok = false;
				break;
			}
			case 1: {
				b.salvare();
				ok = false;
				break;
			}
			default: {
				cout << "Invalid" << endl;
			}
			}
		}
	}

	cin.get();
	return 0;
}