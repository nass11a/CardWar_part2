#pragma once

#ifndef CARD_H_
#define CARD_H_
#include <iostream>


namespace ariel{

class Card{

    public:

        Card(std::string& name_type,size_t value);

        const std::string& getNameType() const;
        
        size_t get_value();

        private:

         std::string name_type_;
         size_t _value;

    };

};
#endif