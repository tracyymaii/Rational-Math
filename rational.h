/**
 * Title:		Lab 05 - rational.h
 * Purpose:		Does math operations on rational numbers
 * Author:		Tracy Mai
 * Date:		June 05, 2024
 */

#ifndef RATIONAL_OPERATOR_OVERLOAD_ASSIGNMENT_RATIONAL_H
#define RATIONAL_OPERATOR_OVERLOAD_ASSIGNMENT_RATIONAL_H

#include <string>
#include <ostream>
#include <iostream>

using std::string;
using std::ostream;

class Rational {
    int _numerator, _denominator;
public:
    Rational();
    Rational(int numerator, int denominator);
    Rational(double number);

    const Rational operator-()const;
    const Rational operator-(const Rational& rhs);
    const Rational operator+(const Rational& rhs);
    const Rational operator*(const Rational& rhs)const;
    const Rational operator/(const Rational& rhs)const;

    const Rational& operator+=(const Rational &rhs);
    const Rational& operator-=(const Rational &rhs);
    const Rational& operator*=(const Rational &rhs);
    const Rational& operator/=(const Rational &rhs);
    const Rational operator=(const Rational &rhs);

    bool operator==(const Rational &rhs)const;
    bool operator!=(const Rational &rhs)const;
    bool operator>(const Rational &rhs)const;
    bool operator>=(const Rational &rhs)const;
    bool operator<=(const Rational &rhs)const;
    bool operator<(const Rational &rhs)const;

    friend ostream& operator<<(ostream& os, const Rational& lhs);

    string ToString()const;
    double ToDouble()const;
    void simplify();
};

#endif //RATIONAL_OPERATOR_OVERLOAD_ASSIGNMENT_RATIONAL_H
