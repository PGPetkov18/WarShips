#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

int GermansRandomNumbers[5];
int BreakersGuessNumbersCP[5];
int RightGuessedNumberCP[5];
int NumbersCountCP = 0;
int CoordsCountCP = 0;

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
    for (int i = 1; i <= 4; i++)
    {
        GermansRandomNumbers[i] = rand() % 7;
    }
}

void CheckBreakersGuessCP()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (BreakersGuessNumbersCP[i] == GermansRandomNumbers[j])
            {
                RightGuessedNumberCP[NumbersCountCP++] = BreakersGuessNumbersCP[i];
                if ((i == j) && (BreakersGuessNumbersCP[i] == GermansRandomNumbers[j]))
                {
                    CoordsCountCP++;
                }
                i++;
            }
        }
    }
}
