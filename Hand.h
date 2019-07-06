#ifndef HAND_H
#define HAND_H

#include <vector>

#include "Card.h"

class Hand {
  public:
		std::vector<Card> cards;
		bool hasAce;
    int numAcesIn11State;
		int total;

		Hand ();

		void add(const Card& newCard);

		int getTotal();

    void addToTotal(int value);
};

#endif // HAND_H
