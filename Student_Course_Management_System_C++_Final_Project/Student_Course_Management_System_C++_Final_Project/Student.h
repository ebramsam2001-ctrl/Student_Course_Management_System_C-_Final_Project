#ifndef _STUDENT_H
#define _STUDENT_H

#include "Person.h"
#include "Course.h"
#include <vector>

class Student : public Person
{
	protected:
		double GPA;
		vector<Course> courses;

	public:
		Student();
		Student(int id, string name, double gpa);
		void setGPA(double gpa);
		double getGPA();
		void enrollInCourse(Course course);
		vector<Course> getCourses();
};

#endif