/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#pragma once
#include <iostream>
#include <string> 
using namespace std;

#include"Networks.h"

class ClothNetwork : public Networks {
private:
	string name_of_importer;

public:
	ClothNetwork(); //default ctor
	ClothNetwork(string, int, string); //ctor
	ClothNetwork(const ClothNetwork&);  //copy ctor
	~ClothNetwork();
	void Print() const;
	string get_importer() { return this->name_of_importer; };  
};