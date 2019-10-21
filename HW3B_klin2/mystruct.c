/** mystruct.c
 * @author Katie Lin
 */

#include <string.h>
#include <stdlib.h>
#include "mystruct.h"

/**
 * Allocates an Employee struct and fills in its fields
 *
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {

	//puts("here");

	struct Employee* temp = (struct Employee*) malloc(sizeof(struct Employee));
	//later must write function that frees everything from memory,
	//take in array of employee pointers and pass pointers into free (individually) and then free it


	//puts("here2");
	temp->birth_year = birth; // Year the employee was born

	//puts("here3");
	temp->start_year = start; // When employee started with the company.

	//puts("here4");
	strcpy(temp->name, name); //array inside struct

	//printf("temp name is : %s\n", temp->name);

	return temp;
}


/**
 * Prints out the contents in the struct, Employee.
 *
 * @param e a pointer to the a Employee struct.
 */
void printEmployee(struct Employee* e) {

	puts("Inside print employee.");
	printf("Inside printStructs: pointer inside: %p\n", e); //works for testALLocateNEA

	printf("Birth year = %d\n", e->birth_year); 					// Year the employee was born
	printf("Starting year = %d\n", e->start_year); 					// When employee started with the company.
	printf("Name = %s\n", e->name); 								//array inside struct

}


/**
 * Allocates an Employee struct and fills in its fields with random data.
 *
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeRandEmployee() {

	puts("Inside makerandEmployee: \n");
	int birth = randInt(2019);
	printf("Birth %d\n", birth);
	int start = randInt(2019);
	printf("Start: %d\n", start);
	char* name = randString(7);
	printf("Name: %s\n", name);

	struct Employee* rand = makeEmployee(birth, start, name);

	return rand;
}


/**
 * Function that returns a random integer from 0 to some specified maximum, inclusive.
 */
int randInt(int specifiedMax){
	//have to write so this number is in the range of 0 < number < specifiedMax

	int n = specifiedMax;
	int number = rand()%n;

	return number;
}


/**
 * Function that generates a random string. Allocates space and returns pointer to freshly allocated string
 *
 * @param specifiedMax The specified maximum value of characters that
 */
char* randString(int specifiedMax){

	//malloc inside here


	puts("Inside randString: ");

	char* randString = (char*) malloc(specifiedMax + 1);
	char* first = randString;

	for(int i = 0; i< specifiedMax; i++,randString++){
		*randString= randChar(); //set the string at that pointer to be a random character
		//printf("char %c\n", *new);
	}

	*randString = '\0'; //add null terminator
	printf("The generated string is %s\n", first);

	return first;
}


/**
 * Function that generates a random character.
 */
char randChar(void){

	int r = rand();
	char randomLetter = 'A' + (r % 26);

	return randomLetter;
}

/**
 * Function that take in a count and allocates an array, which can hold that many pointers to the
 * Employee struct, then fill each element of the array with a pointer to a newly created struct
 * filled with random data.
 *
 * @param count The number of pointers that the newly created array can hold to the Employee struct.
 * @return
 */
struct Employee** allocateNewEmployeeArray(int count){

	puts("Inside allocateNewEmployeeArray: \n");
	struct Employee** EA = (struct Employee**) malloc(sizeof(struct Employee*) * count);
	struct Employee** first = EA;										//pointer to the first element of the array of pointers

	for(int i = 0; i< count; i++){
		printf("\nInside loop, Calling makeRandEmployee for employee: %d\n", i);

		EA[i] = makeRandEmployee();
		printf("\nInside loop, printing employee: %d\n", i);
		printEmployee(EA[i]);

	}

	return first;
}


/**
 *Function takes an array of pointers and a count, and prints out all of the structs.
 *
 *@param pointers The pointer to the first element of the array of pointers to Employee structs.
 *@param count The amount of structs to be printed out.
 */
void printStructs(struct Employee** EA, int count){

	printf("Inside printStructs: pointer inside: %p\n", EA); //works for testALLocateNEA

	puts("here now");
	//printf("Inside printStructs: pointer inside: %p\n", *EA);
	//puts("here");
	//fflush();

	//printEmployee(*EA);
	//puts("here");

	for(int i = 0; i < count; i++){
		//puts("here");
		printf("Calling printEmployee: %d\n", i);
		//printEmployee(EA);
		printEmployee(*EA);
		EA++;
		puts("\n");
	}

	puts("Leaving printStructs: \n");

}

/**
 * Function that duplicates an array of pointers to Employee structs.
 *
 * @return first The pointer to the new array of pointers.
 */
struct Employee** duplicateEmployeeArray(struct Employee** pointerSource, int arraySize){

	puts("Inside duplicateEmployeeArray: \n");
	struct Employee** EA = (struct Employee**) malloc(sizeof(struct Employee*) * arraySize);
	struct Employee** first = EA;						//pointer to the first element of the array of pointers

	for(int i = 0; i< arraySize; i++){
		printf("\nInside loop, setting pointer equal for element: %d\n", i);

		EA[i] = *pointerSource;
		pointerSource++;
	}
	return first;
}

/**
 * Function that takes an array of pointers to the struct, and frees (deallocates) all the
 * structs pointed to.
 */
void freeEmployeeArray(struct Employee** pointerSource, int arraySize){

	puts("Inside freeEmployeeArray: \n");
	struct Employee** EA = (struct Employee**) malloc(sizeof(struct Employee*) * arraySize);
	//struct Employee** first = EA;							//pointer to the first element of the array of pointers

	for(int i = 0; i< arraySize; i++){
		printf("\nInside loop, freeing pointer, %p, of element : %d\n", EA, i);

		free(EA[i]);
		pointerSource++;
	}
}

/**
 * Function that duplicates an array of pointers to Employee structs.
 *
 * @return first The pointer to the new array of pointers.
 */
struct Employee** duplicateDeepEmployeeArray(struct Employee** pointerSource, int arraySize){

	puts("Inside duplicateEmployeeArray: \n");
	struct Employee** EA = (struct Employee**) malloc(sizeof(struct Employee*) * arraySize);
	struct Employee** first = EA;						//pointer to the first element of the array of pointers

	for(int i = 0; i< arraySize; i++){
		printf("\nInside loop, setting pointer equal for element: %d\n", i);

		EA[i] = makeEmployeeCopy(*pointerSource);
		pointerSource++;
	}
	return first;
}

/**
 * Allocates an Employee struct and fills in its fields with the same data as the given employee.
 *
 * @param employee The pointer to the struct employee whose data is going to be copied into the new employee.
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployeeCopy(struct Employee* employee) {


	puts("Inside makeEmployeeCopy: \n");
	/*int birth = employee->birth_year;
	//printf("Birth %d\n", birth);
	int start = employee->start_year;
	//printf("Start: %d\n", start);
	//char* name = employee->name;
	//printf("Name: %s\n", name);

	//*/


	struct Employee* temp = (struct Employee*) malloc(sizeof(struct Employee));
	//later must write function that frees everything from memory,
	//take in array of employee pointers and pass pointers into free (individually) and then free it


	//puts("here2");
	temp->birth_year = employee->birth_year; // Year the employee was born

	//puts("here3");
	temp->start_year = employee->start_year; // When employee started with the company.

	//puts("here4");
	char* name = strcpy(temp->name, employee->name); //array inside struct

	//
	struct Employee* eCopy = makeEmployee(temp->birth_year, temp->start_year, name);


	return eCopy;
}
