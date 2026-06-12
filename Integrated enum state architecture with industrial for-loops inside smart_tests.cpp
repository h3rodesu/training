#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
enum stage {
	stock,
	STAGE_1
};
class Car {
protected:
	int hp;
	std::string name;
	stage tuning;
public:
	Car(std::string naming, int horse,stage tun) : name(naming),hp(horse),tuning(tun) {}

	virtual void ShowCar() {
		std::cout << "Name: " << name << " Power: " << hp << std::endl;
		if (tuning == stock) {
			std::cout << " STOCK " << std::endl;
		}
		else if (tuning == STAGE_1) {
			std::cout << " STAGE_1 " << std::endl;
	}
	}
virtual~Car() {}
};
using CarPtr = std::shared_ptr<Car>;
class Silvia : public Car {
private:
	std::string engine;
public:
	Silvia(std::string sname, int horses,stage stune, std::string dvig) :
		Car(sname, horses,stune), engine(dvig) {}
	void ShowCar() override {
		Car::ShowCar();
		std::cout << "Engine: " << engine << std::endl;
	}
	~Silvia() {}
	using SilviaPtr = std::shared_ptr<Silvia>;
};
int main() {
setlocale(LC_ALL,"Russian");
	std::cout << "Через вектор: " << std::endl;
	std::vector<CarPtr>garrage;
	garrage.push_back(std::make_shared<Car>("Toyota Corolla", 80,stock));
	garrage.push_back(std::make_shared < Silvia>("Silvia s13", 240,STAGE_1 ,"RB26Det"));
	
	for (auto it = garrage.begin(); it != garrage.end();it++) {
		(*it)->ShowCar();
		std::cout << "Счетчик ссылок: " << (*it).use_count();
	}

	std::cout << "Через список: " << std::endl;
	std::list<CarPtr>CarList;
	CarList.push_back(std::make_shared<Car>("Toyota Corolla", 80,stock));
	CarList.push_back(std::make_shared<Silvia>("Silvia s13", 240,STAGE_1, "RB26Det"));
		for(auto it=CarList.begin();it!=CarList.end();it++){
			(*it)->ShowCar();
			std::cout << "Счетчик ссылок: " << (*it).use_count() << std::endl;
		}
	system("Pause");
	return 0;
}