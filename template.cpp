#include <iostream>
#include <string>

using namespace std;

template <typename T1>
T1 sum(T1 a, T1 b) {
	return a + b;
}

template <class T1, class T2>
T1 mul(T1 a, T2 b) {
	return a * (T1)b;
}

template <class T>
class Person {
private:
	string name;
	T height;
public:
	Person(string name, T height);
	void printAll();
	void setName(string name);
	void setHeight(T height);
};

template <class T>
Person<T>::Person(string name, T height) :name(name), height(height) {};

template <class T>
void Person<T>::printAll() {
	cout << "name : " << this->name << endl;
	cout << "height : " << this->height << endl;
};

template <class T>
void Person<T>::setName(string name) { this->name = name; };

template <class T>
void Person<T>::setHeight(T height) { this->height = height; };

int main() {
	int v1 = 10;
	int v2 = 20;
	Person<int> *person1 = new Person<int>("jamespark", 180);
	Person<double> *person2 = new Person<double>("jonson", 190.7);
	person1->printAll();
	person2->printAll();
	cout << sum<int>(v1, v2) << endl;
	cout << mul<double, int>(v1, v2) << endl;
	cout << "main" << endl;
}