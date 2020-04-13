#include <stdio.h>
#include <stdlib.h>

#define definedConstant 4
const int globalConstant = 4;
int globalVar = 4;

void testArray1(int var[4]);
void testArray2(int var[]);
void testArray3(int* var);

int main() {
  int num = 5;

  //errore: in C non si può stampare una stringa dal valore variabile calcolato a compile-time
  // printf("main: stampo numero: "+num+"\n");

  //funge
  printf("main: stampo variabile num: %d\n", num);

  //funge
  printf("main: stampo indirizzo della variabile num: %d\n", &num);

  //errore: "int" e "int*" sono tipi diversi, non posso salvare un puntatore in una variabile int
  // int numPtr = &num;

  //funge
  int* numPtr = &num;

  //funge, sintassi equivalente alla precedente
  // int *numPtr = &num;

  //funge
  printf("main: stampo variabile (di tipo pointer) in cui ho salvato l'indirizzo della variabile num: %d\n", numPtr);

  //funge
  printf("main: stampo il valore presente nell'indirizzo a cui punta il puntatore numPtr: %d\n", *numPtr);

  //errore: non posso modificare un item segnato come #define
  // definedConstant++;

  //errore: non posso modificare una costante
  // globalConstant++;

  //funge
  globalVar++;

  //funge (non serve specificare size se inizializzo subito)
  // int nums[] = {1,2,3,4};

  //errore: va detto che è un array davanti al nome della variabile
  // int[] nums = {1,2,3,4};

  //funge, ma è superfluo specificare grandezza
  // int nums[4] = {1,2,3,4};

  //errore: SE specifico la dimensione, crea l'array con quella dimensione (qui 3), e c'è errore se assegno più elementi
  // int nums[3] = {1,2,3,4};

  //funge, ci sarà nums[4] a cui è stato assegnato "0" come valore di default
  // int nums[5] = {1,2,3,4};

  //funge
  // printf("main: stampo un valore non assegnato in modo esplicito dell'array nums (ottengo il default 0): %d", nums[4]);

  //funge, ora è nums[4]=1
  // nums[4]++;

  //errore: se non dichiaro subito l'array, devo dire quanto è grande
  // int nums[];

  //funge
  // int nums[4];

  //funge
  // int nums[globalConstant];

  //funge
  // int nums[globalVar];

  //funge
  int nums[definedConstant];

  //errore: si può assegnare l'array per intero solo all'istante stesso in cui si dichiara la variabile dell'array
  // nums = {1,2,3,4};

  //funge
  nums[0] = 1; nums[1] = 2; nums[2] = 3; nums[3] = 4;

  //funge
  testArray1(nums);

  //funge
  testArray2(nums);

  //funge
  testArray3(nums);
  return 0;
}

void testArray1(int var[4]) {
  printf("funzione testArray1: input, array con size specificato: stampo primo elem array: %d\n", var[0]);
  printf("funzione testArray1: input, array con size specificato; stampo indirizzo primo elem array: %d\n", &var[0]);
  printf("funzione testArray1: input, array con size specificato; stampo array (ottengo indirizzo primo elem array): %d\n", var);
}

void testArray2(int var[]) {
  printf("funzione testArray2: input, array senza size specificato: stampo primo elem array: %d\n", var[0]);
  printf("funzione testArray2: input, array senza size specificato; stampo indirizzo primo elem array: %d\n", &var[0]);
  printf("funzione testArray2: input, array senza size specificato; stampo array (ottengo indirizzo primo elem array): %d\n", var);
}

void testArray3(int* var) {
  printf("funzione testArray3: input, un puntatore (ma gli do un array); stampo l'input: %d\n", var);
}
