#include "pch.h"
#include <iostream>
using namespace std;

int GermansNumbers[4];
int GermansCords[4];
int NumberOfRounds = 0;

void InputGermansNumbers()
{
	for (int i = 1; i <= 4; i++)
	{
		cout << "Type 4 numbers";
		cin >> GermansNumbers[i];
	}
}

void InputGermansCoordinates()
{
	cout << "Type 4 coordinates:" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << "Number " << i << ": ";
		cin >> GermansCords[i];
		cout << endl;
	}
}
