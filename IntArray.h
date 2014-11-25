// Fig. 11.6: Array.h
// Array class for storing arrays of integers.
#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
using std::ostream;
using std::istream;
using std::string;

class IntArray
{
   friend ostream &operator<<( ostream &, const IntArray & );
   friend istream &operator>>( istream &, IntArray & );
public:
	IntArray();
	IntArray(int);
	IntArray(int, int); // default constructor
	IntArray( const IntArray & ); // copy constructor
	~IntArray(); // destructor
	int getSize() const; // return size

	const IntArray &operator=( const IntArray & ); // assignment operator
	bool operator==( const IntArray & ) const; // equality operator

	// inequality operator; returns opposite of == operator
	bool operator!=( const IntArray &right ) const { 
	  return ! ( *this == right ); // invokes Array::operator==
	} // end function operator!=

	const IntArray operator+(const IntArray&);

	const IntArray operator+=(const IntArray&);

	// subscript operator for non-const objects returns modifiable lvalue
	int &operator[]( int );              

	// subscript operator for const objects returns rvalue
	int operator[]( int ) const;  

	int low();

	int high();

	void setName(string toName);
private:
	string name;
	int lowerBound;
	int upperBound;
   	int size; // pointer-based array size
   	int *ptr; // pointer to first element of pointer-based array
   	int offset;
}; // end class Array

#endif
