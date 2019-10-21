/*
 * mystring.c
 *
 *  Created on: Jan 24, 2019
 *      Author: Katie Lin
 */
#include <stdlib.h>
#include "mystring.h"

/**
 * Calculate the length of the string,
 * excluding the terminating null byte ('\0')
 *
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;
	}

	return n;
}
/**
 * Calculate the length of the string
 * excluding the terminating null byte ('\0')
 *
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s != '\0') {
		n++;
		s++;
	}

	/* Note: This could have been written as:
	 while (*(s++)) n++;
	 */

	return n;
}

/** Duplicates a character string into a freshly-allocated block of memory.
 *
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		strcpy(newstr, s);
	}
	return newstr;
}

/**
 * Copies a string into an empty character array and returns a character pointer
 *
 * @param dest A character pointer to the index of the character array where the character would be copied to.
 * @param src A character pointer to the first character of the string that is to be copied from.
 * @param return new A pointer to the beginning of the new string.
 */
char* mystrcpy(char* dest, char* src) {

	char* new = dest;

	while(*src != '\0'){ //get all the characters in the array and terminates when find null terminator

		*dest = *src; //put whatever character is at the src into the destination
		src++; //increment the pointer
		dest++; //increment the pointer
	}

	*dest = '\0'; //add a null terminator

	return new;
}

/**
 * Copies a maximum of n characters of the string starting at address src to address dest. If there is no
 * null terminator among the first n bytes of src, then the string in dest won't be null terminated. If the
 * length of src is less than n, then a null terminator would be added to ensure that a total of n bytes are
 * written.
 *
 * @param dest A character pointer to the index of the character array where the string would be copied to.
 * @param src A character pointer to the first character of the string that is to be copied from.
 * @param n A given number of maximum characters.
 * @return new A pointer to the beginning of the new string.
 */
char* mystrncpy(char* dest, char* src, size_t n) {

	char* new = dest;
	size_t count = 0;
	while((count < n)&&(*src != '\0')){ //get all the characters in the array and terminates when find null terminator

		*dest = *src; //put whatever character is at the src into the destination
		src++;
		dest++;
		count++;

	}

	while(count < n){
		*dest = '\0'; //add a null terminator
		count++;
	}

	return new;
}

/**
 * Appends the n amount of characters from src at the end of dest, overwriting the null terminator, and then adds
 * a null terminator to the resulting string. The strings don't overlap and the dest string must have enough space
 * for the result. If src contains n or more bytes, the function writes n+1 bytes to dest from src including the null terminator.
 * The src does not need to be null terminated if it contains n or more bytes.
 *
 * @param dest A character pointer to the index of the character array where the character would be appended to.
 * @param src A character pointer to the first character of the string that is to be appended from.
 * @param n A given number of characters to be copied.
 * @return dest A pointer to the beginning of the new string.
 */
char* mystrncat(char* dest, char* src, size_t n) {
	// Must fill in

	char* new = dest;
	size_t count = 0; //how many were actually copied

	while(*dest != '\0'){ //increment the pointer of dest so that
		dest++;				//the new characters being appended won't be written over
	}

	while((*src != '\0') && (count < n)){
		*dest = *src; //put whatever character is at the src into the destination
		src++; //increment the pointer
		dest++; //increment the pointer
		count++;
	}

	if(count<=n)
	{
		*dest = '\0'; //add a null terminator
	}


	return new;
}

//need to write own tests for this

/**
 * Appends the characters from src at the end of dest, overwriting the null terminator, and then adds
 * a null terminate to the resulting string. The strings don't overlap and the dest string must have enough space
 * for the result. If the dest is not large enough, the program will behave unpredictably, causing potential buffer
 * overruns.
 *
 * @param dest A character pointer to the index of the character array where the character would be appended to.
 * @param src A character pointer to the first character of the string that is to be appended from.
 * @return new A pointer to the beginning of the new string.
 */
char* mystrcat(char* dest, char* src) {
	// Must fill in
	//need to write test for later

	char* new = dest;

	while(*dest != '\0'){ //increment the pointer of dest so that
		dest++;				//the new characters being appended won't be written over
	}

	while(*src != '\0'){
		*dest = *src; //put whatever character is at the src into the destination
		src++; //increment the pointer
		dest++; //increment the pointer
	}

	*dest = '\0'; //add a null terminator
	return new;
}

/** Duplicates n amount of characters from a string into a freshly-allocated block of memory. If the
 * character string  is longer than n, then only n bytes are copied, and a null terminator is added.
 *
 * @param s The string to duplicate.
 * @param n A given number of characters to be copied.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrndup(char* s, size_t n) {
	size_t given_length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(given_length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		strncpy(newstr, s, n);
	}
	return newstr;
}
