/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#pragma once
#include <iostream>
#include <string> 
using namespace std;
class Employee {
protected:
	string name;
	int ID;
	float job_percent;
	float base_sal;


public:
	Employee(string = "Unknown",int=0, float = 0.0, float=0.0); // ctor
	string GetName() const;
	virtual int GetID() {return this->ID;};  //get id
	Employee& operator=(const Employee*); //= operator
	virtual void print();
};