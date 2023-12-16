#include "Rational.h"
#include <iostream>
using namespace std;
Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num, int den) {
    if (den == 0) {
        cerr << "Error: Denominator cannot be zero. Setting to default value (0/1)." << endl;
        numerator = 0;
        denominator = 1;
    }
    else {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int gcd_value = gcd(num, den);
        numerator = num / gcd_value;
        denominator = den / gcd_value;
    }
}

Rational::Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {}

int Rational::getNumerator() const {
    return numerator;
}

int Rational::getDenominator() const {
    return denominator;
}

void Rational::setNumerator(int num) {
    numerator = num;
}

void Rational::setDenominator(int den) {
    if (den == 0) {
        cerr << "Error: Denominator cannot be zero. Value not changed." << endl;
    }
    else {
        if (den < 0) {
            numerator = -numerator;
            den = -den;
        }
        int gcd_value = gcd(numerator, den);
        numerator /= gcd_value;
        denominator = den / gcd_value;
    }
}

Rational Rational::operator+(const Rational& other) const {
    int new_num = (numerator * other.denominator) + (other.numerator * denominator);
    int new_den = denominator * other.denominator;
    return Rational(new_num, new_den);
}

Rational Rational::operator-(const Rational& other) const {
    int new_num = (numerator * other.denominator) - (other.numerator * denominator);
    int new_den = denominator * other.denominator;
    return Rational(new_num, new_den);
}

Rational Rational::operator*(const Rational& other) const {
    int new_num = numerator * other.numerator;
    int new_den = denominator * other.denominator;
    return Rational(new_num, new_den);
}

Rational Rational::operator/(const Rational& other) const {
    int new_num = numerator * other.denominator;
    int new_den = denominator * other.numerator;
    return Rational(new_num, new_den);
}

bool Rational::operator==(const Rational& other) const {
    return (numerator == other.numerator) && (denominator == other.denominator);
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator>(const Rational& other) const {
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Rational::operator<(const Rational& other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Rational::operator>=(const Rational& other) const {
    return !(*this < other);
}

bool Rational::operator<=(const Rational& other) const {
    return !(*this > other);
}

Rational& Rational::operator++() {
    numerator += denominator;
    return *this;
}

Rational& Rational::operator--() {
    numerator -= denominator;
    return *this;
}

Rational Rational::operator-() const {
    return Rational(-numerator, denominator);
}

Rational Rational::operator+() const {
    return *this;
}

bool Rational::operator!() const {
    return (numerator == 0);
}

Rational& Rational::operator=(const Rational& other) {
    if (this == &other) {
        return *this;
    }
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    *this = *this / other;
    return *this;
}

int Rational::gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void Rational::simplify() {
    int gcd_value = gcd(numerator, denominator);
    numerator /= gcd_value;
    denominator /= gcd_value;
}

ostream& operator<<(ostream& os, const Rational& r) {
    os << r.numerator;
    if (r.denominator != 1) {
        os << '/' << r.denominator;
    }
    return os;
}

istream& operator>>(istream& is, Rational& r) {
    int num, den;
    is >> num >> den;
    r = Rational(num, den);
    return is;
}
