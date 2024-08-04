#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	Date();
	Date(int year, int month, int day);
	Date(const Date& date);
	~Date();
	Date& operator = (const Date& date);
	Date* operator& ();
	static int Getcount();
	int Getday(int month, int day);
	bool Checkin(int year , int month , int day);
	bool operator<(Date& date);
	bool operator>(Date& date);
	Date& Calculate_Calendar(Date& date);
	int Getallday(int year);
	Date operator++(int);
	Date& operator++();
	Date operator--(int);
	Date& operator--();
	Date& operator+=(int day);
	int operator - (Date & date);
	Date& operator-=(int num);
	friend ostream& operator<<(ostream& out, Date& date);
	friend istream& operator>>(istream& in, Date& date);
private:
	int _year;
	int _month;
	int _day;
	static int count;
}; 
