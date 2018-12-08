#pragma once
#include <string>
#include "degree.h"

using namespace std;

class student {
public:
	student(string student_ID, string first_name, string last_name, string email, int student_age, int days_in_course1, int days_in_course2, int days_in_course3, Degree d);
	~student();

	void setID(string student_ID);
	void setFirstName(string first_name);
	void setLastName(string last_name);
	void setEmail(string student_email);
	void setAge(int student_age);
	void setDaysInCourse(int one, int two, int three);
	void setDegree(Degree d);

	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();

	void virtual print() = 0;
	Degree virtual getDegreeProgram() = 0;
private:
	string ID;
	string firstName;
	string lastName;
	string email;
	int age;
	int *numberOfDays;
	Degree studentDegree;
};