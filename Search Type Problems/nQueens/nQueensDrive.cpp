#include <stdio.h>
#include <stdlib.h>
#include "nQueens.h"
#include <time.h>

#define LIMIT 20

int totalNQueens(int size);

int main(){
    time_t start, end;

    for(int i = 1; i < LIMIT; ++i){
        time(&start);
        int num = totalNQueens(i);
        time(&end);
        printf("There are %d configurations of the board of size %d, Which took %f seconds\n", num, i, difftime(end, start) );
    }
}


int totalNQueens(int size){
    nQueens myQueens {size};
    myQueens.solve(0);
    return myQueens.numberOfpossibleMoves();
}
