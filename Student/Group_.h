#pragma once
#include "List_.h"
#include "student_.h"

class group_
{
	list_<student_> student;
	String_ groupname;
public:
	group_();
	void setGroupName(const group_&name);
	const String_ &getGroupName()const;
	void addStudent(const student_&s);
};

