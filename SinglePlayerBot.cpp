//
// Created by Yannick Hettinga on 27.08.24.
//

#include "SinglePlayerBot.h"
#include "GameLogic.h"
#include <cstdlib>

void makeBotMove(std::vector<std::vector<int> > &field, int counter, bool botFirst) {
    int player;
    if (botFirst) {
        player = 1;
    } else {
        player = 2;
    }

    //If its the first move then always place it in the middle
    if (counter <= 1) {
        if (field[1][1] == 0) {
            field[1][1] = player;
            return;
        }
    }

    //Stop other player from winning
    int size = field.size();
    for (int i = 0; i < size; i++) {
        // Check rows for two in a row
        if (field[i][0] != 0 && field[i][0] == field[i][1] && field[i][2] == 0) {
            field[i][2] = player;// Place the player's mark in the empty spot
            return;
        } else if (field[i][1] != 0 && field[i][1] == field[i][2] && field[i][0] == 0) {
            field[i][0] = player; // Place the player's mark in the empty spot
            return;
        } else if (field[i][0] != 0 && field[i][0] == field[i][2] && field[i][1] == 0) {
            field[i][1] = player; // Place the player's mark in the empty spot
            return;
        }

        // Check columns for two in a row
        if (field[0][i] != 0 && field[0][i] == field[1][i] && field[2][i] == 0) {
            field[2][i] = player; // Place the player's mark in the empty spot
            return;
        } else if (field[1][i] != 0 && field[1][i] == field[2][i] && field[0][i] == 0) {
            field[0][i] = player; // Place the player's mark in the empty spot
            return;
        } else if (field[0][i] != 0 && field[0][i] == field[2][i] && field[1][i] == 0) {
            field[1][i] = player; // Place the player's mark in the empty spot
            return;
        }
    }

    // Check diagonals for two in a row
    if (field[0][0] != 0 && field[0][0] == field[1][1] && field[2][2] == 0) {
        field[2][2] = player; // Place the player's mark in the empty spot
        return;
    } else if (field[1][1] != 0 && field[1][1] == field[2][2] && field[0][0] == 0) {
        field[0][0] = player; // Place the player's mark in the empty spot
        return;
    } else if (field[0][0] != 0 && field[0][0] == field[2][2] && field[1][1] == 0) {
        field[1][1] = player; // Place the player's mark in the empty spot
        return;
    }

    if (field[0][2] != 0 && field[0][2] == field[1][1] && field[2][0] == 0) {
        field[2][0] = player; // Place the player's mark in the empty spot
        return;
    } else if (field[1][1] != 0 && field[1][1] == field[2][0] && field[0][2] == 0) {
        field[0][2] = player; // Place the player's mark in the empty spot
        return;
    } else if (field[0][2] != 0 && field[0][2] == field[2][0] && field[1][1] == 0) {
        field[1][1] = player; // Place the player's mark in the empty spot
        return;
    }

    //Place in the corners if possible
    // Check and place the player's mark in the top-left corner if it's empty
    if (field[0][0] == 0) {
        field[0][0] = player;
        return;
    }

    // Check and place the player's mark in the top-right corner if it's empty
    if (field[0][size - 1] == 0) {
        field[0][size - 1] = player;
        return;
    }

    // Check and place the player's mark in the bottom-left corner if it's empty
    if (field[size - 1][0] == 0) {
        field[size - 1][0] = player;
        return;
    }

    // Check and place the player's mark in the bottom-right corner if it's empty
    if (field[size - 1][size - 1] == 0) {
        field[size - 1][size - 1] = player;
        return;
    }

    //Assign random spot
    int pos_row = (rand()% (2-0+1));
    int pos_col = (rand()% (2-0+1));

    while(field[pos_row][pos_col]!= 0) {
        pos_row = rand()%(2-0+1);
        pos_col = rand()%(2-0+1);
    }
    field[pos_row][pos_col] = player;

}

void playBotGame(std::vector<std::vector<int> > &field, bool botFirst) {
    int counter = 0;
    while (!winning(field)) {
        if (counter >= 9) {
            std::cout << "It's a draw, well played!" << std::endl;
            break;
        }
        if (botFirst) {
            if (counter % 2 == 0) {
                std::cout<<"The Bot has moved: "<<std::endl;
                makeBotMove(field, counter, botFirst);
            } else {
                bool tmp = false;
                setMove(field, tmp);
            }
        } else {
            if (counter % 2 == 0) {
                bool tmp = true;
                setMove(field, tmp);
            } else {
                std::cout<<"The Bot has moved: "<<std::endl;
                makeBotMove(field, counter, botFirst);
            }
        }
        printField(field, false);
        counter++;
    }
}
