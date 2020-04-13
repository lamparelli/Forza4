#include <stdio.h>
#include <stdlib.h>

#define rows 6
#define cols 7
int field[rows][cols];

void printBoard();

int main() {

  printBoard();
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
