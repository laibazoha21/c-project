#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"



using namespace std;

void sortEmployeesBySalaryAscending(Employee* employees,int max_size) {
    for (int i = 0; i < max_size - 1; ++i) {
        for (int j = 0; j < max_size - i - 1; ++j) {
            if (employees[j].salary > employees[j + 1].salary ) {
                
                Employee temp = employees[j];
                employees[j]  = employees[j + 1] ;
                employees[j + 1] = temp;
            }
        }
    }
}

void sortEmployeesBySalaryDescending(Employee* employees, int max_size) {
    for (int i = 0; i < max_size - 1; ++i) {
        for (int j = 0; j < max_size - i - 1; ++j) {
            if (employees[j].salary < employees[j + 1].salary ) {
                Employee temp = employees[j];
                employees[j]  = employees[j + 1] ;
                employees[j + 1] = temp;
            }
        }
    }
}