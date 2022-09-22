/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/

#include "FoodNetwork.h"

FoodNetwork::FoodNetwork(string name, int num, int num_sup): Networks(name, num), num_of_suppliers(num_sup) //ctor
{
	this->shops = new Shop*[num_of_shops];
}
