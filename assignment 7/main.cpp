#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "constants.h"
#include "employee.h"

using namespace std;

Employee* enlarge_array(Employee* emp, int* size) {
	Employee* temp = NULL;
	(*size)++;
	try {
		temp = new Employee[*size];
	}
	catch (bad_alloc xa) {
		cout << "\nAllocation failure\n";
	}

	for (int j = 0; j < *size - 1; j++)

		temp[j + 1] = emp[j];

	delete emp;

	return temp;
}





Employee* remove_employee(Employee* emps, int index, int* size) {

	Employee* temp = new Employee[*size - 1];
	int counter = 0;
	for (int i = 0;i <*size;i++) {

		if (i != index) {
			temp[counter].copy_values(emps[i]);

			counter++;
		}
	}

	delete emps;
	(*size)--;


	return temp;


}



char menu();
Employee* get_name(Employee*,char*, int);
void init_object(Employee*);
Employee* enlarge_array(Employee*, int*);
Employee* search(Employee*,int, int);




int main() {
	int size = 0;
	int i;


	//Here we declare Employee pointer.
	Employee* employees = NULL;
	char choice;
	char answer;
	choice = 'y';

	do {
		char option = menu();


		if (option == 'A'||option=='a') {

			do {

				cout << "Enter Employee data: " << endl;
				employees = enlarge_array(employees, &size);
				init_object(employees);
				cin.get();
				cout << "---------------------------------------------------" << endl;

				cout << "Employee's table" << endl;
				cout << "  NAME  " << "ID  " << "PROFESSION " << "   SALARY   " << "   Status  " << endl;
				for (i = 0; i < size; i++) {
					cout << i + 1<<".";
					cout<<employees[i].to_string() << endl;
					
					cout << endl;

				}
				cout << "---------------------------------------------------" << endl;
				cout << "Do you want to continue? (y/n) ";
				cin.get(choice);

			} while (choice == 'y');
		}





		if (option == 'R'||option=='r') {

			do {
				int id;
				char choice;
				cout << "Enter employee ID" << endl;
				cin >> id;
				cout << " Are you sure you want to remove this employee ? (y/n)" << endl;
				cin >> choice;
				if (choice == 'y') {
					int index = -1;
					Employee* e = NULL;
					for (int i = 0;i < size;i++) {
						e = employees[i].search_employee(id);
						if
							(e != NULL) {
							index = i;
							break;

						}
					}



					if (index != -1) {

						employees = remove_employee(employees, index, &size);
					}
				}
				cin.get();

				cout << "Do you want to continue? (y/n) ";
				cin.get(answer);
				getchar();

			} while (answer == 'y');

		}




		if (option == 'S'||option =='s') {

			do {
				int id;
				char select;
							
				cout << "---------------------------------------------------" << endl;
				cout << "N: search based on the employee's name ." << endl;
				cout << "I: search based on the employee's ID ." << endl;
				cout << "---------------------------------------------------" << endl;
				cin >> select;
				if (select == 'N' || select == 'n') {
					do {
						char name[LEN];
						cout << "Please enter the Employee's name : " << endl;
						cin >> name;
						char* ptr = name;
										
						getchar();
						Employee* temp = get_name(employees,ptr, size);
					
						if (temp != NULL) {
							cout << "Emoloyye's informations : " << temp->to_string() << endl;

						}
						else cout << "There is no mathced result !" << endl;

						cin.get();
						cout << "Do you want to continue? (y/n) ";
						cin.get(answer);
						
					} while (answer == 'y');
				}






				if (select == 'I' || select == 'i') {

					do {
				cout << "Please enter the Employee's ID : " << endl;
				cin >> id;
				cin.get();
				Employee* temp = search(employees, id, size);
				if (temp != NULL) {
					cout << "Emoloyye's informations :" << temp->to_string() << endl;

				}
				else cout << "There is no mathced result !" << endl;

				cin.get();
				cout << "Do you want to continue? (y/n) ";
				cin.get(answer);
				
							} while (answer == 'y');
		}




			} while (answer == 'y');
			

		}



		if (option == 'P'||option=='p') {
			cout << "currrent size" << size << endl;
			cout << "---------------------------------------------------" << endl;
			for (i = 0; i < size; i++) {
				cout << i + 1 << ".";
				cout << employees[i].to_string() << endl;
				
				cout << endl;

			}
			cout << "---------------------------------------------------" << endl;
		}






		if (option == 'U'||option=='u') {
			int index;
			cout << "---------------------------------------------------" << endl;
			for (i = 0; i < size; i++) {

				cout << i + 1 << ".";
				cout << employees[i].to_string() << endl;

				cout << endl;

			}

			cout << "---------------------------------------------------" << endl;
			cout << "Which Employee would you like to update ?" << endl;
			cin >> index;
			for (i = 0; i < size; i++) {
				if (index - 1 == i) {
					cout << " -";
					cout  << employees[i].to_string() << endl;
					cout << endl;

				}
			}
			int update;
			char name[LEN];
			int id;
			char profession[LEN];
			double salary;
			cout << "Select an option : " << endl;
			cout << "1. " << "Change name ." << endl;
			cout << "2. " << "Change id ." << endl;
			cout << "3. " << "Change profession ." << endl;
			cout << "4. " << "Change salary ." << endl;
			cin >> update;

			switch (update) {
			case 1:
				cout << "Enter new name :" << endl;
				cin >> name;
				if (employees != NULL) {
					employees[index - 1].update(name);
					break;
			case 2:
				cout << "Enter new ID :" << endl;
				cin >> id;
				
					employees[index - 1].update(id);
					break;
				
			case 3:
				cout << "Enter new profession :" << endl;
				cin >> profession;
				employees[index - 1].update_pro(profession);
				break;
			case 4:
				cout << "Enter new salary :" << endl;
				cin >> salary;
				employees[index - 1].update(salary);
				break;

				}
			}
		}






		if (option == 'Q'||option=='q') {

			cout << "Goodbye !!" << endl;
			break;
		}






	} while (choice == 'n');



	//Here we delete reserved memory.
	delete[] employees;
	return 0;

	}

