//
// Created by Yannick Hettinga on 27.08.24.
//
#include <vector>
#include <iostream>
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#endif //GAMELOGIC_H

void playGame(std::vector<std::vector<int>>&);
bool winning(const std::vector<std::vector<int>>&);
void setMove(std::vector<std::vector<int>>&, bool &);
void printField(std::vector<std::vector<int>>&, bool);
