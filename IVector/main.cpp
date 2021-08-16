#include <iostream>
#include "IVector.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "Hello World!" << endl;

	// Didn't know what to do for the main so I just did some testing here and left it at that
	IVector e(1, 2);
	
	
	
	e.append(3);
	e.append(0);
	e.append(4);
	e.dump();
	cout << endl << e.min() << endl;
	cout << endl << e.max() << endl;

	return 0;
}