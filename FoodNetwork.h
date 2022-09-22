/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#pragma once
#include <iostream>
#include <string> 
using namespace std;
#include "Networks.h"

class FoodNetwork : public Networks {
protected:
	int num_of_suppliers;

public:
	FoodNetwork(string = "unknown", int=0 , int=0); //ctor
	int get_supplier() {return this->num_of_suppliers;}; //get num of sup
};
