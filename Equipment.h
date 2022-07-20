#pragma once

class Equipment {
public:
	Equipment() {}
	Equipment(int rarity) {
		switch (rarity) {
		case 0:
			rang = "Плохой ";
			break;
		case 1:
			rang = "Обычный ";
			break;
		case 2:
			rang = "Хороший ";
			break;
		case 3:
			rang = "Редкий ";
			break;
		case 4:
			rang = "Легендарный ";
			break;
		}
	}
	Equipment(int rarity, int lvl) {
		level = lvl;
		switch (rarity) {
		case 0:
			rang = "Плохой ";
			break;
		case 1:
			rang = "Обычный ";
			break;
		case 2:
			rang = "Хороший ";
			break;
		case 3:
			rang = "Редкий ";
			break;
		case 4:
			rang = "Легендарный ";
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