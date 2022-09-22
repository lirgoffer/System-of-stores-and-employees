/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#include "Employee.h"

Employee::Employee(string name, int id, float job_per, float base): name(name), ID(id),job_percent(job_per), base_sal(base)  //ctor
{
}

string Employee::GetName() const  //get name 
{
	return string();
}

Employee& Employee::operator=(const Employee* to_copy) {  //copy employee detalis
	this->ID = to_copy->ID;
	this->name = to_copy->name;
	this->base_sal = to_copy->base_sal;
	this->job_percent = to_copy->job_percent;
	return *this;
}
void Employee::print() {
	cout << "name:" << this->name << endl;
	cout << "id:" << this->ID << endl;
	cout << "job per:" << this->job_percent << endl;
	cout << "base sal:" << this->base_sal << endl;
}