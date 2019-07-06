#ifndef PERSON_H
#define PERSON_H

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "Hand.h"
#include "Card.h"
#include "Deck.h"

int getRandomNumber();

// Need to make variables private
class Person {
	public:
		int money;
    int previousBet;
		Hand hand;

		Person ();

    Person (int initMoney);

		Hand getHand();

		void addCard(const Card& newCard);

		void printCards();

    void hit(Deck& deck);

    void stand();

    void doubleDown(Deck& deck, int& pot);

    void fold(bool& finished);

    int getMoney();

    void addToMoney(int moneyToAdd);

    int getPreviousBet();

    void setPreviousBet(int bet);

    bool isBusted();

    void reset();
};

class Dealer: public Person {
	public:
    int id;
    std::string moveAI();
};

class Player: public Person {
	public:
    int id;
};

#endif // PERSON_H
