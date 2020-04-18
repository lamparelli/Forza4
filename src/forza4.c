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

int main() {
  int coin = 1;
  bool keepPlaying = true;
  while(keepPlaying){
    printBoard();
    getMove(coin);
    coin = changePlayer(coin);
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
  //read col
  do{
    printf("\n\nTocca a giocatore %d\n", coin);
    printf("Inserisci una colonna valida da 1 a %d: ", cols);
    scanf("%d", &col);
    col--;
  }while(col < 0 || col >= cols || isColFull(col));

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
