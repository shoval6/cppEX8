#include <iostream>
#include <stdbool.h>
#include "Pair.h"
#include "IllegalCharException.h"


Pair::Pair() {
    chr = '.';
}


Pair::Pair(uint x, uint y) : x(x), y(y) {}


Pair &Pair::operator=(char chr) {
    if (chr != 'X' && chr != 'O' && chr != '.')
        throw IllegalCharException(chr);
    this->chr = chr;

    return *this;
}

bool Pair::operator==(char other) const {
    if (chr == other)
        return true;
    return false;

}

Pair::operator char() const {
    return this->chr;
}

uint Pair::getX() const {
    return x;
}

uint Pair::getY() const {
    return y;

}

char Pair::getChar() const {
    return chr;
}

void Pair::setChar(const char chr) {
    this->chr = chr;
}
