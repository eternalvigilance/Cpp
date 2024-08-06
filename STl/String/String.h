#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class String
{
public:
	static const size_t nops = -1;
	String();//Constructs an empty string, with a length of zero characters.
	String(const char* str );//Copies the null-terminated character sequence (C-string) pointed by s.
	String(size_t n , char c);//Fills the string with n consecutive copies of character c.
	String(const String& str);//Copyconstructor ,Constructs a copy of str.
	~String();//Destroys the String object.
	size_t size()const;
	size_t capacity()const;
	size_t length()const;
	size_t max_size()const;
	void resize(size_t n);
	void reserve(size_t n);
	void clear();
	bool empty();
	String& operator[](size_t pos);
	friend ostream& operator<<(ostream& out, String& s);



private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
