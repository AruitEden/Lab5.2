#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Data
{
private:
	string slovo;
	int number;
	int page[10]{};

public:

	Data();
	Data(string w, int n, int* p);

	string getSlovo();
	void setSlovo(string w);

	int getNumber();
	void setNumber(int n);

	int* getPage();
	void setPage(const int index, int p);

	friend istream& operator >> (istream& f, Data& d);
};

