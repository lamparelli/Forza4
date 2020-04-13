#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define rows 6
#define cols 7
int field[rows][cols];

void printBoard();
void getMove(int coin);
void setMove(int row, int col, int coin);

int main() {
  int coin = 1;
  bool keepPlaying = true;
  while(keepPlaying == true){
    printBoard();
    getMove(coin);
  }
  return 0;
}

void printBoard() {
  for (int row = 0; row < rows; row++) {
    for (int elem = 0; elem < cols; elem++) {
        printf(" %d ", field[row][elem]);
    }
    printf("\n");
  }
}

void getMove(int coin){
  int row, col;
  //read row
  do{
    printf("Inserisci riga da 1 a %d: ", rows);
    scanf("%d", &row);

  }while(row < 1 || row > rows);
  row--;
  //read col
  do{
    printf("Inserisci colonna da 1 a %d: ", cols);
    scanf("%d", &col);

  }while(col < 1 || col > cols);
  col--;
  setMove(row, col, coin);
}

void setMove(int row, int col, int coin){
  field[row][col] = coin;
}
