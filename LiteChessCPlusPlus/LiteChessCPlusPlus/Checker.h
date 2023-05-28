#pragma once
#include <iostream>
using namespace std;
class Checker
{
public:
	string color;
	string letterCord;
	int numberCord;
	bool alive = true;

	Checker(string color, string letterCord, int numberCord) {
		this->color = color;
		this->letterCord = letterCord;
		this->numberCord = numberCord;
	}
};

