#include "constants.h"
using namespace std;
class Employee {
	char name[LEN];
	int id;
	char profession[LEN];
	double salary;
	char status[LEN];

public:
	Employee(char* ,int,char* , double);
	Employee(char*, int, char*);
	Employee(char*, char*, double);
	Employee(char*, char*);
	Employee();

	void update(char*);
    void update(int);
	void update_pro(char*);
	void update(double);


	char* to_string();
	Employee* search_employee(int);
	Employee* get_name(char*);
	void copy_values(Employee);

};