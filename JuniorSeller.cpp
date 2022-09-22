/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#include "JuniorSeller.h"

JuniorSeller::JuniorSeller(string name, int id, float job_per, float base, int num_cl ) : Employee(name, id, job_per, base) //ctor
{
	this->num_of_clients = num_cl;
	this->clients = new float[num_of_clients];
}

float JuniorSeller::Salary() //cal salary
{
	return ((base_sal+num_of_clients+ this->Avarage())*job_percent);
}

float JuniorSeller::Avarage()  //cal avarage client
{
	float sum = 0.0;
	for (int i = 0; i < num_of_clients; i++) {
		sum += clients[i];
	}
	return (sum/=num_of_clients);
}
JuniorSeller& JuniorSeller::operator+=(float to_add) {  //add client
	this->num_of_clients++;
	float* new_list = new float[this->num_of_clients]; //allocate memory
	for (int i = 0; i < this->num_of_clients - 1; i++)
		new_list[i] = this->clients[i];  //copy old
	new_list[this->num_of_clients - 1] = to_add;  //add new
	delete[] this->clients;  //delete memory
	this->clients = new_list;  
	return *this;
}
void JuniorSeller::print_salary() {
	cout << this->Salary() << endl;
}
void JuniorSeller::print() {
	this->Employee::print();
	cout << "Job:Junior selller" << endl;
	cout << "Sales:" << this->num_of_clients << endl;
}