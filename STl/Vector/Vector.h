#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		Vector();
		Vector(size_t size, const T& content);
		Vector(int size, const T& content);
		Vector(const Vector& V);
		~Vector();
		size_t size()const;
		size_t capacity()const;
		void reserve(size_t n);
		const T& operator[](size_t pos)const;
		T& operator[](size_t pos);

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;

	};
	template<class T>
	Vector<T>::Vector()
		:_start(nullptr),_finish(nullptr),_endofstorage(nullptr){}
	template<class T>
	Vector<T>::Vector(size_t size, const T& content )
		:_start(nullptr),_finish(nullptr),_endofstorage(nullptr)
	{
		reserve(size);
		size_t t_size = this->size();
		for (size_t i = 0;i < t_size ; i++)
		{
			_start[i] = content;
	
		}
	}
	template<class T>
	Vector<T>::Vector(int size, const T& content)
		: _start(new T[size])
		, _finish(_start + size)
		, _endofstorage(_finish)
	{
		size_t t_size = this->size();
		for (size_t i = 0; i < t_size; i++)
		{
			_start[i] = content;

		}
	}
	template<class T>
	Vector<T>::Vector(const Vector<T>& V)
		:_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
	{
		size_t t_size = V.size();
		reserve(V.capacity());
		for (size_t i = 0; i < t_size; i++)
		{
			_start[i] = V[i];
		}
		_finish = _start + t_size;
	}
	template<class T>
	Vector<T>::~Vector()
	{
		delete[]_start;
		_start = nullptr;
		_finish = nullptr;
		_endofstorage = nullptr;
	}
	template<class T>
	size_t Vector<T>::size()const
	{
		return (_finish - _start);
	}
	template<class T>
	size_t Vector<T>::capacity()const
	{
		return (_endofstorage - _start);
	}
	template<class T>
	void Vector<T>::reserve(size_t n)
	{
		if (n > capacity())
		{ 
			T* tmp = new T[n];
			size_t old_s = size();
			if (_start)
			{
				for (size_t i = 0; i < old_s; i++)	tmp[i] = _start[i];
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + old_s;
			_endofstorage = _start + n;
		}
	
	}
	template<class T>
	const T& Vector<T>::operator[](size_t pos)const
	{
		assert(pos < size());
		return _start[pos];
	}
	template<class T>
	T& Vector<T>::operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}
