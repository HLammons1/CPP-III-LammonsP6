#include "TemplateSort.h"
#include <iostream>
#include <string>
#include "LammonsPersonGen/PersonGen.h"
#include "Functions.h"
#include <algorithm>

using namespace std;

//string stringArray[25000];


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

	string fileName = getFileName();

	readToArrayTemplate<int>("BJTest200K.txt", unsortedIntArray, INTARRAYSIZE);
	readToArrayTemplate<string>("BJName25000.txt", unsortedStringArray, STRINGARRAYSIZE);
	fillPersonArray(unsortedPersonArray, PERSONARRAYSIZE, pg);



	delete[] unsortedIntArray;
	delete[] unsortedStringArray;
	delete[] unsortedPersonArray;
	delete[] sortedIntArray;
	delete[] sortedStringArray;
	delete[] sortedPersonArray;

	return 0;
}

/*

- Use the chrono to �time� your sort functions. You�ll be reporting your sort time in SEC.MSEC and show the values beside it.  (This will double-check that you convert your values correctly.
- You�ll be sorting each type of array a total of 5 times.

You�ll need to create the first two arrays ( int and string) on the heap using the new operator, else you�ll end up with a stack overflow.

- For each of the five sorting calls, please print information to the screen to update the user as your program runs. Write the first 10 and last 10 unsorted values to the screen, call the sort, then write the first 10 and last 10 sorted values to the screen. You will not write the sorted value to the output file. Be sure your source code follows this scheme for each sort:

	//show the first and last 10 values of the array (call getName for the Person objects)
	//call to chrono
	//call to sort
	//call to chrono
	//show the first and last 10 values of the array

Sort the integer first and report the result in alphabetical order (by sort names). Then sort the strings, then sort the Persons.

Your output file should contain the following information.


Your name:

Number of integer values sorted by each routine: 200000
Number of string values sorted by each routine: 25000
Number of Persons sorted by each routine:  10000

Template Sort information for integers
Name of sort function: 		Elapsed time in secs.msec
	bubble sort				   sec.msec
	comb11 sort				    :
	insertion sort				    :
	selection sort				    :
	shaker sort				    :



Template Sort information for strings
Name of sort function: 		Elapsed time in secs.msec
	bubble sort				   sec.msec
	comb11 sort				    :
	insertion sort				    :
	selection sort				    :
	shaker sort				    :




Template Sort information for Persons
Name of sort function: 		Elapsed time in secs.msec
	bubble sort				   sec.msec
	comb11 sort				    :
	insertion sort				    :
	selection sort				    :
	shaker sort				    :



*/