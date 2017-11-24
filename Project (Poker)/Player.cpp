#include <iostream>
#include "Player.h"
using namespace std;

// <Setters>
void Player::setName(char* name) {
	if (!name) return;
	int size = strlen(name);
	if (Name) delete[] Name;
	Name = new char[size + 1];
	strcpy(Name, name);
}
void Player::setBank(double v) {
	if (v <= 0) return;
	bank = v;
}
// </Setters>

// Получить карту с колоды
void Player::getCard(Cards C) {
	if (countOfCards == 2) { cout << "Больше двух карт иметь нальзя!\n"; return; }
	onHands[countOfCards++] = C;
}

// Показ карт игрока
void Player::showCards() {
	for (int i = 0; i < countOfCards; i++)
		cout << " | " << ToString(onHands[i]);
	cout << endl;
}

// Сделать ставку
double Player::Stavka(double cash) {
	if (cash <= 0) { cout << "У игрока нет денег!\n"; return -2; }
	else if (cash > bank) { cout << "У игрока нет такой суммы!\n"; return -1; }
	else bank -= cash;
	return cash;
}

// Поставить всю сумму
double Player::VaBank() {
	if (bank <= 0) throw "У игрока нет денег!\n";
	double temp = bank;
	bank = 0;
	return temp;
}