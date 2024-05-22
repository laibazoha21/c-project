#include <iostream>
#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// Define the Employee struct
struct Employee {
    string name;
    int id;
    string department;
    double salary;
    string designation;
    double performancePercentage;

    // Default constructor to initialize default values
    Employee() : name("N/A"), id(-1), department("N/A"), salary(0.0), designation("N/A"),performancePercentage(0.0) {}
};

#endif
