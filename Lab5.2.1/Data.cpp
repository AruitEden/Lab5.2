#include "Data.h"

Data::Data()
{
	slovo = "";
	number = 0;
};

Data::Data(string w, int n, int* p)
{
	slovo = w;
	number = n;
	for (int i = 0; i < 10; i++)
	{
		page[i] = p[i];
	}
}


string Data::getSlovo()
{
	return slovo;
};

void Data::setSlovo(string w)
{
	slovo = w;
}

int Data::getNumber()
{
	return number;
};

void Data::setNumber(int n)
{
	number = n;
}

int* Data::getPage()
{
	return page;
}

void Data::setPage(const int index, int p)
{
	page[index] = p;
}


istream& operator >> (istream& f, Data& d)
{
	f >> d.slovo;
	f >> d.number;
	for (int i = 0; i < d.number; i++)
	{
		f >> d.page[i];
		f.ignore(1);
	}
	return f;
}
