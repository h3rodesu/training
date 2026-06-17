#include<iostream>
#include<iomanip>
#include<memory>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	vector<string>Values;
	bool work = true;
	while (work == true) {
		int choice;
		cout << "Ввести значение-1,проверить значение-2,выйти из программы-3" << endl;
		cin >> choice;
		if (choice == 1) {
			string vvod;
			cout << "Введите слово без пробелов" << endl;
			cin >> vvod;
			Values.push_back(vvod);
		}
		else if (choice == 2) {
			unordered_map<string, vector<string>>Map;
			for (const string& word : Values) {//Переменная word для каждого объекта из Values
				string sorted_word = word;//Копия объекта для сортировки
				sort(sorted_word.begin(), sorted_word.end());//Сортировка от начала слова до конца того жеслова 
				//в алфовитном порядке в векторе Values
				Map[sorted_word].push_back(word);//Отсортированное в алфавитном порядке слово становится ключом
				//а несортированный ориганал слова-значением(Данными)во второй ячейке таблицы
			}
			for (auto it = Map.begin(); it != Map.end(); it++) {
				cout << "Key: " << it->first << " Value: " << endl;
				for (const string& obj : it->second) {
					cout << "Value: " << obj << endl;
				}
			}
		}
		else if (choice == 3) {
			work = false;
		}
	}
	system("Pause");
	return 0;
}
