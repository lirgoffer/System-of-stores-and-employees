/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#pragma once
#include "Employee.h"
class JuniorSeller : public Employee {
protected:
	float* clients;
	int num_of_clients;
public:
	JuniorSeller(string = "Unknwon", int = 0, float = 0.0, float = 0.0, int = 0); //ctor
	virtual float Salary();
	float Avarage(); 
	JuniorSeller& operator+=(float);  //+= operator
	void print_salary();
	void print();
};
