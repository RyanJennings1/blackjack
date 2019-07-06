#include "Person.h"

Person::Person() {
  previousBet = 0;
	money = 100;
  hand = Hand();
}

Person::Person(int initMoney) {
  previousBet = 0;
  money = initMoney;
  hand = Hand();
}

Hand Person::getHand() {
  return hand;
}

void Person::addCard(const Card& newCard) {
  hand.add(newCard);
}

void Person::printCards() {
	for (std::vector<Card>::const_iterator it = hand.cards.begin(); it != hand.cards.end(); it++) {
		std::cout << "|" << it->getRank() << it->getSuit() << "| ";
	}
	std::cout << '\n';
}

void Person::hit(Deck& deck) {
  std::cout << "Hit! " << '\n';
  hand.add(deck.deal());
  Person::printCards();

  /*
  std::string playerChoice;
  std::cout << "Hit again? [Y/n] " << '\n';
  std::cout << "->: ";
  std::cin >> playerChoice;

  while (((playerChoice != "Y") &&
         (playerChoice != "y") &&
         (playerChoice != "N") &&
         (playerChoice != "n")) ||
         !isBusted()) {
    std::cout << "Invalid option: " << '\n';
    std::cout << "Hit again? [Y/n] " << '\n';
    std::cout << "->: ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> playerChoice;
  }

  if (playerChoice == "Y" || playerChoice == "y") {
    std::cout << "Hit! " << '\n';
    hand.add(deck.deal());
    Person::printCards();
  } else {
    //
  }
  */

  /*
  if (!isBustedCheck()) {
    std::string res = "";
    // While the response isn't "n" and
    // the player is not busted
    while (res != "n" && !isBustedCheck()) {
      std::cout << "Hit again? [Y/n] " << '\n';
      std::cout << "->: ";
      std::cin >> res;
      if (res == "Y") {
        std::cout << "Hit! " << '\n';
        hand.add(deck.deal());
        Person::printCards();
      }
    }
  }

  if (isBustedCheck()) {
    std::cout << "Busted " << '\n';
  }
  */
}

void Person::stand() {
  std::cout << "Stand " << '\n';
}

void Person::doubleDown(Deck& deck, int& pot) {
  // Double bet and add 1 card only
  std::cout << "Double " << '\n';
  // Add previous bet to pot
  // make check in case bet goes over player money
  std::cout << "Previous bet: " << previousBet << '\n';
  pot += previousBet;
  money -= previousBet;

  // Deal Card
  hand.add(deck.deal());
}

void Person::fold(bool& finished) {
  // forfeit half the wager
  // do not play out the hand
  // only available on initial 2 cards
  
  finished = true;

  // Find a way to end the game from here
  // Set pot to 0
}

int Person::getMoney() {
  return money;
}

void Person::addToMoney(int moneyToAdd) {
  money += moneyToAdd;
}

int Person::getPreviousBet () {
  return previousBet;
}

void Person::setPreviousBet (int bet) {
  previousBet = bet;
}

bool Person::isBusted() {
  return hand.total > 21;
}

void Person::reset() {
  hand.total = 0;
  hand.hasAce = false;
  hand = Hand();
}

int getRandomNumber() {
  std::srand(unsigned(std::time(0)));
  return std::rand()%100;
}

std::string Dealer::moveAI() {
  if (getRandomNumber() > 50) {
    return "hit";
  } else {
    return "stand";
  }
}

