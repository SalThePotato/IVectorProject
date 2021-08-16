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
		vector[i] = other[i];

	// We then return the updated this
	return *this;
}


// Overloaded the brackets operator to get the element at index. It doesn't check if it is valid memory 
int IVector::operator[](size_t index) const
{
	return vector[index];
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



int IVector::at(size_t index) const
{
	// We check if index is accessing invaild memory
	if (index >= size)
	{
		// If it is, we throw an exception
		// error
	}

	return vector[index];
}


// Sets a value in the vector at location index. 
bool IVector::set(size_t index, int value) const
{
	// We make sure index isn't bigger or equal to the vector's size or else we tell the user there was an error and we return
	if (index >= size)
	{
		cout << "ERROR : The index provided into the Set Function in Class IVector is out of bounds of the vector's size. Set function failed. " << endl;
		return false;
	}

	vector[index] = value;
	return true;
}


// Return sum of elements in the ivector 
int IVector::sum() const
{
	int sum = 0;

	// Goes through all the elements of the array and adds them all to the sum
	for (int i = 0; i < size; i++)
		sum += vector[i];

	return sum;
}


// Returns the smallest value in the ivector
int IVector::min() const
{
	// we set the min to the first value as our starting point
	int min = vector[0];

	// We will use this later to see if we have found a smaller number to see if we should test again
	bool found_number_smaller = false;

	// We stay in this infinite loop until we have found the smallest number
	while (true)
	{
		// We reset the bool each iteration
		found_number_smaller = false;

		// We check min with the entire array to make sure there isn't another smaller number somewhere before or after it
		for (size_t b = 0; b < size; b++)
		{
			// We check to see if there is a number smaller then min
			if (vector[b] < min)
			{
				// And if there is, we set min to it and break out of the loop
				min = vector[b];
				found_number_smaller = true;
				break;
			}
		}

		if (found_number_smaller == false)
			break;
	}

	return min;
}


// Returns the biggest value in the ivector
int IVector::max() const
{
	// we set the max to the first value as our starting point
	int max = vector[0];

	// We will use this later to see if we have found a smaller number to see if we should test again
	bool found_number_bigger = false;

	// We stay in this infinite loop until we have found the smallest number
	while (true)
	{
		// We reset the bool each iteration
		found_number_bigger = false;

		// We check max with the entire array to make sure there isn't another smaller number somewhere before or after it
		for (size_t i = 0; i < size; i++)
		{
			// We check to see if there is a number smaller then max
			if (vector[i] > max)
			{
				// And if there is, we set max to it and break out of the loop
				max = vector[i];
				found_number_bigger = true;
				break;
			}
		}

		if (found_number_bigger == false)
			break;
	}

	return max;
}


// Swaps the values at the locations provided in the ivector
void IVector::swap(size_t index_one, size_t index_two)
{
	// We make sure index_one and index_two are not going to access invaild memory
	if (index_one < size || index_two < size)
	{
		cout << "ERROR : The values passed in to the swap function is accessing invaild memory. The task has failed. Calling from the swap function in class IVector. " << endl;
		return;
	}

	int holder = vector[index_one];

	vector[index_one] = vector[index_two];
	vector[index_two] = holder;
}

// Destructor
IVector::~IVector()
{
	delete[] vector;
}