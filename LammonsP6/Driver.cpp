#include "TemplateSort.h"
#include <iostream>
#include <string>
#include "LammonsPersonGen/PersonGen.h"
#include "Functions.h"
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int* unsortedIntArray = new int[200000];
	string* unsortedStringArray = new string[25000];
	Person* unsortedPersonArray = new Person[10000];

	int* sortedIntArray = new int[200000];
	string* sortedStringArray = new string[25000];
	Person* sortedPersonArray = new Person[10000];

	const size_t INTARRAYSIZE{ 200000 };
	const size_t STRINGARRAYSIZE{ 25000 };
	const size_t PERSONARRAYSIZE{ 10000 };

	PersonGen* pg = new PersonGen;
	Sort<int> intSorter;
	Sort<string> stringSorter;
	Sort<Person> personSorter;
	string sortNames[] = { "BubbleSort", "Comb11", "InsertionSort", "Selection", "Shaker" };

	string headerString = "Hayden Lammons\nHLammons1@cnm.edu\nCIS 2277 C++ III\nLammonsP6 Template Sorts\n";
	cout << headerString << endl;

	string fileName = getFileName();
	writeToFile(fileName, headerString);
	stringstream sortInfo;

	sortInfo << "\r\nNumber of integer values sorted by each routine : 200000" << endl;
	sortInfo << "Number of string values sorted by each routine : 25000" << endl;
	sortInfo << "Number of Persons sorted by each routine : 10000\r\n" << endl;
	writeToFile(fileName, sortInfo.str());

	readToArrayTemplate<int>("BJTest200K.txt", unsortedIntArray, INTARRAYSIZE);
	readToArrayTemplate<string>("BJName25000.txt", unsortedStringArray, STRINGARRAYSIZE);
	fillPersonArray(unsortedPersonArray, PERSONARRAYSIZE, pg);

	std::copy(unsortedStringArray, unsortedStringArray + STRINGARRAYSIZE, sortedStringArray);
	std::copy(unsortedIntArray, unsortedIntArray + INTARRAYSIZE, sortedIntArray);
	std::copy(unsortedPersonArray, unsortedPersonArray + PERSONARRAYSIZE, sortedPersonArray);

	vector<function<void(int[], int)>> intSorts = vector<function<void(int[], int)>>{
	[&](int arr[], int total) { intSorter.BubbleSort(sortedIntArray, INTARRAYSIZE); },
	[&](int arr[], int total) { intSorter.Comb11(sortedIntArray, INTARRAYSIZE); },
	[&](int arr[], int total) { intSorter.Insertion(sortedIntArray, INTARRAYSIZE); },
	[&](int arr[], int total) { intSorter.Selection(sortedIntArray, INTARRAYSIZE); },
	[&](int arr[], int total) { intSorter.Shaker(sortedIntArray, INTARRAYSIZE); },
	};

	stringstream intSS;
	intSS << "\r\nTemplate Sort information for integers:" << endl;
	intSS << "|Name of sort function|    |Elapsed time in sec.millisec|" << endl;

	int count{ 0 };
	for (auto& sort : intSorts)
	{
		cout << "\r\nFirst ten ints:" << endl;
		writeFirstTen(sortedIntArray);
		cout << "\r\nLast ten ints:" << endl;
		writeLastTen(sortedIntArray, INTARRAYSIZE);
		cout << "Calling " << sortNames[count] << endl;
		auto start{ chrono::high_resolution_clock::now() };
		sort(sortedIntArray, INTARRAYSIZE);
		auto stop{ chrono::high_resolution_clock::now() };
		auto ms{ duration_cast<chrono::milliseconds>(stop - start).count() };
		cout << "\r\nFirst ten ints:" << endl;
		writeFirstTen(sortedIntArray);
		cout << "\r\nLast ten ints:" << endl;
		writeLastTen(sortedIntArray, INTARRAYSIZE);
		copy(unsortedIntArray, unsortedIntArray + INTARRAYSIZE, sortedIntArray);
		intSS << left << setw(20) << sortNames[count] << right << setw(20) << (ms / 1000.00) << endl;
		cout << sortNames[count] << " finished in " << (ms / 1000.00) << " seconds" << endl;
		count++;

	}
	cout << "\r\n" << intSS.str() << endl;
	writeToFile(fileName, intSS.str());
	count = 0;

	vector<function<void(string[], int)>> stringSorts = vector<function<void(string[], int)>>{
		[&](string arr[], int total) { stringSorter.BubbleSort(sortedStringArray, STRINGARRAYSIZE); },
		[&](string arr[], int total) { stringSorter.Comb11(sortedStringArray, STRINGARRAYSIZE); },
		[&](string arr[], int total) { stringSorter.Insertion(sortedStringArray, STRINGARRAYSIZE); },
		[&](string arr[], int total) { stringSorter.Selection(sortedStringArray, STRINGARRAYSIZE); },
		[&](string arr[], int total) { stringSorter.Shaker(sortedStringArray, STRINGARRAYSIZE); },
	};

	stringstream stringSS;
	stringSS << "\r\nTemplate Sort information for strings:" << endl;
	stringSS << "|Name of sort function|    |Elapsed time in sec.millisec|" << endl;

	for (auto& sort : stringSorts)
	{
		cout << "\r\nFirst ten strings:" << endl;
		writeFirstTen(sortedStringArray);
		cout << "\r\nLast ten strings:" << endl;
		writeLastTen(sortedStringArray, STRINGARRAYSIZE);
		cout << "Calling " << sortNames[count] << endl;
		auto start{ chrono::high_resolution_clock::now() };
		sort(sortedStringArray, STRINGARRAYSIZE);
		auto stop{ chrono::high_resolution_clock::now() };
		auto ms{ duration_cast<chrono::milliseconds>(stop - start).count() };
		cout << "\r\nFirst ten strings:" << endl;
		writeFirstTen(sortedStringArray);
		cout << "\r\nLast ten strings:" << endl;
		writeLastTen(sortedStringArray, STRINGARRAYSIZE);
		copy(unsortedStringArray, unsortedStringArray + STRINGARRAYSIZE, sortedStringArray);
		stringSS << left << setw(20) << sortNames[count] << right << setw(20) << (ms / 1000.00) << endl;
		cout << sortNames[count] << " finished in " << (ms / 1000.00) << " seconds" << endl;
		count++;

	}
	cout << "\r\n" << stringSS.str() << endl;
	writeToFile(fileName, stringSS.str());
	count = 0;

	vector<function<void(Person[], int)>> personSorts = vector<function<void(Person[], int)>>{
	[&](Person arr[], int total) { personSorter.BubbleSort(sortedPersonArray, PERSONARRAYSIZE); },
	[&](Person arr[], int total) { personSorter.Comb11(sortedPersonArray, PERSONARRAYSIZE); },
	[&](Person arr[], int total) { personSorter.Insertion(sortedPersonArray, PERSONARRAYSIZE); },
	[&](Person arr[], int total) { personSorter.Selection(sortedPersonArray, PERSONARRAYSIZE); },
	[&](Person arr[], int total) { personSorter.Shaker(sortedPersonArray, PERSONARRAYSIZE); },
	};

	stringstream personSS;
	personSS << "\r\nTemplate Sort information for Persons:" << endl;
	personSS << "|Name of sort function|    |Elapsed time in sec.millisec|" << endl;

	for (auto& sort : personSorts)
	{
		cout << "Calling " << sortNames[count] << endl;
		auto start{ chrono::high_resolution_clock::now() };
		sort(sortedPersonArray, PERSONARRAYSIZE);
		auto stop{ chrono::high_resolution_clock::now() };
		auto ms{ duration_cast<chrono::milliseconds>(stop - start).count() };
		copy(unsortedPersonArray, unsortedPersonArray + PERSONARRAYSIZE, sortedPersonArray);
		personSS << left << setw(20) << sortNames[count] << right << setw(20) << (ms / 1000.00) << endl;
		cout << sortNames[count] << " finished in " << (ms / 1000.00) << " seconds" << endl;
		count++;

	}
	cout << "\r\n" << personSS.str() << endl;
	writeToFile(fileName, personSS.str());
	count = 0;


	delete[] unsortedIntArray;
	delete[] unsortedStringArray;
	delete[] unsortedPersonArray;
	delete[] sortedIntArray;
	delete[] sortedStringArray;
	delete[] sortedPersonArray;

	return 0;
}