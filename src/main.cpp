#include <iostream>
#include <thread>
#include <chrono>

#include "board.h"
#include "item.h"

void clear(){
    #ifdef __GNUC__
    system("clear");
    #elif defined _MSC_VER
    system("cls");
    #endif
    return;
}

int main(){
    Board board;

    board = item::gosper(board, 2,4);

    while(1){
        board.print();
        board.next();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        clear();
    }

    return 0;
}