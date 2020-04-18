#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define rows 6
#define cols 7
int field[rows][cols];

void printBoard();
void getMove(int coin);
void setMove(int col, int coin);
bool isColFull(int col);
bool isEmptyCell(int row, int col);
int changePlayer(int coin);
int checkVictory();

int main() {
  int coin = 1;
  int winner;
  bool keepPlaying = true;
  while(keepPlaying){
    printBoard();
    getMove(coin);
    coin = changePlayer(coin);
    winner = checkVictory();
    printf("\ndebug vincitore %d\n", winner);
    if(winner != 0){
      printf("\nVince il Giocatore %d\n", winner);
      keepPlaying = false;
    }
  }
  return 0;
}

//Prints the rows in reverse order (the first row in the array will be displayed for last, as bottom row)
void printBoard() {
  for (int row = rows-1; row >= 0; row--) {
    for (int elem = 0; elem < cols; elem++) {
        printf(" %d ", field[row][elem]);
    }
    printf("\n");
  }
}

void getMove(int coin){
  int col;
  bool isValidMove;

  //read user move
  do{
    printf("\n\nTocca a giocatore %d\n", coin);
    printf("Inserisci una colonna valida da 1 a %d: ", cols);
    scanf("%d", &col);
    //converts col inserted by the user to its position in the array(cols go from 0 to n-1)
    col--;
    isValidMove = col >= 0 && col < cols && !isColFull(col);
  }while(!isValidMove);

  setMove(col, coin);
}

//insert coin in lowest empty cell of col
void setMove(int col, int coin) {
  for (int row = 0; row < rows; row++) {
    if (isEmptyCell(row, col)) {
      field[row][col] = coin;
      break;
    }
  }
}

bool isColFull(int col) {
  bool isFull = true;
  for (int row = 0; row < rows; row++) {
    if (isEmptyCell(row, col)) {
      isFull = false;
    }
  }

  return isFull;
}

bool isEmptyCell(int row, int col) {
  if (field[row][col] == 0) {
    return true;
  } else {
    return false;
  }
}

int changePlayer(int coin) {
  if (coin == 1) {
    return 2;
  } else {
    return 1;
  }
}

// returns 0 if no player has won; else returns the winning player
int checkVictory(){
  int winner = 0;
  const int victoryCondition = 4;
  //checking victory conditions horizontally
  for(int row = 0; row < rows || winner != 0; row++){
    for(int cell = 0; cell <= cols - victoryCondition || winner != 0; cell++){
      // if the player has put 4 in a row (if he has won)
      printf("debug row %d, cell %d , valore %d, adiacente %d\n", row, cell, field[row][cell], field[row][cell+1]);
      if(field[row][cell] == field[row][cell + 1] &&
        field[row][cell] == field[row][cell + 2] &&
        field[row][cell] == field[row][cell + 3]){
          winner = field[row][cell];
      }
    }
    printf("\n");
  }
  return winner;
}
