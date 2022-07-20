#pragma once
#include <iomanip>
#include "Creature.h"
#include "Equipment.h"
#include "Rings.h"

class Player :public Creature {
public:
	Player(){}
	void SetStats(int tp, int maxhp, Armor item1, Weapon item2) {
		healthmax = health = maxhp;
		armor = item1;
		weapon = item2;
		mainstat = 20;
		scalemax = scale = mainstat * 5;
		exp = 0;
		level = 0;
		levelcap = 100;
		armor_total = armor.resist_physic_damage;
		type = tp;
		revive = false;
		switch (type) {
		case 1:
			class_name = "Воин";
			armor_name = "доспех";
			weapon_name = "меч";
			mainstat_name = "Сила";
			scale_name = "Выносливость";
			break;
		case 2:
			class_name = "Лучник";
			armor_name = "плащ";
			weapon_name = "лук";
			mainstat_name = "Ловкость";
			scale_name = "Концентрация";
			break;
		case 3:
			class_name = "Маг";
			armor_name = "балахон";
			weapon_name = "посох";
			mainstat_name = "Мудрость";
			scale_name = "Мана";
			break;
		}
	}

	void GetExp(int num) {
		cout << endl << "Получено опыта: " << num << endl;
		exp += num;
		while (exp >= levelcap) {
			level++;
			exp -= levelcap;
			levelcap += 100;
			if (mainstat < 70)
				mainstat += 1;
			scale = scalemax += 5;
			health = healthmax;
			cout << "Уровень повышен! Текущий уровень: " << level << endl;
			cout << scale_name << " повышена! Текущее значение: " << scalemax << endl;
		}
		cout << "Опыт: " << exp << '/' << levelcap << endl;
	}

	int GiveDamage(int type) {
		int impact = weapon.damage + mainstat * type;
		if (IfChance(mainstat)) {
			cout << "Критический урон!" << endl;
			return 1.5 * impact;
		}
		else
			return impact;
	}

	void Healing() {
		health += 25;
		heal_potions_num -= 1;
		if (health > healthmax)
			health = healthmax;
		cout << "Здоровье восполнено (" << 25 << " ед.)" << endl;
		cout << "Текущее здоровье: " << health << '/' << healthmax << endl;
	}

	void Refilling() {
		scale += 10 * level;
		refill_potions_num -= 1;
		if (scale > scalemax)
			scale = scalemax;
		cout << scale_name << " восполнена (" << 10 * level << " ед.)" << endl;
		cout << "Текущая " << scale_name << ": " << scale << '/' << scalemax << endl;
	}

	void ShowRings() {
		if (rings_num == 0) {
			cout << "Колец нет" << endl << endl;
		}
		else {
			cout << "Кольца:" << endl;
			for (int i = 0; i < rings_num; i++) {
				cout << setw(21) << rings[i].name << endl;
			}
			cout << endl;
		}
	}

	void ShowStats() {
		cout << "Ваши характеристики:" << endl;
		cout << setw(15) << "Класс: " << class_name << endl;
		cout << setw(15) << "Уровень: " << level << endl;
		cout << setw(15) << "Опыт: " << exp << '/' << levelcap << endl;
		cout << setw(15) << "Здоровье: " << health << '/' << healthmax << endl;
		cout << setw(13) << scale_name << ": " << scale << '/' << scalemax << endl;
		cout << setw(13) << mainstat_name << ": " << mainstat << endl << endl;
		cout << "Текущее оружие: " << weapon.rang << weapon_name << endl;
		cout << "          Урон: " << weapon.damage << endl;
		cout << " Текущая броня: " << armor.rang << armor_name << endl;
		cout << "  Защита брони: " << armor.resist_physic_damage << endl;
		cout << "  Общая защита: " << armor_total << endl << endl;
		ShowRings();
		cout << "      Зелий здоровья: " << heal_potions_num << endl;
		cout << "Зелий восстановления: " << refill_potions_num << endl << endl;
		Separator();
	}

	void TakeRing(Ring ring) {
		if (rings_num == 5) {
			cout << "У вас максимальное количество колец!" << endl;
			ShowRings();
			cout << "Заменить одно из колец?";
			cout << "1 - Да" << endl;
			cout << "2 - Нет" << endl;
			if (MakeChoise(2) == 1) {
				cout << "Введите номер кольца, которое хотите заменить" << endl;
				int res = MakeChoise(5) - 1;
				switch (rings[res].type) {
				case 0:
					healthmax -= rings[res].increasing;
					break;
				case 1:
					armor_total -= rings[res].increasing;
					break;
				case 2:
					scalemax -= rings[res].increasing;
					break;
				case 3:
					revive = false;
					break;
				}
				rings[res] = ring;
				switch (rings[res].type) {
				case 0:
					healthmax += rings[res].increasing;
					break;
				case 1:
					armor_total += rings[res].increasing;
					break;
				case 2:
					scalemax += rings[res].increasing;
					break;
				case 3:
					revive = true;
					revive_index = res;
					break;
				}
			}
		}
		else {
			rings[rings_num] = ring;
			switch (rings[rings_num].type) {
			case 0:
				healthmax += rings[rings_num].increasing;
				break;
			case 1:
				armor_total += rings[rings_num].increasing;
				break;
			case 2:
				scalemax += rings[rings_num].increasing;
				break;
			case 3:
				revive = true;
				revive_index = rings_num;
				break;
			}
			rings_num++;
		}
	}

	void TeaTime() {
		health = healthmax;
		scale = scalemax;
		exp = 0;
		cout << "Характеристики восстановлены!" << endl;
		ShowStats();
	}

	void Reviving() {
		health = healthmax * 0.5;
		revive = false;
		cout << "Сработало кольцо возрождения!" << endl;
		rings[revive_index].name = "Кольцо возрождения (использовано)";
	}

	Armor armor;
	Weapon weapon;
	Ring rings[5];
	bool revive;
	int mainstat, scale, scalemax, levelcap, heal_potions_num = 0, refill_potions_num = 0, type, rings_num = 0, revive_index, armor_total = 0;
	string class_name, armor_name, weapon_name, mainstat_name, scale_name;
};