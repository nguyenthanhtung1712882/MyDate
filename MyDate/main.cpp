#include"MyDate.h"

int main()
{
	MyDate date(7, 1, 2019);
	cout << date.countDate() << endl;
	cout << date + 1;
	cout << date << endl;
	system("pause");
	return 0;
}