//Hayden Lammons
//HLammons1@cnm.edu
//LammonsP1

//Person.h

#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include "Date.h"
#include <sstream>
using namespace std;

class  Person
{
	private:
		string name;
		int age{0};
		Date bday;
		string first;
		string last;
	public:
		Person()= default;		//default constructor		
		Person(string p, Date d);
		Person(string p, int m, int d, int y);		

		//Setters
		void SetName(string n){ name = n;}
		void SetBirthday(Date d);
		void SetBirthday(int m, int d, int y);

		//Getters
		string GetName(){return last + ", " + first; }
		string GetNameAge();
		string GetFullDesc();
		Date GetBirthDay();

		//overloaded operators
		bool operator < (Person p);
		bool operator > (Person p);
};
#endif
