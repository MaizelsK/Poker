#pragma once
#pragma once
#include <iostream>
#include <array>
#include "Deck.h"
using namespace std;

class Player {
	char* Name;
	double bank;
	array<Cards, 2> onHands;
	int countOfCards, score;

public:
	Player() : Name(nullptr), bank(0), countOfCards(0), score(0) {}
	Player(char* name, double cash) : Player() { setName(name); setBank(cash); }
	Player(Player& P) : Player(P.Name, P.bank) {
		onHands = { P.onHands[0], P.onHands[1] };
		countOfCards = P.countOfCards;
		score = P.score;
	}
	~Player() { if (Name) delete[] Name; }

	// Getters
	char* getName() const { return Name; }
	double getBank() const { return bank; }
	int getScore() const { return score; }

	//--------
	void addCash(double v) { bank += v; }
	void addScore(int v) { score += v; }
	//--------

	void showCash() { cout << bank << '$' << endl; }
	void showName() { cout << Name << endl; }

	Cards operator[](int i) { return onHands[i]; }

	// <Setters>
	void setName(char* name);

	void setBank(double v);
	// </Setters>

	void getCard(Cards C);

	void showCards();

	double Stavka(double cash);

	double VaBank();
};