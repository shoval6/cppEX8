#include <iostream>
#include <fstream>
#include <vector>
#include "Board.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
#include "Image.h"

using namespace std;


Board::Board() {
create(10);
}

Board::Board(uint size) {
    create(size);
}

Board::Board(const Board &other) {
    if(tsize!=0){
        this->free();
    }
    create(other.size());
    for (int i = 0; i < other.size(); i++)
        for (int j = 0; j < other.size(); j++)
            array2D[i][j] = other.array2D[i][j];
}

Board::~Board() {
    free();
}

void Board::create(uint size) {
    this->tsize = size;
    array2D = new Pair *[tsize];
    for (int i = 0; i < tsize; ++i)
        array2D[i] = new Pair[tsize];
}


Pair &Board::operator[](const Pair &pt) {
    if (pt.getX() < 0 || pt.getX() >= tsize || pt.getY() < 0 || pt.getY() >= tsize)
        throw IllegalCoordinateException(pt.getX(), pt.getY());
    return array2D[pt.getX()][pt.getY()];

}

char Board::operator[](const Pair &pt) const {
    if (pt.getX() < 0 || pt.getX() >= tsize || pt.getY() < 0 || pt.getY() >= tsize)
        throw IllegalCoordinateException(pt.getX(), pt.getY());
    return array2D[pt.getX()][pt.getY()].getChar();

}

Board &Board::operator=(char chr) {
//    if (chr != '.')
//        throw IllegalCharException(chr);
    initial();
    return *this;

}

Board &Board::operator=(const Board &other) {
    if (this != &other) {
        if (tsize != other.size()) {
            free();
            create(other.size());
        }
        for (int i = 0; i < other.size(); i++)
            for (int j = 0; j < other.size(); j++)
                array2D[i][j] = other.array2D[i][j];


    }
    return *this;
}

void Board::free() {
    for (int i = 0; i < tsize; i++)
        delete[] array2D[i]; // delete array within matrix
    delete[] array2D;  // delete actual matrix

}

void Board::initial() {
    for (int i = 0; i < tsize; i++)
        for (int j = 0; j < tsize; j++)
            array2D[i][j].setChar('.');
}


ostream &operator<<(ostream &os, const Board &br) {
    for (int i = 0; i < br.size(); i++) {
        for (int j = 0; j < br.size(); j++) {
            os << br.array2D[i][j].getChar();
        }
        os << "" << endl;
    }
    return os;
}


istream &operator>>(istream &in, Board &br) {

    uint i=0,j=0;
    char token;
    vector <char> vec;

    bool flag = true;
    uint sizeOfBoard;
    int counter =0;
    while (cin.get(token)) {
        if(flag&&token=='\n'){
            flag =false;
            sizeOfBoard=counter;
        }
        counter ++;
        vec.push_back(token);
    }
    Board temp{sizeOfBoard};
    int index = 0;
    for(int i=0; i<sizeOfBoard; i++){
        for(int j=0; j<sizeOfBoard; j++){
            if(vec.at(index)!='\n'){
                temp.array2D[i][j] = vec.at(index);
            }
            else{
                temp.array2D[i][j] = vec.at(++index);
            }
            index++;
        }
    }
    br = temp;
    return in;
}


string Board::draw(int dim) {
    Image image(dim);
    uint borad_size = tsize;
    return image.createPPM(array2D,borad_size);

}