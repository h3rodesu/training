#include<iostream>
#include<iomanip>
#include<memory>
#include<vector>
#include<list>
using namespace std;

class Car {
protected:
	int hp;
	string name;
public:
	Car(int horse, string naming) : name(naming), hp(horse) {}
	virtual void ShowCar() {
		cout << "Name: " << name << " Power: " << hp << endl;
}
	virtual~Car() {}
};

class Silvia : public Car {
private:
	string engine;
public:
	Silvia(string sname, int shorse, string dvig)
		:Car (shorse,sname), engine(dvig) {}
void ShowCar() override{
	Car::ShowCar();
	cout << "Engine: " << engine;
}
~Silvia() {}
};

struct Node {
private:
	shared_ptr<Car>CarPtr;
	shared_ptr<Node>next;
public:
	Node(shared_ptr<Car>cptr) : CarPtr(cptr), next(nullptr) {}
	~Node() {}
	friend void InsertAtEnd(shared_ptr<Node>& head, shared_ptr<Car>cptr);
	friend void ShowTrain(shared_ptr<Node> head);
//Прописать friend!!!
};
void InsertAtEnd(shared_ptr<Node>& head,shared_ptr<Car>cptr) {
	shared_ptr<Node>NewNode = make_shared<Node>(cptr);
	shared_ptr<Node>current = head;
	if (head == nullptr) {
		head = NewNode;
}
	else {
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = NewNode;
	}
}

void ShowTrain(shared_ptr<Node> head) {
	shared_ptr<Node>current = head;
	if (head == nullptr) {
		cout << "Пусто!" << endl;
	}
	else {
		while (current != nullptr) {
			cout << "Счетчик ссылок" << current->CarPtr.use_count() << endl;;
			current->CarPtr->ShowCar();
			current = current->next;
		}
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	list<shared_ptr<Car>>jdmList;//ВАЖНО-УМНЫЙ УКАЗАТЕЛЬ SHARED_PTR ЧТОБЫ МОЖНО БЫЛО ХРАНИТЬ КЛАСС СИЛЬВИЯ
	jdmList.push_back(make_shared<Silvia>("Silvia s13", 240, "RB26DET"));
	jdmList.push_back(make_shared<Car>(80,"Toyota Corolla"));


	cout << "Через список:" << endl;
	for (auto currentCar : jdmList) {//currentCar становится типа Car т.к.list<shared_ptr<Car>>jdmList
		currentCar->ShowCar();
	}
	cout << "Через вектор: " << endl;
	vector<shared_ptr<Car>>jdmVector;
	jdmVector.push_back(make_shared<Silvia>("Silvia s13", 240, "RB26DET"));
	jdmVector.push_back(make_shared<Car>(80, "Toyota Corolla"));

	for (auto currentCar : jdmVector) {//currentCar становится типа Car т.к.list<shared_ptr<Car>>jdmList
		currentCar->ShowCar();
	}
	system("Pause");
	return 0;
}