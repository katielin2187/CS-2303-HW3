/** mystruct.h
 * @author Katie Lin
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(struct Employee *e);
struct Employee* makeRandEmployee();
int randInt(int specifiedMax);
char* randString(int specifiedMax);
char randChar(void);
struct Employee** allocateNewEmployeeArray(int count);
void printStructs(struct Employee** EA, int count);
struct Employee** duplicateEmployeeArray(struct Employee** pointerSource, int arraySize);
void freeEmployeeArray(struct Employee** pointerSource, int arraySize);
struct Employee** duplicateDeepEmployeeArray(struct Employee** pointerSource, int arraySize);
struct Employee* makeEmployeeCopy(struct Employee* employee);

