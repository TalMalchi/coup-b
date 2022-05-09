
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "Player.hpp"
#include "Captain.hpp"
using namespace coup;

void Captain::block(Player &target)
{
    if(target.my_role == "Captain" && target.last_action == "steal")
    {
       target.my_coins -=2;
       game.stolen_players.at(0)->my_coins +=2;
       game.stolen_players.erase(game.stolen_players.begin());

    }
    throw "Captain can't block this Player or this action" ;
    is_block_steal=true;

     if (game.turn()==this->name_player){
             game.switch_player();
    }
}

void Captain::steal(Player &target)
{
    if(!enough_palyers()){
        throw "Not enough players to play! " ;
    }
    
    if(!(check_turn())){ //check that its the player turn
        throw "It's not Yout Turn to play! " ;
    }
    if(target.my_coins <1){
        target.my_coins= target.my_coins;
        my_coins=my_coins;
        game.switch_player();
    }
    if(target.my_coins <2){
        target.my_coins-=1;
        my_coins+=1;
        game.switch_player();

    }
    else {
    target.my_coins-=2;
    my_coins+=2;
    last_action="steal";
    game.stolen_players.push_back(&target);
    game.switch_player();
    }

}

