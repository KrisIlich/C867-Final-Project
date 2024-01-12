#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
using std::string;
using std::cout;


class Student 
{
public:
	const static int numDaysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDays[numDaysArraySize];
	DegreeProgram degreeProgram;
	
public: 
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram degreeProgram);
	~Student();

	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumDays();
	DegreeProgram getDegreeProgram();

	void setID (string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDays(int NumDays[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();
};

