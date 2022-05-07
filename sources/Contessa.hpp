/**
 * Created by talko on 4/24/22.
 */

#include "Player.hpp"

using namespace std;

namespace coup {

    class Contessa : public Player {

    public:
        Contessa(coup::Game& g, string n) : Player(g,n,0, false) {
            player_roles = "Contessa";
            if (g.players_names.size() < 6){
                g.players_names.push_back(n);
            }
        }

        void block(Player p1);
    };
}