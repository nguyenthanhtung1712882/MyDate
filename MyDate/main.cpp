#include"MyDate.h"

int main()
{
	MyDate date;
	string temp = "01/8/2019";
	cout << date.stringToDate(temp) << endl;
	
	/*cout << date.countDate() << endl;
	cout << date + 12;
	cout << date.dayOfWeek() << endl;*/
	system("pause");
	return 0;
}