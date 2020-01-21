#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#include <time.h>

int newBoard() {
  for (int i = 1; i <= 110; i++) {
    if (i <= 10) {
      if (i == 1) {
        printf("  ");
      }
      printf("%d ", i - 1);
      if (i == 10) {
        printf("\n0 ");
      }
    }
    else {
      printf("- ");
      if (i % 10 == 0 && i != 110) {
        printf("\n%d ", (i - 10) / 10);
      }
    }
  }
  printf("\n\n");
  return 0;
}

int getRow(int ship, int row) {
  char r[1];
  printf("What row would you like to place your %d unit ship?\n", ship);
  scanf("%s", r);
  row = atoi(r);
  if (row > 9 || row < 0) {
    getRow(ship, row);
  }
  else {
    return(row);
  }
}

int getColumn(int ship, int column) {
  char c[1];
  printf("What column would you like to place your %d unit ship?\n", ship);
  scanf("%s", c);
  column = atoi(c);
  if (column > 9 || column < 0) {
    getColumn(ship, column);
  }
  else {
    return(column);
  }
}

int getOrientation(int ship, int orientation) {
  char o[1];
  printf("What orientation would you like your ship to be? 1 for horizontal, 2 for vertical\n");
  scanf("%s", o);
  orientation = atoi(o);
  if (orientation == 1 || orientation == 2) {
    return(orientation);
  }
  else {
    getOrientation(ship, orientation);
  }
}

int * place(int ship, int * data, int * yb) {
  data[0] = getRow(ship, 0);
  data[1] = getColumn(ship, 0);
  data[2] = getOrientation(ship, 3);
  if (data[2] == 1 && data[1] > 10 - ship) {
    printf("invalid placement\n");
    place(ship, data, yb);
  }
  if (data[2] == 2 && data[0] > 10 - ship) {
    printf("invalid placement\n");
    place(ship, data, yb);
  }
  for(int x = 0; x < 100; x++) {
    if (yb[x] == 1) {
      if (data[2] == 1) {
        if (x == data[0]*10 + data[1] + ship) {
          printf("invalid placement\n");
          place(ship, data, yb);
        }
      }
      if (data[2] == 2) {
        if (x == data[0]*10 + data[1] + ship*10) {
          printf("invalid placement\n");
          place(ship, data, yb);
        }
      }
    }
  }
  return(data);
}

int testHit(int row, int column, int * board) {
  int i = row * 10 + column;
  if (board[i] == 1) {
    printf("hit\n");
    return(1);
  }
  else {
    printf("miss\n");
    return(0);
  }
}

int * guess(int * coord, int * yourguesses) {
  char x[1];
  char y[1];
  printf("enter row\n");
  scanf("%s", x);
  coord[0] = atoi(x);
  printf("enter column\n");
  scanf("%s", y);
  coord[1] = atoi(y);
  for(int z = 0; z < 100; z ++) {
    if (coord[0]*10 + coord[1] == yourguesses[z]) {
      printf("%d, %d already guessed\n", coord[0]*10 + coord[1], yourguesses[z]);
      guess(coord, yourguesses);
    }
  }
}


int showYourBoard(int * yb) {
  printf("Your Board\n  0 1 2 3 4 5 6 7 8 9");
  for (int i = 0; i < 100; i++) {
    if (i % 10 == 0 && i != 100) {
      printf("\n%d ", i / 10);
    }
    if (yb[i] == 1) {
      printf("* ");
    }
    else if (yb[i] == 2) {
      printf("x ");
    }
    else if (yb[i] == 3) {
      printf("o ");
    }
    else{
      printf("- ");
    }
  }
  printf("\n\n");
  return 0;
}

int showEnemyBoard(int * yb) {
  printf("Enemy Board\n  0 1 2 3 4 5 6 7 8 9");
  for (int i = 0; i < 100; i++) {
    if (i % 10 == 0 && i != 100) {
      printf("\n%d ", i / 10);
    }
    if (yb[i] == 1) {
      printf("- ");
    }
    else if (yb[i] == 2) {
      printf("x ");
    }
    else if (yb[i] == 3) {
      printf("o ");
    }
    else{
      printf("- ");
    }
  }
  printf("\n\n");
  return 0;
}

int thething(int * ship, int * yb, int l) {
  int u = 0;
  while (u < l) {
    if (ship[2] == 1) {
      yb[ship[0]*10 + ship[1] + u] = 1;
    }
    else if (ship[2] == 2) {
      yb[ship[0]*10 + ship[1]+u*10]= 1;
    }
    u++;
  }
}

int compguess(int * yb) {
  int q = rand() % 100;
  for(int z = 0; z < 100; z ++) {
    if (2 == yb[z] || 3 == yb[z]) {
      compguess(yb);
    }
  }
  return(q);
}

int gencompboard(int * bb) {
  bb[0] = 1;
  bb[1] = 1;
  bb[2] = 1;
  bb[3] = 1;
  bb[4] = 1;
  bb[9] = 1;
  bb[19] = 1;
  bb[29] = 1;
  bb[39] = 1;
  bb[25] = 1;
  bb[35] = 1;
  bb[45] = 1;
  bb[60] = 1;
  bb[70] = 1;
  bb[80] = 1;
  bb[98] = 1;
  bb[99] = 1;
}
