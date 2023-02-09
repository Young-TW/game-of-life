#include <iostream>
#include <windows.h>

#include "board.h"
#include "item.h"

int main(){
    Board board;

    board = item::gosper(board, 2,4);

    while(1){
        board.print();
        board.next();
        Sleep(10);
        system("CLS");
    }

    return 0;
}