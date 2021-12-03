#include "logic.h"
#include <iostream>
#include <cstdlib>
#include <string>
bool **create_board(const int height, const int width) 
{
  bool **board = (bool **)malloc(sizeof(bool *) * height);
  for (int i = 0; i < height; i++) {
    board[i] = (bool *)malloc(sizeof(bool) * width);
    
  }
  return board;
}

void destroy_board(bool **board, const int height) 
{
  for (int i = 0; i < height; i++)  
  {
    free(board[i]);
  }
  free(board);
}

void place_ships(bool **board, const int shipcount, const int width, const int height) 
  {
    //0 for blank 1 for ship
  int s = 0;
  while(s < shipcount)
  {
    int x = rand() % width;
    int y = rand() % height;
    if(board[x][y] != 1)
    {
      s++;
      board[x][y] = 1;
    }
  }

}

void find_ships(bool **board, const int width, const int height) 
{
  for (int i = 0; i < height; i++)
  {
    guess(board, width, i);
  }
}

ResponseType guess(bool **board, const int x, const int y) {
  find_ships(board, x, y);
  if (board[x][y] == 1)
  {
    std:: cout << ResponseType::HIT << std:: endl;
  }
  else if(board[x][y] == 0)
  {
    std:: cout << ResponseType::MISS << std:: endl;

  }
  else
  {
        std:: cout << ResponseType::NEAR_MISS << std:: endl;
  }
  
}


