#include "Dictionary.h"

Dictionary::Dictionary()
{
	Size = 0;
	haed = nullptr;
}

Dictionary::~Dictionary()
{
	while (Size)
	{
		pop_front();
	}
}

int Dictionary::getSize()
{
	return Size;
}


void Dictionary::pop_front()
{
	Node* temp = haed;
	haed = haed->next;
	delete temp;
	Size--;
}


void Dictionary::push_back(Data& a)
{
	Node* b = new Node(nullptr, a);

	if (haed == nullptr)
	{
		haed = b;
	}

	else
	{
		Node* current = this->haed;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = b;
	}

	Size++;
}



Dictionary::Node& Dictionary:: operator[](const int index)
{
	int counter = 0;
	Node* cut = this->haed;
	while (cut != nullptr)
	{
		if (counter == index)
		{
			return *cut;
		}
		cut = cut->next;
		counter++;
	}
	return *cut;
}


int Dictionary::FindSlovo(string word)
{
	Node* tem = haed;

	for (int i = 0; i < Size; i++)
	{
		if (tem->dat.getSlovo() == word)
		{
			return i;
		}

		tem = tem->next;
	}

	return -1;
}

void Dictionary::Print()
{
	Node* tem = haed;

	for (int i = 0; i < Size; i++)
	{
		cout << i + 1 << ". Слово: " << tem->dat.getSlovo() << "\t\tКоличество страниц: " << tem->dat.getNumber() << "\t\tГде встречаются: ";
		for (int j = 0; j < tem->dat.getNumber(); j++)
		{
			cout << tem->dat.getPage()[j] << " ";
		}
		cout << endl;
		tem = tem->next;
	}
}

void Dictionary::DeletElment(int n)
{

	if (n == 1)
	{
		pop_front();
		return;
	}

	if (n == Size)
	{
		Node* current = this->haed;
		for (int i = 0; i < n - 2; i++)
		{
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}

	if (n > 1 && n < Size)
	{
		Node* temp = haed;
		Node* befor = temp;
		Node* after = temp;
		for (int i = 0; i < n - 1; i++)
		{
			befor = temp;
			temp = temp->next;
			after = temp->next;
		}
		delete temp;
		befor->next = after;
	}
	Size--;
}