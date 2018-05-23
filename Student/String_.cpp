#include "String_.h"


String_::String_(const String_ & obj)
{
	if (obj.length == 0)
	{
		this->length = 0;
		this->str = nullptr;
	}
	else
	{

		this->str = new char[obj.length + 1];
		strcpy_s(this->str, obj.length + 1, obj.str);
		this->length = obj.length;

	}

}

String_::String_()
{
	length = 0;
	str = nullptr;
}

String_::String_(const char *str)
{
	if (str != nullptr)
	{
		this->length = strlen(str);
		this->str = new char[length + 1];
		strcpy_s(this->str, this->length + 1, str);
	}
	else
	{
		this->length = 0;
		this->str = nullptr;
	}
}


String_::~String_()
{
	if (str != nullptr)
		delete[]this->str;
	this->str = nullptr;
	this->length = 0;
}

const char* String_::data() const
{
	return str;
}

void String_::setStr(const char * str)
{
	if (this->str != nullptr)
		delete[]this->str;

	if (str != nullptr)
	{
		this->length = strlen(str);

		this->str = new char[length + 1];
		strcpy_s(this->str, length + 1, str);
	}
	else
	{
		this->str = nullptr;
		this->length = 0;
	}
}

void String_::operator+=(const String_ & obj)
{
	if (this->str == nullptr) {
		this->setStr(obj.str);
	}
	else if (obj.str != nullptr)
	{
		char* n = new char[obj.length + this->length + 1];

		this->length += obj.length;
		strcpy_s(n, this->length + 1, this->str);
		strcat_s(n, this->length + 1, obj.str);

		delete[]this->str;
		str = n;

	}
}

int String_::getLen() const
{
	return length;
}

const char * String_::c_str() const
{
	return this->str;
}

String_  String_::substr_(int ot, int kol) const
{

	if (this->str == nullptr || ot + kol>this->length || ot<0 || kol<0)
	{
		return String_();
	}

	char  *tmp = new char[kol + 1];

	for (int i = ot; i < ot + kol; i++)
	{
		tmp[i - ot] = this->str[i];
	}
	tmp[kol] = '\0';
	String_ s(tmp);

	return s;
}

String_ & String_::operator=(const String_ & obj)
{

	//защита от самоприсваивания
	if (this == &obj)
		return *this;

	if (this->str != nullptr)
		delete[]this->str;

	this->length = 0;
	this->str = nullptr;

	if (obj.length != 0) {
		str = new char[obj.length + 1];
		length = obj.length;
		strcpy_s(str, length + 1, obj.str);
	}

	return *this;
}

String_ & String_::operator=(const char * obj)
{
	return this->operator=(String_(obj));
}

const char & String_::operator[](int index)const
{
	if (index >= 0 && index < length)
		return str[index];
	return NULL;
}

ostream & operator<<(ostream & out, const String_ &obj)
{
	if (obj.data() != nullptr)
		out << obj.data();

	return out;
}

istream & operator >> (istream & in, String_ & obj)
{
	char tmp[1000];
	in.getline(tmp, 1000);
	obj.setStr(tmp);

	return in;
}

bool operator==(const String_ & obj1, const String_ & obj2)
{
	if (obj1 == obj2)
		return true;

	if (obj1.getLen() != obj2.getLen())
		return false;

	for (int i = 0; i < obj1.getLen(); i++)
		if (obj1[i] != obj2[i])
			return false;

	return true;
}
