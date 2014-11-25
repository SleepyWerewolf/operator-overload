// Fig 11.7: Array.cpp
// Member-function definitions for class Array
#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib> // exit function prototype
using std::exit;

#include "IntArray.h" // Array class definition


IntArray::IntArray() {
  size = 10;
  lowerBound = 0;
  upperBound = 9;
  ptr = new int[size];
}

// default constructor for class Array (default size 10)
IntArray::IntArray( int arraySize ) {
   size = ( arraySize > 0 ? arraySize : 10 ); // validate arraySize
   ptr = new int[ size ]; // create space for pointer-based array
   lowerBound = 0;
   upperBound = size-1;

   for ( int i = 0; i < size; i++ )
      ptr[ i ] = 0; // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
IntArray::IntArray( const IntArray &arrayToCopy ) 
   : size( arrayToCopy.size ) {
   ptr = new int[ arrayToCopy.size ]; // create space for pointer-based array
   lowerBound = arrayToCopy.lowerBound;
   upperBound = arrayToCopy.upperBound;

   for ( int i = lowerBound; i <= upperBound; i++ )
      ptr[ i ] = arrayToCopy[ i ]; // copy into object
} // end Array copy constructor

IntArray::IntArray( int lower, int upper) {
  lowerBound = lower;
  upperBound = upper;

  if (lowerBound < 0)
    size = upperBound + (-lowerBound+1);
  else if (upperBound < 0)
    size = (-lowerBound - -upperBound)+1;
  else
    size = (upperBound - lowerBound) + 1;
  ptr = new int[size];
}

// destructor for class Array
IntArray::~IntArray() {
   delete [] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
int IntArray::getSize() const {
   return size; // number of elements in Array
} // end function getSize

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const IntArray &IntArray::operator=( const IntArray &right ) {
   if ( &right != this ) { // avoid self-assignment
      // for Arrays of different sizes, deallocate original
      // left-side array, then allocate new left-side array
      if ( size != right.size ) {
         delete [] ptr; // release space
         size = right.size; // resize this object
         ptr = new int[ size ]; // create space for array copy
      } // end inner if

      for ( int i = 0; i < size; i++ )
         ptr[ i ] = right.ptr[ i ]; // copy array into object
   } // end outer if

   return *this; // enables x = y = z, for example
} // end function operator=

// determine if two Arrays are equal and
// return true, otherwise return false
bool IntArray::operator==( const IntArray &right ) const {
   if ( size != right.getSize() )
      return false; // arrays of different number of elements

   for ( int i = 0; i < size; i++ )
      if ( ptr[ i ] != right.ptr[ i ] )
         return false; // Array contents are not equal

   return true; // Arrays are equal
} // end function operator==

const IntArray IntArray::operator+(const IntArray &right) {
  if (size == right.getSize()) {
    int temp [right.getSize()];
    for (int i=0; i<right.getSize(); i++)
      temp[i] = ptr[i] + right[i];
    return *temp;
  } else {
    cerr << "\nError: Arrays not same length" << endl;
    exit(1);
  }
}

const IntArray IntArray::operator+=(const IntArray &right) {
  if (size == right.getSize()) {
    for (int i=0; i<right.getSize(); i++)
      ptr[i] = ptr[i] + right[i];
    return *this;
  } else {
    cerr << "\nError: Arrays not same length" << endl;
    exit(1);
  }
}

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int &IntArray::operator[]( int index ) {
  if (index < lowerBound || index > upperBound) {
    cerr << "\nError: Index out of bounds" << endl;
    exit(1);
  } 
  else return ptr[index];
} // end function operator[]


// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int IntArray::operator[]( int subscript ) const {
   // check for subscript out-of-range error
   if ( subscript < lowerBound || subscript > upperBound ) {
      cerr << "\nError: Subscript " << subscript << " out of range" << endl;
      exit( 1 ); // terminate program; subscript out of range
   } // end if

   else return ptr[subscript]; // returns copy of this element
} // end function operator[]

// overloaded input operator for class Array;
// inputs values for entire Array
istream &operator>>( istream &input, IntArray &a ) {
   for ( int i = a.lowerBound; i <= a.upperBound; i++ )
      input >> a.ptr[ i ];
   return input; // enables cin >> x >> y;
} // end function 

// overloaded output operator for class Array 
ostream &operator<<(ostream &output, const IntArray &a) {
    for (int i = a.lowerBound; i <= a.upperBound; i++)
        output << "a[" << i << "] = " << a[i] << " ";
    return output;
} // end function operator<<

int IntArray::low() {
  return lowerBound;
}

int IntArray::high() {
  return upperBound;
}

void IntArray::setName(string toName) {
  name = toName;
}
