/*
Justin Strelka
MyFuncts.h
Description: function prototypes to declare the functions
*/

// macro guard to save guard all inside only gets declared once
// use ifndef and defines not pragma once as that is Windows only specific
#ifndef MYFUNCTS_H  // MYFUNCTS_H is a unique indentifier for this file
					// ifndef means if it is not defined and it looks at the identifier 
                    // if it has never defined the identifier then true 
					// or if it has defined the identifier then false
#define MYFUNCTS_H  // define the unique identifier

// 1. includes of system library files - above the system namespaces
#include <cstdlib>  // rand
#include <string>
#include <cctype>   // tolower and toupper

// 2. system namespaces
using namespace std;

// 3. includes of OTHER local programmer .h files

#define PLAY 1
#define STOP 0
#define ERROR -1

int promptYN(string reply);
string strToUpper(string str);
string strToLower(string str);

// 4. function prototypes (declarations) 
/*
function prototype: roll2Dice function
parameters: die1 as a die number value and die2 as a die number value
            side as a default argument set to 6 unless passed in.
pass by ref out: die1 with random # and die2 as a random #
*/
void roll2Dice(int& die1, int& die2, int side=6);

/*
function prototype: strToUpper function
parameters: str as a string
value returned: string in all uppercase
*/
string strToUpper(string str);


/*
function prototype: strToLower function
parameters: str as a string
value returned: string in all lowercase
*/
string strToLower(string str);

#endif  // end the macro guard

