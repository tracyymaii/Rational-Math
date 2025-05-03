/**
 * Title:		main.cpp
 * Purpose:		Test cases. The only changes I made were to assertion
 *              values when they did not match the math they were
 *              supposed to. I did not change anything else, such as
 *              the Rational Constructor values.
 * Author:		Tracy Mai
 * Date:		June 05, 2024
 */


#include "rational.h"


#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <cmath>

using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;
using std::string;

bool DoubleEquals(double a, double b, double epsilon = 1e-2);

int main(int argc, char* argv[]) {
    bool extra = true;
    if (argc == 2){
        string flag = argv[1];
        if (flag == "-extra")
            extra = true;
        else{
            cerr << "Wrong flag" << endl;
            exit(1);
        }
    }
    // Constructors
    Rational a(1,2);
    Rational b(3, 4);
    Rational c(15, 9);
    Rational d(4, 1);
    Rational e(1, 9);
    Rational r(0, 1);

    unsigned int passed = 0;
    cout << "Tests Start" << endl;

    // ToString & ToDouble
    assert(a.ToString() == "1/2");
    cout << ++passed << "\tpassed" << endl;
    assert(DoubleEquals(a.ToDouble(), 0.5));
    cout << ++passed << "\tpassed" << endl;
    assert(c.ToString() == "5/3");
    cout << ++passed << "\tpassed" << endl;
    assert(DoubleEquals(c.ToDouble(), 1.67));
    cout << ++passed << "\tpassed" << endl;
    assert(d.ToString() == "4");
    cout << ++passed << "\tpassed" << endl;
    assert(DoubleEquals(d.ToDouble(), 4.0));
    cout << ++passed << "\tpassed" << endl;
    assert(e.ToString() == "1/9");
    cout << ++passed << "\tpassed" << endl;
    assert(DoubleEquals(e.ToDouble(),1.0/9.0));
    cout << ++passed << "\tpassed" << endl;
    assert(r.ToString() == "0");
    cout << ++passed << "\tpassed" << endl;
    assert(DoubleEquals(r.ToDouble(), 0));
    cout << ++passed << "\tpassed" << endl;

    // Comparison
    assert(a == Rational(1, 2));
    cout << ++passed << "\tpassed" << endl;
    assert(a != b);
    cout << ++passed << "\tpassed" << endl;
    assert(a > Rational(1, 6));
    cout << ++passed << "\tpassed" << endl;
    assert(a < b);
    cout << ++passed << "\tpassed" << endl;
    assert(a >= Rational(1, 2));
    cout << ++passed << "\tpassed" << endl;
    assert(a <= Rational(9, 10));
    cout << ++passed << "\tpassed" << endl;

    // Basic Arithmetic
    r = a + b;
    assert(r.ToString() == "5/4");
    cout << ++passed << "\tpassed" << endl;
    r  = e - c;
    assert(r.ToString() == "-14/9");
    cout << ++passed << "\tpassed" << endl;
    r = a * c;
    assert(r.ToString() == "5/6");
    cout << ++passed << "\tpassed" << endl;
    r = c / b;
    assert(r.ToString() == "20/9");
    cout << ++passed << "\tpassed" << endl;
    r = -e;
    assert(r.ToString() == "-1/9");
    cout << ++passed << "\tpassed" << endl;

    // Assignment operators
    r = Rational(2, 1);
    r += a;
    assert(r == Rational(5,2));
    cout << ++passed << "\tpassed" << endl;
    r -= Rational(3, 2);
    assert(r == Rational(1,1));
    cout << ++passed << "\tpassed" << endl;
    r *= Rational(2, 13);
    assert(r == Rational(2, 13));
    cout << ++passed << "\tpassed" << endl;
    r /= Rational(2, 13);
    assert(r == Rational(1,1));
    cout << ++passed << "\tpassed" << endl;

    cout << "Basic Tests Passed" << endl;

    if (extra){
        Rational f(0.5);
        Rational g(0.1111111);
        if (f == a)
            cout << "Rational(double) 1/2 passed " << ++passed << endl;
        if (g == e)
            cout << "Rational(double) 2/2 passed " << ++passed << endl;

        stringstream out;
        out << a;
        if (out.str() == "1/2")
            cout << "ostream << Rational passed " << ++passed << endl;
    }
    cout << string('-', 40) << endl;
    cout << "Finished, " << passed << "/25 passed " << (passed/25.0)*100 << endl;
    return 0;
}


bool DoubleEquals(double a, double b, double epsilon){
    return abs(a - b) < epsilon;
}