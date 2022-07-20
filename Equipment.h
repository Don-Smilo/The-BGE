#pragma once

class Equipment {
public:
	Equipment() {}
	Equipment(int rarity) {
		switch (rarity) {
		case 0:
			rang = "������ ";
			break;
		case 1:
			rang = "������� ";
			break;
		case 2:
			rang = "������� ";
			break;
		case 3:
			rang = "������ ";
			break;
		case 4:
			rang = "����������� ";
			break;
		}
	}
	Equipment(int rarity, int lvl) {
		level = lvl;
		switch (rarity) {
		case 0:
			rang = "������ ";
			break;
		case 1:
			rang = "������� ";
			break;
		case 2:
			rang = "������� ";
			break;
		case 3:
			rang = "������ ";
			break;
		case 4:
			rang = "����������� ";
			break;
		}
	}
	int level;
	string rang;
};

class Armor :public Equipment {
public:
	Armor() {}
	Armor(int rarity):Equipment(rarity) {
		resist_physic_damage = 20 + rarity * 10;
	}
	int resist_physic_damage;
};

class Weapon :public Equipment {
public:
	Weapon() {}
	Weapon(int rarity, int lvl):Equipment(rarity, lvl) {
		damage = 30 + rarity * 5 + lvl * 10;
	}
	int damage=0;
};

class HillPotion {

};

class RefillPotion {

};