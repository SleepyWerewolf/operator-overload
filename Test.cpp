#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "Test.h"

using namespace std;

int main() {
    test6();
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
    system("clear");
    cout << "3. Array declared with two integers: IntArray c(6, 8);" << endl << endl;
    IntArray c(6, 8);
    for(int i = c.low(); i <= c.high(); i++)
        c[i] = i * 10;
    c.setName("c");
    cout << c << endl;
}

void test4() {
    system("clear");
    cout << "4. Array declared with two identical integers: IntArray d(5, 5);" << endl << endl;
    IntArray d(5, 5);
    for(int i = d.low(); i <= d.high(); i++)
        d[i] = i * 10;
    d.setName("d");
    cout << d << endl;
}

void test5() {
    system("clear");
    cout << "5. Array declared with no integers: IntArray z;" << endl << endl;
    IntArray z;
    for(int i = z.low(); i <= z.high(); i++)
        z[i] = i * 10;
    z.setName("z");
    cout << z << endl;
}

void test6() {
    system("clear");
    cout << "6. Array declared with another object of type IntArray: IntArray c(6, 8);" << endl;
    cout << "                                                        Intarray e(c);"    << endl << endl;
    IntArray c(6, 8);
    for(int i = c.low(); i <= c.high(); i++)
        c[i] = i * 10;
    c.setName("c");
    cout << c << endl;
    IntArray e(c);
    e.setName("e");
    cout << e << endl;  
}





