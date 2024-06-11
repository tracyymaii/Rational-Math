/**
 * Title:		Lab 05 - rational.cpp
 * Purpose:		Does math operations on rational numbers
 * Author:		Tracy Mai
 * Date:		June 05, 2024
 */


#include "rational.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <string>

using std::ostream;
using std::stringstream;
using std::setprecision;
using std::cout;

/**
 * Rational Constructor
 * Makes a rational number of 0, when given no parameters.
 * Sets the numerator to 0 and the denominator to 1
 * @param none
 * @return none
 *
 */
Rational::Rational(): _numerator(0), _denominator(1) {
}

/**
 * Rational Constructor
 * Creates a rational number
 * @param numerator
 * @param denominator
 */
Rational::Rational(int numerator, int denominator): _numerator(numerator), _denominator(denominator) {

    if (_denominator == _numerator) {
        return;
    }

    simplify();
    numerator = _numerator;
    denominator = _denominator;
}


/**
 * Rational Constructor for Doubles
 * Takes in a double and turns it into a rational number.
 * Does so finding out how many decimal numbers there are, making
 * that that be how many decimals are in the denominator after 1.
 * Multiples the denominator by the given number to create the numerator.
 * Calls simplify to simply the rational.
 * @param number
 * @return none
 */
Rational::Rational(double number) {

    stringstream ss;
    ss << number;

    string num = ss.str();

    int pos;

    if (num.find(".") == std::string::npos) {
        _numerator = number;
        _denominator = 1;
        return;
    } else {
        pos = num.find(".");
    }

    ss.str("");
    ss << "1";
    for (size_t i = pos + 1 ; i < num.length(); i++) {
        ss << "0";
    }

    _denominator = stoi(ss.str());
    _numerator = (stoi(num) * _denominator);

    simplify();
}

/**
 * Simplify
 * Simplifies any rational number
 * @param none
 * @return none
 */
void Rational::simplify()  {

    int gcf = 1;

    int smallerNum = (abs(_numerator) < abs(_denominator) ? abs(_numerator) : abs(_denominator));

    for (int i = 2; i <= smallerNum; i++) {
        if (_numerator % i == 0 && _denominator % i == 0) {
            gcf = i;
        }
    }

    _numerator /= gcf;
    _denominator /= gcf;
}

/**
 * Rational Operator - Overload
 * Turns any rational number into its negative
 * @param none
 * @returns the negative of the number that originally called it.
 */
const Rational Rational::operator-()const {
    return Rational(-1 * _numerator, _denominator);
}

/**
 * Rational Operator - Overload
 * Subtracts two rational numbers.
 * Finds common denominators when necessary.
 * @param rhs
 * @returns the difference between the two numbers.
 */
const Rational Rational::operator-(const Rational& rhs) {

    if (_denominator != rhs._denominator) {
        Rational result((_numerator * rhs._denominator) - (rhs._numerator * _denominator), _denominator * rhs._denominator);
        return result;

    } else {
        Rational result(_numerator - rhs._numerator, _denominator);
        return result;

    }
}

/**
 * Rational Operator + Overload
 * Adds two rational numbers.
 * Finds common denominators when necessary.
 * @param rhs
 * @returns the sum between the two numbers.
 */
const Rational Rational::operator+(const Rational& rhs) {
    if (_denominator != rhs._denominator) {
        Rational result((_numerator * rhs._denominator) + (rhs._numerator * _denominator), _denominator * rhs._denominator);
        return result;

    } else {
        Rational result(_numerator + rhs._numerator, _denominator);
        return result;

    }
}


/**
 * Rational Operator * Overload
 * Multiplies two rational numbers.
 * @param rhs
 * @returns the product between the two numbers.
 */
const Rational Rational::operator*(const Rational& rhs)const {
    Rational result(_numerator * rhs._numerator, _denominator * rhs._denominator);
    return result;
}

/**
 * Rational Operator / Overload
 * Divides two rational numbers.
 * @param rhs
 * @returns the quotient between the two numbers.
 */
const Rational Rational::operator/(const Rational& rhs)const {
    Rational result(_numerator * rhs._denominator, _denominator * rhs._numerator);
    return result;
}

/**
 * Rational Operator += Overload
 * Adds two numbers and reassigns it to this
 * @param rhs
 * @returns a reference to the updated this value
 */
const Rational &Rational::operator+=(const Rational &rhs) {

    if (_denominator != rhs._denominator) {
        this->_numerator = (_numerator * rhs._denominator) + (rhs._numerator * _denominator);
        this->_denominator =  _denominator * rhs._denominator;

    } else {
        this->_numerator = _numerator + rhs._numerator;
        this->_denominator = _denominator;
    }

    simplify();
    return *this;
}

/**
 * Rational Operator -= Overload
 * Subtracts two numbers and reassigns it to this
 * @param rhs
 * @returns a reference to the updated this value
 */
const Rational &Rational::operator-=(const Rational &rhs) {
    if (_denominator != rhs._denominator) {
        this->_numerator = (_numerator * rhs._denominator) - (rhs._numerator * _denominator);
        this->_denominator =  _denominator * rhs._denominator;

    } else {
        this->_numerator = _numerator - rhs._numerator;
        this->_denominator = _denominator;
    }

    simplify();
    return *this;
}

/**
 * Rational Operator *= Overload
 * Multiplies two numbers and reassigns it to this
 * @param rhs
 * @returns a reference to the updated this value
 */
const Rational &Rational::operator*=(const Rational &rhs) {
    this->_numerator = _numerator * rhs._numerator;
    this->_denominator = _denominator * rhs._denominator;
    simplify();
    return *this;
}

/**
 * Rational Operator /= Overload
 * Divides two numbers and reassigns it to this
 * @param rhs
 * @returns a reference to the updated this value
 */
const Rational &Rational::operator/=(const Rational &rhs) {
    this->_numerator = _numerator * rhs._denominator;
    this->_denominator = _denominator * rhs._numerator;
    simplify();
    return *this;
}

/**
 * Rational Operator = Overload
 * Assigns rhs numerator and denominator to this numerator and denominator
 * * @param rhs
 * @returns a reference to the updated this value
 */
const Rational Rational::operator=(const Rational &rhs) {
    _numerator = rhs._numerator;
    _denominator = rhs._denominator;
    return *this;
}

/**
 * Rational Operator == Overload
 * Checks to see if the numerator and denominators
 * are equal to rhs numerator and denominator.
 * @param rhs
 * @returns true or false depending on the explanation above.
 */
bool Rational::operator==(const Rational &rhs)const {
    return ((_numerator == rhs._numerator) && (_denominator == rhs._denominator));
}

/**
 * Rational Operator == Overload
 * Checks to see if either the numerator and denominators
 * are equal to either rhs numerator and denominator.
 * @param rhs
 * @returns true or false depending on the explanation above.
 */
bool Rational::operator!=(const Rational &rhs)const {

    return ((_numerator != rhs._numerator) || (_denominator != rhs._denominator));
}

/**
 * Rational Operator > Overload
 * Compares the values of both rationals.
 * @param rhs
 * @returns true if this is grater than rhs and false otherwise.
 */
bool Rational::operator>(const Rational &rhs)const {

    double num1 = ToDouble();
    double num2 = rhs.ToDouble();

    return (num1 > num2);
}

/**
 * Rational Operator >= Overload
 * Compares the values of both rationals.
 * @param rhs
 * @returns true if this is greater than or equal to rhs and false otherwise.
 */
bool Rational::operator>=(const Rational &rhs)const {

    double num1 = ToDouble();
    double num2 = rhs.ToDouble();

    return (num1 >= num2);
}

/**
 * Rational Operator <= Overload
 * Compares the values of both rationals.
 * @param rhs
 * @returns true if this is less than or equal to rhs and false otherwise.
 */
bool Rational::operator<=(const Rational &rhs)const {
    double num1 = ToDouble();
    double num2 = rhs.ToDouble();

    return (num1 <= num2);
}

/**
 * Rational Operator < Overload
 * Compares the values of both rationals.
 * @param rhs
 * @returns true if this is less rhs and false otherwise.
 */
bool Rational::operator<(const Rational &rhs)const {

    double num1 = ToDouble();
    double num2 = rhs.ToDouble();

    return (num1 < num2);
}

/**
 * Rational Operator << Overload
 * Outputs the numerator and denominator to the ostream.
 * @param lhs
 * @returns os
 */
ostream& operator<<(ostream& os, const Rational& lhs) {
    os << lhs._numerator << '/' << lhs._denominator;
    return os;
}

/**
 * ToString
 * Converts the rational number to a string
 * @param none
 * @return the string representation of the rational number
 */
string Rational::ToString()const {

    stringstream ss;

    if (_numerator == _denominator) {
        ss << 1;

    }else if (_numerator == -1 * _denominator) {
        ss << -1;

    } else if (_denominator == 1) {
        ss << _numerator;

    } else {

        ss << _numerator << "/" << _denominator;
    }

    return ss.str();
}

/**
 * To Double
 * Makes the rational number into a double/decimal number
 * @return the decimal number
 */
double Rational::ToDouble()const {
    double result;
    result = (_numerator * 1.0) / (_denominator * 1.0);
    return result;
}


