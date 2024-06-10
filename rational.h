//
// Created by Carlos R. Arias on 5/26/23.
//

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

//    friend Rational operator+(Rational const& lhs, Rational const& rhs);
//
//  friend ostream& operator<<(ostream& os, const Rational& rhs);

    friend ostream& operator<<(ostream& os, const Rational& lhs);


// Define the operator<< for Rational


    string ToString()const;
    double ToDouble()const;
    void simplify();
//    void commonDenom(Rational &rhs);

  //  void ToDouble(ostream& os)const;



    // The other methods!
    // Overload the following operators
    /*
     - Rational
     Rational + Rational
     Rational - Rational
     Rational * Rational
     Rational / Rational

     Rational += Rational
     Rational -= Rational
     Rational *= Rational
     Rational /= Rational
     Rational = Rational

     Rational == Rational
     Rational != Rational
     Rational > Rational
     Rational >= Rational
     Rational <= Rational
     Rational < Rational

     cout << Rational       (EXTRA)

     Add the following Methods:
     Rational::ToString()
     Rational::ToDouble()

     >>>>>> REMEMBER THE NUMBER IS ALWAYS SIMPLIFIED <<<<<<<

     */

};

//const Rational operator+(Rational const& lhs,Rational const& rhs) {
//    return Rational(lhs._numerator + rhs._numerator, lhs._denominator + rhs._denominator);
//}

//std::ostream& operator<<(std::ostream& os, const Rational& r) {
//    os << r.numerator << '/' << r.denominator;
//    return os;


//Rational operator+(Rational const& lhs, Rational const& rhs) {
//    return Rational(lhs._numerator + rhs._numerator, lhs._denominator + rhs._denominator);
//}
//
//ostream& operator<<(ostream& os, const Rational& lhs) {
//    os << lhs._numerator << '/' << lhs._denominator;
//    return os;
//}

//ostream& operator<<(ostream& os, const Rational& lhs) {
//    os << lhs._numerator << '/' << lhs._denominator;
//    return os;
//}

#endif //RATIONAL_OPERATOR_OVERLOAD_ASSIGNMENT_RATIONAL_H
