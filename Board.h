#pragma once

#include "Pair.h"

using namespace std;


class Board {

    Pair** array2D;
    uint tsize;

public:

    Board();

    Board(uint size);

    Board(const Board &other);

    ~Board();

    Pair &operator[](const Pair &pt);

    char operator[](const Pair &pt) const;

    Board &operator=(char chr);

    Board &operator=(const Board &other);

    void initial();

    void create(uint size);

    void free();

    friend ostream &operator<<(ostream &os, const Board &br);

    uint size() const { return tsize; };

    friend istream &operator>>(istream &in, Board &br);

    string draw(int dim);
};

