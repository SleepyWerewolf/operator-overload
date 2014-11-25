#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "Test.h"

using namespace std;

int main() {
    test15();
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
    IntArray a(-10, 2);
    for (int i=a.low(); i<=a.high(); i++)
        a[i] = i*10;
    cout << "Array has " << a.getSize() << " elements" << endl;
    cout << a << endl;

    cout << "Changing value of a[-5]" << endl;
    a[-5] = 27;
    a.setName("a");
    cout << a << endl << endl;

    IntArray b(1, 13);
    cout << "Array has " << b.getSize() << " elements" << endl;
    b.setName("b");
    b = a;
    cout << a << endl;
    cout << b << endl;

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

void test7() {
    system("clear");
    cout << "7. Array assigned to another array with different indices: IntArray f(1, 4);"  << endl;
    cout << "                                                           IntArray g(5, 8);"  << endl;
    cout << "                                                           f = g;"             << endl << endl;
    IntArray f(1, 4);
    for(int i = f.low(); i <= f.high(); i++)
        f[i] = i * 10;
    f.setName("f");
    cout << f << endl;
    IntArray g(5, 8);
    for(int i = g.low(); i <= g.high(); i++)
        g[i] = i * 10;
    g.setName("g");
    cout << g << endl;
    system("clear");

    f = g;
    cout << f << endl;
    cout << g << endl;
}

void test8() {

    cout << "8. Multiple array assignment with different indices: IntArray j(3, 6);"  << endl;
    cout << "                                                     IntArray k(6, 9);"  << endl;
    cout << "                                                     IntArray l(1, 4);"  << endl;
    cout << "                                                     j = k = l;"         << endl << endl;
    IntArray j(3, 6);
    for(int i = j.low(); i <= j.high(); i++)
        j[i] = i * 10;
    j.setName("j");
    cout << j << endl;
    IntArray k(6, 9);
    for(int i = k.low(); i <= k.high(); i++)
        k[i] = i * 10;
    k.setName("k");
    cout << k << endl;
    IntArray l(1, 4);
    for(int i = l.low(); i <= l.high(); i++)
        l[i] = i * 10;
    l.setName("l");
    cout << l << endl;

    cout << "K[6] is " << k[6] << endl;
    //k[6] = l[1];
    //k[7] = l[2];
    //k[8] = l[3];
    //k[9] = l[4];
    cout << j << endl;
    cout << k << endl;
    cout << l << endl;
}

void test9() {
    cout << "9. Overloaded equality operator (identical elements): IntArray m(3, 7);"  << endl;
    cout << "                                                      IntArray n(1, 5);"  << endl;
    cout << "                                                      m == n"             << endl << endl;
    IntArray m(3, 7);
    for(int i = m.low(); i <= m.high(); i++)
        m[i] = i * 10;
    m.setName("m");
    cout << m << endl;
    IntArray n(1, 5);
    for(int i = n.low(); i <= n.high(); i++)
        n[i] = i * 10;
    n.setName("n");
    cout << n << endl;
    m = n;
    cout << m << endl;
    cout << n << endl;
    cout << "M has " << m.getSize() << " elements" << " with a lower bound of " << m.low() << endl;
    cout << "N has " << n.getSize() << " elements" << " with a lower bound of " << n.low() << endl;
    cout << "Returns " << (m == n ? "True." : "False.") << endl << endl;
}

void test10() {
    cout << "10. Overloaded equality operator (different elements): IntArray o(3, 7);"  << endl;
    cout << "                                                       IntArray p(1, 5);"  << endl;
    cout << "                                                       o == p"             << endl << endl;

    IntArray o(3, 7);
    for(int i = o.low(); i <= o.high(); i++)
        o[i] = i * 10;
    o.setName("o");
    cout << o << endl;

    IntArray p(1, 5);
    for(int i = p.low(); i <= p.high(); i++)
        p[i] = i * 10;
    p.setName("p");
    cout << p << endl;
    cout << "Returns " << (o == p ? "True." : "False.") << endl << endl;
}

void test11() {
    cout << "11. Overloaded equality operator (different size arrays): IntArray q(1, 3);"  << endl;
    cout << "                                                          IntArray r(1, 4);"  << endl;
    cout << "                                                          q == r;"    << endl << endl;

    IntArray q(1, 3);
    for(int i = q.low(); i <= q.high(); i++)
        q[i] = i * 10;
    q.setName("q");
    cout << q << endl;

    IntArray r(1, 4);
    for(int i = r.low(); i <= r.high(); i++)
        r[i] = i * 10;
    r.setName("r");
    cout << r << endl;
    cout << "Returns " << (q == r ? "True." : "False.") << endl << endl;
}

void test12() {
    cout << "12. Overloaded inequality operator (identical elements): IntArray s(3, 7);" << endl;
    cout << "                                                         IntArray t(1, 5);" << endl;
    cout << "                                                         s != t;"           << endl << endl;

    IntArray s(3, 7);
    for(int i = s.low(); i <= s.high(); i++)
        s[i] = i * 10;
    s.setName("s");
    cout << s << endl;

    IntArray t(1, 5);
    for(int i = t.low(); i <= t.high(); i++)
        t[i] = i * 10;
    t.setName("t");
    cout << t << endl;

    s = t;
    cout << s << endl;
    cout << t << endl;
    cout << "Returns " << (s != t ? "True." : "False.") << endl << endl;
}

void test13() {
    cout << "13. Overloaded inequality operator (different elements): IntArray u(3, 7);" << endl;
    cout << "                                                         IntArray v(1, 5);" << endl;
    cout << "                                                         u != v;"           << endl << endl;

    IntArray u(3, 7);
    for(int i = u.low(); i <= u.high(); i++)
        u[i] = i * 10;
    u.setName("u");
    cout << u << endl;

    IntArray v(1, 5);
    for(int i = v.low(); i <= v.high(); i++)
        v[i] = i * 10;
    v.setName("v");
    cout << v << endl;
    cout << "Returns " << (u != v ? "True." : "False.") << endl << endl;
}

void test14() {
    cout << "14. Overloaded inequality operator (different size arrays): IntArray w(1, 3);" << endl;
    cout << "                                                            IntArray x(1, 4);" << endl;
    cout << "                                                            w != x;"           << endl << endl;

    IntArray w(1, 3);
    for(int i = w.low(); i <= w.high(); i++)
        w[i] = i * 10;
    w.setName("w");
    cout << w << endl;

    IntArray x(1, 4);
    for(int i = x.low(); i <= x.high(); i++)
        x[i] = i * 10;
    x.setName("x");
    cout << x << endl;
    cout << "Returns " << (w != x ? "True." : "False.") << endl << endl;
}

void test15() {
    cout << "15. Sum of two arrays assigned to third array: IntArray a(1, 5);"   << endl;
    cout << "                                               IntArray b(4, 8);"   << endl;
    cout << "                                               IntArray c = a + b;" << endl << endl;

    IntArray a(1, 5);
    for(int i = a.low(); i <= a.high(); i++)
        a[i] = i * 10;
    a.setName("a");
    cout << a << endl;

    IntArray b(4, 8);
    for(int i = b.low(); i <= b.high(); i++)
        b[i] = i * 10;
    b.setName("b");
    cout << b << endl;

    system("clear");
    a += b;
    /*
    IntArray c = a + b;
    c.setName("c");
    cout << "C has a range of " << c.low() << " to " << c.high() << endl;
    cout << c << endl;
    */
    cout << a << endl;
}
