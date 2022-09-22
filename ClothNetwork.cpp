/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#include "ClothNetwork.h"

ClothNetwork::ClothNetwork()  //default ctor
{
	this->name_of_importer = "unknown";
}

ClothNetwork::ClothNetwork(string name1, int num, string name2) :Networks(name1, num) //ctor
{
	this->name_of_importer = name1;
}

ClothNetwork::ClothNetwork(const ClothNetwork& other) : Networks(other)  //copy ctor
{
	if (this != &other)//check if same
		this->name_of_importer = other.name_of_importer;
}

ClothNetwork::~ClothNetwork()
{
}

void ClothNetwork::Print() const
{
	cout << "Name of importer:" << name_of_importer << endl;
}

