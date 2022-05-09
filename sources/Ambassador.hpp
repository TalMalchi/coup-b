#include <iostream>
#include <string>
#include "Player.hpp"



namespace coup{
    class Game;


    class Ambassador: public Player{

        public:
            Ambassador(Game &game, string name_player):Player(game, name_player){
                this->my_role= "Ambassador";

            }
            void transfer(Player &source, Player &dest); //transfer coins from one player to another
    
            void block(Player &target);  //can block stealing coins from another player
        
            
    
};
}