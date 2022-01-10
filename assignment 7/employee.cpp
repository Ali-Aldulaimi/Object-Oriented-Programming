#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include "constants.h"
#include "employee.h"

using namespace std;

//------------------------------------------------------------------constructors overloading definitions------------------------------------------------------------------------------

Employee::Employee(char* name,int id, char* pro, double salary) {
	strcpy_s(this->name, name);
	this->id = id;
	strcpy_s(this->profession, pro);
	this->salary = salary;
	strcpy_s(this->status, "Completed");

};

Employee::Employee(char* name, int id, char* pro) {
	strcpy_s(this->name, name);
	this->id = id;
	strcpy_s(this->profession, pro);
	strcpy_s(this->status, "Salary is unknown");
	this->salary = 0;
}
Employee::Employee(char* name, char* pro, double salary) {
	strcpy_s(this->name, name);
	strcpy_s(this->status, "ID is unknown");
	this->id = 0;
	strcpy_s(this->profession, pro);
	this->salary = salary;

};
Employee::Employee(char* name, char* pro) {
	strcpy_s(this->name, name);
	this->id = 0;
	strcpy_s(this->status, "Salary and ID are unknown");
	strcpy_s(this->profession, pro);
	this->salary = 0;
	}


Employee::Employee() {
	strcpy_s(this->name, "unknown ");
	this->id = 0;
	strcpy_s(this->profession, "unknown ");
	strcpy_s(this->status, "name,profession are unknown");
	this->salary = 0;
}



//--------------------------------------------------------------------------- Methods definitions------------------------------------------------------------------------------

void Employee::update(char* name) {
	strcpy_s(this->name, name);
	
	cout << "name has been updated successfully ." << endl;
	cout<< this->to_string() << endl;
	cout << endl;

}
void Employee::update(int id) {
	this->id = id;
	cout << "ID has been updated successfully ." << endl;
	cout<< this->to_string() << endl;
	cout << endl;
	}
void Employee::update_pro(char* pro) {
	strcpy_s(this->profession, pro);
	cout << "profession has been updated successfully ." << endl;
	cout << this->to_string() << endl;
	cout << endl;
}
void Employee::update(double salary) {
	this->salary = salary;
	cout << "salary has been updated successfully ." << endl;
	cout << this->to_string() << endl;
	cout << endl;
}
char* Employee::to_string() {
	const unsigned int size = (sizeof(name) + sizeof(id) + sizeof(profession) + sizeof(salary))+LEN;
	char temp[size];
	int actual_size = sprintf_s(temp, "%s   %d  %s     %.2lf     %s", this->name, this->id, this->profession,this->salary,this->status);
	temp[actual_size] = '\0';
	char* object_data = new char[actual_size + 1];
	strcpy_s(object_data, actual_size + 1, temp);
	return object_data;
	}


Employee* Employee::search_employee(int id) {
	if (this->id == id)
		return this;
        else return NULL;
		
}

Employee* Employee::get_name(char* name) {
	if (!strcmp(this->name, name))
		return this;

	return NULL;
}


//Employee* Employee::search_employee(char* name) {
//	if (!strcmp(this->name, name))
//		return this;
//
//	return NULL;
//}
	

void Employee::copy_values(Employee e) {
	this->id = e.id;
	this -> salary = e.salary;
	strcpy_s(this->name, LEN, e.name);
	strcpy_s(this->profession, LEN, e.profession);
	strcpy_s(this->status, LEN, e.status);

}





//---------------------------------------------------------------------------------Functions overloading ---------------------------------------------------------------------------------






Employee* get_name(Employee* emp, char* name, int size) {

	Employee* temp = NULL ;
	for (int i = 0; i < size;i++) {
	temp = emp[i].get_name(name);

		if (temp != NULL)
			break;
		
	}
	
	return temp;
}




Employee* search(Employee* emp, int id, int size) {

	Employee* temp = NULL;
	for (int i = 0; i < size;i++) {
		temp = emp[i].search_employee(id);

		if (temp != NULL)
			break;
	}

	return temp;

}


//--------------------------------------------------------------------------------Functions definitions--------------------------------------------------------------------------------
void init_object(Employee* emp) {
	char name[LEN];
	int id;
	char profession[LEN];
	double salary;
	cout << "Name: ";
	cin >> name;
	getchar();
	cout << "ID: ";
	cin >> id;
	cout << "Profession :" << endl;
	cin >> profession;
	getchar();
	cout << "Salary: ";
	cin >> salary;

	if (salary == 0 && id != 0 && name != NULL && profession != NULL) {
		emp[0] = Employee(name, id, profession);
	}

	else if (id == 0 && salary != 0 && name != NULL && profession != NULL) {
		emp[0] = Employee(name, profession, salary);
	}
	else if (id == 0 && salary == 0 && name && profession) {
		emp[0] = Employee(name, profession);
	}



	else emp[0] = Employee(name, id, profession, salary);


}

char menu() {
	char choice;
	cout << "----------------------- MENU ----------------------" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "A: Add new employee information" << endl;
	cout << "R: remove employee's information" << endl;
	cout << "S: search based on employee's ID" << endl;
	cout << "P: Print the List of the employees" << endl;
	cout << "U: Update the employees" << endl;
	cout << "Q: quit" << endl;
	cout << endl;
	cout << "Please choose an option : ";
	cin >> choice;
	getchar();
	return choice;
}