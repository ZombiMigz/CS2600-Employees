// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c

// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>

#include <stdlib.h>

#include "employee.h"

int main(void)
{

  // defined in employeeSearchOne.c
  PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *targetPhoneNumber);
  PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double targetSalary);

  // defined in employeeTable.c
  extern Employee EmployeeTable[];
  extern const int EmployeeTableEntries;

  PtrToEmployee matchPtr; // Declaration

  // Example Found Phone Number
  matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-1235");
  if (matchPtr != NULL)
    printf("Employee Phone Number 909-555-1235 is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Employee Phone Number is NOT found in the record\n");

  // Example NOT Found Phone Number
  matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "626-615-6295");
  if (matchPtr != NULL)
    printf("Employee Phone Number 626-615-6295 is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Employee Phone Number 626-615-6295 is NOT found in the record\n");

  // Example Found Salary
  matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
  if (matchPtr != NULL)
    printf("Salary $7.80 is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Salary $7.80 is NOT found in the record\n");

  // Example NOT Found Salary
  matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.42);
  if (matchPtr != NULL)
    printf("Salary $8.42 is in record %d\n", matchPtr - EmployeeTable);
  else
    printf("Salary $8.42 is NOT found in the record\n");

  return EXIT_SUCCESS;
}