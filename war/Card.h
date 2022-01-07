#pragma once
#include <stdio.h>
#include "Value.h"

using namespace std;
class Card {
public:
	Card();
	Card(string suitC, Value valueC);
	string suit;
	Value value;
	friend ostream& operator<<(ostream& os, Card c1);
	friend int operator<(Card c1, Card c2);
};