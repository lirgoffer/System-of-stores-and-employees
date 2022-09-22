/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#include "Manager.h"

Manager::Manager(string name, int id, float job_per , float base, int level): Employee(name, id, job_per, base), level(level) //ctor
{
}

float Manager::Salary() const  //cal salary
{
	return base_sal*level*job_percent;
}
void Manager::print_salary() {
	cout << this->Salary() << endl;
}
void Manager::print() {
	this->Employee::print();
	cout << "Job: Manager" << endl;
	cout << "level:" << this->level << endl;
}