
#include <iostream>
#include <algorithm>
#include <random>
#include "namespace.hpp"

using namespace ariel;

const int v1=26;
const int v2=52;
const int printlast_Arr_size=2;
const int printlog_player1_Arr_size=26;
const int printlog_player2_Arr_size=26;
const int stats_size=26;

Game::Game( Player& p1,  Player& p2) : p1_(p1), p2_(p2){

 
   this->print_last_turn.reserve(printlast_Arr_size);
   this->stats.reserve(stats_size);
   this->print_log_player1.reserve(printlog_player1_Arr_size);
   this->print_log_player2.reserve(printlog_player2_Arr_size);
   this->deck.reserve(cards_in_game);

    p1_.stack_size=26;
    
    p2_.stack_size=26;

    for(size_t value=1; value<= 13; value++)
    {
        if(this->deck.size()==52){
            break;   
        }
        std::string hearts="Hearts";
        std::string Diamonds="Diamonds";
        std::string Clubs="Clubs";
        std::string Spades="Spades";
        Card a(hearts, value);
        Card b(Diamonds, value);
        Card c(Clubs, value);
        Card d(Spades, value);
    this->deck.push_back(a);
    this->deck.push_back(b);
    this->deck.push_back(c);
    this->deck.push_back(d);

    }

    std::mt19937 g{std::random_device{}()};
    shuffle(this->deck.begin(), this->deck.end(), g);

    for(int i=0;i<v1;i++){
      
        this->p1_.arr_Cards.push_back(this->deck.at(static_cast<std::vector<Card>::size_type>(i)));

    }

   
    for(int i=v1;i<v2;i++){
   
        this->p2_.arr_Cards.push_back(this->deck.at(static_cast<std::vector<Card>::size_type>(i)));
    }
    
}

void Game::playTurn(){

     int temp_for_draw=0;
    
    
       if(p1_.name_ == p2_.name_){
    std::__throw_runtime_error("players have the same name!");
   }
    
     if(p1_.stack_size==0 && p2_.stack_size==0 ){
        std::__throw_runtime_error("can't play more turn after game ends!");
    }


    Card p1_card=p1_.arr_Cards.at(p1_.arr_Cards.size()-1);
    Card p2_card=p2_.arr_Cards.at(p2_.arr_Cards.size()-1);
   

    print_last_turn.assign({ p1_card, p2_card });
    print_log_player1.push_back(p1_card);
    print_log_player2.push_back(p2_card);

    p1_.last_Card=p1_card.get_value();
    p2_.last_Card=p2_card.get_value();



   if(p1_.arr_Cards.size() ==0 && p2_.arr_Cards.size()==0){
      std::__throw_runtime_error("can't play ");
    }

    if(p1_.last_Card!=p2_.last_Card){
        if(p1_.arr_Cards.size() ==0 && p2_.arr_Cards.size()==0){
      std::__throw_runtime_error("can't play more ");
    }    
        if(p1_.last_Card > p2_.last_Card){
          size_t a=1;
          p1_.cards_taken=p1_.cards_taken+2;
       
    
          p2_.arr_Cards.pop_back();
         
          p1_.arr_Cards.pop_back();

          p1_.stack_size=p1_.arr_Cards.size();
          p2_.stack_size= p2_.arr_Cards.size();

          this->stats.push_back(a);
        }

        if(p2_.last_Card > p1_.last_Card){
            if(p1_.arr_Cards.size() ==0 && p2_.arr_Cards.size()==0){
      std::__throw_runtime_error("can't play more turn ");
    }
            size_t a=2;    
            p2_.cards_taken=p2_.cards_taken+2;
       

          p1_.arr_Cards.pop_back();
        
          p2_.arr_Cards.pop_back();

          p1_.stack_size=p1_.arr_Cards.size();
          p2_.stack_size= p2_.arr_Cards.size();

          this->stats.push_back(a);

        }


    }

    if(p1_.last_Card==p2_.last_Card){
        size_t a=0;
        this->stats.push_back(a);
        if(0 < p1_.arr_Cards.size() && p1_.arr_Cards.size()< 3  && 0 < p2_.arr_Cards.size()  && p2_.arr_Cards.size() < 3 ){
          
          p1_.arr_Cards.pop_back();
        
          p2_.arr_Cards.pop_back();

          p1_.stack_size=p1_.arr_Cards.size();
          p2_.stack_size= p2_.arr_Cards.size();

          p1_.cards_taken+=1;
          p2_.cards_taken+=1;

           
     }

     else{

        Game::draw();
        
        }    

    }

    }



void Game::draw(){
                 
            if(p1_.arr_Cards.size() ==0 && p2_.arr_Cards.size()==0){
      std::__throw_runtime_error("can't play more turn after ");
    } 
    
         if(p1_.arr_Cards.size() < 3 || p2_.arr_Cards.size() < 3 ){
      std::__throw_runtime_error("can't play more turn after game");
    } 

         size_t draw_counter=3;

         Card third_p1_card=p1_.arr_Cards.at(p1_.arr_Cards.size()-3);
         Card third_p2_card=p2_.arr_Cards.at(p2_.arr_Cards.size()-3);
         

      print_last_turn.assign({ third_p1_card, third_p2_card });
      print_log_player1.push_back(third_p1_card);
      print_log_player2.push_back(third_p2_card);

         p1_.last_Card=third_p1_card.get_value();
         p2_.last_Card=third_p2_card.get_value();


        size_t temp=3;

        if(p1_.last_Card > p2_.last_Card){

          p1_.cards_taken=p1_.cards_taken+temp*2;

          p2_.arr_Cards.pop_back();
          p2_.arr_Cards.pop_back();
          p2_.arr_Cards.pop_back();

          p1_.arr_Cards.pop_back();
          p1_.arr_Cards.pop_back();
          p1_.arr_Cards.pop_back();

          p1_.stack_size= p1_.arr_Cards.size();
          p2_.stack_size= p2_.arr_Cards.size();
        
        }

         if(p1_.last_Card < p2_.last_Card){
            
          p2_.cards_taken=p2_.cards_taken+temp*2;

          p1_.arr_Cards.pop_back();
          p1_.arr_Cards.pop_back();
          p1_.arr_Cards.pop_back();

          p2_.arr_Cards.pop_back();
          p2_.arr_Cards.pop_back();
          p2_.arr_Cards.pop_back();

          p1_.stack_size= p1_.arr_Cards.size();
          p2_.stack_size= p2_.arr_Cards.size();

        }


        if(p1_.last_Card==p2_.last_Card){

            Game::anotherdraw(draw_counter);
         
        }

        }



void Game::anotherdraw(size_t dr){
    
    while(p1_.stack_size != 0 && p2_.stack_size !=0){

      size_t draw_c=dr+2;
           
      if(p1_.arr_Cards.size()-draw_c <= 0 || p1_.arr_Cards.size()-draw_c > 26 || p2_.arr_Cards.size()-draw_c <=0 ||p2_.arr_Cards.size()-draw_c > 26  ){
  
        p1_.stack_size=0;
        p2_.stack_size=0;
        p1_.cards_taken+=p1_.arr_Cards.size();
        p2_.cards_taken+=p2_.arr_Cards.size();
        break;
      
      } 

       Card check_p1_card=p1_.arr_Cards.at(p1_.arr_Cards.size()-draw_c);
       Card check_p2_card=p2_.arr_Cards.at(p2_.arr_Cards.size()-draw_c);

        print_last_turn.assign({ check_p1_card, check_p2_card });
        print_log_player1.push_back(check_p1_card);
        print_log_player2.push_back(check_p2_card);

        p1_.last_Card=check_p1_card.get_value();
        p2_.last_Card=check_p2_card.get_value();

          if(p1_.last_Card > p2_.last_Card){

            for(size_t j=0;j<draw_c;j++){
                p2_.arr_Cards.pop_back();
                p1_.arr_Cards.pop_back();
            }

          p1_.cards_taken=p1_.cards_taken+draw_c*2;
           
           p2_.stack_size=-draw_c;
           p1_.stack_size=-draw_c;
          
        }

         if(p1_.last_Card < p2_.last_Card){
            
            for(size_t j=0;j<draw_c;j++){
                p1_.arr_Cards.pop_back();
                p2_.arr_Cards.pop_back();
            }

          p2_.cards_taken=p2_.cards_taken+draw_c*2;

          p1_.stack_size=-draw_c;
          p2_.stack_size=-draw_c;
      
        }

        if(p1_.last_Card ==p2_.last_Card){

            Game::anotherdraw(draw_c);
           
        }
    }
     }


void Game::printLastTurn(){

std::cout << "Print Last Turn :" << endl;

std::cout << p1_.name_<< " " << "played" << " " << convert_value_to_type(print_last_turn.at(0).get_value()) << " " << "of" << " " << print_last_turn.at(0).getNameType()<< std::endl;

std::cout << p2_.name_ << " " <<  "played" << " " <<convert_value_to_type(print_last_turn.at(1).get_value()) << " " << "of" << " " << print_last_turn.at(1).getNameType()<< std::endl;
std::cout << "  " << std::endl;

}

void Game::playAll(){
    while(p1_.stack_size!=0 && p2_.stack_size !=0){
        Game::playTurn();
    }
}


void Game::printWiner(){

std::cout << "///////////////////////////////////////////////////////////////////////////////////" << std::endl;

std::cout << "  " << std::endl;
std::cout << "Winner Of The Game : " << endl;
    if(p1_.cards_taken>p2_.cards_taken){
         std::cout << p1_.name_ << "wins!" << std::endl;
           std::cout << "  " << std::endl;
    }

    if(p2_.cards_taken>p1_.cards_taken){
         std::cout << p2_.name_<< "wins!" << std::endl;
           std::cout << "  " << std::endl;
    }

     if(p1_.cards_taken == p2_.cards_taken){
         std::cout <<  "there is no winner!" <<endl;
         
    }

  std::cout << "///////////////////////////////////////////////////////////////////////////////////" << std::endl;
}

void Game::printLog(){

    std::cout << "Game Log : " << std::endl;
    std::cout << "  " << std::endl;

    for(size_t turn=0;turn<print_log_player1.size();turn++){
       std::cout << "turn -->  " << turn << std::endl;
       std::cout << p1_.name_<< " " <<   "played" << " " << convert_value_to_type(print_log_player1.at(turn).get_value()) << " " <<  "of" << " " << print_log_player1.at(turn).getNameType()<< std::endl;
       std::cout << p2_.name_ << "played" << " " <<convert_value_to_type(print_log_player2.at(turn).get_value()) << " " <<  "of" << " " <<  print_log_player2.at(turn).getNameType()<< std::endl;
      std::cout << "  " << std::endl;
    }
}

void Game::printStats() {

  std::cout << "///////////////////////////////////////////////////////////////////////////////////" << std::endl;
    // Count the number of wins for each player and the number of draws
    int player1Wins = 0;
    int player2Wins = 0;
    int draws = 0;
    for (size_t i = 0; i < stats.size(); i++) {
        if (stats[i] == 1) {
            player1Wins++;
        } else if (stats[i] == 2) {
            player2Wins++;
        } else {
            draws++;
        }
    }
    
    // Calculate the win rate for each player
    double player1WinRate = static_cast<double>(player1Wins) / static_cast<double>(stats.size());
    double player2WinRate = static_cast<double>(player2Wins) / static_cast<double>(stats.size());
    double drawRate = static_cast<double>(draws) / static_cast<double>(stats.size());

    // Print out the basic statistics for each player
    std::cout << "Game Statistics :" << std::endl;
    std::cout << "  " << std::endl;
    std::cout << "Player 1 stats:" << std::endl;
    std::cout << "Win rate: " << player1WinRate << std::endl;
    std::cout << "Cards won: " << p1_.cards_taken << std::endl;
    std::cout << "  " << std::endl;
    std::cout << "Player 2 stats:" << std::endl;
    std::cout << "Win rate: " << player2WinRate << std::endl;
    std::cout << "Cards won: " << p2_.cards_taken << std::endl;
    std::cout << "  " << std::endl;
    // Print out the draw rate and the amount of draws that happened

    std::cout << "Draw rate: " << drawRate << std::endl;
    std::cout << "Number of draws: " << draws << std::endl;
    std::cout << "  " << std::endl;

    std::cout << "///////////////////////////////////////////////////////////////////////////////////" << std::endl;
}

 std::string Game::convert_value_to_type(size_t val){
 if (val == 1) {
        return "Ace";
    }
    else if (val== 11) {
        return "Jack";
    }
    else if (val == 12) {
        return "Queen";
    }
    else if (val == 13) {
        return "King";
    }
    else {
        return std::to_string(val);
    }
}
