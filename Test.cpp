#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "Test.h"

using namespace std;

int main() {
    test2();
}


void test1() {
    IntArray a;
    int low = a.low();
    int high = a.high();
    int size = a.getSize();
    cout << "Low is " << low << endl;
    cout << "High is " << high << endl;
    for (int i=low; i<=high; i++)
        a[i] = i * 10;
    
    cout << "Array has " << size << " elements " << endl;
    cout << a << endl;
}

void test2() {
    IntArray a;
    IntArray b;
    IntArray c = a + b;
    cout << "C has " << c.getSize() << "elements" << endl;
    cout << c << endl;
}

void test3() {
    IntArray a;
    a[1] = 2;
}