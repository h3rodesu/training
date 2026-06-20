#include<iostream>
#include<iomanip>
#include<unordered_map>
#include<string>
using namespace std;
class myHash{
	struct Node {
		string key;
		string value;
		Node(string kl, string val) : key(kl), value(val) {}
	};
public:
	static const int bucket=10;
	list<Node>table[bucket];
	int getHash(const string& key) {
		int hashsum = 0;
		for (char c : key) {
			hashsum +=c;
		}
		return hashsum % bucket;
	}
		//Проверка дубликатов
	void Insert(const string&key,const string&value){
		int index = getHash(key);
		for (auto& x : table[index]) {
			if (x.key == key) {
				x.value = value;
				return;
			}
		}
		table[index].push_back(Node(key, value));
	}
	void search(const string& key) {
		auto index = getHash(key);
		for (auto x : table[index]){
			if (x.key == key) {
				cout << "По ключу" << x.key << " Результат: " << x.value << endl;
				return;
			}
			else {
				cout << "Результатов не найдено" << endl;
			}
	}
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	myHash Map;
	bool work = true;
	int choice;
	while (work == true) {
		cout << "1-put,2=get,3-exit" << endl;
		cin >> choice;
		if (choice == 1) {
		string key;
		cout << "Введите ключ" << endl;
		cin >> ws;
		getline(cin, key);
		string value;
		cout << "Введите данные" << endl;
		cin >> ws;
		getline(cin, value);
		Map.getHash(key);
		Map.Insert(key, value);
	}
		else if (choice == 2) {
				string find;
				cout << "Key: " << endl;
				cin >> ws;
				getline(cin, find);
				Map.search(find);
			}
			else 
				if (choice == 3) {
					work = false;
				}
			}
	system("Pause");
	return 0;
}
