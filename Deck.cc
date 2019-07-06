#include "Deck.h"

Deck::Deck () {
  //
}

Deck::Deck(int numDecks) {
	if (numDecks < 1) {
		// Create just 1 Deck if less than 1 specified
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 13; k++) {
				Card newCard(j, k);
				cards.push_back(newCard);
			}
		}
	} else {
		std::cout << "Generating deck ... " << '\n';
		for (int i = 0; i < numDecks; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 13; k++) {
					Card newCard(j, k);
					cards.push_back(newCard);
				}
			}
		}
	}
}

int uniqueRandom (int i) { return std::rand() % i; }

void Deck::shuffle() {
  std::srand(unsigned(std::time(0)));
  std::random_shuffle(cards.begin(), cards.end(), uniqueRandom);
}

Card Deck::deal() {
	Card temp = cards.back();
	cards.pop_back();
	return temp;
}

int Deck::get_length() {
	return cards.size();
}

