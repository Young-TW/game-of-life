#include <iostream>
#include <windows.h>

#include "Board.h"


int main(){
    Board board;

    board.set(3, 3, true);
    board.set(5, 3, true);
    board.set(4, 4, true);
    board.set(5, 4, true);
    board.set(4, 5, true);

    while(1){
        board.print();
        board.next();
        Sleep(300);
    }

    std::cout << "M M M M";

    return 0;
}