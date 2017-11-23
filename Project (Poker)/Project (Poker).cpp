#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Cards.h"
using namespace std;

class local {
public: local() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
}l;

class Player {
	char* Name;
	double bank;
	Cards *onHands; int top;
	int countOfCards;
public:
	Player() : Name(nullptr), bank(0), countOfCards(0), onHands(new Cards[2]) {}
	Player(char* name, double cash) : Player() { setName(name); setBank(cash); }
	Player(Player& P) :Player(P.Name, P.bank) {}
	~Player() { if (Name) delete[] Name; }

	// Getters
	char* getName() const { return Name; }
	double getBank() const { return bank; }
	void addCash(double v) { bank += v; }

	// Setters
	void setName(char* name) {
		if (!name) return;
		int size = strlen(name);
		if (Name) delete[] Name;
		Name = new char[size + 1];
		strcpy(Name, name);
	}
	void setBank(double v) {
		if (v <= 0) return;
		bank = v;
	}

	void getCard(Cards C) {
		if (countOfCards == 2) { cout << "Больше двух карт иметь нальзя!\n"; return; }
		onHands[countOfCards++] = C;
	}

	void showCards() {
		for (int i = 0; i < countOfCards; i++)
			cout << " | " << ToString(onHands[i]);
		cout << endl;
	}

	double Stavka(double cash) {
		if (cash <= 0) throw "У игрока нет денег!\n";
		else if (cash > bank) throw "У игрока нет такой суммы!\n";
		else bank -= cash;
		return cash;
	}

	double VaBank() {
		if (bank <= 0) throw "У игрока нет денег!\n";
		double temp = bank;
		bank = 0;
		return temp;
	}

	void showCash() { cout << bank << '$' << endl; }
	void showName() { cout << Name << endl; }

};


void createPlayer(Player &p) {
	char buffer[255];
	double tempCash;

	cout << "Введите имя игрока: "; cin >> buffer;
	cout << "Начальный бюджет? "; cin >> tempCash;
	p.setName(buffer); p.setBank(tempCash);
}

void Game(Player& player) {
	double tokens;
	Cards stol[5];

	Koloda koloda;
	cout << "Прошу за стол "; player.showName(); cout << endl;

	player.getCard(koloda.getCard());
	player.getCard(koloda.getCard());

	cout << "Ваши карты: "; player.showCards();
	cout << "Введите вашу начальную ставку: "; cin >> tokens;
	player.Stavka(tokens);
	cout << "Ваша ставка " << tokens << "$\n";

	cout << "\tИгральный стол\n/// ";
	for (int i = 0; i < 5; i++) {
		stol[i] = koloda.getCard();
		cout << ToString(stol[i]) << " ";
	} cout << "\b\\\\\\\n";



}

void StartNewGame() {
	Player p1;
	createPlayer(p1);
	Game(p1);
}

int main()
{
	StartNewGame();
}

