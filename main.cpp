#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
#include "employee.cpp"
#include "report.cpp"
#include "sort_employee.cpp"
#include "export_report.cpp"
#include "average_salary.cpp"

using namespace std;



// Global variables
const int max_size = 100;
Employee employees[max_size];

// Function to write default data to the file
void writeDefaultData(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < max_size; i++) {
            file << employees[i].name << " " << employees[i].id << " " << employees[i].department << " "
                 << employees[i].salary << " " << employees[i].designation << " " << employees[i].performancePercentage << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

// Function to load data from the file into the array
void loadData(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < max_size; i++) {
            file >> employees[i].name >> employees[i].id >> employees[i].department 
                 >> employees[i].salary >> employees[i].designation >> employees[i].performancePercentage;
        }
        file.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}

int main() {
    const string filename = "employee.txt";

    // Check if the file exists
    ifstream file(filename);
    if (!file.good()) {
        // File does not exist, create file with default data
        file.close();
        writeDefaultData(filename);
        cout << "File created and default data written." << endl;
    } else {
        // File exists, load data into the array
        file.close();
        loadData(filename);
        cout << "Data loaded from the file." << endl;
    }

    cout << "=================== Employ Management System ================" << endl;
    cout << "Welcome Admin" << endl;
    cout << "Login" << endl;
    string username,password;
    
    while (true)
    {
        cout<< "Username : ";
        cin>> username;
        cout << "Password : ";
        cin>> password;
        if(username == "admin" && password == "admin123"){
                system("CLS");
                break;
        }else{
                system("CLS");
                cout << "Wrong Credentials"<<endl;
        }
    }

    int choice;
    do {
        cout<<"=============== Main Menu ==================\n\n";
        cout<< "Press 1 to Add New Employee." << endl;
        cout<< "Press 2 to Update Employee Information." << endl;
        cout<< "Press 3 to Display All Employees." << endl;
        cout<< "Press 4 to Display Employees From Specific Department." << endl;
        cout<< "Press 5 to Display Employees Payrolls." << endl;
        cout<< "Press 6 to Sort Employees By Salary." << endl;
        cout<< "Press 7 to Export Payroll As CSV." << endl;
        cout<< "Press 8 to Display Employees Of Specific Designation." << endl;
        cout<< "Press 9 to Display Average Salary." << endl;
        cout<< "Press 10 to Save and Exit." << endl;
        cout<<"\n\n============================================\n";
        cout<< "Enter your choice : ";
        cin >> choice;
        system("CLS");
        Employee emp_temp;
        int id;
        int sortChoice;
        switch (choice){
            case 1:
                emp_temp = getEmployeeFromInput();
                addEmployee(employees,emp_temp,max_size);
                break;
            case 2:
                cout<<"Enter Id : "<<endl;
                cin>>id;
                updateEmployeeById(employees,id,max_size);
                break;
            case 3:
                displayAllEmployee(employees,max_size);
                break;
            case 4 :
                displaySpecificDeptEmployee(employees,max_size);
                break;
            case 5 :
                displayPayrollReportAllEmployee(employees,max_size);
                break;
            case 6 :
                cout<<"Sort Ascending or Descending? Enter (1 or 2) : ";
                cin>>sortChoice;
                switch (sortChoice)
                {
                    case 1:
                        sortEmployeesBySalaryAscending(employees,max_size);
                        cout<<"Sorted Sucessfully!"<<endl;
                        break;
                    case 2:
                        sortEmployeesBySalaryDescending(employees,max_size);
                        cout<<"Sorted Sucessfully!"<<endl;
                        break;
                    default:
                        cout<<"Invalid Chocie!!"<<endl;
                        break;
                }
                
                break;
            case 7 :
                writePayrollReportToCSV(employees,max_size);
                break;
            case 8 :
                displaySpecificDesignationEmployee(employees,max_size);
                break;
            case 9 :
                cout<< "Company Average salary is : " << averageSalary(employees,max_size)<<"$"<<endl;;
                break;

            case 10 :
                writeDefaultData(filename);
                cout<< "Exiting and saving ....";
                break;

            default:
                cout<< "/aInvalid input" << endl;
                break;
        }
    }while (choice != 10);
    return 0;
}
