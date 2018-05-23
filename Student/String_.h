#pragma once
#include <iostream>
using namespace std;

class String_
{
	char *str;
	int length;
public:
	String_();
	String_(const char*str);
	String_(const String_&obj);
	~String_();

	const char* data() const;
	void setStr(const char* str);
	int getLen() const;
	const char* c_str()const;

	String_ substr_(int ot, int kol)const;
	String_& operator=(const String_&obj);
	String_& operator=(const char *obj);
	const char& operator[](int index) const;
	void operator+=(const String_&obj);
};

ostream& operator<<(ostream &out, const String_ &obj);
istream& operator >> (istream &in, String_ &obj);

bool operator==(const String_ &obj1, const String_ &obj2);

