#ifndef _PERSON_H
#define _PERSON_H

#include <string>

using namespace std;

class Person
{
	protected:
		int ID;
		string name;

	public:
		Person();
		Person(int id, string name);
		void setID(int id);
		int getID();
		void setName(string name);
		string getName();
};

#endif