#include "pch.h"
#include <iostream>
using namespace std;

int NumberOfCords;
int Cords=0;
int GermansNumbers[4];
int GermansCords[4];

void MapVisualizer()
{
	for (int i = 1; i <= NumberOfCords; i++)
	{
		for (int i = 1; i <= NumberOfCords; i++)
		{
				Cords++;
			cout << " [";
			if (Cords < 10)
			{
				cout << 0 << Cords;
			}
			else
			{
				cout << Cords;
			}
			cout << "] ";
		}
		cout << endl << endl;
	}
}

int main()
{
	cin >> NumberOfCords;
	for (int i = 1; i <= 4; i++)
	{
		cin >> GermansNumbers[i];

	}
	for (int i = 1; i <= 4; i++)
	{
		cin >> GermansCords[i];
	}
	MapVisualizer();
}