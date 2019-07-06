#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Person.h"

// Game class constructor.
// int numDecks - number of decks to use in the game
Game::Game (int numDecks) {

  finished = false;

  // Generate a new deck and shuffle it
  gameDeck = Deck(numDecks);
  gameDeck.shuffle();

  // Create player and dealer instances
  gamePlayer = Player();
  gameDealer = Dealer();
}

// Start the game, deal out starting hands and print info
void Game::start() {
  std::cout << "-------------------------------------:" << "\n";
  std::cout << "Starting game ..." << "\n\n";

  // Deal two cards each to player and dealer
  gamePlayer.addCard(gameDeck.deal());
  gameDealer.addCard(gameDeck.deal());
  gamePlayer.addCard(gameDeck.deal());
  gameDealer.addCard(gameDeck.deal());

  std::cout << "Dealer Cards: " << '\n';
  gameDealer.printCards();
  std::cout << "Dealer Hand Total: " << gameDealer.hand.getTotal() << "\n\n";

  std::cout << "Player Cards: " << '\n';
  gamePlayer.printCards(); 
  std::cout << "Player Hand Total: " << gamePlayer.hand.getTotal() << "\n\n";

  // std::cout << "Number of cards in deck: " << gameDeck.get_length() << '\n';

}

// Take bets from player and add it to the pot
void Game::takeBets() {
  // Ask to fold first
  int bet;
  std::cout << "Current player money: " << gamePlayer.getMoney() << '\n';
  std::cout << "Enter bet amount " << '\n';
  std::cout << "->: ";
  std::cin >> bet;

  while ((!bet) || (bet > gamePlayer.getMoney()) || (bet < 0)) {
    std::cout << "Invalid bet value  " << '\n';
    std::cout << "Enter bet amount " << '\n';
    std::cout << "->: ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> bet;
  }

  std::cout << "Your bet is: " << bet << '\n';

  // Add bet to pot
  pot += bet;
  gamePlayer.addToMoney(-bet);
  gamePlayer.setPreviousBet(bet);
  std::cout << "The pot is: " << pot << '\n';
  std::cout << "Your money is: " << gamePlayer.getMoney() << '\n';
}

// Ask player if they want to play the hand
// Return true if player wants to play
// Else return false
bool Game::holdOrPlay() {
  std::string playerChoice;

  std::cout << "------------------------------------------------------------------------------------------------" << "\n";
  std::cout << "Play this round? [Y/n] " << '\n';
  std::cout << "->: ";
  std::cin >> playerChoice;
  std::cout << '\n';

  while ((playerChoice != "Y") &&
         (playerChoice != "y") &&
         (playerChoice != "N") &&
         (playerChoice != "n")) {
    std::cout << "Invalid option: " << '\n';
    std::cout << "Play this round? [Y/n] " << '\n';
    std::cout << "->: ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> playerChoice;
  }

  if (playerChoice == "Y" || playerChoice == "y") {
    return true;
  } else {
    finished = true;
    return false;
  }
}

// The player selects what decision to make on their hand
// The player can either hit/stand/double/fold
void Game::selectMove() {
  std::string playerChoice;

  while(!gamePlayer.isBusted() && playerChoice != "s" && playerChoice != "d") {
    std::cout << "Hit (h), Stand (s) or Double (d)? " << '\n';
    std::cout << "->: ";
    std::cin >> playerChoice;
    std::cout << '\n';

    while ((playerChoice != "h") &&
           (playerChoice != "s") &&
           (playerChoice != "d")) {
      std::cout << "Invalid option: " << '\n';
      std::cout << "Hit (h), Stand (s) or Double (d)? " << '\n';
      std::cout << "->: ";
      std::cin.clear();
      std::cin.ignore();
      std::cin >> playerChoice;
    }

    if (playerChoice == "h") {
      gamePlayer.hit(gameDeck);
    } else if (playerChoice == "s") {
      gamePlayer.stand();
    } else if (playerChoice == "d") {
      std::cout << "Value of pot before: " << pot << '\n';
      gamePlayer.doubleDown(gameDeck, pot);
      std::cout << "Value of pot after: " << pot << '\n';
    } else {
      std::cout << "Error incorrect move option " << '\n';
    }

    std::cout << "Player Choice: " << playerChoice << '\n';
    std::cout << "Player total: " << gamePlayer.hand.total << '\n';
  }

}

// Implement the dealers move in the game.
void Game::dealersMove() {
  // Dealer hit/stand
  // The dealer always has to hit if the value of their card is 16 or lower,
  // and he must stop hitting when the value reaches 17 or more.

  while (gameDealer.hand.total <= 16) {
    std::cout << "Dealer Hits" << '\n';
    gameDealer.hit(gameDeck);
  }
}

// Determine the outcome of the game, whether the player wins or loses
int Game::determineOutcome() {
  std::cout << "Player total: " << gamePlayer.hand.total << '\n';
  std::cout << "Dealer total: " << gameDealer.hand.total << '\n';

  // Win condition:
  //   ((player not busted) and (dealer is busted)) or ((player not busted) and (player hand total > dealer hand total))
  if ( (!gamePlayer.isBusted() && gameDealer.isBusted()) ||
       (!gamePlayer.isBusted() && (gamePlayer.hand.total > gameDealer.hand.total)) ) {
    std::cout << "Win" << '\n';
    return 1;
  } else if ( (gamePlayer.isBusted() && gameDealer.isBusted()) ||
              (gamePlayer.hand.total == gameDealer.hand.total) ) {
    std::cout << "Draw" << '\n';
    return 0;
  } else {
    std::cout << "Lose" << '\n';
    return -1;
  }
}

// Finish up the game
void Game::finish() {
  int result = determineOutcome();

  if (result == 1) {
    gamePlayer.addToMoney(pot*2);
  } else if (result == 0) {
    // If draw return player money put in.
    gamePlayer.addToMoney(pot);
  }

  // Clear hands and totals
  gamePlayer.reset();
  gameDealer.reset();

  pot = 0;

  std::cout << "Round finished ..." << '\n';
  if (gamePlayer.money <= 0) {
    finished = true;
    std::cout << "Game Over" << '\n';
  }
}

// Return current pot amount
int Game::getPot() {
  return pot;
}
