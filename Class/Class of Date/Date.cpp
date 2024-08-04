#include"date.h"
Date::Date()
	:_year(2020), _month(1), _day(1)
{
	count++;
}
Date::Date(int year, int month, int day)
	:_year(year),_month(month),_day(day)
{
	count++;
}
Date::Date(const Date& date)
{
	this->_year = date._year;
	this->_month = date._month;
	this->_day = date._day;
	count++;
}
Date::~Date()
{
	this->_year = 2020;
	this->_month = 1;
	this->_day = 1;
	count--;
}
Date& Date::operator=(const Date& R_date)
{
	if (&R_date != this)
	{
		this->_year = R_date._year;
		this->_month = R_date._month;
		this->_day = R_date._day;
	}

	return *this;
}
Date* Date::operator&()
{
	return this;
}
int Date::Getcount()
{
	return Date::count;
}
int Date::Getday(const int year, const int month)
{
	if (month <= 12)
	{
		int Monthday[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return Monthday[month - 1];
	}
	else
		cout << "illegal date" << endl;
}
bool Date::Checkin(int year ,int month, int day)
{
	if (month <= 12 && day <= Getday(year, month) && _year > 0)
	{
		return true;
	}
	else
		cout << "invalid date" << endl;
		return false;
}
bool Date::operator<(Date& date)
{
	if (Checkin(_year, _month, _day))
	{
		if (_year < date._year)
		{
			return true;
		}
		else if (_year == date._year && _month < date._month)
		{
			return true;
		}
		else if (_year == date._year && _month == date._month && _year < date._day)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
bool Date::operator>(Date& date)
{
	if (Checkin(_year, _month, _day))
	{
		if (_year > date._year)
		{
			return true;
		}
		else if (_year == date._year && _month > date._month)
		{
			return true;
		}
		else if (_year == date._year && _month == date._month && _year > date._day)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
Date& Date::Calculate_Calendar(Date& date)
{
	int maxday = Getday(_year, _month);
	if (_day > maxday)
	{
		_day = _day - maxday;
		++_month;
		if (_month == 13)
		{
			_month = 1;
			++_year;
		}
	}
	if (_day < 1)
	{
		if (_month == 1)
		{
			_month = 13;
		}
		_day = Getday(_year,_month - 1) + _day;
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
	}
	//if (&date == this)
	//{
	//	cout << "fuck" << endl;
	//}
	if (_month < 1)
	{
		_month += 12;
		--_year;
	}
	return date;
}
int Date::Getallday(int year)
{
	int common_year = 0;
	int leap_year = 0;
	if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		++leap_year;
	}
	common_year = year - leap_year;
	
	//retrun_year * 365 + leap_year;
	return ((common_year * 365) + (leap_year * 366));
}
Date Date::operator++(int)
{
	Date tmp(*this);
	if (Checkin(_year, _month, _day))
	{
		++_day;
		Calculate_Calendar(*this);
	}
	return tmp;
}
Date& Date::operator++()
{
	if (Checkin(_year, _month, _day))
	{
		++_day;
		Calculate_Calendar(*this);
	}
	return *this;
}
Date Date::operator--(int)
{
	Date tmp(*this);
	if (Checkin(_year, _month, _day))
	{
		--_day;
		Calculate_Calendar(*this);
	}
	return tmp;
}
Date& Date::operator--()
{
	if (Checkin(_year, _month, _day))
	{
		--_day;
		Calculate_Calendar(*this);
	}
	return *this;
}
Date& Date::operator+=(int day)
{
	if (Checkin(_year, _month, _day))
	{
		_day+=day;
		Calculate_Calendar(*this);
	}
	return *this;
}
int Date::operator-(Date& date)
{
	if (Checkin(_year, _month, _day))
	{
		if (*this > date)
		{
			return (Getallday(this->_year) - Getallday(date._year));
		}
		else
			return 0;
	}
	else
		return 0;
}
Date& Date::operator-=(int num)
{
	if (Checkin(_year, _month, _day))
	{
		_day-=num;
		Calculate_Calendar(*this);
	}
	return *this;
}
ostream& operator<<(ostream& out, Date& date)
{
	out << date._year << "-" << date._month << "-" << date._day;
	return out;
}
istream& operator>>(istream& in, Date& date)
{
	in >> date._year;
	in >> date._month;
	in >> date._day;
	if (date.Checkin(date._year , date._month , date._day))
	{
		return in;
	}
	else
	{
		cout << "Illegal date , please input again" << endl;
		return in;
	}


}
