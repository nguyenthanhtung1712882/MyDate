#include"MyDate.h"

int main()
{
	MyDate date(8, 1, 2019);
	cout << date.countDate() << endl;
	cout << date + 12;
	cout << date.dayOfWeek() << endl;
	system("pause");
	return 0;
}