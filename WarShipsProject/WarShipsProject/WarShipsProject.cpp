#include "pch.h"
#include <iostream>
#include "VersusCP.cpp"
#include "VersusRP.cpp"
using namespace std;

int HowToPlayMenuChoice;
int GameMenuChoice;
int NumberOfCords;
int CordsTemp = 0;
int Cords = 0;
bool flagHTP = false;

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
{
	cout << "Type the number of coordinates you want the map to have:";
	cin >> NumberOfCords;
	int TempCountCoords = 0;
	int TempCountNumbersGS = 0;
	int TempCountGermansNumbers = 0;
	NumberOfCords = sqrt(NumberOfCords);
	for (int i = 1; i <= NumberOfCords; i++)
	{
		for (int i = 1; i <= NumberOfCords; i++)
		{
			CordsTemp++;
			if (i != RightGuessedCoords[TempCountCoords++])
			{
				cout << " [";
			}
			else
			{
				cout << " +";
			}
			if (CordsTemp < 10)
			{
				cout << 0 << CordsTemp;
			}
			else
			{
				cout << CordsTemp;
			}
			if (RightGuessedNumber[TempCountNumbersGS++] != GermansNumbers[TempCountGermansNumbers++])
			{
				cout << "] ";
			}
			else
			{
				cout << "+ ";
			}
		}
		cout << endl << endl;
	}
	Cords = CordsTemp;
	CordsTemp = 0;
}

void MenuGame()
{
	cout << "Select a menu: " << endl;
	cout << "1. Play versus the computer" << endl;
	cout << "2. Play versus a person" << endl;
	cout << "3. Exit the program" << endl;
	cin >> GameMenuChoice;
	switch (GameMenuChoice)
	{
		case 1:
		{
			MenuGame();
		}
		case 2:
		{
			InputGermansCoordinates(); 
			MenuGame();
		}
		case 3:
		{
			cout << "Thank you for playing!";
			break;
		}
		default:
		{
			MenuGame();
		}
	}
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