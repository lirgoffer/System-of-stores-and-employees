/*Assignment 3,
Autor:Lir Goffer, ID:209103274*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
using namespace std;
#include"Networks.h"
#include "SeniorSeller.h"
#include"ClothNetwork.h"
#include "FoodNetwork.h"
#include "Manager.h"
#include "CashResponsable.h"
#define SIZE 3

//menu options
void Add_shop(Networks**);
void Add_employee(Networks**);
void Shopping(Networks**);
void Return_item(Networks**);
void Print_chain(Networks**);
void Sum_salaries_chain(Networks**);
void Sum_salaries_shop(Networks**);
void Print_shop(Networks**);
void Print_employee(Networks**);


int main() {   
	Networks** array = new Networks * [SIZE];   //create array of networks
	array[0] = new ClothNetwork("Golbary", 1, "Moshe Gabay");
	*array[0] += new Shop(65,"Golbary");  //add shops
	*array[0] += new Shop(3,"Golbary");
	array[1] = new FoodNetwork("Supersal", 2, 4);
	*array[1] += new Shop(81,"Supersal"); //add shop
	array[2] = new ClothNetwork("TNT", 1, "Ruti Sulimani");
	*array[2] += new Shop(3,"TNT");  //add shop




	int choice = 0;

	do {
		cout << "\nPlease Choose an option from the menu:\n";   
		cout << "1.Add Shop\n2.Add Employee\n3.Shopping\n4.Return Item\n5.Print Chain\n6.Sum Salaries Chain\n7.Sum Salaries Shop\n8.Print Shop\n9.Print Employee\n10.Exit\n";
		cin >> choice;
		if (choice < 1 || choice>10) {
			cout << "wrong chice please try again:" << endl;
			cin >> choice;
		}

		switch (choice) {
		case 1:Add_shop(array);
			break;
		case 2:Add_employee(array);
			break;
		case 3:Shopping(array);
			break;
		case 4:Return_item(array);
			break;
		case 5:Print_chain(array);
			break;
		case 6:Sum_salaries_chain(array);
			break;
		case 7:Sum_salaries_shop(array);
			break;
		case 8:Print_shop(array);
			break;
		case 9:Print_employee(array);
			break;
		case 10:break;
		default: cout << "Bad input try again:" << endl; 
			break;
		}
	} 	while (choice != 10);
	for (int i = 0; i < SIZE; i++)
		delete array[i];
	delete[] array;
}






	//menu options
	void Add_shop(Networks** net) {
		int shop_num;
		string net_name;
		cout << "enter network name" << endl;
		cin >> net_name;
		for (int i = 0; i < SIZE; i++) {
			if (net[i]->get_name() == net_name) {  //if network exist
				cout << "enter shop number" << endl;
				cin >> shop_num;
				if (net[i]->check_id(shop_num)) {  //if shop not exist
					(*net[i]) += new Shop(shop_num, net_name);
					cout << "SHOP ADDED" << endl;
				}
				else
					cout << "SHOP ALREADY EXISTS" << endl;
			}
		}
	}
	void Add_employee(Networks** net) {
		int shop_num,emp_num;
		string net_name;
		char choice;
		string emp_name;
		float sal, work;
		cout << "end network name" << endl;
		cin >> net_name;
		for (int i = 0; i < SIZE; i++) {
			if (net[i]->get_name() == net_name) {  //if network exist
				cout << "enter shop number" << endl;
				cin >> shop_num;
				if (!net[i]->check_id(shop_num)) {  //if shop exist
					cout << "enter emp id" << endl;
					cin >> emp_num;
					if (net[i]->get_shop(shop_num)->check_id(emp_num)) {  //enter detalis
						cout << "Enter emp name" << endl;
						cin >> emp_name;
						cout << "enter emp sal" << endl;
						cin >> sal;
						cout << "enter emp work" << endl;
						cin >> work;
						cout << "Enter emp job A-Manager,B-SeniorSeller,C-JuniorSeller,D-CashResponsible" << endl;
						cin >> choice;
						switch (choice) {   //type of employee
						case 'A':*net[i]->get_shop(shop_num) += new Manager(emp_name, emp_num, work, sal); cout << "ADDED SUCCESSFULLY" << endl; break;
						case 'B':*net[i]->get_shop(shop_num) += new SeniorSeller(emp_name, emp_num, sal, work); cout << "ADDED SUCCESSFULLY" << endl; break;
						case 'C':*net[i]->get_shop(shop_num) += new JuniorSeller(emp_name, emp_num, sal, work); cout << "ADDED SUCCESSFULLY" << endl; break;
						case 'D':*net[i]->get_shop(shop_num) += new CashResponsable(emp_name, emp_num, sal, work); cout << "ADDED SUCCESSFULLY" << endl; break;
						default:cout << "BAD INPUT" << endl; break;
						}

					}
					else
						cout << "EMP EXISTS" << endl;
				}
				else
					cout << "SHOP DOESNT EXISTS" << endl;
			}
		}

	}

	void Shopping(Networks** net) {
		string shop_name;
		int shop_num, emp_num;
		float sum;
		cout << "please enter shop name" << endl;
		cin >> shop_name;
		for (int i = 0; i < SIZE; i++) {
			if (shop_name == net[i]->get_name()) {  //net exist
				cout << "Enter Shop num" << endl;
				cin >> shop_num;
				if (!net[i]->check_id(shop_num)) {   //shop exist
					cout << "enter emp num" << endl;
					cin >> emp_num;
					if (!net[i]->get_shop(shop_num)->check_id(emp_num)) {  //emp exist
						cout << "enter sum" << endl;
						cin >> sum;
						if (dynamic_cast<SeniorSeller*>(net[i]->get_shop(shop_num)->get_emp(emp_num))) {  //check type of emp and update
							*dynamic_cast<SeniorSeller*>(net[i]->get_shop(shop_num)->get_emp(emp_num)) += sum;
							cout << "Purchased successfully" << endl;
						}
						else if (dynamic_cast<JuniorSeller*>(net[i]->get_shop(shop_num)->get_emp(emp_num))) {
							*dynamic_cast<JuniorSeller*>(net[i]->get_shop(shop_num)->get_emp(emp_num)) += sum;
							cout << "Purchased successfully" << endl;
						}
						else
							cout << "EMP NOT SELLER" << endl;
					}
				}
			}
		}
	}

	void Return_item(Networks** net) {
		string shop_name;
		int shop_num, emp_num;
		float sum;
		cout << "please enter shop name" << endl;
		cin >> shop_name;
		for (int i = 0; i < SIZE; i++) {
			if (shop_name == net[i]->get_name()) {  //network exist
				cout << "Enter Shop num" << endl;
				cin >> shop_num;
				if (!net[i]->check_id(shop_num)) {  //shop exist
					cout << "enter emp num" << endl;
					cin >> emp_num;
					if (!net[i]->get_shop(shop_num)->check_id(emp_num)) { //emp exist
						cout << "enter sum" << endl;
						cin >> sum;
						if (dynamic_cast<SeniorSeller*>(net[i]->get_shop(shop_num)->get_emp(emp_num))) {  //update
							*dynamic_cast<SeniorSeller*>(net[i]->get_shop(shop_num)->get_emp(emp_num)) -= sum;
							cout << "Returned successfully" << endl;
						}
						else
							cout << "EMP NOT Senior" << endl;
					}
				}
			}
		}
	}

	void Print_chain(Networks** net) {
		string net_name;
		cout << "please enter network name" << endl;
		cin >> net_name;
		for (int i = 0; i < SIZE; i++) {
			if (net[i]->get_name() == net_name) {  //exist
				cout << "Network name:" << net[i]->get_name()<<endl;
				cout << "Number of shops: " << net[i]->get_shop_num() << endl;
				if (dynamic_cast<FoodNetwork*>(net[i]) != nullptr) //print types
					cout << "num of suppliers:" << dynamic_cast<FoodNetwork*>(net[i])->get_supplier() << endl;
				else if (dynamic_cast<ClothNetwork*>(net[i]) != nullptr)
					cout << "Importer:" << dynamic_cast<ClothNetwork*>(net[i])->get_importer() << endl;
			}
		}

	}
	void Sum_salaries_chain(Networks** net) {
		string net_name;
		cout << "please enter network name" << endl;
		cin >> net_name;
		for (int i = 0; i < SIZE; i++) {
			if (net_name == net[i]->get_name())  //exist
				net[i]->print_salaries();  //print
		}
	}
	void Sum_salaries_shop(Networks** net) {
		int shop_num;
		string net_name;
		cout << "please enter network name" << endl;
		cin >> net_name;
		for (int i = 0; i < SIZE; i++) {
			if (net[i]->get_name() == net_name) {  //exist
				cout << "enter shop number" << endl;
				cin >> shop_num;
				if (!net[i]->check_id(shop_num))  //exist
					net[i]->get_shop(shop_num)->print_salaries(); //print
			}
		}
	}

	void Print_shop(Networks** net) {
		int shop_num;
		string net_name;
		cout << "please enter network name" << endl;
		cin >> net_name;
		for (int i = 0; i < SIZE; i++) {
			if (net[i]->get_name() == net_name) {  //exist
				cout << "enter shop number" << endl;
				cin >> shop_num;
				if (!net[i]->check_id(shop_num))  //exist
					net[i]->get_shop(shop_num)->print_shop();  //print
			}
		}
	}
	void Print_employee(Networks** net) {
		int shop_num,emp_num;
		string net_name;
		cout << "end network name" << endl;
		cin >> net_name;
		for (int i = 0; i < SIZE; i++) {
			if (net[i]->get_name() == net_name) {  //exist
				cout << "enter shop number" << endl;
				cin >> shop_num;
				if (!net[i]->check_id(shop_num)) {  //exist
					cout << "enter emp id" << endl;
					cin >> emp_num;
					if (!net[i]->get_shop(shop_num)->check_id(emp_num)) //emp exist
						net[i]->get_shop(shop_num)->print_emp(emp_num);  //print
				}
			}
		}

	}
