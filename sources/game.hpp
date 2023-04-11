#pragma once

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>

#include "player.hpp"

using namespace std;

const int cards_in_game = 52;

namespace ariel {

    class Player;

    class Game {
    public:
        Game(Player& p1,Player& p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void draw();
        void anotherdraw(size_t dr);
        std::string convert_value_to_type(size_t val);
       // std::string check_card_type(int val);

    private:
        std::vector<Card> deck;

        std::vector<size_t> stats;

        std::vector<Card> print_last_turn;

        std::vector<Card> print_log_player1;

        std::vector<Card> print_log_player2;

        Player &p1_;
        Player &p2_;

    };

}

#endif // GAME_H_
