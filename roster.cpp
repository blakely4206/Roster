#include "stdafx.h"
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <string>
#include <regex>
#include <iostream>

using namespace std;

roster::roster()
{
	this->classRosterArray = new student*[rosterLength];
}

roster::~roster()
{
	for (int i = 0; i < totalStudents; i++)
	{
		delete this->classRosterArray[i];
	}
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int days_in_course1, int days_in_course2, int days_in_course3, Degree degree)
{
	switch (degree)
	{
	case SECURITY:
	{
		securityStudent * ss = new securityStudent(studentID, firstName, lastName, emailAddress, age, days_in_course1, days_in_course2, days_in_course3, degree);
		this->classRosterArray[totalStudents] = ss;
		totalStudents++;
	}
	break;
	case NETWORKING:
	{
		networkStudent * ns = new networkStudent(studentID, firstName, lastName, emailAddress, age, days_in_course1, days_in_course2, days_in_course3, degree);
		this->classRosterArray[totalStudents] = ns;
		totalStudents++;
	}
	break;
	case SOFTWARE:
	{
		softwareStudent * sos = new softwareStudent(studentID, firstName, lastName, emailAddress, age, days_in_course1, days_in_course2, days_in_course3, degree);
		this->classRosterArray[totalStudents] = sos;
		totalStudents++;
	}
	break;
	default:
		break;
	}
}

void roster::remove(string studentID)
{
	bool exists = false;

	cout << "\nREMOVING " << studentID << "...\n";
	for (int i = 0; i < totalStudents; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			exists = true;

			for (int j = i; j < totalStudents; j++)
			{
				this->classRosterArray[j] = this->classRosterArray[j + 1];
			}
			this->classRosterArray[totalStudents] = nullptr;
			totalStudents--;
			cout << "DONE\n";
		}
	}

	if (!exists)
	{
		cout << "Error: Student Not Found\n";
	}
}

void roster::printAll()
{
	cout << "STUDENT ROSTER:\n";

	for (int i = 0; i < totalStudents; i++)
	{
		cout << i + 1 << "\t";
		this->classRosterArray[i]->print();
	}
}

void roster::printAverageDaysInCourse(string studentID)
{
	cout << "\nAVERAGE DAYS IN COURSE:\n";

	for (int i = 0; i < rosterLength; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			int avg = (this->classRosterArray[i]->getDaysInCourse()[0] + this->classRosterArray[i]->getDaysInCourse()[1] + this->classRosterArray[i]->getDaysInCourse()[2]) / 3;
			cout << studentID << ":\t" << avg << " days\n";
		}
	}
}

void roster::printInvalidEmails()
{
	cout << "\nINVALID EMAILS:\n";
	bool invalidEmails = false;
	regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	for (int i = 0; i < totalStudents; i++)
	{
		if (!regex_match(this->classRosterArray[i]->getEmail(), emailPattern))
		{
			cout << this->classRosterArray[i]->getEmail() << "\n";
			invalidEmails = true;
		}
	}
	if (!invalidEmails)
	{
		cout << "No invalid emails\n";
	}
}

void roster::printByDegreeProgram(int degreeProgram)
{
	cout << "\nSTUDENTS BY DEGREE PROGAM (";
	switch (degreeProgram)
	{
	case NETWORKING:
		cout << "NETWORKING)\n";
		for (int i = 0; i < rosterLength; i++)
		{
			if (this->classRosterArray[i]->getDegreeProgram() == NETWORKING)
			{
				cout << i + 1 << "\tFirst Name: "
					<< this->classRosterArray[i]->getFirstName() << "\tLast Name: "
					<< this->classRosterArray[i]->getLastName() <<
					"\tAge: " << this->classRosterArray[i]->getAge() << "\tdaysInCourse: {"
					<< this->classRosterArray[i]->getDaysInCourse()[0]
					<< ", " << this->classRosterArray[i]->getDaysInCourse()[1]
					<< ", " << this->classRosterArray[i]->getDaysInCourse()[2]
					<< "} Degree Program: " << "Networking" << "\n";
			}
		}
		break;
	case SOFTWARE:
		cout << "SOFTWARE)\n";
		for (int i = 0; i < rosterLength; i++)
		{
			if (this->classRosterArray[i]->getDegreeProgram() == SOFTWARE)
			{
				cout << i + 1 << "\tFirst Name: "
					<< this->classRosterArray[i]->getFirstName() << "\tLast Name: "
					<< this->classRosterArray[i]->getLastName() <<
					"\tAge: " << this->classRosterArray[i]->getAge()
					<< "\tdaysInCourse: {" << this->classRosterArray[i]->getDaysInCourse()[0]
					<< ", " << this->classRosterArray[i]->getDaysInCourse()[1]
					<< ", " << this->classRosterArray[i]->getDaysInCourse()[2]
					<< "} Degree Program: " << "Software" << "\n";
			}
		}
		break;
	case SECURITY:
		cout << "SECURITY)\n";
		for (int i = 0; i < rosterLength; i++)
		{
			if (this->classRosterArray[i]->getDegreeProgram() == SECURITY)
			{
				cout << i + 1 << "\tFirst Name: "
					<< this->classRosterArray[i]->getFirstName()
					<< "\tLast Name: " << this->classRosterArray[i]->getLastName() <<
					"\tAge: " << this->classRosterArray[i]->getAge()
					<< "\tdaysInCourse: {" << this->classRosterArray[i]->getDaysInCourse()[0]
					<< ", " << this->classRosterArray[i]->getDaysInCourse()[1]
					<< ", " << this->classRosterArray[i]->getDaysInCourse()[2]
					<< "} Degree Program: " << "Security" << "\n";
			}
		}
		break;
	default:
		break;
	}
}

void main()
{
	cout << "C867 Scripting and Programming-Applications\n" << "C++\n" << "876696 Jeffery Blake Burroughs\n\n\n";
	rosterLength = sizeof(studentData) / sizeof(studentData[0]);
	roster * classRoster = new roster();

	for (int i = 0; i < rosterLength; i++)
	{
		int index = 0;
		int length = 0;
		int days[3] = { 0,0,0 };

		int indicesArray[8];

		for (int j = 0; j < 8; j++)
		{
			if (index == 0)
			{
				index = studentData[i].find(",", 0) + 1;
			}
			else
			{
				index = studentData[i].find(", ", index) + 1;
			}

			indicesArray[j] = index;
		}

		string ID = studentData[i].substr(0, indicesArray[0] - 1);
		string first = studentData[i].substr(indicesArray[0] + 1, indicesArray[1] - indicesArray[0] - 2);
		string last = studentData[i].substr(indicesArray[1] + 1, indicesArray[2] - indicesArray[1] - 2);
		string email = studentData[i].substr(indicesArray[2] + 1, indicesArray[3] - indicesArray[2] - 2);
		int age = atoi(studentData[i].substr(indicesArray[3] + 1, indicesArray[4] - indicesArray[3] - 2).c_str());
		int dayOne = atoi(studentData[i].substr(indicesArray[4] + 1, indicesArray[5] - indicesArray[4] - 2).c_str());
		int dayTwo = atoi(studentData[i].substr(indicesArray[5] + 1, indicesArray[6] - indicesArray[5] - 2).c_str());
		int dayThree = atoi(studentData[i].substr(indicesArray[6] + 1, indicesArray[7] - indicesArray[6] - 2).c_str());
		string degree = studentData[i].substr(indicesArray[7] + 1, studentData[i].length() - indicesArray[7]);

		if (degree == "SOFTWARE")
		{
			classRoster->add(ID, first, last, email, age, dayOne, dayTwo, dayThree, SOFTWARE);
		}
		else if (degree == "SECURITY")
		{
			classRoster->add(ID, first, last, email, age, dayOne, dayTwo, dayThree, SECURITY);
		}
		else if (degree == "NETWORK")
		{
			classRoster->add(ID, first, last, email, age, dayOne, dayTwo, dayThree, NETWORKING);
		}
	}

	classRoster->printAll();
	classRoster->printInvalidEmails();

	for (int i = 0; i < rosterLength; i++)
	{
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getID());
	}

	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->remove("A3");

	classRoster->~roster();
}