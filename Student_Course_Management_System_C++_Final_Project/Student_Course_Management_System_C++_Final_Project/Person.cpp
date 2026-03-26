#include "Person.h"

Person::Person()
{
	this->ID = 0;
	this->name = "";
}

Person::Person(int id, string name)
{
	this->ID = id;
	this->name = name;
}

void Person::setID(int id)
{
	this->ID = id;
}

int Person::getID()
{
	return this->ID;
}

void Person::setName(string name)
{
	this->name = name;
}

string Person::getName()
{
	return this->name;
}