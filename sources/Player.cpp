#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <algorithm>
#include "Game.hpp"
#include "Player.hpp"
using namespace coup;

const short coup_cost = 7;
const short max_player = 6;
const short min_player = 2;
const short special_coup = 10;

void Player::income(){
    
    

    if(!enough_palyers()){
        throw "Not enough players to play! " ;
    }
    
    if(!(check_turn())){ //check that its the player turn
        throw "It's not Yout Turn to play! " ;
    }
    game.check_game_started();
    if(check_coins()){
        coup(*this); //if player has more than 10 cions, have to do coup  ////////////////// ????????? right syntacx??
    }
    
    else{
    last_action="income";
    my_coins++;
    game.switch_player();
    }

    }
   

void Player::foreign_aid(){
    game.check_game_started();

    if(!enough_palyers()){
        throw "Not enough players to play! " ;
    }
    if(!(check_turn())){ //check that its the player turn
        throw "It's not Yout Turn to play! " ;
    }
    if(check_coins()){
        throw "you cant do this action! You have to coup";
        coup(*this); //if player has more than 10 cions, have to do coup  ////////////////// ????????? right syntacx??
    }
     
        this->last_action="forgein_aid";
        this->my_coins+=2;
        game.switch_player();
        
    
    }
//coup a player -> cost 7 coin
void Player::coup(Player &target){
    if(!enough_palyers()){
        throw "Not enough players to play! " ;
    }
    if(!(check_turn())){ //check that its the player turn
        throw "It's not Yout Turn to play! " ;
    }
    if(my_coins<coup_cost){
        throw "You don't have enough coins to coup!";
    }
    if(target.player_coup){
        throw "This player is out of the game!";

    }

        target.player_coup=true;
        last_action="coup";
        my_coins -=coup_cost;
        string name = target.name_player;
        game.player_out(name); // remove the player from the game
        game.switch_player();
        
    
}
unsigned int Player::coins()const{
    if(!enough_palyers()){
        throw "Not enough players to play! " ;
    }
        return my_coins;
    }

string Player::role()const{ //returns the role of the player
        return my_role;
        cout << my_role << endl; 

    }

 bool  Player::enough_palyers()const{
    return !(game.player_list.size()<min_player || game.player_list.size()>max_player) ;

    }
bool Player::check_coins()const{
        return (special_coup <= this->my_coins);
    }
bool Player::check_turn()const{
    //int equals= this->name_player.compare(game.player_list.at(game.next_turn));
     int equals= this->name_player.compare(game.player_list.at(0));
        return (equals==0);
     

}


