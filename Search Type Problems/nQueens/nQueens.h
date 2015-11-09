class nQueens {
    private:
    int sizeOfBoard;
    bool* attackLeftDiag;
    bool* attackRightDiag;
    bool* attackSide;
    int numberOfQueensPlaced;
    int numberOfValidConfigOfQueens;

    bool validMove(int row, int col);
    void placeQueenAt(int row, int col);
    void removeQueenAt(int row, int col);
    void addConfigToCount();

    public:
    nQueens(int n);
    ~nQueens();
    void solve(int colNum);
    int numberOfpossibleMoves();
};
