#include "ClassTConsole.h"
#include "ClassTString.h"
#include <conio.h>
#include <Windows.h>

TConsole::TConsole()
{
	x = 1; y = 1, inlen = 1;
}

TConsole::TConsole(int x_, int y_, int inlen_)
{
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
	x = x_;
}

void TConsole::SetY(int y_)
{
	y = y_;
}

void TConsole::SetInlen(int inlen_)
{
	inlen = inlen_;
}

void TConsole::ConsoleOutputXY() const
{
	for (int i = 0; i < y; i++) cout << '\n';
	for (int i = 0; i < x; i++) cout << ' ';
}

void TConsole::InputInlen(TString &obj) const
{
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
		buff[i] = _getch();
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

