#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Deck.h"
#include "Person.h"

class Game {
	public:
    Deck gameDeck;
    Player gamePlayer;
    Dealer gameDealer;
    bool finished;
    int pot;

    Game (int numDecks);

		void start();

    bool holdOrPlay();

    void takeBets();

    void selectMove();

    int getPot();

    void finish();

    void dealersMove();

    int determineOutcome();
};

#endif // GAME_H
