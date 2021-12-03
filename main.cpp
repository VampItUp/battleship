#include "logic.h"
#include <iostream>

int main() 
{
    int s = 3;
    bool **board = create_board(6, 6);
    destroy_board(board, 6);
    place_ships(board, s, 6, 6);
    guess(board, 6, 6);
}
