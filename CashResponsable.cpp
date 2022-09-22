/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#include "CashResponsable.h"

CashResponsable::CashResponsable(string name, int id, float job_per, float base, int num) : Employee(name, id, job_per, base), num_of_action(num)  //ctor
{
}

float CashResponsable::Salary() const  //cal salary
{
	return ((base_sal+num_of_action)*job_percent);
}
void CashResponsable::print_salary(){
	cout << this->Salary() << endl;
}
void CashResponsable::print(){
	this->Employee::print();
	cout << "Job:Cashier" << endl;
	cout << "Actions:" << this->num_of_action << endl;
}
