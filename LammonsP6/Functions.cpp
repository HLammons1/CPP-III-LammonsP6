#include "Functions.h"



void writeFirstTenPerson(Person* a)
{
	for (size_t i{ 0 }; i < 10; ++i)
	{
		cout << i + 1 << ": " << a[i].GetName() << endl;
	}
}

void writeLastTenPerson(Person* a, size_t size)
{
	for (size_t i{ size - 1 }; i > size - 11; i--)
	{
		cout << i + 1 << ": " << a[i].GetName() << endl;
	}
}

void fillPersonArray(Person a[], size_t size, PersonGen* rPersonGen)
{
	for (int i{ 0 }; i < size; i++)
	{
		Person p = rPersonGen->GetPerson();
		a[i] = p;
	}
}

void readToArrayFunction(string file, int a[])
{
	fstream inputFile(file);
	if (!inputFile)
	{
		cout << "\r\nInput file not found." << endl;
	}

	int num;
	int count = 0;
	while (inputFile >> num)
	{
		a[count] = num;
		count++;
	}
}

string getFileName()
{
	string fileName;
	cout << "Please enter output file name (do not include extensions .txt will be used) : ";
	getline(cin, fileName);
	fileName += ".txt";
	return fileName;
}
