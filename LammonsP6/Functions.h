#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <fstream>
#include <iostream>
#include "LammonsPersonGen/PersonGen.h"

using namespace std;


void fillPersonArray(Person a[], size_t size, PersonGen* rPersonGen);
void readToArrayFunction(string file, int a[]);
string getFileName();

//Only works with type int and type string
template <typename T>
void readToArrayTemplate(string file, T a[], size_t size) {
    try {
        fstream inputFile(file);
        if (!inputFile) {
            cout << "\r\nInput file not found." << endl;
            return;
        }

        T element;
        int count = 0;

        //constexpr makes the compiler evaluate the result at compile time. This means that when the program is
        //compiled and the template is called like this: readToArrayTemplate<int>("BJTest200K.txt", intArray);
        //the compiler will deduce the result and use the correct if branch without having to check the condition at runtime.
        //it is best practice to give the compiler as much information about the types as possible so it generates
        //the fastest implementation of the code.

        //https://en.cppreference.com/w/cpp/types/is_same
        //is_same_v is from <type_traits>, which is a set of classes that provide compile-time information about
        //types. These are often needed when working with templates.
        //is_same_v returns a constexpr bool depending on whether the types are the same. 
        //this function cannot work with Person because constexpr can only be used with builtin types.
        auto inputParser = [&](istream& inputStream) {
            if constexpr (is_same_v<T, string>) {
                getline(inputStream, element);
            }
            else {
                inputStream >> element;
            }
        };

        while (!inputFile.eof() && count < size) {
            inputParser(inputFile);
            a[count] = element;
            count++;
        }

        inputFile.close();
    }
    catch (exception e) {
        cout << e.what();
    }
}


//The below function does not work because the compiler does not have enough information
//at compile time and cannot generate the code for the template.
//From : https://www.simplilearn.com/tutorials/cpp-tutorial/templates-in-cpp
// "the type checking in C++ templates is done before template expansion. This allows the
//compiled code to have multiple copies of the same class."
//it seems to me that the compiler could not deduce what the type was beforehand, and therefore could
//not expand the code, resulting in a build error. This is because typeid is evaluated at runtime.

//Only works with arrays of type int, string, and person.
////////////// NON-WORKING VERSION OF TEMPLATE //////////////
//template <typename T> void readToArrayTemplate(string file, T a[])
//{
//	try
//	{
//		string testString;
//		int testInt;
//
//		fstream inputFile(file);
//		if (!inputFile)
//		{
//			cout << "\r\nInput file not found." << endl;
//			return;
//		}
//
//		T element;
//		int count = 0;
//
//		if (typeid(element) == typeid(testInt))
//		{
//			while (inputFile >> element)
//			{
//				a[count] = element;
//				count++;
//				inputFile.close();
//				return;
//			}
//		}
//		else if (typeid(element) == typeid(testString))
//		{
//			while (getline(inputFile, static_cast<std::string&>(element))) //|| !EOF)
//			{
//				a[count] = element;
//				count++;
//				inputFile.close();
//				return;
//			}
//		}
//		else
//		{
//			cout << "\r\nSomething went wrong, check your function call" << endl;
//			inputFile.close();
//		}
//	}
//	catch (exception e)
//	{
//		cout << e.what();
//	}
//}



#endif // !FUNCTIONS_H
