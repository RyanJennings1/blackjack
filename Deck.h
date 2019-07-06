#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Card.h"

class Deck {
	public:
		std::vector<Card> cards;

    Deck ();

		Deck (int numDecks);

		void shuffle();

		Card deal();

		int get_length();
};

#endif // DECK_H
