/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#include "SeniorSeller.h"

SeniorSeller::SeniorSeller(string name, int id, float job_per, float base, int num_cl, int num_can) : Employee(name, id, job_per, base) //ctor
{ 
	this->num_of_canceled = num_can;
	this->num_of_clients = num_cl;
	this->clients = new float[this->num_of_clients];
	this->canceled = new float[this->num_of_canceled];
}

float SeniorSeller::Salary()  //cal salary
{
	return  (base_sal+num_of_clients+this->Avarage()*1.5); 
}
float SeniorSeller::Avarage()  //cal avarage client
{
	float sum = 0.0;
	for (int i = 0; i < num_of_clients; i++) {
		sum += clients[i];
	}
	return (sum /= num_of_clients);
}
SeniorSeller& SeniorSeller::operator+=(float to_add) {  //add client
	this->num_of_clients++;
	float* new_list = new float[this->num_of_clients]; //allocate memory
	for (int i = 0; i < this->num_of_clients - 1; i++)
		new_list[i] = this->clients[i];  //copy old 
	new_list[this->num_of_clients - 1] = to_add; //add new
	delete[] this->clients; //delete memory
	this->clients = new_list;
	return *this;
}
SeniorSeller& SeniorSeller::operator-=(float to_sub) {  //canceled client
	this->num_of_canceled++;
	float* new_list = new float[this->num_of_canceled];  //allocate memory
	for (int i = 0; i < this->num_of_canceled- 1; i++)
		new_list[i] = this->canceled[i];  //copy old
	new_list[this->num_of_canceled - 1] = to_sub;  //update
	delete[] this->canceled; //delete memory
	this->canceled = new_list;
	return *this;
}
void SeniorSeller::print_salary() {
	cout << this->Salary() << endl;
}
void SeniorSeller::print() {
	this->Employee::print();
	cout << "job:senior seller" << endl;
	cout << "sales:" << this->num_of_clients << endl;
	cout << "returns:" << this->num_of_canceled << endl;
}