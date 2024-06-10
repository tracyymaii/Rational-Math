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



Rational::Rational(double number): _numerator(0), _denominator(1) {
}

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

const Rational Rational::operator-()const {
    return Rational(-1 * _numerator, _denominator);
}

const Rational Rational::operator-(const Rational& rhs) {

    if (_denominator != rhs._denominator) {
        Rational result((_numerator * rhs._denominator) - (rhs._numerator * _denominator), _denominator * rhs._denominator);
        return result;

    } else {
        Rational result(_numerator - rhs._numerator, _denominator);
        return result;

    }

}

const Rational Rational::operator+(const Rational& rhs) {
    if (_denominator != rhs._denominator) {
        Rational result((_numerator * rhs._denominator) + (rhs._numerator * _denominator), _denominator * rhs._denominator);
        return result;

    } else {
        Rational result(_numerator + rhs._numerator, _denominator);
        return result;

    }
}

//void Rational::commonDenom(Rational& rhs) {
//    int denom1 = _denominator;
//    int denom2 = rhs._denominator;
//
//    _numerator *= denom2;
//    _denominator *= denom2;
//
//    rhs._numerator *= denom1;
//    rhs._denominator *= denom1;
//}


const Rational Rational::operator*(const Rational& rhs)const {
    Rational result(_numerator * rhs._numerator, _denominator * rhs._denominator);
    return result;
}

const Rational Rational::operator/(const Rational& rhs)const {
    Rational result(_numerator * rhs._denominator, _denominator * rhs._numerator);
    return result;
}

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

const Rational &Rational::operator*=(const Rational &rhs) {
    this->_numerator = _numerator * rhs._numerator;
    this->_denominator = _denominator * rhs._denominator;
    simplify();
    return *this;
}

const Rational &Rational::operator/=(const Rational &rhs) {
    this->_numerator = _numerator * rhs._denominator;
    this->_denominator = _denominator * rhs._numerator;
    simplify();
    return *this;
}

const Rational Rational::operator=(const Rational &rhs) {
    _numerator = rhs._numerator;
    _denominator = rhs._denominator;
    return *this;
}

bool Rational::operator==(const Rational &rhs)const {
    return ((_numerator == rhs._numerator) && (_denominator == rhs._denominator));

}

bool Rational::operator!=(const Rational &rhs)const {

    return ((_numerator != rhs._numerator) || (_denominator != rhs._denominator));
}

bool Rational::operator>(const Rational &rhs)const {

    double num1 = ToDouble();
    double num2 = rhs.ToDouble();

    return (num1 > num2);

}

bool Rational::operator>=(const Rational &rhs)const {

    double num1 = ToDouble();
    double num2 = rhs.ToDouble();

    return (num1 >= num2);
}

bool Rational::operator<=(const Rational &rhs)const {
    double num1 = ToDouble();
    double num2 = rhs.ToDouble();

    return (num1 <= num2);
}

bool Rational::operator<(const Rational &rhs)const {

    double num1 = ToDouble();
    double num2 = rhs.ToDouble();

    return (num1 < num2);
}


ostream& operator<<(ostream& os, const Rational& lhs) {
    os << lhs._numerator << '/' << lhs._denominator;
    return os;
}


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

double Rational::ToDouble()const {
    double result;
    result = (_numerator * 1.0) / (_denominator * 1.0);
    return result;

//    stringstream ss;
//    ss << result;
//
//    string num = ss.str();
//
//   stringstream rounded;
//
//   bool decimalSeen = false;
//
//   int afterDec = 0;
//
//   for (int i = 0; i < num.length(); i++) {
//       if (num[i] != '.') {
//           rounded << num[i];
//       } else {
//           decimalSeen = true;
//           continue;
//       }
//
//       if (decimalSeen && afterDec < 2) {
//           rounded << num[i];
//           afterDec++;
//       }
//   }
//     return stod(rounded.str());

}


