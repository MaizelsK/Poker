#include <iostream>
#include <Windows.h>
#include <vector>
#include <array>
#include "Deck.h"
#include "Player.h"
using namespace std;

class local {
public: local() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
}l;

void Reveal(Player& user, Player& bot, array<Cards, 5> table) {
	user.addScore(GET_RANG(user[0]) + GET_RANG(user[1]));
	bot.addScore(GET_RANG(bot[0]) + GET_RANG(bot[1]));

	if (user.getScore() > bot.getScore()) {
		cout << "***************\n";
		cout << user.getName() << " выигрывает по рангу карт: "
			<< ToString(user[0]) << " | " << ToString(user[1]) << endl;
		cout << "***************\n";

		cout << "\nКарты " << bot.getName() << ": "
			<< ToString(bot[0]) << " | " << ToString(bot[1]) << "\n\n";
	}
	else {
		cout << "***************\n";
		cout << bot.getName() << " выигрывает по рангу карт: "
			<< ToString(bot[0]) << " | " << ToString(bot[1]) << endl;
		cout << "***************\n";

		cout << "\nКарты " << user.getName() << ": "
			<< ToString(user[0]) << " | " << ToString(user[1]) << "\n\n";
	}
}

void showTable(array<Cards, 5> tableCards) {
	cout << "///";
	for (int i = 0; i < 5; i++) {
		cout << ToString(tableCards[i]) << " |";
	} cout << "\b\b\\\\\\\n\n";
}

void createPlayer(Player &p) {
	char buffer[255];
	double tempCash;

	cout << "Введите имя игрока: "; cin >> buffer;
	cout << "Начальный бюджет? "; cin >> tempCash;
	p.setName(buffer); p.setBank(tempCash);
	system("cls");
}


void Game(Player& player) {
	double tokens, pool = 0;
	array<Cards, 5> stol;
	Player bot("Microsoft", 2000);

	Koloda koloda;
	bot.getCard(koloda.getCard());
	bot.getCard(koloda.getCard());
	for (int i = 0; i < 5; i++) { stol[i] = koloda.getCard(); }

	cout << "Прошу за стол "; player.showName(); cout << endl;
	system("pause"); system("cls");

	player.getCard(koloda.getCard());
	player.getCard(koloda.getCard());

	cout << "Диллер кладет пять карт на стол...\n\n"; system("pause");
	int vibor;
	do {
		system("cls");
		if (player.getBank() == 0) { Reveal(player, bot, stol); break; }
		if (bot.getBank() == 0) {
			cout << "У " << bot.getName() << " нет больше денег, вскрываемся!\n";
			Reveal(player, bot, stol); break;
		}

		showTable(stol);
		cout << "\t\t" << pool << "$\n\n";


		cout << bot.getName() << " сделал ставку в размере 400$\n\n"; pool += bot.Stavka(400);

		cout << "------------\nВаши карты: "; player.showCards();
		do {
			cout << "Ваш ход\nПас(1), Ставка(2), ВаБанк!(3)\nВаше действие: "; cin >> vibor;
			if (vibor < 1 || vibor>3) cout << "Ошибка, введите доступное действие!\n";
		} while (vibor != 1 && vibor != 2 && vibor != 3);
		cout << "------------\n";

		switch (vibor) {
		case 1: cout << player.getName() << " пас..\n"; system("pause"); break;

		case 2: do { // Пока не введут доступную сумму
			cout << "Введите вашу ставку: "; cin >> tokens;
			if (tokens > player.getBank()) { cout << "У вас нет столько денег..., введите другую сумму\n"; }
			else { pool += player.Stavka(tokens); break; }
		} while (true); system("pause"); break;

		case 3: cout << player.getName() << " делает ВаБанк!\n"; pool += player.VaBank(); system("pause"); break;
		} //switch(vibor)

	} while (true);

}

void StartNewGame() {
	do {
		system("cls");
		Player p1;
		createPlayer(p1);
		Game(p1);

		int choice;
		cout << "Спасибо за игру, не желаете сыграть еще раз?" <<
			"\nНачать новую игру (1)" <<
			"\nВыход (!1)"; cin >> choice;
		if (choice != 1) break;
	} while (true);
}

int main()
{
	system("color 2f");
	StartNewGame();
}