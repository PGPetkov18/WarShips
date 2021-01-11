#include "pch.h"
#include <iostream>
using namespace std;

int GermansNumbers[4];
int BreakersGuessNumbersRP[4];
int RightGuessedNumberRP[4];
int NumbersCountRP = 0;
int CoordsCountRP = 0;
bool flagRP = false;
bool flagCheckRPN = false;
int HistoryOfRoundsRP[14][5];
int RowCounterRP = 1;

void StoringHistoryOfRoundsRP()
{
	for (int j = 0; j < 4; j++)
	{
		HistoryOfRoundsRP[RowCounterRP][j] = BreakersGuessNumbersRP[j];
	}
	RowCounterRP++;
}

void VisualizingHistoryOfRoundsRP()
{
	for (int i = 0; i < RowCounterRP; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "[ ";
			cout << HistoryOfRoundsRP[i][j] << " ";
			cout << "] ";
		}
		cout << endl;
	}
}

void CheckGermansRPN()
{
	for (int i = 0; i <= 4; i++)
	{
		for (int j = i; j <= 4; j++)
		{
			do
			{
				if (GermansNumbers[i] == GermansNumbers[j])
				{
					flagCheckRPN = true;
				}
				if (flagCheckRPN == true)
				{
					cout << "Please type the number again" << i + 1 << ":" << endl;
					flagCheckRPN = false;
					cin >> GermansNumbers[i];
				}
			} while (flagCheckRPN == true);
			flagCheckRPN = false;
		}
	}
}

void CheckBreakersRPN()
{
	for (int i = 0; i <= 4; i++)
	{
		for (int j = i; j <= 4; j++)
		{
			do
			{
				if (BreakersGuessNumbersRP[i] == BreakersGuessNumbersRP[j])
				{
					flagCheckRPN = true;
				}
				if (flagCheckRPN == true)
				{
					cout << "Please type the number again" << i + 1 << ":" << endl;
					flagCheckRPN = false;
					cin >> BreakersGuessNumbersRP[i];
				}
			} while (flagCheckRPN == true);
			flagCheckRPN = false;
		}
	}
}

void InputGermansNumbersR()
{
	cout << "Type 4 numbers between 0 and 7!" << endl;
	for (int i = 0; i < 4; i++)
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
	for (int i = 0; i < 4; i++)
	{
		cout << "Number " << i << ":";
		cin >> GermansNumbers[i];
		CheckGermansRPN();
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
	cout << "Please, enter the numbers you want to guess: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "Number " << i << ": ";
		cin >> BreakersGuessNumbersRP[i];
		CheckBreakersRPN();
	}
}

void CheckBreakersGuessRP()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (BreakersGuessNumbersRP[i] == GermansNumbers[j])
			{
				NumbersCountRP++;
				if (i == j)
				{
					CoordsCountRP++;
				}
			}
		}
	}
}

void FeedbackAfterRound()
{
	if (CoordsCountRP == 0)
	{
		cout << "You've guessed " << NumbersCountRP << " numbers correctly, but none of them was in the right spot!" << endl;
		NumbersCountRP = 0;
	}
	else if (CoordsCountRP != 4 && CoordsCountRP != 0)
	{
		cout << "You've guessed " << CoordsCountRP << " numbers correctly on their places, and " << NumbersCountRP - CoordsCountRP << "numbers, but not on their correct places!" << endl;
		CoordsCountRP = 0;
		NumbersCountRP = 0;
	}
	else if (CoordsCountRP == 4)
	{
		cout << "Congatulations, you have beaten the game, you have guessed all the numbers on their correct spots" << endl << endl << endl;
		NumbersCountRP = 0;
		flagRP = true;
		CoordsCountRP = 0;
	}
}