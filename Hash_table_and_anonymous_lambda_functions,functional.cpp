#include<iostream>
#include<iomanip>
#include<unordered_map>
#include<functional>
#include <string>
using namespace std;

void UseNitro(string name, int power, function<int(int)>formula) {
	power = formula(power);
	cout << "Новые характеристики: " << name << power << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	unordered_map<string, int>Garrage;
	Garrage["Honda Civic"] = 200;
	Garrage["Toyota MarkII"] = 240;
	int NitroBal = 3;

	auto Nitro = [&](int power) {
		int up = power + 40;
		NitroBal -= 1;
		cout << "Осталось балонов: " << NitroBal;
		return up;
		};


	string choice;
	cout << "Введите название авто" << endl;
	cin >> ws;
	getline(cin, choice);

	auto it = Garrage.find(choice);
	if (it != Garrage.end()) {
		cout << "Характеристики" << endl;
		cout << "Car: " << it->first << " Power " << it->second << endl;
		UseNitro(it->first, it->second, Nitro);
	
	}
system("Pause");
return 0;                                                                                                                                             
}