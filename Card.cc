#include "Card.h"

Card::Card(int s, int r) {
  suit = s;
	rank = r;
}

std::string suitIntToString (int s) {
	switch(s) {
		case 0: return "Spade";
		case 1: return "Heart";
		case 2: return "Diamond";
		case 3: return "Club";
		default: return "Err";
	}
}

std::string suitNameToSymbol (std::string s) {
	// Switch statement doesn't work on strings
	// so using if statements with comparisons
	if (s == "Spade") {
    return "♠";
	} else if (s == "Heart") {
    return "♥";
	} else if (s == "Diamond") {
    return "♦";
	} else if (s == "Club") {
    return "♣";
	} else {
    return "Err";
	}
}

std::string rankIntToString (int s) {
  switch(s) {
		case 0: return "A";
		case 1: return "2";
		case 2: return "3";
		case 3: return "4";
		case 4: return "5";
		case 5: return "6";
		case 6: return "7";
		case 7: return "8";
		case 8: return "9";
		case 9: return "10";
		case 10: return "J";
		case 11: return "Q";
		case 12: return "K";
		default: return "Err";
	}
}

int rankIntToValue (int s) {
  switch(s) {
		case 0: return 1;
		case 1: return 2;
		case 2: return 3;
		case 3: return 4;
		case 4: return 5;
		case 5: return 6;
		case 6: return 7;
		case 7: return 8;
		case 8: return 9;
		case 9: return 10;
		case 10: return 10;
		case 11: return 10;
		case 12: return 10;
		default: return 1000;
	}
}

std::string Card::to_string() const {
	return "|" + Card::getRank() + " " + Card::getSuit() + "| ";
}

std::string Card::getSuit() const {
	return suitNameToSymbol(suitIntToString(suit));
}

std::string Card::getRank() const {
	return rankIntToString(rank);
}

/*
int Card::getSuit() const {
	return suit;
}

int Card::getRank() const {
	return rank;
}
*/

