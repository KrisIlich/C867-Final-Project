#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main () {

	const string studentData[] = {

		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",      
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,2 2,50,58,40,SECURITY",
		"A5,Kris,Ilich,kris.ilich@wgu.edu,31, 35, 50, 40, SOFTWARE"

	};

	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 010411130" << endl;
	cout << "Name: Kris Ilich" << endl << endl;
	

	const int numStudents = 5;
	Roster classroster;

	for (int i = 0; i < numStudents; i++) classroster.parse(studentData[i]);
	cout << "Displaying all students: ";
	classroster.printAll();
	cout << endl;

	cout << "Displaying invalid emails:" << endl << endl;
	classroster.printInvalidEmails();
	cout << endl;

	for (int i = 0; i < numStudents; i++) {
		classroster.printAverageDays(classroster.studentRosterArray[i]->getID());
	}
	cout << endl;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "Showing students in degree program: " << degreeProgramStrings[i] << endl;
		classroster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "Removing A3:";
	classroster.removeStudentByID("A3");
	classroster.printAll();
	cout << endl;

	cout << "Removing A3 again" << endl <<endl;
	classroster.removeStudentByID("A3");
	cout << endl;

	system("Pause");
	return 0;

}