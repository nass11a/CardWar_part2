#include <iostream>
#include "namespace.hpp"
using namespace ariel;

Player::Player(const std::string& name):name_(name){
    this->name_=name;
    arr_Cards.reserve(first_Player_starter_Cards);
    this->stack_size=0;
    this->cards_taken=0;
}

size_t Player::stacksize(){
    //std::cout << "Stack Size :" << std::endl;
    return this->stack_size;
}
 size_t Player::cardesTaken(){
    //std::cout << "Cards Taken  " << std::endl;
    return this->cards_taken;
    
}

