#include <iostream>

#include "Game.h"

int main(int argc, char **argv) {
  Game game(10);

  /*
   * Game loop while true:
   *   Select money to bet
   *   Dealer gets one card down and one card up
   *   Player gets two cards up
   *   Player can: hit, stand, double down, fold
   *   Keep dealing cards to the player until they stand
   *   Dealer gets cards based on rules in README.md
   *   Handle money / Cash out
   */

  // Call the Game method to ask the player to hold or play.
  // Game::holdOrPlay returns true if the player wants to play the hand
  // returns false otherwise.
  // Continue with the game steps if the player wants to play the hand
  // else skip to the Game::finish method.
  while (!game.finished) {
    if (game.holdOrPlay()) {
      game.takeBets();
      game.start();
      // First take the bets from the player on the hand and add it to the pot
      // game.takeBets();

      // Handle player option selection within the game.
      // The player can hit/stand/double their hand.
      game.selectMove();

      if (game.finished) {
        // Dealer wins because player folds
        // Dealer/House takes the pot
        std::cout << "Player folds / Lose " << '\n';
      } else {
        // if player is not bust
        if (!game.gamePlayer.isBusted()) {
          game.dealersMove();
        }
      }

    }

    // Finish up the game
    game.finish();
  }

  return 0;
}

