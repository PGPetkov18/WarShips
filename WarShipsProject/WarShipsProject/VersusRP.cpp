#include "pch.h"
#include <iostream>
#include "VersusCP.cpp"
#include "VersusRP.cpp"
using namespace std;

int HowToPlayMenuChoice; //We declare a variable by HowToPlayMenuChoice
int GameMenuChoice;//We declare a variable by GameMenuChoice
bool flagHTP = false;
bool RMenu;
int NumberOfRounds = 0;//We declare a variable by NumberOfRounds
int MenuCount = 0;//We declare a variable by MenuCount
int VersusRPMenuCount = 0;//We declare a variable by VersusRPMenuCount
int VersusCPMenuCount = 0;//We declare a variable by VersusCPMenuCount

void MenuHowToPlay() //function for MenuHowToPlay
{
	cout << "Select 1 if you want to see how to play, or 2 if you want to choose your game mode:" << endl;
	cout << "1. Gameplay and rules" << endl;
	cout << "2. Go to the game mode menu" << endl;
	cin >> HowToPlayMenuChoice;
	switch (HowToPlayMenuChoice)
	{
	case 1:
	{
		cout << endl;
		cout << "The Germans (A player or the computer) place a combination of 4 random numbers in the range";
		cout << "between 0 and 7, indicating the coordinates of their battleships. ";
		cout << "The code breaker should guess the number within 13 tries using the board. ";
		cout << "The codebreaker places their guesses. The Germans (a player or a computer) should give ";
		cout << "a feedback whether just a number is guessed or a number and is on a correct place. If just a number ";
		cout << "is guessed, it should be given “Guessed numbers”. If the code breaker guesses a ";
		cout << "number on the correct position, then the information should be displayed “Guessed numbers and positions”.";
		cout << endl;
		cout << "The Germans are NOT allowed to give any further information ";
		cout << "except the correct number of the guessed numbers or the number of ";
		cout << "the guessed numbers on correct positions!" << endl;
		cout << endl;
		MenuHowToPlay();
	}
	case 2:
	{
		flagHTP = true;

		break;
	}
	default:
	{
		MenuHowToPlay();
	}
	}
}

void MapVisualizer() //function for MapVisualizer
{
	;
	int TempCountCoords = 0;
	int TempCountNumbersGS = 0;
	int TempCountGermansNumbers = 0;
	for (int i = 1; i <= 4; i++)
	{
		cout << " [";
		cout << i;
		cout << "] ";
	}
	cout << endl;
}

void MenuVersusCP() //function for MenuVersus
{
	do
	{
		cout << "Please, choose whether you want the germans to have reapeating numbers or no!";
		cout << endl;
		cout << "1. Repeating numbers";
		cout << endl;
		cout << "2. No repeating numbers";
		cout << endl;
		cin >> RMenu;

		switch (RMenu)
		{
		case 1:
		{
			GenerateRandomNumbersR();
			do
			{
				InputBreakersGuess();
				CheckBreakersGuessRP();
				FeedbackAfterRound();
				StoringHistoryOfRoundsCP();
				NumberOfRounds++;
			} while (NumberOfRounds <= 13 && flagCP == false);
			if (NumberOfRounds <= 13 && flagCP == false)
			{
				cout << "Sorry, you have not guessed any numbers and their correct spots!" << endl;
				cout << "Thank you for playing" << endl;
				CoordsCountCP = 0;
				NumberOfRounds = 0;
			}
			VisualizingHistoryOfRoundsCP();
			VersusCPMenuCount++;
			break;

		}
		case 2:
		{
			GenerateRandomNumbersNR();
			do
			{
				InputBreakersGuess();
				CheckBreakersGuessCP();
				FeedbackAfterRound();
				StoringHistoryOfRoundsCP();
				NumberOfRounds++;
			} while (NumberOfRounds <= 13 && flagCP == false);
			if (NumberOfRounds <= 13 && flagCP == false)
			{
				cout << "Sorry, you have not guessed any numbers and their correct spots!" << endl;
				cout << "Thank you for playing!" << endl;
				CoordsCountCP = 0;
				NumberOfRounds = 0;
			}
			VisualizingHistoryOfRoundsCP();
			VersusCPMenuCount++;
			break;
		}
		case 3:
		{
			VersusCPMenuCount++;
			break;
		}
		default:
		{
			cout << "Please choose other menu!" << endl;
		}
		}
	} while (VersusCPMenuCount == 0);
}

void MenuVersusRP() //function for MenuVersus
{
	do
	{
		cout << "Please, choose whether you want the germans to have reapeating numbers or no!";
		cout << endl;
		cout << "1. Repeating numbers";
		cout << endl;
		cout << "2. No repeating numbers";
		cout << endl;
		cin >> RMenu;

		switch (RMenu)
		{
		case 1:
		{
			InputGermansNumbersR();
			do
			{
				InputBreakersGuess();
				CheckBreakersGuessRP();
				FeedbackAfterRound();
				StoringHistoryOfRoundsRP();
				NumberOfRounds++;
			} while (NumberOfRounds <= 13 && flagRP == false);
			if (NumberOfRounds <= 13 && flagRP == false)
			{
				cout << "Sorry, you have not guessed any numbers and their correct spots!" << endl;
				cout << "Thank you for playing" << endl;
				CoordsCountRP = 0;
				NumberOfRounds = 0;
			}
			VisualizingHistoryOfRoundsRP();
			VersusRPMenuCount++;
			break;

		}
		case 2:
		{
			InputGermansNumbersR();
			do
			{
				InputBreakersGuess();
				CheckBreakersGuessRP();
				FeedbackAfterRound();
				StoringHistoryOfRoundsRP();
				NumberOfRounds++;
			} while (NumberOfRounds <= 13 && flagRP == false);
			if (NumberOfRounds <= 13 && flagRP == false)
			{
				cout << "Sorry, you have not guessed any numbers and their correct spots!" << endl;
				cout << "Thank you for playing!" << endl;
			}
			VersusRPMenuCount++;
			VisualizingHistoryOfRoundsRP();
			break;
		}
		case 3:
		{
			VersusRPMenuCount++;
			break;
		}
		default:
		{
			cout << "Please choose other menu!" << endl;
		}
		}
	} while (VersusRPMenuCount == 0);
}

void MenuGame() //function for MenuGame
{
	do
	{
		cout << "Select a menu: " << endl;
		cout << "1. Play versus a person" << endl;
		cout << "2. Play versus the computer" << endl;
		cout << "3. Exit the program" << endl;
		cin >> GameMenuChoice;

		switch (GameMenuChoice)
		{
		case 1:
		{
			MenuVersusRP();
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			cout << "Thank you for playing!";
			MenuCount = 1;
			break;
		}
		default:
		{
			cout << "Please, choose other menu!" << endl;
		}
		}
	} while (MenuCount == 0);
}

int main() //we go to int main
{
	cout << "Welcome to the game!" << endl;
	cout << "You can play versus the computer or a friend." << endl;
	MenuHowToPlay();
	if (flagHTP == true)
	{
		MenuGame();
	}
}
