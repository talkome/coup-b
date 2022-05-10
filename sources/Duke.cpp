/**
 * Created by talko on 4/24/22.
 */

#include "Duke.hpp"

void coup::Duke::tax() {
    if (game->turn() == this->name() && !this->must_coup()){
        int price = 3;
        this->coins() += price;
        this->moves().push_back(TAX);
        next_turn();
    } else {
        throw invalid_argument("Wrong Player Turn");
    }
}

void coup::Duke::block(coup::Player &p1) {
    if (!this->must_coup()){
        size_t size = p1.moves().size();
        int price = 2;
        if (p1.moves().at(size-1) == FOREIGN_AID){
            p1.pay(price);
        }
        this->moves().push_back(BLOCK);
    }
}

string coup::Duke::role() const {
    return this->player_roles;
}

string &coup::Duke::role() {
    return this->player_roles;
}
