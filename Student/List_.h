#pragma once
#include <iostream>
using namespace std;


template<class T>
class elem_
{
public:
	T obj;
	elem_<T> *prev;
	elem_<T> *next;
};



template<class T>
class list_
{
	int size;
	elem_<T>*head;
	elem_<T>*tail;

public:
	list_() {//solomatin
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	void push_back(const T& obj)//solomatin
	{

		elem_<T>* newobj = new elem_<T>;
		newobj->obj = obj;
		newobj->next = nullptr;
		if (head == nullptr)
		{
			head = tail = newobj;
			newobj->prev = nullptr;
		}
		else
		{
			tail->next = newobj;
			newobj->prev = tail;
			tail = newobj;
		}
		size++;
	}
	void push_front(const T& obj) {
		if (head == nullptr)
			push_back(obj);
		else {
			elem_<T> *tmp = new elem_<T>;
			tmp->obj = obj;

			tmp->prev = nullptr;
			tmp->next = head;
			head->prev = tmp;
			head = tmp;
			size++;
		}
	}
	void pop_back()	//?o?oaiia
	{
		if (head == nullptr)
			return;
		if (size == 1)
		{
			size = 0;
			delete tail;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
			size--;
		}
	}
	void pop_front() {
		if (size <= 1)
			pop_back();
		else {
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			size--;
		}
	}
	~list_()	//?o?oaiia
	{
		while (head != nullptr)
		{
			elem_<T> *tmp = head;
			head = head->next;
			delete tmp;
		}
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	list_(const list_<T>& obj)
	{
		if (obj->head == nullptr)
		{
			size = 0;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			this->size = obj.size;
			elem_<T> *tmp = obj.head;
			for (int i = 0; i < obj.size - 1; i++)
			{
				push_back(tmp->obj);
				tmp = tmp->next;
			}
		}
	}
	list_<T>& operator=(const list_<T>&obj)
	{
		if (this == &obj)
			return *this;

		~list_();

		this->size = obj.size;
		elem_<T> *tmp = obj.head;
		for (int i = 0; i < obj.size - 1; i++)
		{
			push_back(tmp->obj);
			tmp = tmp->next;
		}
		return *this;
	}
	int getSize()const { return size; }
	bool isEmpty()const { return size == 0; }
	void clear() {
		this->~list_();
	}
	void insert(size_t pos, const T& obj)
	{
		if (pos == 0)
		{
			push_front(obj);
			return;
		}
		if (pos == size)
		{
			push_back(obj);
			return;
		}
		if (pos < size)
		{
			elem_<T> *posElem;
			if (pos < size / 2 + 1)
			{
				posElem = head;
				for (size_t i = 0; i < pos - 1; i++)
				{
					posElem = posElem->next;
				}

			}
			else
			{
				posElem = tail;
				for (size_t i = 0; i < size - pos; i++)
				{
					posElem = posElem->prev;
				}
			}
			elem_<T> *newElem = new elem_<T>;
			newElem->obj = obj;
			newElem->prev = posElem;
			newElem->next = posElem->next;
			posElem->next = newElem;
			newElem->next->prev = newElem;
			size++;
		}
	}
	void erase(int pos) {
		if (pos < 0 || pos >= size)
			return;
		if (pos == 0) {
			pop_front();
			return;
		}

		if (pos == size - 1) {
			pop_back();
			return;
		}

		elem_<T> *posElem;
		if (pos < size / 2) {
			posElem = head;
			for (size_t i = 0; i < pos; i++)
			{
				posElem = posElem->next;
			}

		}
		else {
			posElem = tail;
			for (size_t i = 0; i < size - pos - 1; i++)
			{
				posElem = posElem->prev;
			}
		}
		posElem->prev->next = posElem->next;
		posElem->next->prev = posElem->prev;
		delete posElem;
		size--;

	}
	template<class TT>
	friend ostream& operator<<(ostream&os, const list_<TT>&l);
};
template<class TT>
ostream& operator<<(ostream&os, const list_<TT>&l) {
	auto it = l.head;
	for (size_t i = 0; i < l.size; i++)
	{
		cout << it->obj << " ";
		it = it->next;
	}
	return os;
}