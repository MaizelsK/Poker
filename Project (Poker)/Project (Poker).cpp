#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <vector>
#include <array>
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
	void addCash(double v) { bank += v; }
	int getScore() const { return score; }

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

void Reveal(int userScore, int botScore) {

}

void createPlayer(Player &p) {
	char buffer[255];
	double tempCash;

	cout << "Введите имя игрока: "; cin >> buffer;
	cout << "Начальный бюджет? "; cin >> tempCash;
	p.setName(buffer); p.setBank(tempCash);
	system("cls");
}

Player bot("Microsoft", 20000);

void Game(Player& player) {
	double tokens, pool;
	array<Cards, 5> stol;

	Koloda koloda;
	bot.getCard(koloda.getCard());
	bot.getCard(koloda.getCard());

	cout << "Прошу за стол "; player.showName(); cout << endl;
	system("pause"); system("cls");

	player.getCard(koloda.getCard());
	player.getCard(koloda.getCard());

	cout << "Ваши карты: "; player.showCards();
	cout << "Введите вашу ставку: "; cin >> tokens;
	player.Stavka(tokens);
	cout << "Ваша ставка " << tokens << "$\n";

	cout << "\nДиллер клаедет пять карт на стол...\n\n///";
	for (int i = 0; i < 5; i++) {
		stol[i] = koloda.getCard();
		cout << ToString(stol[i]) << " |";
	} cout << "\b\b\\\\\\\n";

	bool reveal = false;
	int vibor;
	do {

		if (bot.getBank != 0) { cout << bot.getName() << " сделал ставку в размере 400$\n"; bot.Stavka(400); }
		else Reveal(player.getScore(), bot.getScore());

		do {
			cout << "\nВаш ход\nПас(1), Ставка(2), ВаБанк!(3)\nВаше действие: "; cin >> vibor;
			if (vibor < 1 && vibor>3) cout << "Ошибка, введите свой выбор снова!\n";
		} while (vibor < 1 && vibor>3);

		switch (vibor) {
		case 1: cout << player.getName() << " пас..\n"; break;

		case 2: cout << "Введите вашу ставку: "; cin >> tokens;
			player.Stavka(tokens); break;

		case 3: cout << player.getName() << " делает ВаБанк!\n"; player.VaBank(); break;
		} //switch(vibor)

		cout << "Введите вашу ставку: "; cin >> tokens;
		player.Stavka(tokens);

	} while (player.getBank() != 0 || bot.getBank() != 0 || reveal == true);

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

