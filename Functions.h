#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;


int MakeChoise(int lim) {
	int choise;
	bool done = false;
	while (!done) {
		cout << "��� �����: ";
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
	cout << "����� ���������� � ���� The BGE!" << endl;
	cout << "� ���� ���� ��� ������������ ��������� ������," << endl;
	cout << "�������� ����� ������ �� ���������� ��������� ��������." << endl;
	cout << "� ���� ������������ 3 ������: ����, ������ � ���." << endl;
	cout << "���� ���� ����������� ��������� ������ � ����������� ���������������" << endl;
	cout << "(������������ � �����, ������������ � �������, ���� � ����)." << endl;
	cout << "�� ���� ���� �� ������ �������, � ������� ����� ��������� �����, ������ ��� ����� �������� ��� ��������������." << endl;
	cout << "������ ����� ������� �� � ������ ��������." << endl;
	cout << "��������� ������� ���� ������� �� ��� �������� � ������." << endl;
	cout << "�� ������ ���������� �������� ��� ����������� �������������� � ���, ����������� ��������������� �����." << endl;
	cout << "����� �� ������ ���������� �� �� �������, �� � ���� ������ ���������� ���������� ����." << endl;
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