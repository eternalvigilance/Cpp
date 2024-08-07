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
String::iterator String::begain()
{
	return _str;
}
String::iterator String::end()
{
	return _str + _size;
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
		_size = strlen(_str);
		for (size_t i = _size; i < _capacity; ++i)
		{
			_str[i] = '\0';
		}

	}
}
void String::clear()
{
	_size = 0;
	_capacity = 0;
	_str[0] = '\0';
}
bool String::empty()
{
	if (_size = 0)
	{
		return true;
	}
	else
		return false;
}
char& String::operator[](size_t pos)
{
	return _str[pos];
}
void String::swap(String& str)
{
	String s2(*this);
	if (_size > str._size)
	{
		reserve(_size - str._size);
	}
	else
	{
		reserve(str._size - _size);
	}
	strcpy(_str, str._str);
	strcpy(str._str, s2._str);
	size_t size = _size;
	_size = str._size;
	str._size = size;
	size_t capacity = _capacity;
	_capacity = str._capacity;
	str._capacity = capacity;
}
String& String::operator+=(const char* str)
{
	size_t size = strlen(str);
	reserve(_size + size);
	strcpy(_str + _size, str);
	_size += size;
	return *this;
}
const char* String::c_str()const
{
	if (_str)
	{
		_str[_size] = '\0';
	}
	return _str;
}
size_t String::find(const char* str, size_t nps )
{
	iterator it_l = begain();
	size_t sit = 0;
	size_t i = 0;
	while (it_l != end())
	{
		while (str[i] == *it_l)
		{
			++i;
			++sit;
			++it_l;
			if (str[i] == '\0')
			{
				return sit - strlen(str + 1);
			}
			if (str[i] != *it_l)
			{
				i = 0;
			}
		}
		it_l++;
		sit++;
	}
	return 0;
}
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
istream& operator>>(istream& in, String& str)
{
	str.clear();
	char tmp_buffer[1024];
	in >> tmp_buffer;
	size_t size = strlen(tmp_buffer);
	str.reserve(size + 1);
	strcpy(str._str, tmp_buffer);
	str._size = size;
	return in;
}
