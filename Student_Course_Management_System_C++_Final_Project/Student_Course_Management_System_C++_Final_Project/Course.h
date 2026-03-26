#ifndef _COURSE_H
#define _COURSE_H

#include <string>

using namespace std;

class Course
{
	protected:
		int ID;
		string name;
		int credits;
		double grade;

	public:
		Course();
		Course(int id, string name, int credits, double grade);
		void setID(int id);
		int getID();
		void setName(string name);
		string getName();
		void setCredits(int credits);
		int getCredits();
		void setGrade(double grade);
		double getGrade();
};

#endif