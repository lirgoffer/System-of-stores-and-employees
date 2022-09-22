/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#pragma once
#include "Employee.h"
#include "JuniorSeller.h"
class SeniorSeller : public Employee {
protected:
	float* clients;
	int num_of_clients;
	float* canceled;
	int num_of_canceled;

public:
	SeniorSeller(string = "Unknwon", int = 0, float = 0.0, float = 0.0, int = 0, int=0); //ctor
	float Salary();
	float Avarage();
	SeniorSeller& operator+=(float);  //+= operator
	SeniorSeller& operator-=(float);  //-= operator
	void print_salary();
	void print();

};

