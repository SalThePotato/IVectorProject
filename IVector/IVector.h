#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class IVector
{

public:

	// Default Constructor
	IVector();

	// The user specifys the object's attributes in this constructor
	IVector(size_t n, int value);

	// Copy Constructor
	IVector(const IVector& other);
	
	// Overloaded Intalizer copy operator
	IVector& operator=(const IVector& other);

	// Returns the size of the array
	size_t get_size() const;

	// Adds another value to our array
	void append(int value);

	// Displays our entire array to the console
	void dump() const;

	// Gets an element from the array at a certain index. Returns true or false depending if it was successful or not
	// If it is succesful, we put the value in the Int out.
	bool get(size_t index, int& out) const;

	// Sets a value in the vector at location index. 
	void set(size_t index, int value) const;

	// Destructor
	~IVector();

private:

	int* vector;
	size_t size;
};

