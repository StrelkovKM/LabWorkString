#pragma once

#include <iostream>
#include "ClassTString.h"

using namespace std;

class TConsole
{
protected:
	int x;
	int y;
	int inlen;
public:
	TConsole();
	TConsole(int x_, int y_, int inlen_);
	~TConsole();

	int GetX() const;
	int GetY() const;
	int GetInlen() const;

	void SetX(int x_);
	void SetY(int y_);
	void SetInlen(int inlen_);

	void ConsoleOutputXY() const;
	void InputInlen(TString &obj) const;

	friend istream& operator>>(istream& input, TConsole& obj);
};