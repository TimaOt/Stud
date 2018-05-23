#pragma once
#include <iostream>
#include "String_.h"
#include "Vector_.h"
using namespace std;

class student_
{
	String_ name;
	String_ sname;
	int age;
	vector_ marks;
	int size;
	
public:
	student_();
	void setAge(const int&age);
	void setName(const String_&name);
	void setSname(const String_&sname);
	void setMarks(const vector_&marks);
	int getAge()const;
	const String_&getName()const;
	const String_&getSname()const;
	const vector_&getMarks()const;
	friend ostream& operator<<(ostream&out, const student_&s);
	friend istream& operator>>(istream&in, const student_&s);

};

