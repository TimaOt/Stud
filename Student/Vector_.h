#pragma once
#include <iostream>
using namespace std;
class vector_
{
	int *mas;
	int size;
public:
	vector_();
	vector_(const vector_&obj);
	vector_(int size, int val = 0);
	~vector_();
	vector_ &operator=(const vector_&obj);

	const int*data()const;
	void push_back(int a);
	void pop_back();
	void insert(int pos, int val);
	void print()const;
	bool isEmpty()const;
	int  getSize()const;
	void clear();
	void reverse();

	int& operator[](int pos)const { return mas[pos]; }
	vector_ &operator+=(const vector_&obj);

	friend vector_ operator-(const vector_ & obj);
	friend ostream& operator<<(ostream&os, const vector_&v);
	friend istream& operator >> (istream&is, vector_&v);

};

vector_ operator+(const vector_ &obj, const vector_ &obj2);
vector_ operator-(const vector_ &obj);

bool operator==(const vector_ &a, const vector_ &b);
bool operator!=(const vector_ &a, const vector_ &b);
bool operator>(const vector_ &a, const vector_ &b);
bool operator<(const vector_ &a, const vector_ &b);	