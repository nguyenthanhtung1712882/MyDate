#include "MyDate.h"



MyDate::MyDate()
{
}


bool isLeap(int year)
{
	if (year % 4 != 0)
		return false;
	else if (year % 400 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else
		return true;
}

bool MyDate::isValid()
{ 
	if (this->year<0 || this->year>INT_MAX)
		return false;
	if (this->month < 1 || this->month>12)
		return false;
	if (this->date < 1 || this->date>31)
		return false;
	switch (this->month)
	{
	case 1:return true;
	case 2:
		if (isLeap(this->year) == true)return this->date <= 29;
		else return this->date <= 28;
	case 3:return true;
	case 4:return this->date < 31;
	case 5:return true;
	case 6:return this->date < 31;
	case 7:return true;
	case 8:return true;
	case 9:return this->date < 31;
	case 10:return true;
	case 11:return this->date < 31;
	case 12:return true;
	default:
		break;
	}
	return false;
}

string MyDate::toString()
{
	string stringDate;
	if (this->date < 10)stringDate.append("0");
	stringDate.append(to_string(this->date));
	stringDate.append("/");
	if (this->month < 10)stringDate.append("0");
	stringDate.append(to_string(this->month));
	stringDate.append("/");
	stringDate.append(to_string(this->year));
	return stringDate;
}

int MyDate::dateOfMonth(int month,int year)
{
	switch (month)
	{
	case 1:return 31;
	case 2:
		if (isLeap(year) == true)return 29;
		else return 28;
	case 3:return 31;
	case 4:return 30;
	case 5:return 31;
	case 6:return 30;
	case 7:return 31;
	case 8:return 31;
	case 9:return 30;
	case 10:return 31;
	case 11:return 30;
	case 12:return 31;
	default:
		break;
	}
}

int MyDate::countDate()
{
	int date = 0;
	if (this->year >= 2000)
	{
		for (int i = 2000; i < this->year; i++)
		{
			if (isLeap(i) == true)
				date += 366;
			else date += 365;
		}
		for (int i = 1; i < this->month; i++)
		{
			date += dateOfMonth(i, this->year);
		}
		date += this->date;
	}
	return date;
}

MyDate MyDate::dateAfter(int date)
{
	MyDate md;
	md.year = 2000;
	md.month = 1;
	date += this->countDate();
	while (date > 365)
	{
		if (isLeap(md.year) == true)date -= 366;
		else date -= 365;
		md.year++;
	}
	while (date > dateOfMonth(md.month, md.year))
	{
		date -= dateOfMonth(md.month,md.year);
		md.month++;
	}
	md.date = date;
	return MyDate(md);
}

MyDate MyDate::dateBefore(int date)
{
	MyDate md;
	md.year = 2000;
	md.month = 1;
	date = this->countDate() - date;
	while (date > 365)
	{
		if (isLeap(md.year) == true)date -= 366;
		else date -= 365;
		md.year++;
	}
	while (date > dateOfMonth(md.month, md.year))
	{
		date -= dateOfMonth(md.month, md.year);
		md.month++;
	}
	md.date = date;
	return MyDate(md);
}

string MyDate::dayOfWeek()
{
	// 01/01/2000 Saturday => 31/12/1999 Friday
	int day = this->countDate() % 7 - 1;
	switch (day)
	{
	case 0:return "Saturday";
	case 1:return "Sunday";
	case 2:return "Monday";
	case 3:return "Tuesday";
	case 4:return "Wednesday";
	case 5:return "Thursday";
	case 6:return "Friday";
	default:
		break;
	}
}



MyDate & MyDate::operator=(const MyDate & md)
{
	this->date = md.date;
	this->month = md.month;
	this->year = md.year;
	return *this;
	// TODO: insert return statement here
}

MyDate & MyDate::operator+(int date)
{
	*this = this->dateAfter(date);
	return *this;
	// TODO: insert return statement here
}


MyDate::~MyDate()
{
}

int operator-(MyDate & md1, MyDate & md2)
{
	return abs(md1.countDate()-md2.countDate());
}

ostream & operator<<(ostream & outDev, MyDate md)
{
	if (md.date < 10)outDev << "0";
	outDev << md.date << "/";
	if (md.month < 10)outDev << "0";
	outDev << md.month << "/";
	outDev << md.year;
	return outDev;
	// TODO: insert return statement here
}

istream & operator>>(istream & inDev, MyDate & md)
{
	do {
		cout << "Nhap ngay : ";
		inDev >> md.date;
		cout << "Nhap thang : ";
		inDev >> md.month;
		cout << "Nhap nam : ";
		inDev >> md.year;
		if (md.isValid() == true)break;
		else cout << "Thoi gian khong hop le. Nhap lai." << endl;
	} while (1);
	return inDev;
	// TODO: insert return statement here
}
