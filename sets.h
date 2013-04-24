#ifndef SETS_H
#define SETS_H

#include <iostream>
using namespace std;

class Set {

    int n;
    int *elements_set;

public:

    Set();
    Set(const Set &equally); //конструктор копирования
    ~Set();

    friend ostream& operator<<(ostream &out ,const Set &a);
    friend istream& operator>>(istream &in,Set &a);

    Set operator+(const Set &unio) const;
    Set operator=(const Set &equally);
    Set operator*(const Set &intersect) const;
    Set operator-(const Set &differ) const;

};

#endif SETS_H;
