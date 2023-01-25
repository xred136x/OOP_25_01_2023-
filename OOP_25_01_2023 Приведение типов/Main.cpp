#include<iostream>
#include<string>
#include<vector>
// создать абстрактный класс , где 2-3 метода все абстрактные
// —оздать два наследника, которые переопредел€ют методы
// —оздать функцию, котора€ принимает в себ€ вектор
// ѕриведение типов

class IVehicle {
public:
	virtual void PrintName() {
		std::cout << "IVehicle" << '\n';
	}
	virtual int getSpeed() = 0;
		
	virtual ~IVehicle() {
		std::cout << "IVehicle delete\n";
	}

};

class Car : public IVehicle {
public:
	Car(int speed) : _speed(speed){}
	void PrintName() override {
		std::cout << "Car" << '\n';
	}
	int getSpeed() override {
		return _speed;
	}
	~Car() {
		std::cout << "Car destructor was called" << '\n';
	}
private:
	int _speed;
};

class Van : public IVehicle {
public:
	Van(int speed) : _speed(speed) {}
	void PrintName() override {
		std::cout << "Van" << '\n';
	}
	int getSpeed() override {
		return _speed;
	}
	~Van() {
		std::cout << "Van destructor was called" << '\n';
	}
private:
	int _speed;
};

void func(const std::vector<IVehicle*>& vehicle) {
	for (size_t i = 0; i < vehicle.size(); i++) {
		vehicle[i]->PrintName();
		std::cout << vehicle[i]->getSpeed() << '\n';
	}
}

// ѕриведение типов

class Parent {
public:
	virtual void sleep() {
		std::cout << "sleep()\n";
	}
};

class Child : public Parent {
public:
	void sleep() override {
		std::cout << "child sleep()\n";
	}
	void gotoSchool() {
		std::cout << "gotoSchool()\n";
	}
};

void Foo(Parent derived_obj) {
	std::cout << "Inside foo()\n";
	derived_obj.sleep();
}

int main() {

	/*IVehicle* a = new Car(100);
	IVehicle* b = new Van(200);
	std::vector<IVehicle*> vehicle;
	vehicle.push_back(a);
	vehicle.push_back(b);
	func(vehicle);
	delete a;
	delete b;*/

	Parent parent;
	Child child;

	int a = 5;
	double l = (double)a; // C-style приведение типа
	//double l = double(a);//


	// upcast - не€вное преобразование
	Parent* pParent = &child;

	// downcast - €вное преобразование
	Child* pCild = (Child*)&parent;// (Child *)Parent *

	pParent->sleep();
	pCild->sleep();

	Foo(*pParent);



	return 0;
}