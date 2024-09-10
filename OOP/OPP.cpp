#include<iostream>
#include<clocale>
#include<string>

using std::string;
using std::cout;
using std::endl;

class Person
{
public:
	string name;
	int age;
	bool isHappy; 
	string hobbies[3];

	void set_data(string name, int age, bool isHappy);
	void set_data(string name, int age);
	void set_hobby(string* p, int n);
	void get_hobby();
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Person alex, bob;
	alex.set_data("Alex", 23, true);

	bob.set_data("Bob", 25);
	string hobbies[] = {"skate", "paint", "football"};
	string* p = hobbies;
	bob.set_hobby(p, 3);

	cout << alex.name << endl << alex.age << endl << alex.isHappy << endl;
	cout << bob.name << endl << bob.age << endl;
	bob.get_hobby();

	Person* p_alex = &alex;
	cout << p_alex->name << endl;

	Person* max = new Person;
	max->isHappy = false;
	max->set_data("Max", 56);
	cout << max->name << endl;
	delete max;

	return 0;
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