#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Card.h"
using namespace std;
class Deck {
public:
	Deck();
	Card cards[52];
	void shuffleCards();
	int nbCards = 52;
	void printDeck();
};