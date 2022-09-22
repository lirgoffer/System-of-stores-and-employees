/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#pragma once
#include "Employee.h"
class CashResponsable : public Employee {
protected:
	int num_of_action;

public:
	CashResponsable(string = "Unknwon", int = 0, float = 0.0, float = 0.0, int = 0); //ctor
	float Salary()const; 
	void print_salary();
	void print();
};
