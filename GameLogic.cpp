//
// Created by Yannick Hettinga on 27.08.24.
//
#include "GameLogic.h"
#include "SinglePlayerBot.h"

void playGame(std::vector<std::vector<int>> &field) {
    bool playerOneTurn = true;
    int counter = 0;
    while(!winning(field)) {
        if(counter >= 9) {
            std::cout<<"Its a draw, well played!"<<std::endl;
            break;
        }
        setMove(field, playerOneTurn);
        printField(field, false);
        counter++;
    }
}



bool winning(const std::vector<std::vector<int>> &field) {
    int size = field.size();
    for(int i = 0; i< size; i++) {
        if (field[0][i] != 0 && field[0][i] == field[1][i] && field[1][i] == field[2][i]) {
            std::cout<<"Player "<<field[0][i]<<" has won!"<<std::endl;
            return true;
        }
        if (field[0][i] != 0 && field[0][i] == field[1][i] && field[1][i] == field[2][i]) {
            std::cout<<"Player "<<field[0][i]<<" has won!"<<std::endl;
            return true;
        }
    }
    if (field[0][0] != 0 && field[0][0] == field[1][1] && field[1][1] == field[2][2]) {
        std::cout<<"Player "<<field[0][0]<<" has won!"<<std::endl;
        return true;
    }

    if (field[0][2] != 0 && field[0][2] == field[1][1] && field[1][1] == field[2][0]) {
        std::cout<<"Player "<<field[0][0]<<" has won!"<<std::endl;
        return true;
    }
    return false;
}

void setMove(std::vector<std::vector<int>> &field, bool &playerOneTurn) {
    std::string move;
    std::vector<std::string> validMoves {"A0","A1", "A2", "B0","B1","B2","C0","C1","C2"};
    bool validMove = false;
    std::cout<<"Please enter where you want to place your move ";
    if(playerOneTurn) {
        std::cout<<"Player 1: ";
    }else {
        std::cout<<"Player 2: ";
    }
    while(!validMove) {
        std::cin>>move;
        for(int i = 0; i<validMoves.size(); i++) {
            if(move == validMoves[i] && field[move[0]-'A'][move[1]-'0']== 0) {
                validMove = true;
            }
        }
        if(validMove == false) {
            std::cout<<"Move invalid, please enter a new move ";
            if(playerOneTurn) {
                std::cout<<"Player 1: ";
            }else {
                std::cout<<"Player 2: ";
            }
        }
    }
    if(playerOneTurn) {
        field[move[0]-'A'][move[1]-'0'] = 1;
    }else {
        field[move[0]-'A'][move[1]-'0'] = 2;
    }
    playerOneTurn = !playerOneTurn;
}

void printField(std::vector<std::vector<int>>&field, bool firstTurn) {
    int rows = field.size();
    int cols = field[0].size();
    if(firstTurn) {
        std::cout<<"A0|A1|A2"<<std::endl;
        std::cout<<"B0|B1|B2"<<std::endl;
        std::cout<<"C0|C1|C2"<<std::endl;
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (field[i][j] == 0) {
                std::cout << " ";
            } else if (field[i][j] == 1) {
                std::cout << "X";
            } else {
                std::cout << "O";
            }

            if (j != cols - 1) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;

        if (i != rows - 1) {
            std::cout << "-----------\n";
        }
    }
}
