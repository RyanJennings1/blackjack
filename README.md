# Blackjack

This is a simple Blackjack game made from scratch in C++.

### Setup and Game Flow:
The game consists of: 
  * 52 cards (A, 2-10, J, Q, K of each of the 4 suits).
  * 1 player and 1 dealer.

In this game of blackjack, the player and the dealer is 2 random cards.
The player can see both of his cards but only one of the dealer’s card.
The dealer (program) can see both of his cards but only one of the player’s card.

Players will look at their card and calculate the sum of their card. The calculations are based on the following:
  * Ace represents 1 or 11.
  * Numerical cards represent their respective number.
  * Jack, Queen, King represents 10.
  * The color or suit of the card does not make a difference.

Based on the player’s card combination, the player will choose to hold or to play.
To hold means to finish his turn and allow the dealer to start his turn.
To play means to draw another card to get a different combination.
The sum of the player’s cards must be above 16 in order to hold.
At any time, the player can decide to change the Ace value from 11 to 1.
The program will not specifically ask the player but it will automatically change the value if it goes above 21.

##### Scoring/Deciding Winner
  The winning conditions are:
    * Player hits 21 when cards are dealt.
    * Player cards are above 16 and higher than the dealer.
    * The dealer’s card is above 21 while the player maintains 16-21.
    * The player has 5 cards on his hand and the total value is still 21 or below, (hitting 16 is not required in this case).

  The draw conditions are:
    * Both the player and the dealer the same card sum of between 16-21.
    * The player and deal receives 21 when the card is dealt.

  The lose conditions are:
    * The total sum of the player’s card is above 21.
    * The player has 5 cards on his hands and the total value is above 21.
    * The player cards are above 16 but lower than the dealer whose cards are 21 or below.
    * The dealer is dealt 21 while the player is not.

### How to Play Blackjack
In order to win blackjack, you have to beat the dealer. If the final combined value of the cards is greater than that of dealer, you win.  
When you see the value of your blackjack cards and the value of one of the cards of the dealer, you can adjust your bets accordingly.  
You can "HIT" to add more cards and "STAND" to stop. The dealer always has to hit if the value of their card is 16 or lower, and he must stop hitting when the value reaches 17 or more.

##### Blackjack Strategy
1. The goal of blackjack is not to get as close to 21, but to lose the least amount of money to the house.
2. When the combined value of your blackjack cards is 12,13,14 or 15, you should only hit when when the dealer's face-up card is 7,8,9,10 or A.
3. You should always double your bet if the combined value of your cards is 11.
4. You should always split if you have a pair of 8s.

### Installation

```sh
$ cd blackjack
$ g++ -Wall -std=c++11 *.cc -o blackjack
$ ./blackjack
```

License
----

MIT

There's a gazillion other blackjack implementations. Use this for whatever, I don't care

