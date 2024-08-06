#include"String.h"
String::String()
{	
	_str = new char[1];
	_str[0] = '\0';
	_size = strlen(_str);
	_capacity = _size + 1;
}
String::String(const char* str )
{	

	_size = strlen(str);
	_capacity = _size + 1;
	_str = new char[_capacity];
	strcpy(_str, str);

}
String::String(size_t n, char c)
{
	_size = n;
	_capacity = _size + 1;
	_str = new char[_capacity];
	for (size_t i = 0; i < _size; ++i)
	{
		_str[i] = c;
	}
	_str[_size] = '\0';
}
String::String(const String& str)
{

	_str = new char[str._capacity];
	_size = str._size;
	_capacity = str._capacity;
	strcpy(_str, str._str);
}
String::~String()
{
	_str = nullptr;
	_size = _capacity = 0;
	delete[]_str;
}
size_t String::size()const
{
	return _size;
}
size_t String::capacity()const
{
	return _capacity;
}
size_t String::length()const
{
	return _size;
}
size_t String::max_size()const
{
	return ((size_t)-1) >> 1;
}
void String::resize(size_t n)
{
	if (n <= _size)
	{
		_str[n] = '\0';
		_size = n;
	}
	else
	{
		_capacity = _capacity  + n;
		String s2(*this);
		delete[]_str;
		_str = new char[_capacity];
		strcpy(_str, s2._str);
		for (size_t i = _size; i < _capacity; ++i)
		{
			_str[i] = '\0';
		}

	}
}
void String::reserve(size_t n)
{
	if (n <= _size)
	{
		return;
	}
	else
	{
		_capacity = _capacity + n;
		String s2(*this);
		delete[]_str;
		_str = new char[_capacity];
		strcpy(_str, s2._str);
		for (size_t i = _size; i < _capacity; ++i)
		{
			_str[i] = '\0';
		}

	}
}
//void clear()
//{
//
//}
//bool empty()
//{
//
//}
//String& operator[](size_t pos)
//{
//
//}
ostream& operator<<(ostream& out, String& s)
{
	for (size_t i = 0; i < s._capacity ; ++i)
	{
		if (s._str[i] == '\0')
			break;
		else
		out << s._str[i];
	}
	return out;
}
