#pragma once
#include <iostream>
using namespace std;
class Field
{
public:
	string leftRight[21] = { "|", " ", "|", "  ", "|", "  ", "|", "  ", "|", "  ", "|", "  ", "|", "  ", "|", "  ", "|", "  ", "|", "  ", "|" };
	string topBottom[10] = { " --", "--", "--", "--", "--", "--", "--", "--", "--", "-- " };

	void PrintField() {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    cout << "X";
                }
                else
                {
                    cout << "O";
                }
            }
            cout << endl;
        }
	}
};

