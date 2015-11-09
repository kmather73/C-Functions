#include "rainFall.h"
#define WIDTH 13
#define RANGE 999999999999999999

Rainfall::Rainfall(int rows, int cols){
	this->rows = rows;
	this->cols = cols;

	
	std::vector<std::vector<int> > board;
	std::vector<std::vector<bool>> flowsRight(rows, std::vector<bool>(cols, false));
	std::vector<std::vector<bool>> flowsLeft(rows, std::vector<bool>(cols,false));

	srand(time(NULL));
	std::vector<int> currRow(cols);

	//Set the board to random values.
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			currRow[j] = rand();
		}
		board.push_back(std::vector<int>(currRow.begin(), currRow.end()));
	}


	int rightEnd = cols - 1;
	for(int i = 0; i < rows; ++i){
		flowsLeft[i][0] = true;
		flowsRight[i][rightEnd] = true;
	}

	this->board = board;
	this->flowsRight = flowsRight;
	this->flowsLeft = flowsLeft;
}



Rainfall::printBoard(){
	std::cout << "The current board looks like this." << std::endl;
	std::cout << " " << std::setfill('-') << std::setw(WIDTH*cols+1) << " " << std::endl;
	
	for(int i = 0; i<rows; ++i){
		std::cout << "|";
		for(int j=0; j<cols; ++j){
			std::cout << std::setfill(' ') << std::setw(WIDTH);
			std::cout << board[i][j];
		}
		std::cout << "|" << std::endl;
	}
	
	std::cout << " " << std::setfill('-') << std::setw(WIDTH*cols+1) << " " << std::endl;
}

Rainfall::printDoubleFlowPoints(){
	std::cout << "The points where water can flow to both sides are marked on the board with *." << std::endl;
	std::cout << " " << std::setfill('-') << std::setw(WIDTH*cols+1) << " " << std::endl;
	
	for(int i = 0; i<rows; ++i){
		std::cout << "|";
		for(int j=0; j<cols; ++j){
			std::cout << std::setfill(' ') << std::setw(WIDTH);

			if(flowsLeft[i][j])
				std::cout << "*";
			else
				std::cout << board[i][j];
		}
		std::cout << "|" << std::endl;
	}
	
	std::cout << " " << std::setfill('-') << std::setw(WIDTH*cols+1) << " " << std::endl;
}

Rainfall::solveFlows(){
	for(int i = 0; i < rows; ++i){
		for(int j = 1; j < cols; ++j){
			if(board[i][j-1] <= board[i][j] && flowsLeft[i][j-1])
				flowsLeft[i][j] = true;
			if(i > 0 && board[i-1][j] <= board[i][j] && flowsLeft[i-1][j])
				flowsLeft[i][j] = true;
			if(i + 1 < rows && board[i][j] >= board[i+1][j] && flowsLeft[i+1][j])
				flowsLeft[i][j] = true;
			if(j + 1 < cols && board[i][j] >= board[i][j+1] && flowsLeft[i][j+1])
				flowsLeft[i][j] = true;
		}
	}

	for(int i = rows - 1; i >=0; --i){
		for(int j = cols - 2; j > 0; --j){
			if(board[i][j] >= board[i][j+1] && flowsLeft[i][j+1])
				flowsLeft[i][j] = true;
			if(i > 0 && board[i-1][j] <= board[i][j] && flowsLeft[i-1][j])
				flowsLeft[i][j] = true;
			if(i + 1 < rows && board[i][j] >= board[i+1][j] && flowsLeft[i+1][j])
				flowsLeft[i][j] = true;
			if(j -1 >= 0 && board[i][j] >= board[i][j-1] && flowsLeft[i][j-1])
				flowsLeft[i][j] = true;
		}
	}
}

int main(){
	Rainfall myBoard (10000,5);
	myBoard.printBoard();
	myBoard.solveFlows();
	myBoard.printDoubleFlowPoints();
	return 0;
}
