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

// �������� ����� � ������
void Player::getCard(Cards C) {
	if (countOfCards == 2) { cout << "������ ���� ���� ����� ������!\n"; return; }
	onHands[countOfCards++] = C;
}

// ����� ���� ������
void Player::showCards() {
	for (int i = 0; i < countOfCards; i++)
		cout << " | " << ToString(onHands[i]);
	cout << endl;
}

// ������� ������
double Player::Stavka(double cash) {
	if (cash <= 0) { cout << "� ������ ��� �����!\n"; return -2; }
	else if (cash > bank) { cout << "� ������ ��� ����� �����!\n"; return -1; }
	else bank -= cash;
	return cash;
}

// ��������� ��� �����
double Player::VaBank() {
	if (bank <= 0) throw "� ������ ��� �����!\n";
	double temp = bank;
	bank = 0;
	return temp;
}