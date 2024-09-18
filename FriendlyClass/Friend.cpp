#include <iostream>
#include <clocale>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Fears;
class Person
{
private:
	int age;
	string name;
	float mental_power;
public:
	Person(int age, string name, float mental_power)
	{
		this->age = age;
		this->name = name;
		this->mental_power = mental_power;
	}
	friend void check_mental(Person& person, Fears& fears);
};

class Fears
{
private:
	string name;
	bool is_dangerous;
public:
	Fears(string name, bool is_dangerous)
	{
		this->is_dangerous = is_dangerous;
		this->name = name;
	}
	friend void check_mental(Person& person, Fears& fears);
};

void check_mental(Person& person, Fears& fears)
{
	if(fears.is_dangerous && person.mental_power < 40)
	{
		cout << "Your character is weak. He has a low mental power " << person.mental_power << endl
		<< "He lose his control.";
	}
	else if ((fears.is_dangerous && person.mental_power > 40) || (!fears.is_dangerous))
	{
		cout << "Your character can win" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Person Dem(23, "Demdeis", 41);
	Fears noneName("__", true);

	check_mental(Dem, noneName);

	return 0;
}