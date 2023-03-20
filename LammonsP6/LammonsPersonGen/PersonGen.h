//PersonGen.h
//This is the Person Generator class definition.
//CIS2277, Program 2

#ifndef  _PERSONGEN_H
#define  _PERSONGEN_H

#include <string>
#include "Person.h"
#include <fstream>
#include <random>
#include <string>

class PersonGen
{
private:
	default_random_engine engine;
	fstream input1;
	string firstFemale[300];
	string firstMale[300];
	string Last[300];
	string firstName;
	string lastName;
	Date readFileBirthday;
	string useFileName;
	int youngAge{ 4 };
	int oldAge{ 85 };
	int fileCount{ 0 };
	int lineRead{ 0 };
	bool bNameFileRead{ false };
	bool bUseFile{ false };

	void ReadFile();
	string NameGen();
	void ReadUseFile();
	Date BirthdayGen();

public:
	//default creation, alternate male, female, age range toddler to elderly
	PersonGen();	

	//overloaded constructor, specify age range of persons
	PersonGen( int youngAge, int oldAge);	

	//returns a Person object, created locally in class, not using new
	Person GetPerson();		

	//return a Person created via the new operator
	Person* GetNewPerson();	

	//return a bool indicating that the text files were correctly opened
	//and read.  Returns false if any file was not opened and read.
	bool IsTextFileRead() { return bNameFileRead; }
	

	//createFile creates a file with number of persons, 
	//return true if file successfully written, false if not.
	bool CreateFile(string filename, int numOfPersons); 

	//useFile directs the generator to use the person data that is 
	//stored in the file instead of random creation. 
	//Return true indicates it was able to locate and open the file. 
	//Returns false file not found. 
	//When this method is called, the generator will only read the file 
	//line-by-line to pull out person data AS NEEDED. It DOES NOT read 
	//the entire file and store the data. If the file runs out of names, 
	//begin generating the persons randomly. 
	bool UseFile(string filename);	

}; 
#endif
