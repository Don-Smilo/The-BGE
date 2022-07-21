#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;


int MakeChoise(int lim) {
	int choise;
	bool done = false;
	while (!done) {
		cout << "Âàø âûáîð: ";
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
	cout << "Äîáðî ïîæàëîâàòü â èãðó The BGE!" << endl;
	cout << "Â ýòîé èãðå Âàì ïðåäëàãàåòñÿ óïðàâëÿòü ãåðîåì," << endl;
	cout << "ñîâåðøàÿ âûáîð îäíîãî èç íåñêîëüêèõ âîçìîæíûõ äåéñòâèé." << endl;
	cout << "Â èãðå ïðèñóòñòâóþò 3 êëàññà: Âîèí, Ëó÷íèê è Ìàã." << endl;
	cout << "Òèïû àòàê ðàçëè÷àþòñÿ íàíîñèìûì óðîíîì è ðàñõîäóåìîé õàðàêòåðèñòèêîé" << endl;
	cout << "(Âûíîñëèâîñòü ó Âîèíà, Êîíöåíòðàöèÿ ó ëó÷íèêà, Ìàíà ó Ìàãà)." << endl;
	cout << "Ïî õîäó èãðû Âû íàéä¸òå ñóíäóêè, â êîòîðûõ ìîæåò íàõîäèòñÿ Áðîíÿ, Îðóæèå èëè çåëüÿ çäîðîâüÿ èëè âîññòàíîâëåíèÿ." << endl;
	cout << "Çàùèòà áðîíè çàâèñèò îò å¸ óðîâíÿ ðåäêîñòè." << endl;
	cout << "Íàíîñèìûé îðóæèåì óðîí çàâèñèò îò åãî ðåäêîñòè è óðîâíÿ." << endl;
	cout << "Âû ìîæåòå âîñïîëíèòü çäîðîâüå èëè ðàñõîäóåìóþ õàðàêòåðèñòèêó â áîþ, èñïîëüçîâàâ ñîîòâåòñòâóþùåå çåëüå." << endl;
	cout << "Òàêæå Âû ìîæåòå âîñïîëíèòü èõ íà ïðèâàëå, íî â ýòîì ñëó÷àå îáíóëÿåòñÿ ïîëó÷åííûé îïûò." << endl;
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
	cout << "       **         **  **      **  **"  << endl;
	cout << "       **          ****        ****"   << endl << endl;

	cout << "******      ******    ******    ******"    << endl;
	cout << "**   **       **      **        **   **"   << endl;
	cout << "**    **      **      **        **    **"  << endl;
	cout << "**     **     **      **        **     **" << endl;
	cout << "**     **     **      ******    **     **" << endl;
	cout << "**    **      **      **        **    **"  << endl;
	cout << "**   **       **      **        **   **"   << endl;
	cout << "******      ******    ******    ******"    << endl;
}
