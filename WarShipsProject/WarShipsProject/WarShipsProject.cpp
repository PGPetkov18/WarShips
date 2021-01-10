#include "pch.h"
#include <iostream>
#include "VersusCP.cpp"
#include "VersusRP.cpp"
using namespace std;

int HowToPlayMenuChoice;
int GameMenuChoice;
bool flagHTP = false;
bool RMenu;
int NumberOfRounds = 0;
int MenuCount = 0;
int VersusRPMenuCount = 0;

void MenuHowToPlay()
{
	cout << "Select for which game mode you want to see how to play:" << endl;
	cout << "1. Versus a player" << endl;;
	cout << "2. Versus the computer" << endl;
	cout << "3. Go to the game mode menu" << endl;
	cin >> HowToPlayMenuChoice;
	switch (HowToPlayMenuChoice)
	{
		case 1:
		{
			cout << " ";
			MenuHowToPlay();
		}
		case 2:
		{
			cout << " ";
			MenuHowToPlay();
		}
		case 3: 
		{
			flagHTP = true;
			system("cls");
			break;
		}
		default:
		{
			MenuHowToPlay();
		}
	}
}

void MapVisualizer()
{;
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

void MenuVersusRP()
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
		system("cls");
		switch (RMenu)
		{
		case 1:
		{
			InputGermansNumbersR();
			system("cls");
			do
			{
				MapVisualizer();
				InputBreakersGuess();
				CheckBreakersGuessRP();
				FeedbackAfterRound();
				NumberOfRounds++;
			} while (NumberOfRounds <= 13 && flagRP==false);
			if (NumberOfRounds <= 13 && flagRP == false)
			{
				cout << "Sorry, you have not guessed any numbers and their correct spots!" << endl;
				cout << "Thank you for playing" << endl;
				CoordsCountRP = 0;
				NumberOfRounds = 0;
			}	
			VersusRPMenuCount++;
			break;

		}
		case 2:
		{
			InputGermansNumbersR();
			system("cls");
			do
			{
				MapVisualizer();
				InputBreakersGuess();
				CheckBreakersGuessRP();
				FeedbackAfterRound();
				NumberOfRounds++;
			} while (NumberOfRounds <= 13 && flagRP == false);
			if (NumberOfRounds <= 13 && flagRP==false)
			{
				cout << "Sorry, you have not guessed any numbers and their correct spots!" << endl;
				cout << "Thank you for playing!" << endl;
			}
			VersusRPMenuCount++;
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
	} while (VersusRPMenuCount==0);
}

void MenuGame()
{
	do
	{
		cout << "Select a menu: " << endl;
		cout << "1. Play versus a person" << endl;
		cout << "2. Play versus the computer" << endl;
		cout << "3. Exit the program" << endl;
		cin >> GameMenuChoice;
		system("cls");
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
	}while (MenuCount == 0);
}

int main()
{
	cout << "Welcome to the game!" << endl;
	cout << "You can play versus the computer or a friend." << endl;
	MenuHowToPlay();
	if (flagHTP == true)
	{
		MenuGame();
	}
}