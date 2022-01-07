#include "Engine.h"

Engine::Engine()
{
	deck = Deck();
	deck.shuffleCards();
	//deck.printDeck();
	for (int i = 0; i < 52; i++) {
		i % 2 == 0 ? player1deck.playerDeck.push_back(deck.cards[i]) : player2deck.playerDeck.push_back(deck.cards[i]);
	}
	player1deck.sortPDeck();
	player2deck.sortPDeck();
}

void Engine::compare(Card c1, Card c2)
{
	if (c1 < c2 == 1) {
		player1Score++;
	}
	else if (c1 < c2 == 2) {
		player2Score++;
	}
}
