#include "ClassTString.h"

#include <iostream>

using namespace std;

int main()
{
	TString B("B") , G("G"), BG = B + G, K = BG;
	cout << B[0];
}
