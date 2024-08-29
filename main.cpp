
#include "GameLogic.h"
#include <cstdlib>
#include <time.h>

#include "SinglePlayerBot.h"


const int row = 3;
const int col = 3;

int main()
{
    srand(time(0));
    std::cout << "Welcome to TicTacToe! This is how the field is structured: " << std::endl;
    std::vector<std::vector<int>> field(row,std::vector<int>(col));
    printField(field, true);
    std::cout<<"Would you like to play against a bot? Y/N"<<std::endl;
    std::string input;
    while(input != "Y" && input != "N" && input!="y"&&input != "n") {
        std::cin>>input;
        if(input != "Y" && input != "N" && input!="y"&&input != "n") {
            std::cout<<"Invalid input, please try again: ";
        }
    }
    if(input == "Y" || input=="y") {
        std::cout<<"Which player would you like to be? 1/2"<<std::endl;
        while(input != "1" && input!= "2") {
            std::cin>>input;
            if(input != "1" && input != "2") {
                std::cout<<"Invalid input, please try again: ";
            }
        }
        if(input == "1") {
            playBotGame(field, false);
        }else{
            playBotGame(field,true);
        }
    }else {
        std::cout<<"You have chosen a two player game!"<<std::endl;
        std::cout<<"Player 1 starts!"<<std::endl;
        playGame(field);
    }

    return 0;
}

