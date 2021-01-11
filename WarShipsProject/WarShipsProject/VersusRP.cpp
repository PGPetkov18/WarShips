#include "pch.h"
#include <iostream>
using namespace std;

int GermansNumbers[5];
int BreakersGuessNumbersRP[5];
int RightGuessedNumberRP[5];
int NumbersCountRP = 0;
int CoordsCountRP = 0;
bool flagRP=false;
int HistoryOfRoundsRP[14][5];
int RowCounterRP = 1;

void StoringHistoryOfRoundsRP()
{
	for (int j = 1; j < 5; j++)
	{
		HistoryOfRoundsRP[RowCounterRP][j] = BreakersGuessNumbersRP[j];
	}
	RowCounterRP++;
}

void VisualizingHistoryOfRoundsRP()
{
	for (int i = 1; i < RowCounterRP; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			cout << "[ ";
			cout << HistoryOfRoundsRP[i][j]<<" ";
			cout << "] ";
		}
		cout << endl;
	}
}

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
		cin >> BreakersGuessNumbersRP[i];
		if (BreakersGuessNumbersRP[i] < 0 || BreakersGuessNumbersRP[i]>7)
		{
			cout << "Please, type the number again!";
			i--;
			cout << endl;
		}
	}
}

void CheckBreakersGuessRP()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (BreakersGuessNumbersRP[i] == GermansNumbers[j])
			{
				NumbersCountRP++;
				if (i == j)
				{
					CoordsCountRP++;
				}
				i++;
			}
		}
	}
}

void FeedbackAfterRound()
{
	if (CoordsCountRP == 0)
	{
		cout << "You've guessed " << NumbersCountRP << "numbers correctly, but none of them was in the right spot!" << endl;
		NumbersCountRP = 0;
	}
	else if(CoordsCountRP!=4 && CoordsCountRP!=0)
	{
		cout << "You've guessed " << CoordsCountRP+1 << "numbers correctly on their places, and " << NumbersCountRP-CoordsCountRP << "numbers, but not on their correct places!" << endl;
		CoordsCountRP = 0;
		NumbersCountRP = 0;
	}
	else if(CoordsCountRP==4)
	{
		cout << "Congatulations, you have beaten the game, you have guessed all the numbers on their correct spots" << endl << endl << endl;
		NumbersCountRP = 0;
		flagRP = true;
		CoordsCountRP = 0;
	}
}