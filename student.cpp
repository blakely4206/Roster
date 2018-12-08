#include "stdafx.h"
#include <string>
#include "student.h"
#include <iostream>
#include "degree.h"

using namespace std;

student::student(string student_ID, string first_name, string last_name, string email_address, int student_age, int days_in_course1, int days_in_course2, int days_in_course3, Degree d)
{
	this->ID = student_ID;
	this->firstName = first_name;
	this->lastName = last_name;
	this->email = email_address;
	this->age = student_age;
	this->numberOfDays = new int[3];
	this->numberOfDays[0] = days_in_course1;
	this->numberOfDays[1] = days_in_course2;
	this->numberOfDays[2] = days_in_course3;
	this->studentDegree = d;
}

student::~student()
{
	delete[] numberOfDays;
}

void student::setID(string student_ID)
{
	ID = student_ID;
}

void student::setFirstName(string first_name)
{
	firstName = first_name;
}

void student::setLastName(string last_name)
{
	lastName = last_name;
}

void student::setEmail(string student_email)
{
	email = student_email;
}

void student::setAge(int student_age)
{
	age = student_age;
}

void student::setDaysInCourse(int one, int two, int three)
{
	numberOfDays[0] = one;
	numberOfDays[1] = two;
	numberOfDays[2] = three;
}

void student::setDegree(Degree d)
{
	studentDegree = d;
}

string student::getID()
{
	return ID;
}

string student::getFirstName()
{
	return firstName;
}

string student::getLastName()
{
	return lastName;
}

string student::getEmail()
{
	return email;
}

int student::getAge()
{
	return age;
}

int* student::getDaysInCourse()
{
	return numberOfDays;
}
