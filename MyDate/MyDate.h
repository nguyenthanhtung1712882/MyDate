#ifndef _MYDATE_H_
#define _MYDATE_H_

#include<iostream>
#include<string>
using namespace std;

const int MIN_YEAR = 1900;

class MyDate
{
private:
	int date, month, year;
	// day la thu Hai, Ba, Tu,...
	// date la ngay
public:
	MyDate();
	MyDate(int Date, int Month, int Year) :date(Date), month(Month), year(Year) {}
	
	int dateOfMonth(int month, int year);
	bool isValid();
	string toString();
	int countDate();    // so voi 31/12/1899
	MyDate dateAfter(int date = 1);
	MyDate dateBefore(int date = 1);
	string dayOfWeek();  // What day is today ?
	MyDate& operator=(const MyDate& md);
	MyDate& operator+(int date );
	friend int operator-(MyDate& md1, MyDate& md2);
	friend ostream& operator<<(ostream& outDev, MyDate md);
	friend istream& operator>>(istream& inDev, MyDate& md);
	~MyDate();
};

bool isLeap(int year);

#endif // !_MYDATE_H_



