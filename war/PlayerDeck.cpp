#include "PlayerDeck.h"

PlayerDeck::PlayerDeck(){}

void PlayerDeck::printPlayerDeck()
{
	int n = 0;
	for (auto it = playerDeck.begin(); it != playerDeck.end(); ++it) {
		cout << (*it).value.value << " " << (*it).suit << " ("<< n << ") | ";
		n++;
		if (n % 10 == 0 && n != 0) {
			cout << endl;
		}
	}
}

void PlayerDeck::sortPDeck()
{
	playerDeck.sort([](Card c1, Card c2)
		{
			return (c1 < c2) == 1;
		}
	);
}

Card PlayerDeck::getAndRemoveByIndex(int index)
{
	auto it = playerDeck.begin();
	advance(it, index);
	Card copyCard = Card((*it).suit, (*it).value);
	playerDeck.erase(it);
	return copyCard;
}
