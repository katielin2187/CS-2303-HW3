/*
 ============================================================================
 Name        : HW3Astarter.c
 Author      : Katie Lin (klin2)
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"

/**
 *The main function that calls production and checks to see if it is working properly.
 *
 *@param argc Number of words on the command line
 *@param argv Array of pointers to character strings representing the words on the command line.
 * @return true if tests succeed
 *         false if something went wrong in the tests.
 */
int main(int argc, char* argv[]) {
	puts("!!!Hello class, we are working HW3A!!!"); /* prints !!!Hello World!!! */
	if(tests())
	{
		puts("Tests succeeded.");
		if(production(argc, argv))
		{
			puts("Production successful.");
		}
		else
		{
			puts("Tests succeeded, but production didn't");
		}
	}
	else
	{
		puts("Tests did not succeed.");
	}

	return EXIT_SUCCESS;
}
