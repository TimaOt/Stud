#include "vector_.h"

vector_::vector_()
{
	size = 0;
	mas = nullptr;
}

vector_::vector_(const vector_ & obj)
{
	this->size = obj.size;
	if (size == 0)
	{
		mas = nullptr;
	}
	else
	{
		this->mas = new int[this->size];
		for (size_t i = 0; i < size; i++)
		{
			this->mas[i] = obj.mas[i];
		}
	}
}

vector_::vector_(int size, int val)
{
	if (size > 0)
	{
		this->size = size;
		mas = new int[size];

		for (int i = 0; i < size; i++)
			mas[i] = val;
	}
}

vector_::~vector_()
{
	delete[]mas;
}

vector_ & vector_::operator=(const vector_ & obj)
{
	if (&obj == this)
		return *this;
	this->clear();
	for (size_t i = 0; i < obj.size; i++)
	{
		this->push_back(obj.mas[i]);
	}
	return *this;
}

const int* vector_::data()const {
	return this->mas;
}

void vector_::push_back(int a)
{
	if (size == 0)
	{
		this->mas = new int[1];
		*mas = a;
		//mas[0] = a;
		size = 1;
	}
	else
	{
		int *tmp = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = mas[i];
		}
		delete[]mas;
		mas = tmp;
		mas[size] = a;
		size++;
	}
}

void vector_::pop_back()
{
	if (size == 0)return;

	if (size == 1) {
		delete[]mas;
		mas = nullptr;
		size = 0;
	}

	else {
		int *NewArray = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
			NewArray[i] = mas[i];
		}
		delete[]mas;
		mas = NewArray;
		size--;
	}



}

void vector_::insert(int pos, int val)
{
	if (pos >= 0 && pos < size)
	{
		int *tmp = new int[size + 1];
		for (int i = 0; i < pos; i++)
		{
			tmp[i] = this->mas[i];
		}
		tmp[pos] = val;
		for (int i = pos + 1; i <size + 1; i++)
		{
			tmp[i] = this->mas[i - 1];

		}
		delete[]mas;
		mas = tmp;
		size++;
	}

}

void vector_::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << this->mas[i] << " ";
	}
	cout << endl;
}

bool vector_::isEmpty() const
{
	return size == 0;
}

int  vector_::getSize() const
{
	return this->size;
}

void vector_::clear()
{
	if (this->size > 0) {
		delete[]mas;
		mas = nullptr;
		this->size = 0;
	}
}

void vector_::reverse()
{
	for (int i = 0; i < size / 2; i++)
		swap(mas[i], mas[size - 1 - i]);
}

vector_ & vector_::operator+=(const vector_ & obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		this->push_back(obj.mas[i]);
	}
	return *this;
}

ostream & operator<<(ostream & os, const vector_ & v)
{
	for (size_t i = 0; i < v.size; i++)
	{
		os << v.mas[i];
	}
	return os;
}

istream & operator >> (istream & is, vector_ & v)
{
	v.clear();
	cout << "Ââåäèòå ðàçìåð ìàññèâà\n";
	int cnt;
	is >> cnt;
	if (cnt > 0) {
		for (size_t i = 0; i < cnt; i++)
		{
			int x;
			is >> x;
			v.push_back(x);
		}
	}

	return is;
}

bool operator==(const vector_ & a, const vector_ & b)
{
	if (a.getSize() != b.getSize())
		return false;
	for (int i = 0; i < a.getSize(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

bool operator!=(const vector_ & a, const vector_ & b)
{
	return !(a == b);
}

bool operator>(const vector_ & a, const vector_ & b)
{
	return a.getSize() > b.getSize();


}
bool operator<(const vector_ & a, const vector_ & b)
{
	return a.getSize() < b.getSize();


}

vector_ operator-(const vector_ & obj)
{
	vector_ tmp(obj);
	for (size_t i = 0; i < obj.getSize(); i++)
	{
		tmp.mas[i] = -tmp.mas[i];
	}

	return tmp;
}

vector_ operator+(const vector_ & obj, const vector_ &obj2)
{
	return vector_(obj) += obj2;
}
