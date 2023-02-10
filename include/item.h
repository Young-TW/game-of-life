#ifndef ITEM_H
#define ITEM_H

#include "board.h"

namespace item{
    Board glider(Board, int, int);
    Board gosper(Board, int, int);
}

Board item::glider(Board board, int x, int y){
    board.set(x, y, true);
    board.set(x+2, y, true);
    board.set(x+1, y+1, true);
    board.set(x+2, y+1, true);
    board.set(x+1, y+2, true);
    return board;
}

Board item::gosper(Board board, int x, int y){
    board.set(x+24, y, true);
    board.set(x+22, y+1, true);
    board.set(x+24, y+1, true);
    board.set(x+12, y+2, true);
    board.set(x+13, y+2, true);
    board.set(x+20, y+2, true);
    board.set(x+21, y+2, true);
    board.set(x+34, y+2, true);
    board.set(x+35, y+2, true);
    board.set(x+11, y+3, true);
    board.set(x+15, y+3, true);
    board.set(x+20, y+3, true);
    board.set(x+21, y+3, true);
    board.set(x+34, y+3, true);
    board.set(x+35, y+3, true);
    board.set(x, y+4, true);
    board.set(x+1, y+4, true);
    board.set(x+10, y+4, true);
    board.set(x+16, y+4, true);
    board.set(x+20, y+4, true);
    board.set(x+21, y+4, true);
    board.set(x, y+5, true);
    board.set(x+1, y+5, true);
    board.set(x+10, y+5, true);
    board.set(x+14, y+5, true);
    board.set(x+16, y+5, true);
    board.set(x+17, y+5, true);
    board.set(x+22, y+5, true);
    board.set(x+24, y+5, true);
    board.set(x+10, y+6, true);
    board.set(x+16, y+6, true);
    board.set(x+24, y+6, true);
    board.set(x+11, y+7, true);
    board.set(x+15, y+7, true);
    board.set(x+12, y+8, true);
    board.set(x+13, y+8, true);
    return board;
}

#endif