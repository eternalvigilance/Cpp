#pragma once
#include<iostream>
#include<list>
#include<algorithm>
#include<cassert>
using namespace std;
template <class T>
struct ListNode
{
	ListNode(const T& content = T())
		:_prev(nullptr)
		,_next(nullptr)
		,_content(content)
	{}
	ListNode<T>* _prev;
	ListNode<T>* _next;
	T _content;
};
template <class T, class Ref , class Ptr>
class ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
public:
	typedef Ref Ref;
	typedef Ptr Ptr;public:
	ListIterator(Node* node = nullptr)
		:_node(node)
	{}
	Ref operator*()
	{
		return _node->_content;
	}
	Ptr operator->()
	{
		return &(operator*());
	}
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	Self operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}
	bool operator!=(const Self& right)const
	{
		return _node != right._node;
	}
	bool operator ==(const Self& right)const
	{
		return _node == right._node;
	}
	Node* _node;
};
template<class Iterator>
class ReverseIterator
{
public:
	typedef typename Iterator::Ref Ref;
	typedef typename Iterator::Ptr Ptr;
	typedef typename ReverseIterator<Iterator> Self;
public:
	ReverseIterator(Iterator it)
		:_it(it)
	{}
	Ref operator*()
	{
		Iterator tmp(_it);
		--tmp;
		return *tmp;
	}
	Ptr operator->()
	{
		return &(operator*());
	}
	Self& operator++()
	{
		--_it;
		return *this;
	}
	Self operator++(int)
	{
		Iterator tmp(*this);
		tmp;
		--_it;
		return tmp;
	}
	Self& operator--()
	{
		++_it;
		return *this;
	}
	Self operator--(int)
	{
		Iterator tmp(*this);
		++_it;
		return tmp;

	}
	bool operator!=(const Self& RI)
	{
		return _it != RI._it;
	}
	bool operator==(const Self& RI)
	{
		return _it == RI._it;
	}
	Iterator _it;
};
template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	typedef ListIterator<T,T&,T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator;
	typedef ReverseIterator<const_iterator> const_reverse_iterator;
public:
	List()
	{
		Createhead();
	}
	List(int n , const T& content = T())
	{
		Createhead();
		for (int i = 0; i < n; ++i)
		{
			push_back(content);
		}
	}
	template<class Iterator>
	List(Iterator first, Iterator last)
	{
		Createhead();
		while (first != last)
		{
			push_bank(*first);
			++first;
		}
	}
	List(const List<T>& L)
	{
		Createhead();
		List<T> tmp(L.begin(), L.end());
		swap(tmp);
	}
	~List()
	{
		clear();
		delete[]_head;
		_head = nullptr;
	}
	void clear()
	{
		Node* current = _head->_next;
		while (current != _head)
		{
			_head->_next = current->_next;
			delete[]current;
			current = _head->_next;
		}
		_head->_next = _head->_prev = _head;
	}
	void swap(const List& tmp)
	{
		::swap(tmp);
	}
	iterator begin()
	{
		return iterator(_head->_next);
	}
	const_iterator begin()const
	{
		return const_iterator(_head->_next);
	}
	iterator end()
	{
		return iterator(_head);
	}
	const_iterator end()const
	{
		return const_iterator(_head);
	}
	void push_back(const T& content)
	{
		insert(end(), content);
	}
	iterator insert(iterator pos, const T& content)
	{
		Node* n_newnode = new Node(content);
		Node* n_node = pos._node;
		n_newnode->_next = n_node;
		n_newnode->_prev = n_node->_prev;
		n_node->_prev->_next = n_newnode;
		n_node->_prev = n_newnode;
		return iterator(n_newnode);

	}
private:
	void Createhead()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
private:
	Node* _head;
};
