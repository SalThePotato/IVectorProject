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

	// Overloaded the brackets operator to get the element at index. It doesn't check if it is valid memory 
	int operator[](size_t index) const;

	// Returns the size of the array
	size_t get_size() const;

	// Adds another value to our array
	void append(int value);

	// Displays our entire array to the console
	void dump() const;

	// Returns the element at location index. This will check if it is valid memory 
	int at(size_t index) const;

	// Sets a value in the vector at location index. Returns true or false depending if it was successful or not
	bool set(size_t index, int value) const;

	// Return sum of elements in the ivector 
	int sum() const;

	// Returns the smallest value in the ivector
	int min() const;

	// Returns the biggest value in the ivector
	int max() const;
	
	// Swaps the values at the locations provided in the ivector
	void swap(size_t index_one, size_t index_two);

	// Destructor
	~IVector();

private:

	int* vector;
	size_t size;
};

