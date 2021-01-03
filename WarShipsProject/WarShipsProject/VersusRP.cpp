#include "pch.h"
#include <iostream>
using namespace std;

int GermansNumbers[4];
int GermansCoords[4];
int NumberOfRounds = 0;
int BreakersGuessNumbers[3];
int BreakersGuessCoords[3];
int RightGuessedNumber[3];
int RightGuessedCoords[3];
int NumbersCount = 0;
int CoordsCount = 0;

void InputGermansNumbersR()
{
	cout << "Type 4 numbers between 0 and 7!" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << "Number " << i << ":";
		cin >> GermansNumbers[i];
		if (GermansNumbers[i] < 0 || GermansNumbers[i]>7)
		{
			cout << "Please, type the number again!";
			i -= 1;
		}
		cout << endl;
	}
}

void InputGermansNumbersNR()
{
	cout << "Type 4 numbers between 0 and 7 without repeating any of them!" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << "Number " << i << ":";
		cin >> GermansNumbers[i];
		if (GermansNumbers[i] < 0 || GermansNumbers[i]>7)
		{
			cout << "Please, type the number again!";
			i -= 1;
		}
		cout << endl;
	}
}

void InputGermansCoordinates()
{
	cout << "Type 4 coordinates between 1 and 16:" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << "Coordinate " << i << ": ";
		cin >> GermansCoords[i];
		{
			if (GermansCoords[i] < 1 || GermansCoords[i]>16)
			{
				cout << "Please, type the coordinate again!";
				i -= 1;
			}
		}
		cout << endl;
	}
}

void InputBreakersGuess()
{
	cout << "Please, enter the numbers you want to guess and the coordinate where you think they are: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Number " << i << ": ";
		cin >> BreakersGuessNumbers[i];
		cout << "Coordinate " << i << ": ";
		cin >> BreakersGuessCoords[i];
	}
}

void CheckBreakersGuess()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (BreakersGuessNumbers[i] == GermansNumbers[j])
			{
				RightGuessedNumber[NumbersCount++] = BreakersGuessNumbers[i];
				j = 0;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (BreakersGuessCoords[i] == GermansCoords[j])
			{
				RightGuessedCoords[CoordsCount++] = BreakersGuessCoords[i];
				j = 0;
			}
		}
	}
	NumberOfRounds++;
}