#include "Group_.h"

group_::group_()
{
	
}

void group_::setGroupName(const group_ & name)
{
	this->groupname = name;
}

const String_ & group_::getGroupName() const
{
	return groupName;
}

void group_::addStudent(const student_ & s)
{
	student.push_back(s);
}
