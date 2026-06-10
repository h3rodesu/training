#include<iostream>
#include<iomanip>
#include<memory>
using namespace std;
class Car {
protected:
	string name;
	int hp;
public:
	Car(int horses, string naming) : name(naming), hp(horses){}
	virtual void ShowCar() {
		cout << "Car: " << name << " Power: " << hp << endl;
	}

  virtual  ~Car(){}
};
class Silvia : public Car {
private:
	string engine;
public:
	Silvia(int hpower, string sname, string dvig)
		:Car(hpower, sname), engine(dvig) {
	}
	void ShowCar() override {
		Car::ShowCar();
		cout << " Engine: " << engine << endl;
	}
	~Silvia() {}
};

struct Node {
private:
	shared_ptr<Car>CarPtr;
	shared_ptr<Node> next;
public:
	Node(shared_ptr<Car> cptr) : CarPtr(cptr), next(nullptr) {}
	~Node() {}
	friend void InsertAtHead(shared_ptr<Node>& head, shared_ptr<Car>& cptr);
	friend void ShowTrain(shared_ptr<Node>head);
};
	void InsertAtHead(shared_ptr<Node>& head, shared_ptr<Car>& cptr) {
		shared_ptr<Node>NewNode = make_shared<Node>(cptr);//Здесь появляется ячейка,помечаю т.к. в main создаю указатель TrainHead 
		NewNode->next = head;
		head = NewNode;
	}
	void ShowTrain(shared_ptr<Node>head) {
		shared_ptr<Node>current=head;//без make_shared
		while (current != nullptr) {
			current->CarPtr->ShowCar();//обратить внимание

			cout << "Колличество ссылок:" << current->CarPtr.use_count()<<endl;//Здесь cout << "Колличество ссылок:"
			//<< current.use_count();т.к. нужен счетчик ссылок на объекты машин
			current = current->next;
		}
	}
	
int main() {
	setlocale(LC_ALL, "Russian");
	shared_ptr<Node>TrainHead = nullptr;//Указатель
	shared_ptr<Car>SilviaS13 = make_shared<Silvia>(240, "Silvia s13", "RB26DET");//Левая часть <Car>(т.к. инсертэтхед требует
	//УКАЗАТЕЛЬ класса Car),который указывает на сильвию,правая часть <Silvia>-создание ОБЪЕКТА
	shared_ptr<Car>stockCar = make_shared<Car>(80, "Toyota Corolla");
	InsertAtHead(TrainHead, SilviaS13);
	InsertAtHead(TrainHead, stockCar);
	ShowTrain(TrainHead);
	system("Pause");
	return 0;
}

