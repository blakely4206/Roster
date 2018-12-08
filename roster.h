#pragma once
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <string>
#include "degree.h"

using namespace std;

static int rosterLength = 0;
const string studentData[] =
{ "A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
"A2, Suzan, Erickson, Erickson_1990@gmail.com, 19, 50, 30, 40, NETWORK",
"A3, Jack, Napoli, The_lawyer99@yahoo.com, 19, 20, 40, 33, SOFTWARE",
"A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
"A5, Jeffery, Burroughs, jburr54@wgu.edu, 31, 30, 35, 40, SOFTWARE" };

class roster
{
public:
	roster();
	~roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int days_in_course1, int days_in_course2, int days_in_course3, Degree degree);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	student** classRosterArray;
private:
	int totalStudents = 0;
};

