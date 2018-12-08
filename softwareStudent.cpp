#include "stdafx.h"
#include "softwareStudent.h"
#include "student.h"
#include <string>
#include <iostream>

using namespace std;


softwareStudent::softwareStudent(string student_ID, string first_name, string last_name, string email, int student_age, int days_in_course1, int days_in_course2, int days_in_course3, Degree d) :
	student(student_ID, first_name, last_name, email, student_age, days_in_course1, days_in_course2, days_in_course3, d)
{
	setDegree(d);
}

Degree softwareStudent::getDegreeProgram()
{
	return the_degree;
}

void softwareStudent::print()
{
	cout << "First Name: " << getFirstName() << "\tLast Name: " << getLastName() <<
		"\tAge: " << getAge() << "\tdaysInCourse: {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1]
		<< ", " << getDaysInCourse()[2] << "} Degree Program: " << "Software" << "\n";
}