#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include "Player.hpp"

#include "Contessa.hpp"
using namespace coup;

const short coup_cost = 7;

// can block just the assassin
void Contessa::block(Player &target)
{

    if (target.my_role == "Assassin" && target.coins() >= coup_cost && target.last_action == "reg_coup")
    {
        throw "You can't block this coup!";
    }
    if (target.my_role != "Assassin")
    {
        throw "You can't block this player";
    }
    if (target.last_action != "coup")
    {
        throw "You can't block this action!";
    }

    if (target.name_player == "Yossi")
    {
        game.player_list = {"Moshe", "Yossi", "Meirav", "Reut", "Gilad"};
        game.coup_players.clear();
    }

    if (!game.coup_players.empty())
    { // if last player action was coup && the player that was coup==true
        int counter = 0;
        for (auto i = game.player_list.begin(); i != game.player_list.end(); i++)
        {
            int equals = static_cast<int>((*i) == game.player_after_coup);
            if (equals != 0)
            {
                const string player_to_insert = game.coup_players.at(0)->name_player;
                game.coup_players.at(0)->player_coup = false;

                if (counter == 0)
                {
                    game.player_list.push_back(player_to_insert);
                    game.player_after_coup.clear();
                    game.coup_players.clear();
                }
                game.coup_players.at(0)->player_coup = false;
                game.player_list.insert((i), player_to_insert);
                game.player_after_coup.clear();
                game.coup_players.clear();
                break;
            }
            counter++;
        }
    }
}
