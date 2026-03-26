#include "Student.h"

Student::Student() : Person()
{
	this->GPA = 0.0;
}

Student::Student(int id, string name, double gpa) : Person(id, name)
{

	if (gpa < 0.0) {
		gpa = 0.0;
	}

	if (gpa > 4.0) {
		gpa = 4.0;
	}

	this->GPA = gpa;
}

void Student::setGPA(double gpa)
{
	if (gpa < 0.0) {
		gpa = 0.0;
	}

	if (gpa > 4.0) {
		gpa = 4.0;
	}

	this->GPA = gpa;
}

double Student::getGPA()
{
	return this->GPA;
}

void Student::enrollInCourse(Course course)
{
	for (Course& c : this->courses) {
		if (c.getID() == course.getID()) {
			// already enrolled
			return;
		}
	}
	this->courses.push_back(course);
}

vector<Course> Student::getCourses()
{
	return this->courses;
}