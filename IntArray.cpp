// IntArray.cpp
// Operator Overloading Lab - CS 320
//
// This class is a dynamic Array, enhancing
// the normal c++ array to allow for specified
// index ranges, including negative numbers,
// as well as allowing for addition of arrays.
//
// 11/25/14
// Viet Truong - masc 0859

#include <iostream>
#include <iomanip>
#include <cstdlib> // exit function prototype
#include "IntArray.h" // Array class definition

using namespace std;

//--------------- CONSTRUCTORS --------------------

IntArray::IntArray() {
  size = 10;
  lowerBound = 0;
  upperBound = 9;
  ptr = new int[size];
  for (int i=0; i<size; i++)
    ptr[i] = 0;
}

// default constructor for class Array (default size 10)
IntArray::IntArray(int arraySize) {
  // validate arraySize
  if (arraySize > 0)
    size = arraySize;
  else 
    size = 10;

  ptr = new int[ size ];
  lowerBound = 0;
  upperBound = size-1;

  for (int i = 0; i < size; i++)
    ptr[i] = 0;
}

IntArray::IntArray(const IntArray &arrayToCopy){
  size = arrayToCopy.size;
  ptr = new int[size];
  lowerBound = arrayToCopy.lowerBound;
  upperBound = arrayToCopy.upperBound;

  for (int i = 0; i < size; i++)
    ptr[i] = arrayToCopy.ptr[i];
}

IntArray::IntArray(int lower, int upper) {
  if (lower > upper) {
    lowerBound = 0;
    upperBound = 9;
    ptr = new int[10];
  }
  else {
    lowerBound = lower;
    upperBound = upper;

    if (lowerBound < 0)
      size = upperBound + (-lowerBound+1);
    else if (upperBound < 0)
      size = (-lowerBound - -upperBound)+1;
    else
      size = (upperBound - lowerBound) + 1;
    ptr = new int[size];
    for (int i=0; i < size; i++)
      ptr[i] = 0;
  }
}

IntArray::~IntArray() {
   delete [] ptr;
}

int IntArray::getSize() const {
   return size;
}

int IntArray::low() {
  return lowerBound;
}

int IntArray::high() {
  return upperBound;
}

void IntArray::setName(string toName) {
  name = toName;
}

//--------------- OVERLOADED OPERATORS --------------------

const IntArray &IntArray::operator=(const IntArray &right) {
  if (this != &right) {
    if (size != right.size) 
      cerr << "Error: Arrays not the same size" << endl;
    else {
      for (int i=0; i<size; i++)
        ptr[i] = right.ptr[i];
    }
  } 
  return *this;
}

bool IntArray::operator==(const IntArray &right) const {
  if (size != right.getSize())
    return false;
  else
    for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
         return false;
  return true;
}

bool IntArray::operator!=(const IntArray &right) const {
  return !(*this == right);
}

IntArray IntArray::operator+(const IntArray &right) {
  if (size == right.getSize()) {
    IntArray temp = *this;
    temp.lowerBound = 0;
    temp.upperBound = size-1;
    for (int i=0; i<size; i++)
      temp[i] += right.ptr[i];
    return temp;
  } else {
    cerr << "\nError: Arrays not the same length" << endl;
    exit(1);
  }
}

/*
const IntArray &IntArray::operator+(const IntArray &right, IntArray &temp) {
  if (size == right.getSize()) {
    temp = new int[right.getSize()];
    for (int i=0; i<size; i++)
      temp[i] = ptr[i] + right.ptr[i];
    return temp;
  } else {
    cerr << "\nError: Arrays not same length" << endl;
    exit(1);
  }
}
*/

const IntArray IntArray::operator+=(const IntArray &right) {
  if (size == right.getSize()) {
    for (int i=0; i<size; i++)
      ptr[i] += right.ptr[i];
    return *this;
  } else {
    cerr << "\nError: Arrays not same length" << endl;
    exit(1);
  }
}

int &IntArray::operator[](int index) {
  if (index < lowerBound || index > upperBound) {
    cerr << "\nError: Index out of bounds" << endl;
  } 
  if (lowerBound < 0 || upperBound < 0)
    return ptr[index + lowerBound];
  else return ptr[index-lowerBound];
}

int IntArray::operator[](int index) const {
  if (index < lowerBound || index > upperBound) {
    cerr << "\nError: Subscript " << index << " out of range" << endl;
  }
  if (lowerBound < 0 || upperBound < 0)
    return ptr[index + lowerBound];
  else return ptr[index-lowerBound];
}

// overloaded output operator for class Array 
ostream &operator<<(ostream &output, const IntArray &a) {
    for (int i = a.lowerBound; i <= a.upperBound; i++)
        output << a.name << "[" << i << "] = " << a[i] << " ";
    return output;
}
