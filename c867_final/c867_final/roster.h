#pragma once
#include <iostream>
#include <string>
#include "student.h"	
using namespace std;
class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
public:
	Student* studentRosterArray[numStudents];
	void parse(string row);
	void add(string sStudentID,
		string sFirstName,
		string sLastName,
		string sEmail,
		int sAge,
		int sNumDays1,
		int sNumDays2,
		int sNumDays3,
		DegreeProgram dp);
	void printAll();
	void printByDegreeProgram(DegreeProgram dp);
	void printInvalidEmails();
	void printAverageDays(string studentID);
	void removeStudentByID(string studentID);
	~Roster();
};