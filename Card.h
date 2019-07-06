#ifndef CARD_H
#define CARD_H

#include <iostream>

std::string suitIntToString (int s);

std::string suitNameToSymbol (std::string s);

std::string rankIntToString (int s);

int rankIntToValue (int s);

class Card {
	public:
		int suit;
		int rank;

		Card (int s, int r);

		std::string to_string () const;

		std::string getSuit () const;

		std::string getRank () const;
};

#endif // CARD_H
