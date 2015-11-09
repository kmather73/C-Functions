#include <time.h>
#include <algorithm>    // std::copy
#include <functional>
#include <stdio.h>		//printf
#include <stdarg.h>		//
#include <vector>       // std::vector
#include <ostream>
#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <iomanip>      // std::setw
class Rainfall {
private:
	int rows;
	int cols;
	std::vector<std::vector<int>> board;
	std::vector<std::vector<bool>> flowsRight;
	std::vector<std::vector<bool>> flowsLeft;

	solveFlowsLeft();
	solveFlowsRight();

public:
	Rainfall(int rows, int cols);
	solveFlows();
	printDoubleFlowPoints();
	printBoard();
};