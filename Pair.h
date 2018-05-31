#pragma once

#include<iostream>

using namespace std;


class Pair {
    uint x;
    uint y;
    char chr;

public:

    Pair();

    Pair(uint x, uint y);

    Pair &operator=(char chr);

    bool operator==(char other) const;

    operator char() const;

    uint getX() const;

    uint getY() const;

    char getChar() const;

    void setChar(const char chr);

};

