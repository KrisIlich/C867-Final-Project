#include <iostream>
#include <string>
#include "roster.h"
#include <string>
#include <vector>
#include <sstream>
#include <regex>
using namespace std;

void Roster::parse(string studentData)
{
	DegreeProgram dp = SECURITY;
	if (studentData[studentData.length() - 1] == 'Y') dp = SECURITY;
	else if (studentData[studentData.length() - 1] == 'K') dp = NETWORK;
	else if (studentData[studentData.length() - 1] == 'E') dp = SOFTWARE;

	int rs = studentData.find(",");
	string sStudentID = studentData.substr(0, rs);

	int ls = rs + 1;
	rs = studentData.find(",", ls); 
	string sFirstName = studentData.substr(ls, rs - ls);

	ls = rs + 1;
	rs = studentData.find(",", ls);
	string sLastName = studentData.substr(ls, rs - ls);

	ls = rs + 1;
	rs = studentData.find(",", ls);
	string sEmail = studentData.substr(ls, rs - ls);

	ls = rs + 1;
	rs = studentData.find(",", ls);
	int sAge = stoi(studentData.substr(ls, rs - ls));
	
	ls = rs + 1;
	rs = studentData.find(",", ls);
	int sNumDays1 = stoi(studentData.substr(ls, rs - ls));

	ls = rs + 1;
	rs = studentData.find(",", ls);
	int sNumDays2 = stoi(studentData.substr(ls, rs - ls));

	ls = rs + 1;
	rs = studentData.find(",", ls);
	int sNumDays3 = stoi(studentData.substr(ls, rs - ls));

	add(sStudentID, sFirstName, sLastName, sEmail, sAge, sNumDays1, sNumDays2, sNumDays3, dp);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int numDays1, int numDays2, int numDays3, DegreeProgram dp)
{
	int darr[3] = { numDays1, numDays2, numDays3 };
	studentRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, darr, dp);
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		studentRosterArray[i]->print();
	}
}


void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::studentRosterArray[i]->getDegreeProgram() == dp) studentRosterArray[i]->print();
	}
	cout << endl;
}
void Roster::printInvalidEmails()
{
	const regex pattern(
		"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string sEmail = (studentRosterArray[i]->getEmail());
		if (!regex_match(sEmail, pattern))
		{
			any = true;
			cout << sEmail << ": is invalid." << endl;
		}
	}
}

void Roster::printAverageDays(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (studentRosterArray[i]->getID() == studentID) {
			cout << "Student ID: " << studentRosterArray[i]->getID() << ", average days in course is: ";
			cout << (studentRosterArray[i]->getNumDays()[0]
				+ studentRosterArray[i]->getNumDays()[1]
				+ studentRosterArray[i]->getNumDays()[2]) / 3;
		}
	}
	cout << endl;
}

void Roster::removeStudentByID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (studentRosterArray[i]->getID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numStudents - 1];
				studentRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << endl;
	}
	else cout << "Student with the ID: " << studentID << " was not found." << endl << endl;
}

Roster::~Roster()
{
	cout << "Destructor initiated" << endl << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Releasing Memory for Roster #" << i + 1 << endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}