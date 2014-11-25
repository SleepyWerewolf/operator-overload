// IntArray.h
// Operator Overloading Lab - CS 320
//
// This class is a dynamic Array, enhancing
// the normal c++ array to allow for specified
// index ranges, including negative numbers,
// as well as allowing for addition of arrays.
//
// 11/25/14
// Viet Truong - masc 0859

#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
using std::ostream;
using std::istream;
using std::string;

class IntArray
{
   friend ostream &operator<<(ostream &, const IntArray &);
public:
	IntArray();
	IntArray(int);
	IntArray(int, int); // default constructor
	IntArray(const IntArray &); // copy constructor
	~IntArray(); // destructor
	int getSize() const; // return size
	int low();
	int high();
	void setName(string);

	const IntArray &operator=(const IntArray &);
	bool operator==(const IntArray &) const;
	bool operator!=(const IntArray &right) const;
	const IntArray operator+(const IntArray &);
	const IntArray operator+=(const IntArray &);
	int &operator[](int);              
	int operator[](int) const;  

private:
	string name;
	int lowerBound;
	int upperBound;
   	int size; // pointer-based array size
   	int *ptr; // pointer to first element of pointer-based array
};

#endif
