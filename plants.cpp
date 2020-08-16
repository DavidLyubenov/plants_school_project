#include <iostream>
#include <fstream>
#include<iomanip>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
class Plant
{	
	public:
		
	Plant(string name = "", string latinname = "", string location = "", string description = "", vector<string> continent = vector<string>()) : name(name), latinname(latinname), location(location), description(description), continent(continent) {}
    string Getname()
	{
		return this->name;
	}

	string Getlatinname()
	{
		return this->latinname;
	}

	string Getlocation()
	{
		return this->location;
	}

	string Getdescription()
	{
		return this->description;
	}

	vector<string>& Getcontinent() 
	{
		return this->continent;
	}
	  


//Plant(string name, string latinname, string location, string description, vector <string> p_continent);

	private:
		
	  string name;
      string latinname;
      string location;
      string description;
      vector <string> continent;

};

//Plant::Plant (string name,string latinname, string location, string description, vector <string> continent):
//name(name),latinname(latinname),location(location),description(description){}

int main()
{
Plant Rasteniya[8]{
	Plant("Venerina Myholovka", "Dionaea", "Shtata Severna Karolina", "Vid dvyzemedelno rastenie ot semeistvo Ryziankovi\n Edinstven predstavitel na rod Dionea", {"USA", "..."}),
	Plant("Nepentes Ampolaria", "Kariofilales","Borneo", "Stubloto moje da dostinge visochina do 15 metra\n Listata sa svetlo zeleni- dulgi do 25cm i shiroki do 6", {"Azia", "..."}),
	Plant("Drosera Capenis", "Drosera Capenis","Iujna Afrika", "Ima antenki dulgi do 4cm, koito sekretirat lepkava mokilaga,\n sus koyato hvashta antropodi", {"Africa", "..."}),
	Plant("Saracenya Purporeya", "Sarracenia purpurea","Shtata Virginia", "Suraceniite sa mnogodishni trevisti nasekomoyadni rasteniya\n Obrazyvaneto na kanichki zapochva na Prolet",{"USA", "..."}),
	Plant("Ytrikylariya", "utricullaria","Kitai", "Cvetyata sa edinstvenata chast koyato se vijda ot rastenieto,\n koeto inache e pokrito s pochva ili voda",{"Australia", "..."}),
	Plant("Sramejliva mimoza", "mimosa pudica","Brazil", "Izpolzva se s lechebni celi pri nervni razstroistva i bezsunie", {"Azia", "..."}),
	Plant("Rafleziya Arnoudi", "raffnesia arnoldii","Symatra", "Izvestno e s tova che formira nai-golemiyat edenichen cvyat na planetata", {"Australia", "..."}),
	Plant("Biblis", "byblis","Avstralia", "Cvetut na bibisa e s 5 izviti tichinki na rastoyanie do ednata strana na plodnika", {"Azia", "..."})
};
map<string, vector<unsigned short>> plants_continents; 
	for (unsigned short i = 0; i < 8; i++) 
	{
		for (vector<string>::iterator iter = Rasteniya[i].Getcontinent().begin(); iter != Rasteniya[i].Getcontinent().end(); iter++) 
		{
			if (plants_continents.find(*iter) == plants_continents.end()) 
			{
				plants_continents.insert(make_pair(*iter, vector<unsigned short>({ i }))); 
			}
			else
			{
				if (find(plants_continents.find(*iter)->second.begin(), plants_continents.find(*iter)->second.end(), i) == plants_continents.find(*iter)->second.end()) 
				{
					plants_continents.find(*iter)->second.push_back(i);
				}
			}
		}
	}
	bool exit_while = false;
	while (exit_while == false)
	{
		int choice = -1;
		cout << "Get info by:\n1) Name of plant\n2) Continent\n\n0) Exit\n\n"; 
		cin >> choice;
		while (choice >= 0 && choice <= 2)
		{
			if (choice == 1) 
			{
				choice = -1;
				while (choice < 0 || choice > 8)
				{
					cout << "\nChoose continent:\n";
					for (unsigned short i = 0; i < 8; i++)
					{
						cout << i + 1 << ") " << Rasteniya[i].Getname() << '\n';
					}
					cout << "\n0) Back\n\n";
					cin >> choice;
				}
				if (choice-- == 0) 
				{
					break;
				}
				cout << "\nContinent: " << Rasteniya[choice].Getname() << "\nLatin Name: " << Rasteniya[choice].Getlatinname() << "\nIs located in: " << Rasteniya[choice].Getlocation() << "\nDescription: " << Rasteniya[choice].Getdescription();
			}
			else if (choice == 2) 
			{
				choice = -1;
				while (choice < 0 && choice > plants_continents.size())
				{
					cout << "\nChoose song:\n"; 
					unsigned short n = 1;
					for (map<string, vector<unsigned short>>::iterator iter = plants_continents.begin(); iter != plants_continents.end(); iter++) 
					{
						cout << n++ << ") " << iter->first << '\n'; 
					}
					cout << "\n0) Back\n\n";
					cin >> choice;
				}
				if (choice == 0) 
				{
					break;
				}
				map<string, vector<unsigned short>>::iterator _iter = plants_continents.begin(); 
				for (unsigned short i = 0; i < choice - 1; i++)
				{
					_iter++;
				}
				cout << "Hishtni rasteniya jiveeshti na tozi koninent:\n";
				for (vector<unsigned short>::iterator iter = _iter->second.begin(); iter != _iter->second.end(); iter++) 
				{
					cout << Rasteniya[*iter].Getname() << '\n'; 
				}
			}
			else
			{
				exit_while = true;
			}
			choice = -1;
			cout << "\n\n";
		}
	}
	return 0;
  
}
