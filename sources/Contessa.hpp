#include <iostream>
#include <string>
#include "Player.hpp"




namespace coup{
    class Game;

    class Contessa: public Player{

        
        


        public:
            Contessa(Game &game, string name_player):Player(game, name_player){
                this->my_role= "Contessa";
            }
            ~Contessa(){}
            //void coup(Player &b);

            // void block(Assassin &b);
            //COntessa can block just the assassin-the player that the assassin blocked will come back to the game

            void block(Player &target);
            

        // string role(){
        //     my_role="Contessa";
        //     return my_role;
        // }
            
            
            
    };
    
}