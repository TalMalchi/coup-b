#pragma once
#include <iostream>
#include <string>
#include "Game.hpp"
using namespace std;

const short max_players = 6;

namespace coup{
class Game;

class Player{

   
        // unsigned int my_coins;
        // string name_player;
        // string my_role;

    public:
        unsigned int my_coins;
        string name_player;
        string my_role;
        bool player_coup=false;
        bool is_block_coup= false; 
        bool is_block_forgein_aid= false;
        bool is_block_steal= false;
        coup::Game& game;
        string last_action;
        
        
        Player(Game &new_game, string name):game(new_game), name_player(name){
            if (game.player_list.size()>max_players){
                throw "Maximum players in the game!";
            }
            new_game.add_NewPlayer(name);
            my_coins=0;
        } 
        ~Player(){}

        Player(const Player& other):game(other.game), name_player(other.name_player), my_coins(other.my_coins), my_role(other.my_role), player_coup(other.player_coup), is_block_coup(other.is_block_coup), is_block_forgein_aid(other.is_block_forgein_aid), is_block_steal(other.is_block_steal), last_action(other.last_action){}
    

    void income();
    void foreign_aid();
    virtual void coup(Player &target);
    unsigned int coins()const;
    virtual string role()const; //returns the role of the player
    bool enough_palyers()const; // check if there is enough player to play
    bool check_coins()const; //true-> 10 <= coins -----> coup!
    bool check_turn()const; // check if is your turn to play 

    
};
    
}