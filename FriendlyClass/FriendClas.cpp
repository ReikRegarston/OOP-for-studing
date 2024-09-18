#include <iostream>
#include <clocale>
#include <string>

using std::cout;
using std::string;
using std::endl;

class ObDel;

class Humanity
{
private:
	int health = 100;
	friend class ObDel;
};

class ObDel
{
public:
	void damage(Humanity& humanity)
	{
		humanity.health -= 25;
	}
};

int main()
{
	setlocale(LC_ALL, "Rusiian");



	return 0;
}