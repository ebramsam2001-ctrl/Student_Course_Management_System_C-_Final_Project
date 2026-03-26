#include "Course.h"

Course::Course()
{
	this->ID = 0;
	this->name = "";
	this->credits = 0;
	this->grade = 0.0;
}

Course::Course(int id, string name, int credits, double grade)
{
	this->ID = id;
	this->name = name;
	this->credits = credits;
	this->grade = grade;
}

void Course::setID(int id)
{
	this->ID = id;
}

int Course::getID()
{
	return this->ID;
}

void Course::setName(string name)
{
	this->name = name;
}

string Course::getName()
{
	return this->name;
}

void Course::setCredits(int credits)
{
	this->credits = credits;
}

int Course::getCredits()
{
	return this->credits;
}

void Course::setGrade(double grade)
{
	this->grade = grade;
}

double Course::getGrade()
{
	return this->grade;
}