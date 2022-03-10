#include <string.h>
#include "employee.h"
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber)
{
  const PtrToConstEmployee endPtr = ptr + tableSize;
  for (; ptr < endPtr; ptr++) // search until end of table  ptr++ will increment by what??
  {
    if (ptr->number == targetNumber) // check if it equals the Employee number
      return (PtrToEmployee)ptr;     // return location of the number to callee.
  }
  return NULL; // this will only happen if no Employee number matches in loop above
}

// Essentially the same functionality as above but comparing strings to check if equal
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName)
{
  const PtrToConstEmployee endPtr = ptr + tableSize;
  for (; ptr < endPtr; ptr++)
  {
    if (strcmp(ptr->name, targetName) == 0)
      return (PtrToEmployee)ptr;
  }
  return NULL;
}

// search by phone number

PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char *targetPhoneNumber)
{
  const PtrToConstEmployee tableEnd = ptr + tableSize; // find the address of the end of the table (last item)
  for (; ptr < tableEnd; ptr++)                        // loops each employee until the end of table
  {
    if (strcmp(ptr->phone, targetPhoneNumber) == 0) // check if strings values of phone number are the same
    {
      return (PtrToEmployee)ptr; // return ptr
    }
  }
  return NULL; // phone number never found
}

// search by salary

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary)
{
  const PtrToConstEmployee tableEnd = ptr + tableSize;
  for (; ptr < tableEnd; ptr++)
  {
    double diff = ptr->salary - targetSalary;
    if ((diff < .01) && (-1 * diff < .01)) // compare two salaries (less than 1cent of a difference)
    {
      return (PtrToEmployee)ptr;
    }
  }
  return NULL;
}