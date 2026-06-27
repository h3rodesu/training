	#include <iostream>
	#include<iomanip>
	#include<pqxx/pqxx>
	#include<string>
	#include<memory>
	using namespace std;
	int main() {
		setlocale(LC_ALL, "Russian");
		cout << "Введите имя пилота" << endl;
		string pilot_name;
		cin >> ws;
		getline(cin, pilot_name);
		cout << "Введите машину" << endl;
		string car_name;
		cin >> ws;
		getline(cin, car_name);
		cout << "Введите давление в турбине" << endl;
		int boost = 0;
		cin >> boost;
		setlocale(LC_ALL, ".UTF8");
		try {
			pqxx::connection connect("dbname=Least_Recently_Used_Cache user=postgres password=zxcursed1234 host=localhost port=5432");
			pqxx::work tx(connect);
			string query_table1 = "CREATE TABLE IF NOT EXISTS car(id SERIAL PRIMARY KEY,name VARCHAR(50),boost INT ) ";
			string query_table2 = "CREATE TABLE IF NOT EXISTS pilot(id SERIAL PRIMARY KEY, name VARCHAR (50),car_ref_id INT REFERENCES car(id))";
			tx.exec(query_table1);
			tx.exec(query_table2);
			string safe_pname = tx.quote(pilot_name);
			string safe_cname = tx.quote(car_name);
			string safe_boost = to_string(boost);
			string insert_car = "INSERT INTO car(name,boost)VALUES(" + safe_cname + "," + safe_boost + ") RETURNING id;";
			pqxx::result res = tx.exec(insert_car);
			int my_car_id = res[0][0].as<int>();//1 ячейка тоесть айди машины
			string insert_pilot = "INSERT INTO pilot(name,car_ref_id)VALUES(" + safe_pname + "," + to_string(my_car_id) + "); ";
			tx.exec(insert_pilot);
			string final_table = "SELECT p.name,c.name,c.boost FROM car c INNER JOIN pilot p ON p.car_ref_id=c.id WHERE c.boost>0";
			pqxx::result fres = tx.exec(final_table);
			for (const auto& row : fres) {
				cout << "Водитель: " << row[0].as<string>() << endl;
				cout << "Авто: " << row[1].as<string>() << endl;
				cout << "Наддув: " << row[2].as<string>() << endl;

			}
			tx.commit();
		}
		catch (const exception& e) {
			cout << "ВНИМАНИЕ! " << e.what() << endl;
		}
		system("Pause");
		return 0;
	}
	