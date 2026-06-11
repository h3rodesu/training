#include<iostream>
#include<iomanip>
#include<vector>
#include <list>
using namespace std;

struct Node;//Указываем что структура Node БУДЕТ НИЖЕ В КОДЕ
using NodePtr = shared_ptr <Node>;
class Car {
protected:
	int hp;
	string name;
public:
	Car(int horse,string naming): name(naming),hp(horse){}
	virtual void ShowCar() {
		cout << "Name: " << name << " Power " << hp << endl;
	}
	virtual ~Car() {}
};

using Carptr = shared_ptr<Car>;//Псевдоним

class Silvia : public Car {
private:
	string engine;
public:
	Silvia(string sname, int shorse, string dvig)
		:Car(shorse,sname), engine(dvig) {}
	void ShowCar() override{
		Car::ShowCar();
		cout << "Engine: " << engine << endl;
	}
	~Silvia(){}
};
struct Node {
private:
	Carptr CarPtr;
	NodePtr next;
public:
	Node(shared_ptr<Car> cptr) : CarPtr(cptr), next(nullptr) {}
	~Node() {}
	friend void InsertAtEnd(NodePtr& head,Carptr cptr);
};
	void InsertAtEnd(NodePtr& head,Carptr cptr) {
		NodePtr NewNode = make_shared<Node>(cptr);
		auto current = head;
		if(head==nullptr){
		head = NewNode;
	}
	else {
			while (current->next != nullptr) {
				current = current->next;
			}
				current->next = NewNode;
			}
}
	int main() {
		setlocale(LC_ALL, "Russian");
		
		cout << "Через вектор:" << endl;
		vector<Carptr>carVector;
		carVector.push_back(make_shared<Car>(80, "Toyota Corolla"));
		carVector.push_back(make_shared<Silvia>("Silvia s13", 240, "RB26DET"));

		auto it = carVector.begin();
		while (it != carVector.end()) {
			(*it)->ShowCar();
			cout << "Счетчик ссылок: " << (*it).use_count() << endl;
			it++;
		}
		{
			cout << "Через список: " << endl;
			list<Carptr>carList;
			carList.push_back(make_shared<Car>(80, "Toyota Corolla"));
			carList.push_back(make_shared<Silvia>("Silvia s13", 240, "RB26DET"));

			auto it = carList.begin();
			while (it != carList.end()) {
				(*it)->ShowCar();
				cout << "Счетчик ссылок: " << (*it).use_count() << endl;
				it++;
			}
		}
		system("Pause");
		return 0;
		}