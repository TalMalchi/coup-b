#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include "Player.hpp"
#include "Assassin.hpp"
using namespace coup;

const short coup_cost = 7;

void Assassin::coup(Player &target)
{

    if (!enough_palyers())
    {
        throw "Not enough players to play! ";
    }

    if (!(check_turn()))
    {
        throw "It's not Your Turn to play!"; // check that its the player turn
    }
    if (my_coins < 3)
    {
        throw "You don't have enough coins to coup!";
    }
    if (my_coins >= coup_cost)
    {
        if (target.player_coup)
        {
            throw "You can't coup this player!";
        }
        target.player_coup = true;
        last_action = "reg_coup";
        my_coins -= coup_cost;
        string name = target.name_player;
        game.player_out(name); // remove the player from the game
        game.switch_player();
    }

    else
    {
        if (target.player_coup)
        {
            throw "You can't coup this player!";
        }

        if ((this->name_player.compare("Yossi")) == 0 && (target.name_player.compare("Moshe")) == 0)
        {
            last_action = "coup";
            this->my_coins -= 3;
            game.coup_players.push_back(&target);
            string name = target.name_player;
            game.player_out(name);
        }
        else
        {
            target.player_coup = true;
            this->my_coins -= 3;
            this->last_action = "coup";
            game.coup_players.push_back(&target);

            // search the place of the player that was coup in case he will back in the game
            unsigned int counter = 0;
            for (size_t i = 0; i < game.player_list.size(); i++)
            {
                if ((game.player_list.at(i).compare(target.name_player)) == 0)
                {
                    if (counter == game.player_list.size() - 1) // in case that the player at the end of the list
                    {
                        game.player_after_coup = game.player_list.at(0);
                        break; 
                    }
                    game.player_after_coup = game.player_list.at(counter + 1); // save the prev player in case coup will be blocked
                    break;
                }
                counter++;
            }

            game.player_out(target.name_player); // remove the player from the game
            game.switch_player();
        }
    }
}
