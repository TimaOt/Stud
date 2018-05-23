#include "student_.h"


student_::student_()
{
	name = "Nothing";
	sname = "Nothing";
	age = 0;
	marks = 0;
}

void student_::setAge(const int & age)
{
	this->age = age;
}

void student_::setName(const String_ & name)
{
	this->name = name;
}

void student_::setSname(const String_ & sname)
{
	this->sname = sname;
}


void student_::setMarks(const vector_ & marks)
{
	this->marks = marks;
}

int student_::getAge() const
{
	return age;
}

const String_ & student_::getName() const
{
	return name;
}

const String_ & student_::getSname() const
{
	return sname;
}

const vector_ & student_::getMarks() const
{
	return marks;
}

ostream & operator<<(ostream & out, const student_ & s)
{
	out << "Возрост студента:" << s.age;
	out << "Имя студента:" << s.name;
	out << "Фамилия студента:" << s.sname;
	out << "Оценка студента:" << s.marks;
	return out;
}

istream & operator>>(istream & in, const student_ & s)
{
	cout << "Введите имя студента:" << s.name;
	in >> s.getName;
	cout << "Введите фамилию студента:" << endl;
	in >> s.getSname;
	cout << "Введите возрост студента:" << endl;
	in >> s.getAge;
}
