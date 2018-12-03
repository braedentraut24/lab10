// * Change this #include statement to work when downloading from github *
// * Check included header file in repo for further documentation! *
#include "../include/lab10Header.h"

/* PROGRAM DOCUMENTATION *
 * Location: 	Temple University Computer Science
 * Programmer: 	Braeden Z. Trautz
 * Class: 	Introduction to C Programming 1057 Fall 2018
 * Assignment:	Lab 10 - Sorting and Searching
 * Date:	28 November 2018
 * Version: 	1
 * Description:	An interactive "Scantron" sheet data miner.
 */

int main ( )
{

	printStartupBanner();

	// * Initiate Variables *
	int i, id, menuChoice;
	double grade;
	char nameOne[NAME_LEN], nameTwo[NAME_LEN];
	char choices[NUM_QS];
	char var;
	bubble_response currentStudent;
	bubble_response fullData[MAX_STUDENTS];

	// * Create Data Structure *
	FILE *IN = fopen("data.csv", "r");
	for ( i = 0; i < MAX_STUDENTS; i++ ) {
		fscanf(IN, "%d", &id);
		fscanf(IN, "%c", &var);
		currentStudent.id = id;
//		printf("Id reported as %d\t", currentStudent.id);

		fscanf(IN, "%s", nameOne);
		fscanf(IN, "%[^,],", nameTwo);
		strcat(nameOne, nameTwo);
		strcpy(currentStudent.name, nameOne);
//		printf("Name reported as %s\n", currentStudent.name);

//		printf("Choices reported as: ");
		int j;
		for ( j = 0; j < NUM_QS; j++ ) {
			fscanf(IN, "%c", &choices[j]);
			fscanf(IN, "%c", &var);
			currentStudent.choices[j] = choices[j];
//			printf("%c,", currentStudent.choices[j]);
		}
//		printf("\n");

		fscanf(IN, "%f", &grade);
		fscanf(IN, "%c", &var);
		fullData[i] = currentStudent;
	}

	// * Run Menu Options Until Exit *
	menuChoice = choiceMenu();
	while ( 1 ) {

		switch ( menuChoice ) {

			case 1:
				execChoiceOne(fullData);
				break;
			case 2:
				execChoiceTwo(fullData);
				break;
			case 3:
				execChoiceThree(fullData);
				break;
			case 4:
				execChoiceFour(fullData);
				break;
			case 5:
				printf("Goodbye!\a\n\a");
				return EXIT_SUCCESS;
			default:
				printf("Not a choice!, try again!\n");
				break;
		}

		menuChoice = choiceMenu();

	}

}


/*
 * Function:	choiceMenu
 * Programmer: 	Braeden Trautz
 * Date:	31 November 2018
 * Inputs:	* None *
 * Outputs:	Prints		-	the interactive menu
 * Globals:	{ ALL }		-	check colors.h for more information
 * Returns:	int choice	-	integer representing the menu choice made by user
 * Description:	Prints out a choice menu and a prompt to enter a value, and returns the value that the user enters.
 */
int choiceMenu ( )
{

	int choice;
	printf("\tEnter the value of one of the below choices.\n");
	printf(BOLDWHITE "\tBubble Sheet Mining Menu \n" RESET);
	printf("\t1. Search via specific ID \n");
	printf("\t2. Search via any name \n");
	printf("\t3. Search via ID's within a range \n");
	printf("\t4. Search via last name only \n");
	printf("\t5. End the program \n");
	scanf("%d", &choice);
	return choice;

}

/*
 * Function:	execChoiceOne
 * Programmer: 	Braeden Trautz
 * Date:	01 December 2018
 * Inputs:	bubble_response fullData[ ]	-	array of bubble_response types that contains all students in data.csv
 * Outputs:	Prints				-	prompts to enter ID to search for
 * Globals:	MAX_STUDENTS			-	max number of students to scan through in data.csv
 * Returns:	* None *
 * Description:	Executes menu option one, which displays the information of a student searched via ID number
 */
void execChoiceOne ( bubble_response fullData[] )
{

	int id, i, flag = 0;
	printf("Enter the ID you would like to search for\n");
	scanf("%d", &id);

	for ( i = 0; i < MAX_STUDENTS; i++ ) {
		if ( id == fullData[i].id ) {
			flag = 1;
			printOneStudent( fullData, id );
		}
	}

	if ( flag != 1 ) printf("No student data found for id %d\n", id);
	else return;

}

/*
 * Function:	execChoiceTwo
 * Programmer: 	Braeden Trautz
 * Date:	02 December 2018
 * Inputs:	bubble_response fullData[ ]	-	array of bubble_response types that contains all students in data.csv
 * Outputs:	Prints 				-	prompts to enter student's name to search information of
 * Globals:	NAME_LEN			-	max length of a student's name string
 *		MAX_STUDENTS			-	max number of students in data.csv to search through
 * Returns:	* None *
 * Description:	Executes menu option two, which displays student information based on a search of a name
 */
void execChoiceTwo ( bubble_response fullData[] )
{

	printf("Enter any part of the student's name, \nyou will be shown all names with a match\n");
	char input[NAME_LEN];
	char compareMe[NAME_LEN];
	int i, flag = 0;
	scanf("%s", input);
	convertToLC(input);


	for ( i = 0; i < MAX_STUDENTS; i++ ) {
		strcpy(compareMe, fullData[i].name);
		convertToLC(compareMe);
		if ( strstr(compareMe, input) )
			printOneStudent( fullData, fullData[i].id );
			flag++;
	}

	if ( flag == 0 ) printf("No student matched your search for \"%s\"\n", input);
	else return;

}

/*	**STUB**
 * Function:	execChoiceThree
 * Programmer: 	Braeden Trautz
 * Date:	03 December 2018
 * Inputs:	bubble_response fullData[ ]	-	array of bubble_response types that contains all students in data.csv
 * Outputs:	Prints 				-	prompts to enter a range of numbers to search through
 * Globals:	MAX_STUDENTS			-	max number of students to search through in data.csv
 * Returns:	* None *
 * Description:	Executes menu option three, which displays up to five students in a range of ID numbers
 */
void execChoiceThree ( bubble_response fullData[] )
{

	printf("Stub3!\n");

}

/*	**STUB**
 * Function:	execChoiceFour
 * Programmer: 	Braeden Trautz
 * Date:	03 December 2018
 * Inputs:	bubble_response fullData[ ]	-	array of bubble_response types that contains all students in data.csv
 * Outputs:	Prints				-	prompts to enter the last name of a student to search for
 * Globals:	MAX_STUDENTS			-	max number of students to search through in data.csv
 * Returns:	* None *
 * Description:	Executes menu option four, which displays information on students who match searched last name
 */
void execChoiceFour ( bubble_response fullData[] )
{

	printf("Stub4!\n");

}

/*
 * Function:	printOneStudent
 * Programmer: 	Braeden Trautz
 * Date:	01 December 2018
 * Inputs:	bubble_response fullData[ ]	-	array of bubble_response types that contains all students in data.csv
 *		int id				-	id of student to display information of
 * Outputs:	Prints				-	student information (name, ID, choices)
 * Globals:	MAX_STUDENTS			-	max number of students to search through in data.csv
 *		{COLORS.H}			-	check colors.h for more information
 * Returns:	* None *
 * Description:	Prints the data of one student based on their ID number.
 */
void printOneStudent( bubble_response fullData[], int id )
{

	int i;
	for ( i = 0; i < MAX_STUDENTS; i++ ) {
		if ( fullData[i].id == id ){
			printf(BOLDRED "");
			printf("ID: %5.5d\nName: %s\nChoices: %s\n", fullData[i].id, fullData[i].name, fullData[i].choices);
			printf("" RESET);
			return;
		}
	}

}

/*
 * Function:	convertToLC
 * Programmer: 	Braeden Trautz
 * Date:	03 December 2018
 * Inputs:	char *input	-	string that is going to be converted to lowercase
 * Outputs:	char *input	-	string that has been converted to lowercase
 * Globals:	NAME_LEN	-	max length of student's name
 * Returns:	* None *
 * Description:	Converts a string into all lowercase characters.
 */
void convertToLC( char *input )
{

	int i;
	for ( i = 0; i < NAME_LEN; i++ ) {
		input[i] = tolower(input[i]);
	}

	return;

}
