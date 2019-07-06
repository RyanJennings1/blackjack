#include "Hand.h"
#include "Card.h"

Hand::Hand () {
  numAcesIn11State = 0;
	total = 0;
}

void Hand::add(const Card& newCard) {
  cards.push_back(newCard);

  total += rankIntToValue(newCard.rank);
  if (newCard.rank == 0) {
    hasAce = true;
    if (total < 12) {
      total += 10;
      numAcesIn11State += 1;
    }
  }

  if (numAcesIn11State > 0 && total > 21) {
    total -= 10;
    numAcesIn11State -= 1;
  }
}

int Hand::getTotal() {
  return total;
}

void Hand::addToTotal(int value) {
  total += rankIntToValue(value);
}
