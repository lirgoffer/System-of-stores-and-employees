/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#pragma once
#include <iostream>
#include <string> 
using namespace std;

#include "Shop.h"

class Networks {
protected:
	string name;
	Shop** shops;
	int num_of_shops;

public:
	Networks(string="unknown", int=0);  
	Networks& operator+=(Shop*);  //+= operator
	string get_name() { return this->name; };  //get name of network
	bool check_id(int);  //check the id
	virtual Shop* get_shop(int);   //get shop
	int get_shop_num() { return this->num_of_shops; };  //get num of shops in network
	void print_salaries();

};

