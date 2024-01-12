#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstName= "";
	this->lastName = "";
	this->age = 0;
	this->email = "";
	for (int i = 0; i < numDaysArraySize; i++) this->numDays[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < numDaysArraySize; i++) this->numDays[i] = numDays[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getNumDays() { return this->numDays; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setNumDays(int NumDays[])
{
	for (int i = 0; i < numDaysArraySize; i++) this->numDays[i] = numDays[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader()
{
	cout << endl;
}

void Student::print()
{
	cout << this->studentID << '\t';
	cout << this->firstName << '\t' << '\t';
	cout << this->lastName << '\t';
	//cout << this->email << '\t';
	cout << this->age << '\t' << '\t';
	cout << '{' << this->numDays[0] << ',';
	cout << this->numDays[1] << ',';
	cout << this->numDays[2] << '}' << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}