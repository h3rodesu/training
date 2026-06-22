#include <iostream>
#include<iomanip>
#include<list>
#include<unordered_map>
#include<memory>
#include<string>


using namespace std;
class myHash {
	struct Node {
		string key;
		int value;
		Node(string k, int v) : key(k), value(v) {}
	};
	size_t razmer = 4;
	static const int bucket = 4;
	list<Node>Cache[bucket];
public:
	int getHash(const string& key) {
		int hashsum = 0;
		for (char c : key) {
			hashsum += c;
		}
		return hashsum % bucket;
	}
	void Insert(const string& key, const int& value) {
		int index = getHash(key);
		//Проеверить дубликаты
		for (auto& x : Cache[index]) {
			if (x.key == key) {
				x.value = value;
				return;
			}
		}
			Cache[index].push_front(Node(key, value));	
	}
	void remove(const string& key) {
		auto index = getHash(key);
		for (auto it = Cache[index].begin(); it != Cache[index].end();it++) {//Бегунок по спсику в списке
			if (it->key == key) {
				Cache[index].erase(it);
				cout << "Элемент под ключем " << key << " удалён" << endl;
				return;
			}
			else {
			cout<<"Элемент под ключом" << key << "не найден" << endl;
			}
		}
	}
	void search(const string& key) {
		auto index = getHash(key);
		for (auto it = Cache[index].begin(); it != Cache[index].end(); it++) {
			if (it->key == key) {
				cout << "По ключу " << it->key << endl;
				cout << "Результат " << it->value << endl; 
				return;
			}
		}
		cout << "Не найдено результатов по ключу" << key << endl;
	}
	~myHash() {}	
	};
int main() {
	setlocale(LC_ALL, "Russian");
	myHash Map;
	bool work = true;
	int choice;
	while (work == true) {
		cout << "1-Добавить элемент,2-найти элемент,3-удалить элемент,0-выход" << endl;
		cin >> choice;
		if (choice == 1) {
			string key;
			cout << "key:" << endl;
			cin >> ws;
			getline(cin, key);
			int value;
			cout << "value" << endl;
			cin >> value;
			Map.Insert(key, value);
		}
		else if (choice == 2) {
			string find;
			cout << "key:" << endl;
			cin >> ws;
			getline(cin, find);
			Map.search(find);
		}
		else if (choice == 3) {
			string del;
			cout << "key" << endl;
			cin >> ws;
			getline(cin, del);
			Map.remove(del);
		}
		else if (choice == 0) {
			work = false;
		}
	}
	system("Pause");
	return 0;
} 