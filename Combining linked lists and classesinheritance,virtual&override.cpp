
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

class Car {
protected:
	int  hp;
	string name;
	public:
		Car(int horse, string naming) :hp(horse), name(naming) {}
		virtual void ShowCar() {
			cout << " car: " << name << " Power; " << hp << endl;
		}
		virtual~Car() {}
};
class Silvia : public Car {
private:
	string engine;
public:
	Silvia(int power, string carName, string dvig)
		:Car(power, carName), engine(dvig) {}
	void ShowCar() override {
		Car::ShowCar();
		cout << " Engine: " << engine;
	}
	~Silvia() {}
};

struct Node {
	Car* CarPtr=nullptr;
	Node* next;Node* head = nullptr;
	Node(Car* ptr) :CarPtr(ptr), next(nullptr) {}
	~Node() {}
};
Node* head = nullptr;
void InsertAtEnd(Node*&head,Car*CarPtr) {
		Node* NewNode = new Node(CarPtr);
		Node* current = head;
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
	void ShowNode(Node* head) {
		Node* current=head;
		if (head == nullptr) {
			cout << "ШоуНод Пусто" << endl;

		}
		else {

			while (current != nullptr) {
				current->CarPtr->ShowCar();
				current = current->next;
			}
		}
	}
	void DeleteTrain(Node*&head) {
		Node* current = head;
		Node* nextNode;
		while (current != nullptr) {
			nextNode = current->next;
			delete current->CarPtr;//ЭТО ВАЖНО,ЧТОБЫ МУСОР ОТ ПЕРЕМЕННЫХ НЕ ОСТАВАЛСЯ
			delete current;
			current = nextNode;
			cout << "Список удален" << endl;
		}
	}
int main() {
	setlocale(LC_ALL, "Russian");
	vector<Car>garage;
	Node* head = nullptr;

	InsertAtEnd(head,new Car(80,"Toyota Corolla"));
	InsertAtEnd(head, new Silvia(140, "Silvia s13", "RB26DET"));
	
	ShowNode(head);
	DeleteTrain(head);
	system("Pause");
	return 0;

}