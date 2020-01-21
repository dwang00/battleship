#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main() {
  srand(time(0));
  //newBoard();
  printf("Welcome to Battleship!\nWould you like to read the instructions? \n1 for yes, 2 for no\n");
  char an[1];
  scanf("%s", an);
  int ans = atoi(an);
  if (ans == 1) {
    FILE *ins = fopen("ins.txt", "r");
    char buff[2500];
    for (int p = 0; p <= 19; p++) {
      fgets(buff, 2500, (FILE*)ins);
      printf("%s", buff);
    }
  }
  int turn = 0;
  int a[3];
  int b[3];
  int c[3];
  int d[3];
  int e[3];
  int q[2];
  int yourBoard[100] = {0};
  int enemyBoard[100] = {0};
  gencompboard(enemyBoard);
  int *ac = place(5, a, yourBoard);
  thething(ac, yourBoard, 5);
  int *bs = place(4, b, yourBoard);
  thething(bs, yourBoard, 4);
  int *ds = place(3, c, yourBoard);
  thething(ds, yourBoard, 3);
  int *sm = place(3, d, yourBoard);
  thething(sm, yourBoard, 3);
  int *pb = place(2, e, yourBoard);
  thething(pb, yourBoard, 2);
  showYourBoard(yourBoard);
  int yourhits = 0;
  int hitsonyou = 0;
  int stuff = 0;
  int yourguesses[100];
  for (stuff; stuff < 100; stuff++) {
    yourguesses[stuff] = -1;
  }
  stuff = 0;
  int compguesses[100];
  for (stuff; stuff < 100; stuff++) {
    compguesses[stuff] = -1;
  }
  int t;
  while (yourhits != 17 || hitsonyou != 17) {
    guess(q, yourguesses);
    yourguesses[turn] = q[0]*10 + q[1];
    if (testHit(q[0], q[1], enemyBoard) == 1) {
      enemyBoard[q[0]*10+q[1]] = 2;
      yourhits++;
    }
    else {
      enemyBoard[q[0]*10+q[1]] = 3;
    }
    t = compguess(compguesses);
    printf("computer shot at %d, %d\n", t / 10, t % 10);
    if (yourBoard[t] == 1) {
      printf("hit\n");
      yourBoard[t] = 2;
      hitsonyou++;
    }
    else {
      yourBoard[t] = 3;
      printf("miss\n");
    }
    printf("your hits: %d\nhits left: %d\n", yourhits, 17 - yourhits);
    showYourBoard(yourBoard);
    showEnemyBoard(enemyBoard);
  }
  if (yourhits == 17) {
    printf("you win");
  }
  else if (hitsonyou == 17) {
    printf("enemy wins");
  }
  return 0;
}
