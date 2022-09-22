/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#include "Shop.h"

Shop::Shop(int shop, string name) //ctor
{
	this->shop_number = shop;
	this->network = name;
	this->employees = nullptr;
	this->num_of_employee = 0;
}
Shop& Shop::operator=(const Shop* to_copy) {  //copy shop
	this->network = to_copy->network;  //copy network name
	this->num_of_employee = to_copy->num_of_employee;  //copy num of emp
	this->shop_number = to_copy->shop_number;  //copy shop number
	if (this->employees != nullptr)
		delete this->employees;
	this->employees = new Employee*[this->num_of_employee];  
	for (int i = 0; i < this->num_of_employee; i++)
		this->employees[i] = to_copy->employees[i];  //copy emp
	return *this;
}
bool Shop::check_id(int id) {  //check if emp exsit
	if (this->num_of_employee > 0) {
		for (int i = 0; i < this->num_of_employee; i++)
			if (this->employees[i]->GetID() == id)
				return false;
	}
		return true;
}

Shop& Shop::operator +=(Employee* to_add) {  //add employee to shop
	this->num_of_employee++;
	Employee** new_list = new Employee * [this->num_of_employee];
	if (this->employees != nullptr) {
		for (int i = 0; i < this->num_of_employee - 1; i++)
			new_list[i] = this->employees[i];  //copy old
	}
	delete[] this->employees;
	this->employees = new_list;
	this->employees[this->num_of_employee - 1] = to_add;  //add new
	return *this;
}

Employee* Shop::get_emp(int id) {  //get employee from shop
	for (int i = 0; i < this->num_of_employee; i++)
		if (this->employees[i]->GetID() == id)
			return this->employees[i];  //return emp
	return nullptr;
}

void Shop::print_salaries() {  //print salaries  by checking type of emp
	for (int i = 0; i < this->num_of_employee; i++) {
		if (dynamic_cast<Manager*>(this->employees[i]))
			dynamic_cast<Manager*>(this->employees[i])->print_salary();  //manager salaries
		if (dynamic_cast<SeniorSeller*>(this->employees[i]))
			dynamic_cast<SeniorSeller*>(this->employees[i])->print_salary();  //senior salaries
		if (dynamic_cast<JuniorSeller*>(this->employees[i]))
			dynamic_cast<JuniorSeller*>(this->employees[i])->print_salary();  //junior salaries
		if (dynamic_cast<CashResponsable*>(this->employees[i]))
			dynamic_cast<CashResponsable*>(this->employees[i])->print_salary();  //cashies salaries
	}
}
void Shop::print_shop() {
	cout << "shop id:" << this->shop_number << endl;
	cout << "employee num:" << this->num_of_employee << endl;
	cout << "network:" << this->network << endl;

}
void Shop::print_emp(int emp_num) {  //print employees by checking type of emp
	for (int i = 0; i < this->num_of_employee; i++)
		if (this->employees[i]->GetID() == emp_num) {
			if (dynamic_cast<Manager*>(this->employees[i]))
				dynamic_cast<Manager*>(this->employees[i])->print();   //print manager
			else if (dynamic_cast<SeniorSeller*>(this->employees[i]))
				dynamic_cast<SeniorSeller*>(this->employees[i])->print();  //print senior
			else if (dynamic_cast<JuniorSeller*>(this->employees[i]))
				dynamic_cast<JuniorSeller*>(this->employees[i])->print();  //print junior
			else if (dynamic_cast<CashResponsable*>(this->employees[i]))
				dynamic_cast<CashResponsable*>(this->employees[i])->print();  //print cashier
		}
			
}