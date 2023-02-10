#include <thread>
#include <chrono>

#include "board.h"
#include "item.h"
#include "clear.h"

int main(){
    Board board;

    board = item::gosper(board, 2,4);

    while(1){
        board.print();
        board.next();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        clear();
    }

    return 0;
}