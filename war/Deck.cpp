#include "Deck.h"
Deck::Deck() {
	string allSuits[4] = { "Spade", "Heart", "Diamond", "Club" };
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		Card card = Card(allSuits[i], Value());
		cards[counter++] = card;
		string nextValue = ++card.value;
		while (nextValue != "2") {
			cards[counter] = Card(allSuits[i], nextValue);
			nextValue = ++cards[counter++].value;
		}
	}
}

void Deck::shuffleCards() {
	vector<int> positions;
	for (int i = 0; i < 52; i++) {
		positions.push_back(i);
	}
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(begin(positions), end(positions), default_random_engine(seed));
	Card deckCopy[52] = {};
	int counter = 0;
	while (counter < 52) {
		for (auto i : positions) {
			deckCopy[counter] = cards[positions[counter]];
			counter++;
		}
	}
	for (int j = 0; j < 52; j++) {
		cards[j] = deckCopy[j];
	}
}

void Deck::printDeck() {
	for (int i = 0; i < 52; i++) {
		cout << cards[i] << endl;
	}
}