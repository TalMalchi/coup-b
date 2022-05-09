#include <iostream>
using namespace std;
#include <string>
#include "Player.hpp"
#include "Ambassador.hpp"
using namespace coup;




void Ambassador::transfer(Player &source, Player &dest){ //transfer coins from one player to another
    if(!enough_palyers()){
        throw "Not enough players to play! " ;
    }
    
    if(!(check_turn())){ //check that its the player turn
        throw "It's not Yout Turn to play! " ;
    }
    if(source.coins()<1){
        throw "Dont have enough monet to transfer";
    }
        source.my_coins--;
        dest.my_coins++;
        last_action="transfer";
        game.switch_player();
                
            }
//can block stealing coins from another player
void Ambassador::block(Player &target){
    if(target.my_role != "Captain" || target.last_action != "steal")
    {
        throw "Ambassador can't block this Player of this action! " ;
        is_block_steal=true;

    }

    target.my_coins -=2;
    game.stolen_players.at(0)->my_coins +=2;
    game.stolen_players.erase(game.stolen_players.begin());
    

     if (game.turn()==this->name_player){
             game.switch_player();
         }
}
                
            



