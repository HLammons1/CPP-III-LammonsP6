#include "TemplateSort.h"
#include <iostream>


using namespace std;

int main()
{
	int example[] = {9, 12, 3, 20, 15, 23, 90, 1, 32, 45};
	string stringExample[] = { "here", "are", "ten", "words", "that", "need", "to", "be", "sorted", "quickly" };


	Sort<int> intSorter;
	Sort<string> stringSorter;
	stringSorter.Comb11(stringExample, 10);

	for (int i{ 0 }; i < 10; i++)
	{
		cout << stringExample[i] << " ";
	}
	//are be here need quickly sorted ten that to words

	return 0;
}