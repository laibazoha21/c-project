#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
using namespace std;

double averageSalary(Employee* employees,int max_size){
    double totalSalary = 0.0;
    int employeeCount = 0;
    for (int i = 0; i < max_size; i++) {
        if (employees[i].id != -1) {
            employeeCount++;
            totalSalary += employees[i].salary;
        
        }
    }

    return totalSalary/employeeCount;

}