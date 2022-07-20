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
			class_name = "����";
			armor_name = "������";
			weapon_name = "���";
			mainstat_name = "����";
			scale_name = "������������";
			break;
		case 2:
			class_name = "������";
			armor_name = "����";
			weapon_name = "���";
			mainstat_name = "��������";
			scale_name = "������������";
			break;
		case 3:
			class_name = "���";
			armor_name = "�������";
			weapon_name = "�����";
			mainstat_name = "��������";
			scale_name = "����";
			break;
		}
	}

	void GetExp(int num) {
		cout << endl << "�������� �����: " << num << endl;
		exp += num;
		while (exp >= levelcap) {
			level++;
			exp -= levelcap;
			levelcap += 100;
			if (mainstat < 70)
				mainstat += 1;
			scale = scalemax += 5;
			health = healthmax;
			cout << "������� �������! ������� �������: " << level << endl;
			cout << scale_name << " ��������! ������� ��������: " << scalemax << endl;
		}
		cout << "����: " << exp << '/' << levelcap << endl;
	}

	int GiveDamage(int type) {
		int impact = weapon.damage + mainstat * type;
		if (IfChance(mainstat)) {
			cout << "����������� ����!" << endl;
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
		cout << "�������� ���������� (" << 25 << " ��.)" << endl;
		cout << "������� ��������: " << health << '/' << healthmax << endl;
	}

	void Refilling() {
		scale += 10 * level;
		refill_potions_num -= 1;
		if (scale > scalemax)
			scale = scalemax;
		cout << scale_name << " ���������� (" << 10 * level << " ��.)" << endl;
		cout << "������� " << scale_name << ": " << scale << '/' << scalemax << endl;
	}

	void ShowRings() {
		if (rings_num == 0) {
			cout << "����� ���" << endl << endl;
		}
		else {
			cout << "������:" << endl;
			for (int i = 0; i < rings_num; i++) {
				cout << setw(21) << rings[i].name << endl;
			}
			cout << endl;
		}
	}

	void ShowStats() {
		cout << "���� ��������������:" << endl;
		cout << setw(15) << "�����: " << class_name << endl;
		cout << setw(15) << "�������: " << level << endl;
		cout << setw(15) << "����: " << exp << '/' << levelcap << endl;
		cout << setw(15) << "��������: " << health << '/' << healthmax << endl;
		cout << setw(13) << scale_name << ": " << scale << '/' << scalemax << endl;
		cout << setw(13) << mainstat_name << ": " << mainstat << endl << endl;
		cout << "������� ������: " << weapon.rang << weapon_name << endl;
		cout << "          ����: " << weapon.damage << endl;
		cout << " ������� �����: " << armor.rang << armor_name << endl;
		cout << "  ������ �����: " << armor.resist_physic_damage << endl;
		cout << "  ����� ������: " << armor_total << endl << endl;
		ShowRings();
		cout << "      ����� ��������: " << heal_potions_num << endl;
		cout << "����� ��������������: " << refill_potions_num << endl << endl;
		Separator();
	}

	void TakeRing(Ring ring) {
		if (rings_num == 5) {
			cout << "� ��� ������������ ���������� �����!" << endl;
			ShowRings();
			cout << "�������� ���� �� �����?";
			cout << "1 - ��" << endl;
			cout << "2 - ���" << endl;
			if (MakeChoise(2) == 1) {
				cout << "������� ����� ������, ������� ������ ��������" << endl;
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
		cout << "�������������� �������������!" << endl;
		ShowStats();
	}

	void Reviving() {
		health = healthmax * 0.5;
		revive = false;
		cout << "��������� ������ �����������!" << endl;
		rings[revive_index].name = "������ ����������� (������������)";
	}

	Armor armor;
	Weapon weapon;
	Ring rings[5];
	bool revive;
	int mainstat, scale, scalemax, levelcap, heal_potions_num = 0, refill_potions_num = 0, type, rings_num = 0, revive_index, armor_total = 0;
	string class_name, armor_name, weapon_name, mainstat_name, scale_name;
};