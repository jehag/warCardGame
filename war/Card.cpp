#include "Card.h"

Card::Card() {
	suit = "Spade";
	value = Value();
}

Card::Card(string suitC, Value valueC) {
	suit = suitC;
	value = valueC;
}

ostream& operator<<(ostream& os, Card c1)
{
	os << c1.value.value << " " << c1.suit;
	return os;
}

int operator<(Card c1, Card c2)
{
	return c1.value < c2.value;
}
