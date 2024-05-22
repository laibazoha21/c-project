#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
#include "report.cpp"



using namespace std;

void writePayrollReportToCSV(Employee* employees, int max_size) {
    cin.ignore();
    string filename;
    cout << "Enter the filename and location path to save the CSV file. example : filename.csv: ";
    getline(cin, filename);

    // Open the file for writing
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error opening file " << filename << " for writing!" << endl;
        return;
    }

    // Write header
    outputFile << "ID,Name,Department,Salary,Designation,Bonus,Total Earning,Performance Percentage" << endl;

    // Write data
    double bonus, totalEarnings;
    for (int i = 0; i < max_size; i++) {
        if (employees[i].id != -1) {
            bonus = calculateBonus(employees[i].salary, employees[i].performancePercentage);
            totalEarnings = employees[i].salary + bonus;
            outputFile << employees[i].id << ","
                       << employees[i].name << ","
                       << employees[i].department << ","
                       << employees[i].salary << ","
                       << employees[i].designation << ","
                       << bonus << ","
                       << totalEarnings << ","
                       << employees[i].performancePercentage << endl;
        }
    }

    // Close the file
    outputFile.close();
    cout << "Payroll report has been successfully written to " << filename << endl;
}