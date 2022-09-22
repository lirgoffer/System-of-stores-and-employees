/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#pragma once
#include <iostream>
#include <string> 
using namespace std;
#include "Employee.h"
#include "Manager.h"
#include "CashResponsable.h"
#include "JuniorSeller.h"
#include "SeniorSeller.h"

class Shop {
protected:
	int shop_number;
	string network;
	Employee** employees;
	int num_of_employee;

public:
	Shop(int = -1, string="");  //ctor 
	Shop& operator=(const Shop*);  //= operator
	bool check_id(int);  //check id
	Shop& operator +=(Employee*);  //+= operator
	Employee* get_emp(int);  //get employee
	void print_salaries();
	int get_id() { return this->shop_number; };  //get shop number
	void print_shop();
	void print_emp(int);
};
