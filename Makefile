CC = g++
CFLAGS = -Wall -std=c++11
DEPS = Person.h Game.h Card.h Deck.h Hand.h
OBJ = blackjack.o

%.o: %.c Person.h Game.h Card.h Deck.h Hand.h
	$(CC) $(CFLAGS) -c -o blackjack Person.h Game.h Card.h Deck.h Hand.h

main: $(OBJ)
	$(CC) $(CFLAGS) -o blackjack blackjack.cc

clean:
	rm -rf *.o blackjack

