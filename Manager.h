/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#pragma once
#include "Employee.h"
class Manager : public Employee {
protected:
	int level;
public:
	Manager(string = "Unknwon", int=0, float=0.0, float=0.0, int=1); //ctor
	float Salary() const;
	void print_salary();
	void print();
};

