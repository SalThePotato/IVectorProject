#include "IVector.h"
#include <algorithm>


// Default Constructor
IVector::IVector() : vector{ new int[1] }, size{ 1 }
{
	*vector = 0;
}


// The user specifys the object's attributes in this constructor
IVector::IVector(size_t n, int value) : vector{ new int[n] }, size{ n }
{
	std::fill_n(vector, n, value); 
}


// Copy Constructor
IVector::IVector(const IVector& other) : vector{ new int[1] }, size{ 1 }
{
	*this = other;
}


// Overloaded Intalizer copy operator
IVector& IVector::operator=(const IVector& other)
{
	// Checks the addresses of each object to make sure their not the same and if they are we return this object
	if (this == &other)
		return *this;

	// We then delete vector and make a new array
	delete[] vector;
	vector = new int[other.get_size()];

	// We then update our size to match our array
	size = other.get_size();

	// We then copy the other array to this new array
	for (size_t i = 0; i < other.get_size(); i++)
		if (other.get(i, vector[i]) == false)
			cout << "ERROR : Copying between two IVectors has failed because it is trying to access memory that is out of bounds of vector's size. Called from Overloaded = operator in the IVector Class. " << endl;

	// We then return the updated this
	return *this;
}


// Returns the size of the array
size_t IVector::get_size() const
{
	return size;
}


// Adds another value to our array
void IVector::append(int value) 
{
	// We make a new array with a new size
	int* new_vector = new int[size + 1];

	// We then copy everything from our old array to this new one
	for (size_t i = 0; i < size; i++)
		new_vector[i] = vector[i];

	// Finally, we add the passed in value to the new array
	new_vector[size] = value;

	// We delete our old array and assign vector to our new array
	delete[] vector;
	vector = new_vector;

	// We assign new_vector to nullptr so when we delete it, it doesn't delete the data vector points to
	new_vector = nullptr;
	delete[] new_vector;

	size += 1;
}


// Displays our entire array to the console
void IVector::dump() const
{
	cout << endl << "The Ivector's entire " << size << " values: ";

	for (size_t i = 0; i < size; i++)
		cout << vector[i] << ", ";
}


// Gets an element from the array at a certain index. Returns true or false depending if it was successful or not
// If it is succesful, we put the value in Int out.
bool IVector::get(size_t index, int& out) const
{
	// We make sure index isn't bigger or equal to the vector's size or else we tell the user there was an error and we return
	if (index >= size)
	{
		cout << "ERROR : The index provided into the Get Function in Class IVector is out of bounds of the vector's size. Get function failed." << endl;
		return false;
	}

	out = vector[index];
	return true;
}


// Sets a value in the vector at location index. 
void IVector::set(size_t index, int value) const
{
	// We make sure index isn't bigger or equal to the vector's size or else we tell the user there was an error and we return
	if (index >= size)
	{
		cout << "ERROR : The index provided into the Set Function in Class IVector is out of bounds of the vector's size. Set function failed. " << endl;
		return;
	}

	vector[index] = value;
}


// Destructor
IVector::~IVector()
{
	delete[] vector;
}