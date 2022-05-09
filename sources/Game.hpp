#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
#pragma once





namespace coup{
    class Player;
    
    class Game{


        public:
            vector<Player*>stolen_players;
            vector<Player*>coup_players;
            vector<string>player_list;
            bool game_started=false;
            string player_after_coup;
            string name_game;
            unsigned long next_turn;
            Game(){
                this->next_turn=0;
            }
            ~Game(){}
            string turn();
                
            friend ostream& operator<<(ostream& out, const Game& game);      
            void add_NewPlayer(string &new_player); //add new player to the list players
             vector<string> players()const; //reutn list of player's names
            void add_coupPLayer(string &coup_player);
            string winner(); //print the winner of the game  
            void switch_player(); 
            void player_out(const string &name);
            void check_action();     
            void check_game_started(); 
        
    };
    
}
