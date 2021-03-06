#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

int GermansRandomNumbers[5]; //We declare a variable by random number
int BreakersGuessNumbersCP[5];//We declare a variable by Breakers
int RightGuessedNumberCP[5];//We declare a variable by RightGuessedNumber
int NumbersCountCP = 0;//We declare a variable by NumbersCount
int CoordsCountCP = 0;//We declare a variable by CoordsCount
bool flagCP = false;
int HistoryOfRoundsCP[14][5];//We declare a variable by HistoryOfRounds
int RowCounterCP = 0;

void StoringHistoryOfRoundsCP()//function for StoringHistoryOfRounds
{
	for (int j = 0; j < 4; j++)
	{
		HistoryOfRoundsCP[RowCounterCP][j] = BreakersGuessNumbersCP[j];
	}
	RowCounterCP++;
}

void VisualizingHistoryOfRoundsCP()//function for VisualizingHistoryOfRounds
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

void GenerateRandomNumbersNR()//function for GenerateRandomNumbers
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

void GenerateRandomNumbersR()//function for GenerateRandomNumbers
{
	for (int i = 0; i < 4; i++)
	{
		GermansRandomNumbers[i] = rand() % 7;
	}
}

void CheckBreakersGuessCP()//function for CheckBreakers
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

void FeedbackAfterRoundCP()//function for FeedbackAfterRound
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