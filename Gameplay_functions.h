#pragma once
#include "Functions.h"
#include "Player.h"
#include "Enemies.h"
using namespace std;

int StartMenu() {
	cout << "�������� ��������:" << endl;
	cout << "1 - �������� ������� �� ����" << endl;
	cout << "2 - ������ ����" << endl;
	cout << "3 - ����� �� ����" << endl;
	return MakeChoise(3);
}

int Initialization() {
	cout << "�������� ����� ���������: " << endl;
	cout << "1 - ����" << endl;
	cout << "2 - ������" << endl;
	cout << "3 - ���" << endl;
	return MakeChoise(3);
}

Ring* GenRing(int type, int revive) {
	Ring* ring;
	switch (rand() % (4-revive)) {
	case 0:
		ring = new RingOfArmor;
		return ring;
	case 1:
		ring = new RingOfHealth;
		return ring;
	case 2:
		ring = new RingOfScale(type);
		return ring;
	case 3:
		ring = new RingOfReviving;
		return ring;
	}
}

void GenLoot(Player* player) {
	switch (rand() % 5) {
	case 0: {
		Weapon item(RarityGen(), player->level);
		cout << "�� �����: " << item.rang << player->weapon_name << ' ' << item.level << "-�� ������" << endl;
		cout << "����: " << item.damage << endl << endl;
		cout << "� ���: " << player->weapon.rang << player->weapon_name << ' ' << player->weapon.level << "-�� ������" << endl;
		cout << "����: " << player->weapon.damage << endl << endl;
		cout << "1 - ������� ������" << endl;
		cout << "2 - ������ ����" << endl;
		if (MakeChoise(2) == 1) {
			player->weapon.damage = item.damage;
			player->weapon.level = item.level;
			player->weapon.rang = item.rang;
			player->ShowStats();
		}
		break;
	}
	case 1: {
		Armor item (RarityGen());
		cout << "�� ����� " << item.rang << player->armor_name << endl;
		cout << "������: " << item.resist_physic_damage << endl;
		cout << "� ���: " << player->armor.rang << player->armor_name << endl;
		cout << "������: " << player->armor.resist_physic_damage << endl;
		cout << "1 - ������� �����" << endl;
		cout << "2 - ������ ����" << endl;
		if (MakeChoise(2) == 1) {
			player->armor.resist_physic_damage = item.resist_physic_damage;
			player->armor.rang = item.rang;
			player->ShowStats();
		}
		break;
	}
	case 2: {
		int num = rand() % 5 + 1;
		cout << "�� ����� ����� ��������: " << num << " ��." << endl;
		player->heal_potions_num += num;
		cout << "������ � ��� " << player->heal_potions_num << " ��. ����� ��������" << endl;
		break;
	}
	case 3: {
		int num = rand() % 3 + 1;
		cout << "�� ����� ����� ��������������: " << num << " ��." << endl;
		player->refill_potions_num += num;
		cout << "������ � ��� " << player->refill_potions_num << " ��. ����� ��������������" << endl;
		break;
	}
	case 4:
		Ring* ring = GenRing(player->type, player->revive);
		cout << "�� �����: " << ring->rang << ring->name << endl;
		cout << "�������� ��������:" << endl;
		cout << "1 - ������ ������" << endl;
		cout << "2 - �������� ������" << endl;
		if (MakeChoise(2) == 1) {
			player->TakeRing(*ring);
		}
	}
}

Enemy* GenEnemy(int level, int step) {
	Enemy* foe;
	int range = rand() % 4 + step / 20;
	switch (range) {
	case 0:
		foe = new Sceleton(level);
		break;
	case 1:
		foe = new Orc(level);
		break;
	case 2:
		foe = new Vampire(level);
		break;
	case 3:
		foe = new DarkElf(level);
		break;
	case 4:
		foe = new Witch(level);
		break;
	case 5:
		foe = new Ogre(level);
		break;
	case 6:
		foe = new Ent(level);
		break;
	case 7:
		foe = new Gargoyle(level);
		break;
	case 8:
		foe = new SpiderBoss(level);
		break;
	default:
		foe = new Dragon(level);
	}
	cout << "�� ��������� �����: " << foe->name << endl;
	return foe;
}

void Battle(Enemy* enemy, Player* player) {
	int choise = 0, impact = 0;
	bool foealive = true;
	while ((player->health > 0) && foealive) {
		cout << "�������� �����: " << enemy->health << '/' << enemy->healthmax << endl << endl;
		cout << "�������� ��������:" << endl;
		cout << "1 - ������� �����" << endl;
		cout << "2 - ������� ����� (10)" << endl;
		cout << "3 - ������ ����� (25)" << endl;
		cout << "4 - ������ ����� �������� (" << player->heal_potions_num << " ��.)" << endl;
		cout << "5 - ������ ����� �������������� (" << player->refill_potions_num << " ��.)" << endl;
		cout << endl << setw(15) << "��������: " << player->health << '/' << player->healthmax << endl;
		cout << setw(13) << player->scale_name << ": " << player->scale << '/' << player->scalemax << endl;
		do {
			choise = MakeChoise(5);
			switch (choise) {

			case 1:
				impact = player->GiveDamage(0) * (1 - enemy->armor*1. / 100);
				break;

			case 2:
				if (player->scale >= 10) {
					player->scale -= 10;
					cout << player->scale_name << ": " << player->scale << '/' << player->scalemax << endl << endl;
					impact = player->GiveDamage(1) * (1 - enemy->armor*1. / 100);
				}
				else {
					cout << player->scale_name << " - ������������" << endl;
					choise = 0;
				}
				break;

			case 3:
				if (player->scale >= 25) {
					player->scale -= 25;
					cout << player->scale_name << ": " << player->scale << '/' << player->scalemax << endl << endl;
					impact = player->GiveDamage(1) * (1 - enemy->armor*1. / 100);
				}
				else {
					cout << player->scale_name << " - ������������" << endl;
					choise = 0;
				}
				break;

			case 4:
				if ((player->heal_potions_num > 0) && (player->health < player->healthmax))
					player->Healing();
				else {
					cout << "�� ������� ���������� ��������" << endl;
				}
				cout << "� ��� �������� " << player->heal_potions_num << " ��. ����� ��������" << endl;
				choise = 0;
				break;

			case 5:
				if ((player->refill_potions_num > 0) && (player->scale < player->scalemax))
					player->Refilling();
				else {
					cout << "�� ������� ���������� " << player->scale_name << endl;
				}
				cout << "� ��� �������� " << player->refill_potions_num << " ��. ����� ��������������" << endl;
				choise = 0;
				break;
			}
		} while (choise == 0);

		cout << "�� ������� " << impact << " �����" << endl;
		enemy->health -= impact;
		if (enemy->health <= 0) {
			cout << "�� �����: " << enemy->name << endl << endl;
			player->GetExp(enemy->exp);
			delete enemy;
			foealive = false;
		}

		if (foealive) {
			impact = enemy->attack * (1 - player->armor_total*1./100);
			cout << "�������� �����: " << impact << endl;
			player->health -= impact;
			if (player->health < 0) {
				if (player->revive) {
					player->Reviving();
					cout << "��������: " << player->health << '/' << player->healthmax << endl;
					break;
				}
				else {
					cout << "��� ����: " << enemy->name << endl;
				}
				break;
			}
			else
				cout << "��������: " << player->health << '/' << player->healthmax << endl;
		}
		Separator(1, 250);
	}
}

void Event(int stepcounter, Player* player) {
	switch (stepcounter % 3) {
	case 0:
		GenLoot(player);
		break;
	default:
		int choise = 0;
		do {
			cout << "�������� ��������:" << endl;
			cout << "1 - �������� � ���" << endl;
			cout << "2 - ������� ������" << endl;
			cout << "3 - �������� ��������������" << endl;
			choise = MakeChoise(3);
			switch (choise) {

			case 1:
				Battle(GenEnemy(player->level, stepcounter), player);
				break;

			case 2:
				player->TeaTime();
				choise = 0;
				break;

			case 3:
				player->ShowStats();
				choise = 0;
				break;
			}
		} while (choise == 0);
	}
}