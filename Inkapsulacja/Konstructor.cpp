#include <iostream>
#include <string>
#include <clocale>

using std::cout;
using std::string;
using std::endl;

class Person
{
private:
	string name, type;
	int age;
	bool isHappy;

public:
	string hobbies[3];
	Person(){}
	Person(string name, int age, bool isHappy, string type);
	Person(string name, int age, bool isHappy, string* p, int n);

	void set_data(string name, int age, bool isHappy);
	void set_data(string name, int age);
	void set_hobby(string* p, int n);
	void get_hobby();
	void set_name(string name);
	void set_age(int age);
	void set_isHappy(bool isHappy);
	string get_name();
	bool get_isHappy();
	int get_age();

	Person& increase_age(int age)
	{
		this->age += age;
		return *this;
	}

	~Person()
	{
		cout << "Person " << name << " deleted" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Person alex = Person("Alex", 23, true, "player");
	
	string hobbies[] = { "skate", "paint", "football" };
	string* p = hobbies;
	Person bob = Person("Bob", 25, false, p, 3);
	cout << alex.get_name() << endl << alex.get_age() << endl << alex.get_isHappy() << endl;
	bob.increase_age(1).increase_age(5).increase_age(1);
	cout << bob.get_name() << endl << bob.get_age() << endl;
	bob.get_hobby();

	Person* p_alex = &alex;
	cout << p_alex->get_name() << endl;

	Person* max = new Person;
	bool notHappy = false;
	max->set_isHappy(notHappy);
	max->set_data("Max", 56);
	cout << max->get_name() << endl;
	delete max;

	return 0;
}

Person::Person(string name, int age, bool isHappy, string type)
{
	set_data(name, age, isHappy);
	this->type = type;
}

Person::Person(string name, int age, bool isHappy, string* p, int n)
{
	set_data(name, age, isHappy);
	set_hobby(p, n);
}

void Person::set_data(string name, int age, bool isHappy)
{
	this->name = name;
	this->age = age;
	this->isHappy = isHappy;
}

void Person::set_data(string name, int age)
{
	this->name = name;
	this->age = age;
}

void Person::set_hobby(string* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		hobbies[i] = *(p + i);
	}
}

void Person::get_hobby()
{
	for (int i = 0; i < 3; i++)
	{
		cout << hobbies[i] << endl;
	}
}

void Person::set_age(int age)
{
	if (age < 1)
		return;
}

void Person::set_name(string name)
{
	if (name == "")
		return;
}

void Person::set_isHappy(bool isHappy)
{
	if (isHappy == NULL)
		return;
}

string Person::get_name()
{
	return name;
}

int Person::get_age()
{
	return age;
}

bool Person::get_isHappy()
{
	return isHappy;
}