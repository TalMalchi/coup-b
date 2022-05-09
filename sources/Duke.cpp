
#include <iostream>
using namespace std;
#include <string>
#include "Player.hpp"
#include "Duke.hpp"
using namespace coup;


void Duke::tax(){
    game.check_game_started();
    if(!enough_palyers()){
        throw "Not enough players to play! " ;
    }
    if(!(check_turn())){ //check that its the player turn
        throw "It's not Yout Turn to play! " ;
    }
    my_coins+=3;
    game.switch_player();
        }

      void Duke::block(Player &target) {
        if(target.last_action!="forgein_aid"){
            throw "You can't block this action!";
             
        }
        target.my_coins-=2; 
        }