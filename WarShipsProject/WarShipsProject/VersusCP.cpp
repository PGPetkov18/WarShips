#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

int GermansRandomNumbers[5];
int BreakersGuessNumbersCP[5];
int RightGuessedNumberCP[5];
int NumbersCountCP = 0;
int CoordsCountCP = 0;
bool flagCP = false;
int HistoryOfRoundsCP[14][5];
int RowCounterCP = 0;

void StoringHistoryOfRoundsCP()
{
	for (int j = 0; j < 4; j++)
	{
		HistoryOfRoundsCP[RowCounterCP][j] = BreakersGuessNumbersCP[j];
	}
	RowCounterCP++;
}

void VisualizingHistoryOfRoundsCP()
{
	for (int i = 0; i < RowCounterCP; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "[ ";
			cout << HistoryOfRoundsCP[i][j] << " ";
			cout << "] ";
		}
		cout << endl;
	}
}

void GenerateRandomNumbersNR()
{
	srand(time(NULL));
	int a[] = { 0,1,2,3,4,5,6,7 };
	int container;
	for (int i = 0; i < 8; i++)
	{
		container = rand() % 7;
		swap(a[0], a[container]);
	}
	for (int i = 0; i < 4; i++)
	{
		GermansRandomNumbers[i] = a[i];
	}
}

void GenerateRandomNumbersR()
{
	for (int i = 0; i < 4; i++)
	{
		GermansRandomNumbers[i] = rand() % 7;
	}
}

void CheckBreakersGuessCP()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (BreakersGuessNumbersCP[i] == GermansRandomNumbers[j])
			{
				NumbersCountCP++;
				if (i == j)
				{
					CoordsCountCP++;
				}
			}
		}
	}
}

void FeedbackAfterRoundCP()
{
	if (CoordsCountCP == 0)
	{
		cout << "You've guessed " << NumbersCountCP << " numbers correctly, but none of them was in the right spot!" << endl;
		NumbersCountCP = 0;
	}
	else if (CoordsCountCP != 4 && CoordsCountCP != 0)
	{
		cout << "You've guessed " << CoordsCountCP << " numbers correctly on their places, and " << NumbersCountCP - CoordsCountCP << "numbers, but not on their correct places!" << endl;
		CoordsCountCP = 0;
		NumbersCountCP = 0;
	}
	else if (CoordsCountCP == 4)
	{
		cout << "Congatulations, you have beaten the game, you have guessed all the numbers on their correct spots" << endl << endl << endl;
		NumbersCountCP = 0;
		flagCP = true;
		CoordsCountCP = 0;
	}
}