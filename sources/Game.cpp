#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include "Game.hpp"
#include "Player.hpp"
using namespace coup;
const short max_player = 6;
const short min_player = 2;


string Game::turn()
{
    //string ans= player_list.at(next_turn);
    string ans = player_list.at(0); 
    return ans;
}
void Game::add_NewPlayer(string &new_player){ // add new player to the list players
if( player_list.size()>=max_player){
    throw logic_error ("Maximum Players in the Game!") ;  ; 

}
    player_list.push_back(new_player);
    if(this->game_started){
       throw "Game already started!";
    }
    
        
}

ostream &operator<<(ostream &out, const Game &game){
    return out;
}

 vector<string> Game::players()const{ // reutn list of player's names
    return player_list;
}

string Game::winner(){ // print the winner of the game
    if(player_list.size()>1){
        throw "The Game is not finished yet!"; 
        
    }
    if (!this->game_started){
        throw "The Game is not started yet!"; 
    }
    this->game_started=false;
    return player_list.at(0);
    
          
    
}

void Game::switch_player(){
    // this->next_turn++;
    // next_turn= next_turn%player_list.size();

    player_list.push_back(player_list.at(0)); // add the first player to the end of the list players
    auto it = player_list.at(0);
    player_list.erase(player_list.begin()); // delete the first player from the list players
    
}

void Game::player_out(const string &name){

    for(unsigned int i= 0 ; i< player_list.size() ; i++){
        if((player_list.at(i).compare(name))==0){
            player_list.erase(player_list.begin()+i);
        }
    }
}
void Game::check_game_started(){
    if(!this->game_started){
       this->game_started=true;
    }
    
}