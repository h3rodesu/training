#include<iostream>
#include<iomanip>
#include<pqxx/pqxx>
#include<list>
#include<string>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	string car_name;
	cout << "Введите название" << endl;
	cin >> ws;
	getline(cin, car_name);
	int val = 0;
	cout << "Введите значение" << endl;
	cin >> val;;
	string owner_name;
	cout << "Введите имя владельца" << endl;
	cin >> ws;
	getline(cin, owner_name);
	int car_ref;
	cout << "ID машины" << endl;
	cin >> car_ref;
	
	
	try {
		pqxx::connection connect("dbname=Least_Recently_Used_Cache user=postgres password=zxcursed1234 host=localhost port=5432");
		pqxx::work tx(connect);
		string query_table1 = "CREATE TABLE IF NOT EXISTS test1(car_id SERIAL PRIMARY KEY, car_name VARCHAR(50)NOT NULL, value INT NOT NULL);";
		string query_table2 = "CREATE TABLE IF NOT EXISTS test2(owner_id SERIAL PRIMARY KEY,owner_name VARCHAR(50)NOT NULL,car_ref_id INT REFERENCES test1(car_id));";
		string safe_name = tx.quote(car_name);
		string safe_value = to_string(val);
		string safe_owner = tx.quote(owner_name);
		string safe_ref = to_string(car_ref);
		string table1 = "INSERT INTO test1 (car_name,value) VALUES (" + safe_name + "," + safe_value + ");";
		string table2 = "INSERT INTO test2(owner_name,car_ref_id)VALUES(" + safe_owner + "," + safe_ref + ");";
		cout << "Записано на диск" << endl;
		tx.exec(query_table1);
		tx.exec(table1);
		tx.exec(query_table2);
		tx.exec(table2);

		tx.commit();

		pqxx::work tx_read(connect);
		string query_join = "SELECT o.owner_name, t.car_name, t.value FROM test2 o INNER JOIN test1 t ON o.car_ref_id =t.car_id;";
		//Выше иннер джоин
		pqxx::result res=tx_read.exec(query_join);//Передаем в бд сшитую таблицу
		
		for (const auto&  row : res) {
			string pilot =row["owner_name"].as<string>();
			string car = row["car_name"].as<string>();
			int hp = row["value"].as<int>();
			cout << pilot << " " << car << " " << hp << "Power" << endl;
		}
		tx_read.commit();
	}

	catch (const exception& e) {
		cout << "ОШИБКА" << e.what() << endl;
	}
	system("Pause");
	return 0;
}