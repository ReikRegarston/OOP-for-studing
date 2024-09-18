#include<iostream>
#include<clocale>
#include<string>

using std::cout;
using std::endl;

class MyString
{
private:
	size_t size;
	char* text;

public:
	MyString(char* text);
	~MyString();
	void get_text();
};

MyString::MyString(char* text)
{
	size = strlen(text) + 1;
	this->text = new char[size];

	strcpy_s(this->text, size, text);
}

MyString::~MyString()
{
	delete[] text;
}

void MyString::get_text()
{
	cout << text << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	char some[] = "Hello";
	MyString str(some);
	str.get_text();

	return 0;
}