/*
Justin Strelka
MyFuncts.cpp
Description: function definitions
*/

#include "MyFuncts.h"  // connect the definition to the declarations in the .h file
// no other #includes needed in this file, they are all in the myfuncts.h file

// definitions of programmer defined functions declared in myfuncts.h
/*
function definition: roll2Dice function
parameters: die1 as a die number value and die2 as a die number value
side as a default argument set to 6 unless passed in.
pass by ref out: die1 with random # and die2 as a random #
*/
void roll2Dice(int& die1, int& die2, int side)
{
	die1 = rand() % side + 1;
	die2 = rand() % side + 1;
}

/*
function prototype: strToUpper function
parameters: str as a string
value returned: string in all uppercase
*/
string strToUpper(string str)
{
	//convert string toupper with FOR loop will work with tolower also.
	string ans = str; // must set ans to str to create memory the same for both
	for (int i = 0; i < ans.length(); i++)  // loop through letter by letter of str
		ans[i] = toupper(ans[i]);
	return ans;  // return the uppercase version of the passed in string
}

/*
function prototype: strToLower function
parameters: str as a string
value returned: string in all lowercase
*/
string strToLower(string str)
{
	//convert string toupper with WHILE loop will work with tolower also.
	// charecter '\0' is end of string auto assigned.
	int i = 0;
	string ans = str; // must set ans to str to create memory the same for both
	while (str[i] != '\0') // loop through letter by letter of str
	{
		ans[i] = tolower(str[i]);
		i++;
	}
	return ans;  // return the lowercase version of the passed in string
}


int promptYN(string reply)
{
	reply = strToUpper(reply);

	if (reply == "YES" || reply == "SURE" || reply == "OK" || reply == "Y")
		return PLAY;
	else if (reply == "NO" || reply == "QUIT" || reply == "STOP" || reply == "TERMINATE" || reply == "N" || reply == "Q")
		return STOP;
	else
		return ERROR;
}

bool binarySearch(char usedLetters[], int used, char letterToFind)
{
	bool found = false;
	int mid = 0, first = 0, last = used - 1;
	while (!found && first <= last)
	{
		mid = (first + last) / 2;
		if (usedLetters[mid] == letterToFind)
			found = true;
		else if (usedLetters[mid] > letterToFind)
			last = mid - 1;
		else
			first = mid + 1;
	}
	if (found)
		return true;
	return false;
}

void bubbleSort(char usedLetters[], int used)
{
	char temp = ' ';
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		for(int index = 0; index < used - 1; index++)
			if (usedLetters[index] > usedLetters[index + 1])
			{
				sorted = false;
				temp = usedLetters[index];
				usedLetters[index] = usedLetters[index + 1];
				usedLetters[index + 1] = temp;
			}
	}
}