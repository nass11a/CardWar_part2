#pragma once

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include <iostream>
#include <vector>
#include "card.hpp"

using namespace std;

const int first_Player_starter_Cards=26;

namespace ariel{

class Player{

    public:

        Player(const std::string& name);
         size_t stacksize();
         size_t cardesTaken();
        std::vector<Card> arr_Cards;
         size_t last_Card;
         size_t cards_taken;
         size_t stack_size;
         std::string name_;

    };

};

#endif 



