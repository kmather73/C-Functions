#include "nQueens.h"

    nQueens::nQueens(int n){
        attackLeftDiag = new bool[2*n - 1];
        attackRightDiag = new bool[2*n - 1];

        int limit = 2*n - 1;
        for(int i = 0; i < limit; ++i){
            attackRightDiag[i] = false;
            attackLeftDiag[i] = false;
        }

        attackSide = new bool[n];
            
        numberOfQueensPlaced = 0;
        numberOfValidConfigOfQueens = 0;
        sizeOfBoard = n;
    }
    nQueens::~nQueens(){
        delete attackLeftDiag;
        delete attackRightDiag;
        delete attackSide;
    }

    void nQueens::solve(int colNum){
        if(colNum == sizeOfBoard)
            return;
        for(int row = 0; row < sizeOfBoard; ++row)
            if(validMove(row, colNum)){
                placeQueenAt(row, colNum);
                solve(colNum + 1);
                removeQueenAt(row, colNum);
            }
        return ;
    }

    bool nQueens::validMove(int row, int col){
        int left = row + col;
        int right = sizeOfBoard - 1  - row + col;
        return !(attackRightDiag[right] || attackLeftDiag[left] || attackSide[row]);
    }

    void nQueens::placeQueenAt(int row, int col){
        ++numberOfQueensPlaced;
        attackSide[row] = true;
        
        attackLeftDiag[row + col] = true;

        attackRightDiag[sizeOfBoard - 1 - row + col] = true;

        if(numberOfQueensPlaced == sizeOfBoard)
            addConfigToCount();
        return;
    }

    void nQueens::removeQueenAt(int row, int col){
        --numberOfQueensPlaced;

        attackSide[row] = false;

        attackLeftDiag[row + col] = false;

        attackRightDiag[sizeOfBoard - 1 - row + col] = false;
        return;
    }

    void nQueens::addConfigToCount(){
        ++numberOfValidConfigOfQueens;
    }

    
    int nQueens::numberOfpossibleMoves(){
        return numberOfValidConfigOfQueens;
    }
