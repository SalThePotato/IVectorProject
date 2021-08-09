#include <iostream>
#include "IVector.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "Hello World!" << endl;

	// Didn't know what to do for the main so I just did some testing here and left it at that
	IVector e(5, 2);
	
	IVector b(3, 6);
	b.append(73);
	e.dump();
	b.dump();

	e = b;
	e.dump();

	return 0;
}