/*
 * tests.c
 *
 *  Created on: Jan 24, 2019
 *      Author: Katie Lin
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystring.h"

bool tests(void)
{
	bool ok = false;
	bool ok1 = testMystrlen1();

	if (ok1) {
		puts("mystrlen1() passed.");
	}

	bool ok2 = testMystrlen2();
	if (ok2) {
		puts("mystrlen2() passed.");
	}

	bool ok3 = testMystrdup();
	if (ok3) {
		puts("mystrdup() passed.");
	}

	bool ok8 = testMystrndup();
	if (ok8) {
		puts("mystrndup() passed.");
	}

	bool ok4 = testMystrncpy();
	if (ok4) {
		puts("mystrncpy() passed.");
	}

	bool ok5 = testMystrcpy();
	if (ok5) {
		puts("mystrcpy() passed.");
	}

	bool ok6 = testMystrncat();
	if (ok6) {
		puts("mystrncat() passed.");
	}

	bool ok7 = testMystrcat();  //new test for mystrcat
	if (ok7) {
		puts("mystrcat() passed.");
	}

	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8; // Did all tests pass?
	return ok;
}

/** Tests the mystrlen1() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen1(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen1(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen1(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
}


/** Tests the mystrlen2() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen2(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen2(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen2(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
	return ok;
}

/** Test mystrdup() function by comparing it to the standard strdup().
 * @return true if it passes all tests.
 */
bool testMystrdup() {
	bool ok1 = false;

	char s1[] = "Some sample string."; // String we will duplicate.
	char* s2 = strdup(s1); // Copy it using standard function
	char* s3 = mystrdup(s1); // Copy it using my function

	if (strcmp(s2, s3) == 0) { // Same result!
		ok1 = true;
	}

	char* s4 = "Some other string."; // Another string for testing
	printf("Address of a local variable ok1, on stack:   %p\n", &ok1);
	printf("Address of original string, on stack:        %p\n", s1);
	printf("Address of first duplicate string, on heap:  %p\n", s2);
	printf("Address of second duplicate string, on heap: %p\n", s3);
	printf("Address of other string, on heap?:           %p\n", s4);

	bool ok = ok1;
	return ok;
}

/** Test mystrdup() function by comparing it to the standard strdup().
 * @return true if it passes all tests.
 */
bool testMystrndup() {
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	////////////////
	//test  string longer than n
	puts("\nTest 1: String longer than n.\n");

	char s1[] = "Some sample string."; // String we will duplicate.
	char* s2 = strndup(s1, 4); // Copy it using standard function
	char* s3 = mystrndup(s1, 4); // Copy it using my function

	if (strcmp(s2, s3) == 0) { // Same result!
		ok1 = true;
	}

	char* s4 = "Some other string."; // Another string for testing
	printf("Address of a local variable ok1, on stack:   %p\n", &ok1);
	printf("Address of original string, on stack:        %p\n", s1);
	printf("Original string:           %s\n", s1);
	printf("Address of first duplicate string, on heap:  %p\n", s2);
	printf("First duplicate string:           %s\n", s2);
	printf("Address of second duplicate string, on heap: %p\n", s3);
	printf("Second duplicate string:          %s\n", s3);
	printf("Address of other string, on heap?:           %p\n", s4);
	printf("Other string:           %s\n\n", s4);


	///////////////
	//test  string shorter than n
	puts("\n\nTest 1: String short than n.\n");
	char sa1[] = "Take It Easy."; // String we will duplicate.
	char* sa2 = strndup(sa1, 25); // Copy it using standard function
	char* sa3 = mystrndup(sa1, 25); // Copy it using my function

	if (strcmp(sa2, sa3) == 0) { // Same result!
		ok2 = true;
	}

	char* sa4 = "Some other string."; // Another string for testing
	printf("Address of a local variable ok2, on stack:   %p\n", &ok2);
	printf("Address of original string, on stack:        %p\n", sa1);
	printf("Original string:           %s\n", sa1);
	printf("Address of first duplicate string, on heap:  %p\n", sa2);
	printf("First duplicate string:           %s\n", sa2);
	printf("Address of second duplicate string, on heap: %p\n", sa3);
	printf("Second duplicate string:          %s\n", sa3);
	printf("Address of other string, on heap?:           %p\n", sa4);
	printf("Other string:           %s\n\n", sa4);


	////////
	//test string equal to n
	puts("\n\nTest 1: String equal to n.\n");
	char sb1[] = "Dancing With Our Hands Tied"; // String we will duplicate.
	char* sb2 = strndup(sb1, 27); // Copy it using standard function
	char* sb3 = mystrndup(sb1, 27); // Copy it using my function

	if (strcmp(sb2, sb3) == 0) { // Same result!
		ok3 = true;
	}

	char* sb4 = "Some other string."; // Another string for testing
	printf("Address of a local variable ok3, on stack:   %p\n", &ok3);
	printf("Address of original string, on stack:        %p\n", sb1);
	printf("Original string:           %s\n", sb1);
	printf("Address of first duplicate string, on heap:  %p\n", sb2);
	printf("First duplicate string:           %s\n", sb2);
	printf("Address of second duplicate string, on heap: %p\n", sb3);
	printf("Second duplicate string:          %s\n", sb3);
	printf("Address of other string, on heap?:           %p\n", sb4);
	printf("Other string:           %s\n\n", sb4);

	/////

	bool ok = ok1 && ok2 && ok3;
	return ok;
}
/*
 * Test mystrcpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrcpy() {
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	bool ok4 = false;

	//test copy empty string
	//test 1
	puts("\nTest 1: Copy empty string\n");
	char s1[] = "Some sample string."; // String we will copy.
	char s2[30]; // Empty string we will copy into

	char* s3 = mystrcpy(s2, s1); // Copy the string
	if (strcmp(s1, s2) == 0) { // Does original equal copy?
		ok1 = true; // Yes!
	}

	printf("The result: In testMystrcpy(): s3 = /%s/\n", s3);

	if (s3 == s2) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	//test copy string
	//test 2
	puts("\nTest 2: Copy into string with chars\n");
	char s1a[] = "Some sample string."; // String we will copy.
	char s2a[30] = "String with chars"; // Empty string we will copy into

	char* s3a = mystrcpy(s2a, s1a); // Copy the string
	if (strcmp(s1a, s2a) == 0) { // Does original equal copy?
		ok3 = true; // Yes!
	}

	printf("The result: In testMystrcpy(): s3a = /%s/\n", s3a);

	if (s3a == s2a) { // Is the return value correct?
		ok4 = true; // Yes!
	}

	///////


	bool ok = ok1 && ok2 && ok3 && ok4;
	return ok;
}

/*
 * Test mystrncpy() function.
 * @return true if pass, false if fail.
 */

bool testMystrncpy() {
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	//test 1
	puts("Test string with length equal to n\n");

	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it.
	char* s3a = strncpy(s1a, s2a, 6); // The result

	printf("In testMystrncpy(): s3a = /%s/\n", s3a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it.
	char* s3b = mystrncpy(s1b, s2b, 6); // The result

	if (strcmp(s3a, s3b) == 0) {
		ok1 = true;
	}

	printf("The result: In testMystrncpy(): s3a = /%s/\n", s3a);
	printf("The result: In testMystrncpy(): s3b = /%s/\n", s3b);


	//test 2
	puts("Test string with length less than n\n");

	char s1c[] = "012345678901234567890123456789"; // A long string
	char s2c[] = "ABC"; // A short string we will copy into it.
	char* s3c = strncpy(s1a, s2c, 6); // The result

	printf("In testMystrncpy(): s3c = /%s/\n", s3c);

	char s1d[] = "012345678901234567890123456789"; // A long string
	char s2d[] = "ABC"; // A short string we will copy into it.
	char* s3d = mystrncpy(s1d, s2d, 6); // The result

	if (strcmp(s3c, s3d) == 0) {
		ok2 = true;
	}

	printf("The result: In testMystrncpy(): s3c = /%s/\n", s3c);
	printf("The result: In testMystrncpy(): s3d = /%s/\n", s3d);


	// test 3
	puts("Test string with length greater than n\n");

	char s1e[] = "012345678901234567890123456789"; // A long string
	char s2e[] = "ABCDEFG"; // A short string we will copy into it.
	char* s3e = strncpy(s1e, s2e, 6); // The result

	printf("In testMystrncpy(): s3e = /%s/\n", s3e);

	char s1f[] = "012345678901234567890123456789"; // A long string
	char s2f[] = "ABCDEFG"; // A short string we will copy into it.
	char* s3f = mystrncpy(s1f, s2f, 6); // The result

	if (strcmp(s3e, s3f) == 0) {
		ok3 = true;
	}

	printf("The result: In testMystrncpy(): s3e = /%s/\n", s3e);
	printf("The result: In testMystrncpy(): s3f = /%s/\n", s3f);


	bool ok = ok1 && ok2 && ok3;
	return ok;
}

/*
 * Test mystrncat() function.
 * @return true if pass, false if fail.
 */
bool testMystrncat() {
	bool ok1 = false;
	bool ok2 = false;

	bool ok3 = false;
	bool ok4 = false;
	bool ok5 = false;
	bool ok6 = false;

	//test 6 chars
	//orig function

	puts("\n\nTest 1: length of string is equal to n");
	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it twice.

	char* s3a = strcpy(s1a, s2a);
	char* s4a =	strncat(s1a, s2a, 6); // The result

	printf("In testMystrncat(): s1a = /%s/\n\n", s1a);
	printf("The result for orig: ");
	printf("In testMystrncat(): s4a = /%s/\n", s4a);

	//own implementation
	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.

	char* s3b = strcpy(s1b, s2b);
	char* s4b = mystrncat(s1b, s2b, 6); // The result

	printf("In testMystrncat(): s1b = /%s/\n\n", s1b);
	printf("The result for own: ");
	printf("In testMystrncat(): s4b = /%s/\n", s4b);

	/////////////////
	//test less than 6 chars

	puts("\n\nTest 2: length of string is less than n");
	//orig function
	char s1c[] = "012345678901234567890123456789"; // A long string
	char s2c[] = "Lily"; // A short string we will copy into it twice.

	char* s3c = strcpy(s1c, s2c);
	printf("before my: s3c = /%s/\n", s3c);
	char* s4c =	strncat(s1c, s2c, 6); // The result               //debug

	printf("In testMystrncat(): s1c = /%s/\n", s1c);
	printf("In testMystrncat(): s3c = /%s/\n\n", s3c);
	printf("The result for orig: ");
	printf("In testMystrncat(): s4c = /%s/\n", s4c);

	//own implementation
	char s1d[] = "012345678901234567890123456789"; // A long string
	char s2d[] = "Lily"; // A short string we will copy into it twice.

	char* s3d = strcpy(s1d, s2d);
	printf("before my: s3d = /%s/\n", s3d);
	char* s4d = mystrncat(s1d, s2d, 6); // The result              // mystrncat(s1d, s3d, 6) has issues

	printf("In testMystrncat(): s1d = /%s/\n", s1d);
	printf("In testMystrncat(): s3d = /%s/\n\n", s3d);
	printf("The result for own: ");
	printf("In testMystrncat(): s4d = /%s/\n", s4d);

	////////
	//test more than 6 chars

	puts("\n\nTest 3: length of string is more than n");

	//orig function
	char s1e[] = "012345678901234567890123456789"; // A long string
	char s2e[] = "LilytheMalamute"; // A short string we will copy into it twice.

	char* s3e = strcpy(s1e, s2e);
	char* s4e =	strncat(s1e, s2e, 6); // The result                      //debug

	printf("In testMystrncat(): s1e = /%s/\n", s1e);
	printf("In testMystrncat(): s3e = /%s/\n\n", s3e);
	printf("The result for orig: ");
	printf("In testMystrncat(): s4e = /%s/\n", s4e);

	//own implementation
	char s1f[] = "012345678901234567890123456789"; // A long string
	char s2f[] = "LilytheMalamute"; // A short string we will copy into it twice.

	char* s3f = strcpy(s1f, s2f);
	char* s4f = mystrncat(s1f, s2f, 6); // The result                         // mystrncat(s1f, s3f, 6); -> has problems

	printf("In testMystrncat(): s1f = /%s/\n", s1f);
	printf("In testMystrncat(): s3f = /%s/\n\n", s3f);
	printf("The result for own: ");
	printf("In testMystrncat(): s4f = /%s/\n", s4f);


	/////
	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}

	///

	if (strcmp(s1c, s1d) == 0) {
		ok3 = true;
	}

	if (strcmp(s4c, s4d) == 0) {
		ok4 = true;
	}

	///

	if (strcmp(s1e, s1f) == 0) {
		ok5 = true;
	}

	if (strcmp(s4e, s4f) == 0) {
		ok6 = true;
	}



	return ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
}

/*
 * Test mystrcat() function.
 * @return true if pass, false if fail.
 */
bool testMystrcat() { //new created test for mystrcat
	bool ok1 = false;
	bool ok2 = false;

	bool ok3 = false;
	bool ok4 = false;

	bool ok5 = false;
	bool ok6 = false;


	//test 1
	puts("\n\nTest 1: \n");

	//orig function
	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3a = strcpy(s1a, s2a);
	char* s4a =	strcat(s1a, s2a); // The result

	printf("In testMystrcat(): s1a = /%s/\n\n", s1a);
	printf("The result for orig: ");
	printf("In testMystrcat(): s4a = /%s/\n", s4a);

	//own implementation
	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.
	char* s3b = strcpy(s1b, s2b);
	char* s4b = mystrcat(s1b, s2b); // The result

	printf("In testMystrcat(): s1b = /%s/\n\n", s1b);
	printf("The result for own: ");
	printf("In testMystrcat(): s4b = /%s/\n", s4b);

	//////

	//test 2
	puts("\n\nTest 2: \n");


	//orig function
	char s1c[] = "LilytheMalamute"; // A long string
	char s2c[] = "Lote"; // A short string we will copy into it twice.
	char* s3c = strcpy(s1c, s2c);
	char* s4c =	strcat(s1c, s2c); // The result    				//strcat(s1c, s3c); // does not match

	printf("In testMystrcat(): s1c = /%s/\n", s1c);
	printf("In testMystrcat(): s3c = /%s/\n\n", s3c);
	printf("The result for orig: ");
	printf("In testMystrcat(): s4c = /%s/\n", s4c);

	//own implementation
	char s1d[] = "LilytheMalamute"; // A long string
	char s2d[] = "Lote"; // A short string we will copy into it twice.
	char* s3d = strcpy(s1d, s2d);
	char* s4d = mystrcat(s1d, s2d); // The result              // mystrcat(s1d, s3d); // has issues

	printf("In testMystrncat(): s1d = /%s/\n", s1d);
	printf("In testMystrcat(): s3c = /%s/\n\n", s3c);
	printf("The result for own: ");
	printf("In testMystrncat(): s4d = /%s/\n", s4d);

	/////

	//test 3
	puts("\n\nTest 3: \n");


	//orig function
	char s1e[] = "012345678901234567890123456789"; // A long string
	char s2e[] = "LilytheMalamute"; // A short string we will copy into it twice.

	char* s3e = strcpy(s1e, s2e);
	char* s4e =	strcat(s1e, s2e); // The result

	printf("In testMystrcat(): s1e = /%s/\n", s1e);
	printf("In testMystrcat(): s3e = /%s/\n\n", s3e);
	printf("The result for orig: ");
	printf("In testMystrcat(): s4e = /%s/\n", s4e);

	//own implementation
	char s1f[] = "012345678901234567890123456789"; // A long string
	char s2f[] = "LilytheMalamute"; // A short string we will copy into it twice.

	char* s3f = strcpy(s1f, s2f);
	char* s4f = mystrcat(s1f, s2f); // The result

	printf("In testMystrcat(): s1f = /%s/\n", s1f);
	printf("In testMystrcat(): s3f = /%s/\n\n", s3f);
	printf("The result for own: ");
	printf("In testMystrcat(): s4f = /%s/\n", s4f);


	///

	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}

	//////

	if (strcmp(s1c, s1d) == 0) {
		ok3 = true;
	}

	if (strcmp(s4c, s4d) == 0) {
		ok4 = true;
	}

	////

	if (strcmp(s1e, s1f) == 0) {
		ok5 = true;
	}

	if (strcmp(s4e, s4f) == 0) {
		ok6 = true;
	}


	return ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
}
