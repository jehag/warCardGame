#pragma once
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>
#include "Deck.h"
#include "PlayerDeck.h"

using namespace std;

class Engine {
public:
	Engine();
	Deck deck;
	PlayerDeck player1deck;
	PlayerDeck player2deck;
	int player1Score;
	int player2Score;
	void compare(Card c1, Card c2);
};