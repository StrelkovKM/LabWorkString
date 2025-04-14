#include "ClassTConsole.h"
#include "ClassTString.h"
#include <conio.h>

TConsole::TConsole()
{
	x = 1; y = 1, inlen = 1;
}

TConsole::TConsole(int x_, int y_, int inlen_)
{
	if (x_ < 0 || y_ < 0 || inlen_ < 0) throw(0);
	x = x_; y = y_; inlen = inlen_;
}

TConsole::~TConsole()
{
}

int TConsole::GetX() const
{
	return x;
}

int TConsole::GetY() const
{
	return y;
}

int TConsole::GetInlen() const
{
	return inlen;
}

void TConsole::SetX(int x_)
{
	if (x_ < 0) throw(0);
	x = x_;
}

void TConsole::SetY(int y_)
{
	if (y_ < 0) throw(0);
	y = y_;
}

void TConsole::SetInlen(int inlen_)
{
	if (inlen_ < 0) throw(0);
	inlen = inlen_;
}

void TConsole::ConsoleOutputXY() const
{
	for (int i = 0; i < y; i++) cout << '\n';
	for (int i = 0; i < x; i++) cout << ' ';
}

void TConsole::InputInlen(TString &obj) const
{
	system("cls");
	ConsoleOutputXY();

	char* buff = new char[256] {};
	int i = 0;
	while (buff[i-1] != '\r')
	{
		if (i % inlen == 1) 
		{
			system("cls");
			ConsoleOutputXY();
		}
		buff[i] = getch();
		cout << buff[i++];
	}
	buff[i] = '\0';
	system("cls");
	obj.SetStr(buff);
	delete[] buff;
}

istream& operator>>(istream& input, TConsole& obj)
{
	cout << "Enter X:"; input >> obj.x;
	cout << "Enter Y:"; input >> obj.y;
	cout << "Enter len of window:"; input >> obj.inlen;
	return input;
}

