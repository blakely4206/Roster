#pragma once
#include "student.h"
class securityStudent :
	public student
{
public:
	securityStudent(string student_ID, string first_name, string last_name, string email, int student_age, int days_in_course1, int days_in_course2, int days_in_course3, Degree d);
	Degree getDegreeProgram();
	void print();
private:
	Degree the_degree = SECURITY;
};
