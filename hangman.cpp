/*
Justin Strelka
CSC 160-470
Program Name: Hangman Project 5
Description: Extract words using getWords, get user input for gameplay status, initiate gameplay, print corresponding hangman board, can win!!
Date: 4/25/2018
Source: Problem Solving with C++, https://stackoverflow.com/questions/7131858/stdtransform-and-toupper-no-matching-function
*/

//List directive libraries
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//specify namespace
using namespace std;

//prototype functions
string getNextWord();
void getWords(string);
int promptYN(string);
string strToUpper(string);
string drawBoard(int);
bool binarySearch(char usedLetters[], int used, char letterToFind);
void bubbleSort(char usedLetters[], int used);

int main()
{
	//initialize and define variables
	int failCount(1), errorCount(1);
	string guessLetterStr = " ";
	string guessWord = " ";
	string reply = " ";
	char guessLetter = ' ';
	bool playStatus = true;
	int amountUsedLetters = 0;
	bool correctGuess = false;
	bool winner = false;

	//Array
	char usedLetters[27];
	
	//Vectors
	vector <char> maskedWord;
	
	//Call to get words
	getWords("hangman.dat");
	

	//initiate gameplay loop
	while (playStatus)
	{
		failCount = 1;		
		
		maskedWord.clear();
		
		for (int i = 0; i <= amountUsedLetters; i++)
		{
			usedLetters[i] = ' ';
		}
		amountUsedLetters = 0;

		//print hangman line
		cout << endl << "-------- HANGMAN GAME --------" << endl << endl;

		cout << "Do you want to play hangman? (y or n): ";
		cin >> reply;
		
		//check input for quit, error, or play
		if (promptYN(reply) == 0)
		{
			cout << "Goodbye";
			// Pause program before pressing any key to continue
			if (cin.peek() == '\n')
				cin.ignore();
			cin.get();
			break;
		}
		else if (promptYN(reply) == -1)
		{
			if (errorCount < 3)
			{
				cout << "Error - please enter (y or n)" << endl;
				errorCount++;
			}
			else
			{
				cout << "Game TERMINATED";
				// Pause program before pressing any key to continue
				if (cin.peek() == '\n')
					cin.ignore();
				cin.get();
				return 1;
			}
		}
		
		//user wants to play
		else
		{
			
			//obtain and capitalize word for gameplay
			guessWord = strToUpper(getNextWord());
			
			//check to see user is not out of words for play
			if (guessWord != "")
			{
				errorCount = 1;
				winner = false;

				cout << endl << "Let's PLAY" << endl << endl;
				//Create masked Word
				for (int i = 0; i < guessWord.length(); i++)
				{
					maskedWord.push_back('_');
					maskedWord.push_back(' ');
				}
				//start board switch cases
				while (failCount <= 7)
				{
					if (failCount == 1)
					{
						//reset check variables guess bool
						correctGuess = false;

						for (int i = 0; i < maskedWord.size(); i += 2)
						{
							if (maskedWord[i] == guessWord[i / 2])
							{
								winner = true;
							}
							else
							{
								winner = false;
								break;
							}
						}

						if (winner == true)
						{
							failCount = 99;
							break;
						}

						//print out maskedWord
						for (int i = 0; i < maskedWord.size(); i++)
						{
							cout << maskedWord[i];
						}
						//print out gameplay board
						cout << endl << endl << drawBoard(failCount) << endl;
						cout << "<<<<<<< MAKE A GUESS >>>>>>>" << endl << endl;
						cout << "Guessed Letters: ";
						//print out guessed letters in alpha order
						for (int i = 0; i < amountUsedLetters; i++)
						{
							cout << usedLetters[i] << ' ';
						}
						cout << endl << endl;

						//get user input for letter to guess
						cout << "Enter a letter to guess: ";

						//put user input into string
						cin >> guessLetterStr;

						//capitalize guessLetterStr
						transform(guessLetterStr.begin(), guessLetterStr.end(), guessLetterStr.begin(), ::toupper);

						//put guessLetter into char for comparison
						guessLetter = guessLetterStr[0];

						//start while loop to compare guessLetter to guess word letters
						if (binarySearch(usedLetters, amountUsedLetters, guessLetter) == false)
						{
							//place guess letter in usedletters array
							usedLetters[amountUsedLetters] = guessLetter;
							amountUsedLetters++;

							//alpha order usedletters array
							bubbleSort(usedLetters, amountUsedLetters);

							for (int i = 0; i < maskedWord.size(); i += 2)
							{
								if (((i / 2) < guessWord.length()) && guessLetter == guessWord[i / 2])
								{
									maskedWord[i] = guessLetter;
									correctGuess = true;
								}
							}
						}
						else
						{
							cout << endl << "That Letter has already been used" << endl << endl;
							correctGuess = true;
						}
						if (correctGuess == false)
						{
							failCount++;
							cout << endl << guessLetter << " is NOT in the word to guess." << endl << endl;
						}
					}
					else if (failCount == 2)
					{
						//reset check variables guess bool
						correctGuess = false;

						for (int i = 0; i < maskedWord.size(); i += 2)
						{
							if (maskedWord[i] == guessWord[i / 2])
							{
								winner = true;
							}
							else
							{
								winner = false;
								break;
							}
						}

						if (winner == true)
						{
							failCount = 99;
							break;
						}

						//print out maskedWord
						for (int i = 0; i < maskedWord.size(); i++)
						{
							cout << maskedWord[i];
						}
						//print out gameplay board
						cout << endl << endl << drawBoard(failCount) << endl;
						cout << "<<<<<<< MAKE A GUESS >>>>>>>" << endl << endl;
						cout << "Guessed Letters: ";
						//print out guessed letters in alpha order
						for (int i = 0; i < amountUsedLetters; i++)
						{
							cout << usedLetters[i] << ' ';
						}
						cout << endl << endl;

						//get user input for letter to guess
						cout << "Enter a letter to guess: ";

						//put user input into string
						cin >> guessLetterStr;

						//capitalize guessLetterStr
						transform(guessLetterStr.begin(), guessLetterStr.end(), guessLetterStr.begin(), ::toupper);

						//put guessLetter into char for comparison
						guessLetter = guessLetterStr[0];

						//start while loop to compare guessLetter to guess word letters
						if (binarySearch(usedLetters, amountUsedLetters, guessLetter) == false)
						{
							//place guess letter in usedletters array
							usedLetters[amountUsedLetters] = guessLetter;
							amountUsedLetters++;

							//alpha order usedletters array
							bubbleSort(usedLetters, amountUsedLetters);

							for (int i = 0; i < maskedWord.size(); i += 2)
							{
								if (((i / 2) < guessWord.length()) && guessLetter == guessWord[i / 2])
								{
									maskedWord[i] = guessLetter;
									correctGuess = true;
								}
							}
						}
						else
						{
							cout << endl << "That Letter has already been used" << endl << endl;
							correctGuess = true;
						}
						if (correctGuess == false)
						{
							failCount++;
							cout << endl << guessLetter << " is NOT in the word to guess." << endl << endl;
						}
					}
					else if (failCount == 3)
					{
						//reset check variables guess bool
						correctGuess = false;

						for (int i = 0; i < maskedWord.size(); i += 2)
						{
							if (maskedWord[i] == guessWord[i / 2])
							{
								winner = true;
							}
							else
							{
								winner = false;
								break;
							}
						}

						if (winner == true)
						{
							failCount = 99;
							break;
						}

						//print out maskedWord
						for (int i = 0; i < maskedWord.size(); i++)
						{
							cout << maskedWord[i];
						}
						//print out gameplay board
						cout << endl << endl << drawBoard(failCount) << endl;
						cout << "<<<<<<< MAKE A GUESS >>>>>>>" << endl << endl;
						cout << "Guessed Letters: ";
						//print out guessed letters in alpha order
						for (int i = 0; i < amountUsedLetters; i++)
						{
							cout << usedLetters[i] << ' ';
						}
						cout << endl << endl;

						//get user input for letter to guess
						cout << "Enter a letter to guess: ";

						//put user input into string
						cin >> guessLetterStr;

						//capitalize guessLetterStr
						transform(guessLetterStr.begin(), guessLetterStr.end(), guessLetterStr.begin(), ::toupper);

						//put guessLetter into char for comparison
						guessLetter = guessLetterStr[0];

						//start while loop to compare guessLetter to guess word letters
						if (binarySearch(usedLetters, amountUsedLetters, guessLetter) == false)
						{
							//place guess letter in usedletters array
							usedLetters[amountUsedLetters] = guessLetter;
							amountUsedLetters++;

							//alpha order usedletters array
							bubbleSort(usedLetters, amountUsedLetters);

							for (int i = 0; i < maskedWord.size(); i += 2)
							{
								if (((i / 2) < guessWord.length()) && guessLetter == guessWord[i / 2])
								{
									maskedWord[i] = guessLetter;
									correctGuess = true;
								}
							}
						}
						else
						{
							cout << endl << "That Letter has already been used" << endl << endl;
							correctGuess = true;
						}
						if (correctGuess == false)
						{
							failCount++;
							cout << endl << guessLetter << " is NOT in the word to guess." << endl << endl;
						}
					}
					else if (failCount == 4)
					{
						//reset check variables guess bool
						correctGuess = false;

						for (int i = 0; i < maskedWord.size(); i += 2)
						{
							if (maskedWord[i] == guessWord[i / 2])
							{
								winner = true;
							}
							else
							{
								winner = false;
								break;
							}
						}

						if (winner == true)
						{
							failCount = 99;
							break;
						}

						//print out maskedWord
						for (int i = 0; i < maskedWord.size(); i++)
						{
							cout << maskedWord[i];
						}
						//print out gameplay board
						cout << endl << endl << drawBoard(failCount) << endl;
						cout << "<<<<<<< MAKE A GUESS >>>>>>>" << endl << endl;
						cout << "Guessed Letters: ";
						//print out guessed letters in alpha order
						for (int i = 0; i < amountUsedLetters; i++)
						{
							cout << usedLetters[i] << ' ';
						}
						cout << endl << endl;

						//get user input for letter to guess
						cout << "Enter a letter to guess: ";

						//put user input into string
						cin >> guessLetterStr;

						//capitalize guessLetterStr
						transform(guessLetterStr.begin(), guessLetterStr.end(), guessLetterStr.begin(), ::toupper);

						//put guessLetter into char for comparison
						guessLetter = guessLetterStr[0];

						//start while loop to compare guessLetter to guess word letters
						if (binarySearch(usedLetters, amountUsedLetters, guessLetter) == false)
						{
							//place guess letter in usedletters array
							usedLetters[amountUsedLetters] = guessLetter;
							amountUsedLetters++;

							//alpha order usedletters array
							bubbleSort(usedLetters, amountUsedLetters);

							for (int i = 0; i < maskedWord.size(); i += 2)
							{
								if (((i / 2) < guessWord.length()) && guessLetter == guessWord[i / 2])
								{
									maskedWord[i] = guessLetter;
									correctGuess = true;
								}
							}
						}
						else
						{
							cout << endl << "That Letter has already been used" << endl << endl;
							correctGuess = true;
						}
						if (correctGuess == false)
						{
							failCount++;
							cout << endl << guessLetter << " is NOT in the word to guess." << endl << endl;
						}
					}
					else if (failCount == 5)
					{
						//reset check variables guess bool
						correctGuess = false;

						for (int i = 0; i < maskedWord.size(); i += 2)
						{
							if (maskedWord[i] == guessWord[i / 2])
							{
								winner = true;
							}
							else
							{
								winner = false;
								break;
							}
						}

						if (winner == true)
						{
							failCount = 99;
							break;
						}

						//print out maskedWord
						for (int i = 0; i < maskedWord.size(); i++)
						{
							cout << maskedWord[i];
						}
						//print out gameplay board
						cout << endl << endl << drawBoard(failCount) << endl;
						cout << "<<<<<<< MAKE A GUESS >>>>>>>" << endl << endl;
						cout << "Guessed Letters: ";
						//print out guessed letters in alpha order
						for (int i = 0; i < amountUsedLetters; i++)
						{
							cout << usedLetters[i] << ' ';
						}
						cout << endl << endl;

						//get user input for letter to guess
						cout << "Enter a letter to guess: ";

						//put user input into string
						cin >> guessLetterStr;

						//capitalize guessLetterStr
						transform(guessLetterStr.begin(), guessLetterStr.end(), guessLetterStr.begin(), ::toupper);

						//put guessLetter into char for comparison
						guessLetter = guessLetterStr[0];

						//start while loop to compare guessLetter to guess word letters
						if (binarySearch(usedLetters, amountUsedLetters, guessLetter) == false)
						{
							//place guess letter in usedletters array
							usedLetters[amountUsedLetters] = guessLetter;
							amountUsedLetters++;

							//alpha order usedletters array
							bubbleSort(usedLetters, amountUsedLetters);

							for (int i = 0; i < maskedWord.size(); i += 2)
							{
								if (((i / 2) < guessWord.length()) && guessLetter == guessWord[i / 2])
								{
									maskedWord[i] = guessLetter;
									correctGuess = true;
								}
							}
						}
						else
						{
							cout << endl << "That Letter has already been used" << endl << endl;
							correctGuess = true;
						}
						if (correctGuess == false)
						{
							failCount++;
							cout << endl << guessLetter << " is NOT in the word to guess." << endl << endl;
						}
					}
					else if (failCount == 6)
					{
						//reset check variables guess bool
						correctGuess = false;

						for (int i = 0; i < maskedWord.size(); i += 2)
						{
							if (maskedWord[i] == guessWord[i / 2])
							{
								winner = true;
							}
							else
							{
								winner = false;
								break;
							}
						}

						if (winner == true)
						{
							failCount = 99;
							break;
						}

						//print out maskedWord
						for (int i = 0; i < maskedWord.size(); i++)
						{
							cout << maskedWord[i];
						}
						//print out gameplay board
						cout << endl << endl << drawBoard(failCount) << endl;
						cout << "<<<<<<< MAKE A GUESS >>>>>>>" << endl << endl;
						cout << "Guessed Letters: ";
						//print out guessed letters in alpha order
						for (int i = 0; i < amountUsedLetters; i++)
						{
							cout << usedLetters[i] << ' ';
						}
						cout << endl << endl;

						//get user input for letter to guess
						cout << "Enter a letter to guess: ";

						//put user input into string
						cin >> guessLetterStr;

						//capitalize guessLetterStr
						transform(guessLetterStr.begin(), guessLetterStr.end(), guessLetterStr.begin(), ::toupper);

						//put guessLetter into char for comparison
						guessLetter = guessLetterStr[0];

						//start while loop to compare guessLetter to guess word letters
						if (binarySearch(usedLetters, amountUsedLetters, guessLetter) == false)
						{
							//place guess letter in usedletters array
							usedLetters[amountUsedLetters] = guessLetter;
							amountUsedLetters++;

							//alpha order usedletters array
							bubbleSort(usedLetters, amountUsedLetters);

							for (int i = 0; i < maskedWord.size(); i += 2)
							{
								if (((i / 2) < guessWord.length()) && guessLetter == guessWord[i / 2])
								{
									maskedWord[i] = guessLetter;
									correctGuess = true;
								}
							}
						}
						else
						{
							cout << endl << "That Letter has already been used" << endl << endl;
							correctGuess = true;
						}
						if (correctGuess == false)
						{
							failCount++;
							cout << endl << guessLetter << " is NOT in the word to guess." << endl << endl;
						}
					}
					else if (failCount == 7)
					{
						//print out maskedWord
						for (int i = 0; i < maskedWord.size(); i++)
						{
							cout << maskedWord[i];
						}
						//print out gameplay board
						cout << endl << endl << drawBoard(failCount) << endl;
						cout << "Sorry you LOSE :( it was " << guessWord;
						failCount++;
					}

				}
			}

			else
			{
				cout << "Sorry you are out of words to guess in hangman.dat" << endl << "Press any key to continue. . .";
				// Pause program before pressing any key to continue
				if (cin.peek() == '\n')
					cin.ignore();
				cin.get();
				return 2;
			}
		}
		if (failCount == 99)
		{
			cout << endl << "You've guessed the word. WINNER! It was " << guessWord << endl << endl;
		}
	}
	return 0;
}

string drawBoard(int fail)
{
	const string BOARD_1 = " -------:\n :      :\n        :\n        :\n        :\n        :\n      -----\n";
	const string BOARD_2 = " -------:\n :      :\n O      :\n        :\n        :\n        :\n      -----\n";
	const string BOARD_3 = " -------:\n :      :\n O      :\n :      :\n        :\n        :\n      -----\n";
	const string BOARD_4 = " -------:\n :      :\n O      :\n-:      :\n        :\n        :\n      -----\n";
	const string BOARD_5 = " -------:\n :      :\n O      :\n-:-     :\n        :\n        :\n      -----\n";
	const string BOARD_6 = " -------:\n :      :\n O      :\n-:-     :\n/       :\n        :\n      -----\n";
	const string BOARD_7 = " -------:\n :      :\n O      :\n-:-     :\n/ \\     :\n        :\n      -----\n";
	switch (fail)
	{
		case 1:
			return BOARD_1;
		case 2:
			return BOARD_2;
		case 3:
			return BOARD_3;
		case 4:
			return BOARD_4;
		case 5:
			return BOARD_5;
		case 6:
			return BOARD_6;
		case 7:
			return BOARD_7;
	}
}