#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

using namespace std;


namespace coup{
    class Game;

    class Assassin: public Player{



        public:
         Assassin(Game &game, string name_player):Player(game, name_player){
             this->my_role= "Assassin";
         }
        ~Assassin(){}
        void coup(Player &target);


    };
    
}