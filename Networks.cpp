/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#include "Networks.h"

Networks::Networks(string name, int num) //ctor
{
	this->name = name;
	this->num_of_shops = 0;
	shops = nullptr;
}

Networks& Networks::operator+=(Shop* new_shop) { //add shop to network 
	this->num_of_shops++;
	Shop** new_shop_list = new Shop*[this->num_of_shops];  //allocate memory
	for (int i = 0; i < this->num_of_shops - 1; i++)
		new_shop_list[i] = this->shops[i];  //copy old
	new_shop_list[this->num_of_shops - 1] = new_shop; //add new
	delete[] this->shops;  //delete memory
	this->shops = new_shop_list; 
	return *this;
}

bool Networks::check_id(int id) {  //check if shop exist
	for (int i = 0; i < this->num_of_shops; i++)
		if (this->shops[i]->get_id() == id) //if same
			return false;
	return true;
}

Shop* Networks::get_shop(int id) {   //get shop by id
	for (int i = 0; i < this->num_of_shops; i++)
		if (this->shops[i]->check_id(id))  //==true
			return this->shops[i];
	return nullptr;  //if not exist
}

void Networks::print_salaries() {  //print salaries
	for (int i = 0; i < this->num_of_shops; i++)
		this->shops[i]->print_salaries();
}
