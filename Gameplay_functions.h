#pragma once
#include "Functions.h"
#include "Player.h"
#include "Enemies.h"
using namespace std;

int StartMenu() {
	cout << "Выберете действие:" << endl;
	cout << "1 - Показать справку по игре" << endl;
	cout << "2 - Начать игру" << endl;
	cout << "3 - Выйти из игры" << endl;
	return MakeChoise(3);
}

int Initialization() {
	cout << "Выберите класс персонажа: " << endl;
	cout << "1 - Воин" << endl;
	cout << "2 - Лучник" << endl;
	cout << "3 - Маг" << endl;
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
		cout << "Вы нашли: " << item.rang << player->weapon_name << ' ' << item.level << "-го уровня" << endl;
		cout << "Урон: " << item.damage << endl << endl;
		cout << "У вас: " << player->weapon.rang << player->weapon_name << ' ' << player->weapon.level << "-го уровня" << endl;
		cout << "Урон: " << player->weapon.damage << endl << endl;
		cout << "1 - сменить оружие" << endl;
		cout << "2 - пройти мимо" << endl;
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
		cout << "Вы нашли " << item.rang << player->armor_name << endl;
		cout << "Защита: " << item.resist_physic_damage << endl;
		cout << "У вас: " << player->armor.rang << player->armor_name << endl;
		cout << "Защита: " << player->armor.resist_physic_damage << endl;
		cout << "1 - сменить броню" << endl;
		cout << "2 - пройти мимо" << endl;
		if (MakeChoise(2) == 1) {
			player->armor.resist_physic_damage = item.resist_physic_damage;
			player->armor.rang = item.rang;
			player->ShowStats();
		}
		break;
	}
	case 2: {
		int num = rand() % 5 + 1;
		cout << "Вы нашли зелье здоровья: " << num << " шт." << endl;
		player->heal_potions_num += num;
		cout << "Теперь у вас " << player->heal_potions_num << " шт. зелий здоровья" << endl;
		break;
	}
	case 3: {
		int num = rand() % 3 + 1;
		cout << "Вы нашли зелье восстановления: " << num << " шт." << endl;
		player->refill_potions_num += num;
		cout << "Теперь у вас " << player->refill_potions_num << " шт. зелий восстановления" << endl;
		break;
	}
	case 4:
		Ring* ring = GenRing(player->type, player->revive);
		cout << "Вы нашли: " << ring->rang << ring->name << endl;
		cout << "Выберите действие:" << endl;
		cout << "1 - Надеть кольцо" << endl;
		cout << "2 - Оставить кольцо" << endl;
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
	cout << "Вы встретили врага: " << foe->name << endl;
	return foe;
}

void Battle(Enemy* enemy, Player* player) {
	int choise = 0, impact = 0;
	bool foealive = true;
	while ((player->health > 0) && foealive) {
		cout << "Здоровье врага: " << enemy->health << '/' << enemy->healthmax << endl << endl;
		cout << "Выберите действие:" << endl;
		cout << "1 - Обычная атака" << endl;
		cout << "2 - Сильная атака (10)" << endl;
		cout << "3 - Мощная атака (25)" << endl;
		cout << "4 - Выпить зелье здоровья (" << player->heal_potions_num << " шт.)" << endl;
		cout << "5 - Выпить зелье восстановления (" << player->refill_potions_num << " шт.)" << endl;
		cout << endl << setw(15) << "Здоровье: " << player->health << '/' << player->healthmax << endl;
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
					cout << player->scale_name << " - недостаточно" << endl;
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
					cout << player->scale_name << " - недостаточно" << endl;
					choise = 0;
				}
				break;

			case 4:
				if ((player->heal_potions_num > 0) && (player->health < player->healthmax))
					player->Healing();
				else {
					cout << "Не удалось восполнить здоровье" << endl;
				}
				cout << "У вас осталось " << player->heal_potions_num << " шт. зелий здоровья" << endl;
				choise = 0;
				break;

			case 5:
				if ((player->refill_potions_num > 0) && (player->scale < player->scalemax))
					player->Refilling();
				else {
					cout << "Не удалось восполнить " << player->scale_name << endl;
				}
				cout << "У вас осталось " << player->refill_potions_num << " шт. зелий восстановления" << endl;
				choise = 0;
				break;
			}
		} while (choise == 0);

		cout << "Вы нанесли " << impact << " урона" << endl;
		enemy->health -= impact;
		if (enemy->health <= 0) {
			cout << "Вы убили: " << enemy->name << endl << endl;
			player->GetExp(enemy->exp);
			delete enemy;
			foealive = false;
		}

		if (foealive) {
			impact = enemy->attack * (1 - player->armor_total*1./100);
			cout << "Получено урона: " << impact << endl;
			player->health -= impact;
			if (player->health < 0) {
				if (player->revive) {
					player->Reviving();
					cout << "Здоровье: " << player->health << '/' << player->healthmax << endl;
					break;
				}
				else {
					cout << "Вас убил: " << enemy->name << endl;
				}
				break;
			}
			else
				cout << "Здоровье: " << player->health << '/' << player->healthmax << endl;
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
			cout << "Выберите действие:" << endl;
			cout << "1 - Вступить в бой" << endl;
			cout << "2 - Сделать привал" << endl;
			cout << "3 - Показать характеристики" << endl;
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