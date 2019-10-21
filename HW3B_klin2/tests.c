/*
 * tests.c
 *
 *  Created on: Feb 4, 2019
 *      Author: Katie Lin
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

bool tests(void)
{
	bool ok = false;

	bool ok1 = testPrintEmployee();
	if (ok1) {
		puts("printEmployee() passed.");
	}

	bool ok2 = testMakeEmployee();
	if (ok2) {
		puts("makeEmployee() passed.");
	}

	////

	bool ok3 = testRandInt();
	if (ok3) {
		puts("randInt() passed.");
	}

	bool ok4 = testRandChar();
	if (ok4) {
		puts("randChar() passed.");
	}

	bool ok5 = testRandString();
	if (ok5) {
		puts("randString() passed.");
	}

	bool ok6 = testMakeRandEmployee();
	if (ok6) {
		puts("makeRandEmployee() passed.");
	}

	///////

	bool ok8 = testPrintStructs();
	if (ok8) {
		puts("printStructs() passed.");
	}

	bool ok7 = testAllocateNewEmployeeArray();
	if (ok7) {
		puts("allocateNewEmployeeArray() passed.");
	}

	//////////

	bool ok9 = testDuplicateEmployeeArray();
	if (ok9) {
		puts("duplicateEmployeeArray() passed.");
	}

	bool ok10 = testFreeEmployeeArray();
	if (ok10) {
		puts("freeEmployeeArray() passed.");
	}

	////////////

	bool ok11 = testMakeEmployeeCopy();
	if (ok11) {
		puts("makeEmployeeCopy() passed.");
	}

	bool ok12 = testDuplicateDeepEmployeeArray();
	if (ok12) {
		puts("duplicateDeepEmployeeArray() passed.");
	}

	///////////

	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11; // Did all tests pass?
	return ok;
}

/**
 * Test the testDuplicateDeepEmployeeArray() function by creating known array of pointers to employee structs
 * and calling the function and then comparing the data held in the structs to the original. through printing.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 *
 */
bool testDuplicateDeepEmployeeArray(){
	bool ok = false;

	puts("---------testDuplicateDeepEmployeeArray---------------------");
	struct Employee* EA[3];

	for(int i =0; i<3; i++){
		EA[i] = NULL;
	}
	puts("--------------------making employees for orig-------------------");
	//employee 1
	puts("\nEmployee 1: ");
	EA[0] = makeEmployee(1952, 1999, "Mike Ciaraldi");
	//puts("here");
	printEmployee(EA[0]);

	//employee 2
	puts("\nEmployee 2: ");
	EA[1] = makeEmployee(1962, 1997, "Percy Quill");
	printEmployee(EA[1]);

	//employee 3
	puts("\nEmployee 3: ");
	EA[2] = makeEmployee(1972, 2007, "Kylo Stark");
	printEmployee(EA[2]);

	puts("---------------------calling dup deep array now--------------------");

	struct Employee** newCopy = duplicateDeepEmployeeArray(EA, 3);

	puts("---------------------printing dup deep array now--------------------");
	printStructs(newCopy, 3);

	puts("-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-------");


	return ok;
}

/**
 * Test the makeEmployeeCopy() function by creating known employee struct and calling the function
 * and then comparing the data held in the structs to the original.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeEmployeeCopy(){
	bool ok = false;

	puts("---------test make employee copy ---------------------");
	puts("\nEmployee percy: ");
	struct Employee* percy = makeEmployee(1962, 1997, "Percy Quill");
	puts("print the original-------------\n");
	printEmployee(percy);

	puts("\nEmployee percy copy: ");
	struct Employee* percyCopy = makeEmployeeCopy(percy);
	puts("print the copy---------------\n");
	printEmployee(percyCopy);

	puts("---------done with test ---------------------\n");

	bool c1 = percy->birth_year == percyCopy->birth_year;
	printf("C1 is: %s\n", c1 ? "true" : "false");
	bool c2 = percy->start_year == percyCopy->start_year;
	printf("C2 is: %s\n", c2 ? "true" : "false");
	//bool c3 = percy->name == percyCopy->name; // will check if the two pointers are the same., won't work
	//printf("C3 is: %s\n", c3 ? "true" : "false");

	printf("percy name is: %s\n", percy->name  );
	printf("percyCopy name is: %s\n", percyCopy->name);

	bool c3b = !strcmp(percy->name, percyCopy->name); //strcmp return a 0, which is false if they match

	printf("C3b is: %s\n", c3b ? "true" : "false");


	if (c1 && c2 && c3b){
		ok = true;
	}
	return ok;
}


/**
 * Test the FreeEmployeeArray() function by function by calling it and seeing if it is able to run.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testFreeEmployeeArray(){

	bool ok = true;

	struct Employee* EA[3];

	for(int i =0; i<3; i++){
		EA[i] = NULL;
	}

	puts("---------test free---------------------");
	//employee 1
	puts("\nEmployee 1: ");
	EA[0] = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(EA[0]);

	//employee 2
	puts("\nEmployee 2: ");
	EA[1] = makeEmployee(1962, 1997, "Percy Quill");
	printEmployee(EA[1]);

	//employee 3
	puts("\nEmployee 3: ");
	EA[2] = makeEmployee(1972, 2007, "Kylo Stark");
	printEmployee(EA[2]);

	///////////////

	puts("---------calling testFreeEmployeeArray---------------------\n");
	freeEmployeeArray(EA, 3);

	return ok;
}

/**
 * Test the duplicateEmployeeArray() function by function by creating a known array of structs
 * and then calling duplicateEmployeeArray and comparing its output pointer to the original
 * pointer, while also checking to see if both arrays print the same content.
 *
 * @return ok A boolean value that indicates if the pointer values inside the newly
 * allocated array are the same.
 */
bool testDuplicateEmployeeArray(){

	bool ok = false;
	struct Employee* EA[3];

	for(int i =0; i<3; i++){
		EA[i] = NULL;
	}

	//employee 1
	puts("\nEmployee 1: ");
	EA[0] = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(EA[0]);

	//employee 2
	puts("\nEmployee 2: ");
	EA[1] = makeEmployee(1962, 1997, "Percy Quill");
	printEmployee(EA[1]);

	//employee 3
	puts("\nEmployee 3: ");
	EA[2] = makeEmployee(1972, 2007, "Kylo Stark");
	printEmployee(EA[2]);

	///////////////

	puts("---------calling duplicateEmployeeArray---------------------\n");
	struct Employee** result = duplicateEmployeeArray(EA, 3);

	//test to see if pointers match
	if (EA[0] == *result){
		printf("Pointers are equal. Good.");
		ok = true;
	}

	puts("---------PRINT results!!!!!!!!---------------------\n");
	printStructs(result, 2);
	puts("---------Done!!!!!!!!---------------------\n");


	return ok;
}

/**
 * Test the printStructs() function by function by creating a known array of pointers to known structs
 * and printing it.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testPrintStructs(){

	struct Employee* EA[3];

	for(int i =0; i<3; i++){
		EA[i] = NULL;
	}

	//employee 1
	puts("\nEmployee 1: ");
	EA[0] = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(EA[0]);

	//employee 2
	puts("\nEmployee 2: ");
	EA[1] = makeEmployee(1962, 1997, "Percy Quill");
	printEmployee(EA[1]);

	//employee 3
	puts("\nEmployee 3: ");
	EA[2] = makeEmployee(1972, 2007, "Kylo Stark");
	printEmployee(EA[2]);


	puts("\nCalling printStructs from tests: \n");

	printf("pointer outside: %p\n", EA);

	puts("---------TEST PRINT STRUCTS---------------------\n");

	puts("test 1, Print out 2/3 employees:\n");
	printStructs(EA, 2);

	puts("test 2, Print out 3/3 employees:\n");
	printStructs(EA, 3);

	puts("--------------------------------------------\n");


	return true;
}

/**
 * Test the allocateNewEmployeeArray() function by calling allocateNewEmployeeArray
 * and checking the output to see if it seems to be printing out random employees of the
 * given number.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testAllocateNewEmployeeArray(){

	puts("//////////////////////////////////////////////////////////\n");

	puts("testing testAllocateNewEmployeeArray.\n");
	puts("Test 1, allocate New employee Array:\n");
	struct Employee** EA = allocateNewEmployeeArray(3);

	puts("\n\nTest 1, print the structs:\n");
	printf("pointer outside: %p\n", EA);

	puts("/////////////print structs///////////////////////////////\n");
	printStructs((struct Employee**) EA, 2);

	/*puts("test 2, Print out 3/3 employees:\n");
	printStructs((struct Employee**) EA, 3);*/

	return true;
}

/**
 *  Test the makeRandEmployee() function by calling makerandEmployee and checking to see if
 *  its outputs are random for the birth, start year, and name.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeRandEmployee() {

	//test makeRandEmployee
	puts("\nTest 4, randString: We're about to start calling makeRandEmployee.\n");

	puts("Employee 1: \n");
	struct Employee* a;
	a = makeRandEmployee();
	puts("\nPrinting employee 1: \n");
	printEmployee(a);

	return true;
}


/**
 * Test the randString() function by calling randString and printing out the string that
 * it returns to see if it seems to be random.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testRandString() {

	//test randString function to see if it seems to generate a random String
	puts("\nTest 3, randString: We're about to start calling random string.\n");
	char x[6];
	for(int i = 0; i<5; i++){
		strncpy (x, randString(5), 5);
		printf("String x: %s\n", x);
	}

	return true;
}


/**
 * Test the randChar() function by calling randChar and printing out the character that
 * it returns to see if it seems to be random.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testRandChar() {

	//test randChar function to see if it seems to generate a random character
	puts("\nTest 2, randChar: We're about to start calling random char.\n");
	for(int i = 0; i<5; i++){
		char x = randChar();
		printf("char x: %c\n", x);
	}

	return true;
}

/**
 * Test the randInt() function by calling randInt and printing out the value that
 * it returns to see if it seems to be random.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testRandInt() {

	///// test randInt function to see if it seems to generate a random integer
	puts("\nTest 1, randInt: We're about to start calling random integer.\n");
	for(int i = 0; i<5; i++){
		char x = randInt(20);
		printf("int x: %d\n", x);
	}

	return true;
}

/**
 * Test the printEmployee() function by creating a known struct and printing it.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testPrintEmployee() {

	struct Employee e; // Variable to hold employee
	e.birth_year = 1952; // Put data into numeric fields
	e.start_year = 1999;
	// Copy into string field. Be sure not to overflow it.
	strncpy(e.name, "Mike Ciaraldi", MAX_NAME);
	e.name[MAX_NAME] = '\0'; // Be sure string is terminated.

	printEmployee(&e);

	return true;
}


/**
 * Test the make Employee() function by making an employee with known data and printing it.
 *
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeEmployee() {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);

	return true;
}
