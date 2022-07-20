#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;


int MakeChoise(int lim) {
	int choise;
	bool done = false;
	while (!done) {
		cout << "Ваш выбор: ";
		cin >> choise;
		for (int i = 1; i <= lim; i++) {
			if (choise == i) {
				done = true;
				cout << endl;
				return choise;
			}
		}
	}
}

bool IfChance(int chance) {
	return chance > rand() % 100;
}

int RarityGen() {
	int rarity = (rand() % 100);
	if (rarity < 40)
		return 0;
	else if (rarity < 70)
		return 1;
	else if (rarity < 85)
		return 2;
	else if (rarity < 95)
		return 3;
	else
		return 4;
}

void Separator(int number = 1, int pause = 0) {
	Sleep(pause);
	for (int i = 0; i < number; i++) {
		cout << endl << "-----------------------------------";
	}
	cout << endl << endl;
}

void ShowHelp() {
	cout << "Добро пожаловать в игру The BGE!" << endl;
	cout << "В этой игре Вам предлагается управлять героем," << endl;
	cout << "совершая выбор одного из нескольких возможных действий." << endl;
	cout << "В игре присутствуют 3 класса: Воин, Лучник и Маг." << endl;
	cout << "Типы атак различаются наносимым уроном и расходуемой характеристикой" << endl;
	cout << "(Выносливость у Воина, Концентрация у лучника, Мана у Мага)." << endl;
	cout << "По ходу игры Вы найдёте сундуки, в которых может находится Броня, Оружие или зелья здоровья или восстановления." << endl;
	cout << "Защита брони зависит от её уровня редкости." << endl;
	cout << "Наносимый оружием урон зависит от его редкости и уровня." << endl;
	cout << "Вы можете восполнить здоровье или расходуемую характеристику в бою, использовав соответствующее зелье." << endl;
	cout << "Также Вы можете восполнить их на привале, но в этом случае обнуляется полученный опыт." << endl;
	Separator(3, 1000);
}

void YouDied() {
	cout << endl;
	cout << "  **        **     ****      **    **" << endl;
	cout << "   **      **     **  **     **    **" << endl;
	cout << "    **    **     **    **    **    **" << endl;
	cout << "      ****       **    **    **    **" << endl;
	cout << "       **        **    **    **    **" << endl;
	cout << "       **        **    **    **    **" << endl;
	cout << "       **         **  **      **  **" << endl;
	cout << "       **          ****        ****" << endl << endl;

	cout << "******      ******    ******    ******" << endl;
	cout << "**   **       **      **        **   **" << endl;
	cout << "**    **      **      **        **    **" << endl;
	cout << "**     **     **      **        **     **" << endl;
	cout << "**     **     **      ******    **     **" << endl;
	cout << "**    **      **      **        **    **" << endl;
	cout << "**   **       **      **        **   **" << endl;
	cout << "******      ******    ******    ******" << endl;
	getchar();
}