#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include<iostream>
using namespace std;
class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational();
    Rational(int num, int den);
    Rational(const Rational& other);

    // Getters and setters
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int num);
    void setDenominator(int den);

    // Operator overloads
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator<=(const Rational& other) const;

    Rational& operator++(); // Prefix increment
    Rational& operator--(); // Prefix decrement
    Rational operator-() const; // Unary minus
    Rational operator+() const; // Unary plus
    bool operator!() const; // Logical NOT

    Rational& operator=(const Rational& other); // Assignment operator
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    friend ostream& operator<<(ostream& os, const Rational& r);
    friend istream& operator>>(istream& is, Rational& r);

    // Simplify the rational number
    void simplify();

    // Static function to find the greatest common divisor (GCD)
    static int gcd(int a, int b);
};

#endif


