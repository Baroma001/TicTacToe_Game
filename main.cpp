
#include "GameLogic.h"


const int row = 3;
const int col = 3;

int main()
{
    std::cout << "Welcome to TicTacToe! This is how the field is structured: " << std::endl;
    std::vector<std::vector<int>> field(row,std::vector<int>(col));
    printField(field, true);
    std::cout<<"Player 1 starts!"<<std::endl;
    playGame(field);
    return 0;
}

