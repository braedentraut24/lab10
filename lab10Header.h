#ifndef LAB10HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "colors.h"

/* HEADER DOCUMENTATION *
 * Location:	Temple University Computer Science
 * Programmer:	Braeden Trautz
 * Class:	Introduction to C Programming 1057 Fall 2018 Section 005
 * Assignment: 	Lab 10 - OMR Data Miner HEADER FILE
 * Date:	28 November 2018
 * Version:	1
 * Description: A header file to increase abstraction levels for myself when programming. Incldues libraries and a
 *		printStartupBanner function, as well as a bubble_response data structure.
 */

#define PRIME_PROGRAMMER "Braeden Trautz"
#define TITLE "OMR Data Miner"
#define DESCRIPTION "This program will allow you to mine data from the data.csv spreadsheet"

#define NAME_LEN 50
#define NUM_QS 11
#define MAX_STUDENTS 234

typedef struct {
	int id;
	char name[NAME_LEN];
	char choices[NUM_QS];
} bubble_response;

void printStartupBanner( void );
int choiceMenu ( );
void execChoiceOne ( bubble_response fullData[] );
void execChoiceTwo ( bubble_response fullData[] );
void execChoiceThree ( bubble_response fullData[] );
void execChoiceFour ( bubble_response fullData[] );
void printOneStudent ( bubble_response fullData[], int idx );
void convertToLC( char *input );

/*
 * Function:	printStartupBanner ( void )
 * Programmer: 	Braeden Trautz
 * Date:	10 October 2018
 * Inputs:	* None *
 * Outputs: 	Prints - program description, date compiled, and programmer name, along with info sheet.
 * Globals:	PRIME_PROGRAMMER - programmer's name
 *		__DATE__	 - date compiled
 *		TITLE		 - title of the program
 *		DESCRIPTION	 - description of program
 * Returns:	* None *
 * Description: Prints out a the programmer's name, the date compiled, and then program title and description.
 */
void printStartupBanner(void)
{

	printf(BOLDRED "This program written by %s and compiled on %s\n\n", PRIME_PROGRAMMER, __DATE__);
	printf("%s\n",TITLE);
	printf("%s\n\n",DESCRIPTION RESET);

}

#endif // LAB10HEADER_H
