#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"



using namespace std;

Employee getEmployeeFromInput() {
    Employee emp;
    cin.ignore();
    // Input employee name
    cout << "Enter employee name: "; 
    while (true) {
        getline(cin, emp.name);
        if (!emp.name.empty()) {
            break;
        } else {
            cout << "Name cannot be empty. Please enter employee name: ";
        }
    }

    // Input employee ID
    cout << "Enter employee ID: ";
    while (!(cin >> emp.id) || emp.id <= 0) {
        cout << "Invalid input. Please enter a valid employee ID: ";
        cin.clear(); 
    }
    cin.ignore(); // Ignore newline character left in the buffer after cin

    // Input employee department
    cout << "Enter employee department: ";
    while (true) {
        getline(cin, emp.department);
        if (!emp.department.empty()) {
            break;
        } else {
            cout << "Department cannot be empty. Please enter employee department: ";
        }
    }

    // Input employee salary
    cout << "Enter employee salary: ";
    while (!(cin >> emp.salary) || emp.salary <= 0) {
        cout << "Invalid input. Please enter a valid employee salary: ";
        cin.clear();
    }
    cin.ignore(); // Ignore newline character left in the buffer after cin

    // Input employee designation
    cout << "Enter employee designation: ";
    while (true) {
        getline(cin, emp.designation);
        if (!emp.designation.empty()) {
            break;
        } else {
            cout << "Designation cannot be empty. Please enter employee designation: ";
        }
    }

    // Input employee salary
    cout << "Enter performace percentage: ";
    while (!(cin >> emp.performancePercentage) || emp.performancePercentage <= 0) {
        cout << "Invalid input. Please enter a valid employee performace percentage: ";
        cin.clear();
    }
    cin.ignore(); // Ignore newline character left in the buffer after cin

    return emp;
}


// Function to add a new employee to the array
void addEmployee(Employee* employees,const Employee& emp,int max_size) {
    bool added = false;
    for (int i = 0; i < max_size; i++) {
        if (employees[i].id == -1) {
            employees[i] = emp;
            cout << "Employee added successfully." << endl;
            added = true;
            break;
        }
    }

    if (!added) {
        cerr << "Employee array is full. Cannot add more employees." << endl;
    }
}

// Function to update an employee by their ID
void updateEmployeeById(Employee* employees,int id,int max_size) {
    bool found = false;
    for (int i = 0; i < max_size; i++) {
        if (employees[i].id == id) {
            Employee emp = getEmployeeFromInput();
            employees[i] = emp;
            cout << "Employee with ID " << id << " updated successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cerr << "Employee with ID " << id << " not found." << endl;
    }
}




void displayAllEmployee(Employee* employees, int max_size) {
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "ID\tName\t\tDepartment\tSalary\tDesignation\tPerformance Percentage" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < max_size; i++) {
        if (employees[i].id != -1) {
            cout << employees[i].id << "\t"
                      << employees[i].name << "\t\t"
                      << employees[i].department << "\t\t"
                      << employees[i].salary<<"$" << "\t"
                      << employees[i].designation << "\t\t"
                      << employees[i].performancePercentage<<"%" << endl;
        }
    }

    cout << "------------------------------------------------------------------------------" << std::endl;
}


void displaySpecificDeptEmployee(Employee* employees, int max_size) {
    string dept;
    cout<<"Please Enter Department Name : ";
    cin>>dept;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "ID\tName\t\tDepartment\tSalary\tDesignation\tPerformance Percentage" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < max_size; i++) {
        if (employees[i].department == dept && employees[i].id != -1) {
            cout << employees[i].id << "\t"
                      << employees[i].name << "\t\t"
                      << employees[i].department << "\t\t"
                      << employees[i].salary<<"$" << "\t"
                      << employees[i].designation << "\t\t"
                      << employees[i].performancePercentage<<"%" << endl;
        }
    }

    cout << "------------------------------------------------------------------------------" << std::endl;
}


void displaySpecificDesignationEmployee(Employee* employees, int max_size) {
    string desig;
    cout<<"Please Enter Designation Name : ";
    cin>>desig;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "ID\tName\t\tDepartment\tSalary\tDesignation\tPerformance Percentage" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < max_size; i++) {
        if (employees[i].designation == desig && employees[i].id != -1) {
           cout << employees[i].id << "\t"
                      << employees[i].name << "\t\t"
                      << employees[i].department << "\t\t"
                      << employees[i].salary<<"$" << "\t"
                      << employees[i].designation << "\t\t"
                      << employees[i].performancePercentage<<"%" << endl;
        }
    }

    cout << "------------------------------------------------------------------------------" << std::endl;
}