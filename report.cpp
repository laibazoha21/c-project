#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
using namespace std;

#ifndef REPORT_CPP
#define REPORT_CPP

double calculateBonus(double salary,double performancePercentage){
    return (salary * ((performancePercentage / 100) + 1)) - salary;

}

void displayPayrollReportAllEmployee(Employee* employees, int max_size) {
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "ID\tName\tDepartment\tSalary\tDesignation\tBonus\tTotal Earning\tPerformance Percentage" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    double bonus = 0.0;
    double totalEarnings = 0.0;
    for (int i = 0; i < max_size; i++) {
        if (employees[i].id != -1) {
            bonus = calculateBonus(employees[i].salary,employees[i].performancePercentage);
            totalEarnings = employees[i].salary + bonus;
            cout << employees[i].id << "\t"
                      << employees[i].name << "\t\t"
                      << employees[i].department << "\t"
                      << employees[i].salary<<"$" << "\t"
                      << employees[i].designation << "\t\t"
                      << bonus <<"$" << "\t"
                      << totalEarnings <<"$"  << "\t\t"
                      << employees[i].performancePercentage<<"%"<< endl;
        }
    }

    cout << "------------------------------------------------------------------------------------" << std::endl;
}

#endif