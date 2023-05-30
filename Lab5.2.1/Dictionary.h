#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Data.h"

using namespace std;

class Dictionary
{
private:
	class Node
	{
	public:
		Data dat;
		Node* next;

		Node(Node* ne = nullptr, Data d = Data())
		{
			next = ne;
			dat = d;
		}
	};

	Node* haed;
	int Size;

public:
	Dictionary();
	~Dictionary();
	int getSize();

	void pop_front();
	void push_back(Data& a);

	Node& operator[](const int index);

	int FindSlovo(string word);
	void Print();

	void DeletElment(int n);

};


