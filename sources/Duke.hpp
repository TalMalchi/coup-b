#include <iostream>
#include <string>
#include "Player.hpp"


namespace coup{
    class Game;


    class Duke:public Player{
        public:

        Duke(Game &game, string name_player):Player(game, name_player){
            if (game.player_list.size()>6){
                throw "Maximum players in the game!";
            }
            this->my_role= "Duke"; 
        }
        ~Duke(){}

        void tax();
        //can block foregin aid from another player. the player that block add the coins 
         static void block(Player &target);


    };
    
}