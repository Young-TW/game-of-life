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

    private:
        int size;
        std::vector<std::vector<Point>> board;
};

Board::Board(){
    resize(30);
    fill(false);
}

Board::Board(int size){
    resize(size);
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
    // 每個細胞有兩種狀態 - 存活或死亡，每個細胞與以自身為中心的周圍八格細胞產生互動（如圖，黑色為存活，白色為死亡）

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
        // 當前細胞為存活狀態時，當周圍的存活細胞低於2個時（不包含2個），該細胞變成死亡狀態。（模擬生命數量稀少）
        // 當前細胞為存活狀態時，當周圍有2個或3個存活細胞時，該細胞保持原樣。
        // 當前細胞為存活狀態時，當周圍有超過3個存活細胞時，該細胞變成死亡狀態。（模擬生命數量過多）
        if(count == 2 || count == 3){
            return 1;
        }else{
            return 0;
        }
    }else{
        // 當前細胞為死亡狀態時，當周圍有3個存活細胞時，該細胞變成存活狀態。（模擬繁殖）
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

