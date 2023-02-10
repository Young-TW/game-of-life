#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

#include "point.h"

class Board{
    public:
        Board();
        Board(int);
        bool get(int, int);
        void set(int, int, bool);
        void fill(bool);
        void print();
        void resize(int);
        bool calculate(int, int);
        void next();
        std::vector<std::vector<Point>> get_all();

    private:
        int size;
        std::vector<std::vector<Point>> board;
};

Board::Board()
    : board(50, std::vector(50, Point()))
{
    resize(50);
    fill(false);
}

Board::Board(int size)
    : board(size, std::vector(size, Point()))
{
    fill(false);
}

bool Board::get(int x, int y){
    return board.at(x).at(y).get();
}

void Board::set(int x, int y, bool status){
    board.at(x).at(y).set(status);
    return;
}

void Board::fill(bool status){
    for(int y=0;y<size;y++){
        for(int x=0;x<size;x++){
            board.at(x).at(y).set(status);
        }
    }
}

void Board::print(){
    bool status;
    for(int y=0;y<size;y++){
        for(int x=0;x<size;x++){
            status = get(x, y);
            if(status){
                std::cout << "M";
            }else{
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
    return;
}

void Board::resize(int size){
    this->size = size;
    std::vector<Point> temp(size);
    board.resize(size, temp);
    return;
}

bool Board::calculate(int x, int y){
    if(x-1 < 0 || y-1 < 0 || x+1 > size-1 || y+1 > size-1){
        return 0;
    }

    int count = 0;

    count += get(x-1, y-1);
    count += get(x-1, y);
    count += get(x-1, y+1);
    count += get(x, y-1);
    count += get(x, y+1);
    count += get(x+1, y-1);
    count += get(x+1, y);
    count += get(x+1, y+1);

    if(get(x, y) == true){
        if(count == 2 || count == 3){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(count == 3){
            return 1;
        }else{
            return 0;
        }
    }

    return 0;
}

void Board::next(){
    Board next_board;

    for(int y=0;y<size;y++){
        for(int x=0;x<size;x++){
            next_board.set(x, y, calculate(x, y));
        }
    }

    *this = next_board;
    return;
}

std::vector<std::vector<Point>> Board::get_all(){
    return this->board;
}

#endif