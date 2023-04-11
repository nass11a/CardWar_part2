
 #include <iostream>
#include "namespace.hpp"
 
using namespace ariel;

Card::Card(std::string& name_type,size_t value):name_type_(name_type),_value(value){
    this->name_type_=name_type;
    this->_value=value;
 }

size_t Card::get_value(){
    return this->_value;
}


const std::string& Card::getNameType() const{
    return this->name_type_;
}

