#include "pch.h"
#include <iostream>
using namespace std;

int GermansNumbers[5];
int BreakersGuessNumbers[5];
int RightGuessedNumber[5];
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


void InputBreakersGuess()
{
	cout << "Please, enter the numbers you want to guess and the coordinate where you think they are: " << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << "Number " << i << ": ";
		cin >> BreakersGuessNumbers[i];
	}
}

void CheckBreakersGuess()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (BreakersGuessNumbers[i] == GermansNumbers[j])
			{
				RightGuessedNumber[NumbersCount++] = BreakersGuessNumbers[i];
				if ((i ==j)  && (BreakersGuessNumbers[i] == GermansNumbers[j]))
				{
					CoordsCount++;
				}
				i++;
			}
		}
	}
}

void FeedbackAfterRound()
{
	if (CoordsCount == 0)
	{
		cout << "You've guessed " << NumbersCount << "numbers correctly, but none of them was in the right spot!" << endl;
		NumbersCount = 0;
	}
	else if(CoordsCount!=4 && CoordsCount!=0)
	{
		cout << "You've guessed " << CoordsCount << "numbers correctly on their places, and " << NumbersCount << "numbers, but not on their correct places!" << endl;
		CoordsCount = 0;
		NumbersCount = 0;
	}
	else if(CoordsCount==4)
	{
		cout << "Congatulations, you have beaten the game, you have guessed all the numbers on their correct spots" << endl << endl << endl;
	}
}