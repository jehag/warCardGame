#pragma once
#include <iostream>
#include <iterator>
#include <list>
#include "Deck.h"

using namespace std;

class PlayerDeck {
public:
	PlayerDeck();
	void printPlayerDeck();
	list<Card> playerDeck;
	int score = 0;
	void sortPDeck();
	Card getAndRemoveByIndex(int index);
};