#pragma once

class Enemy :public Creature {
public:
	Enemy() {}
	Enemy(int lvl) {
		level = lvl;
		health_coef = 1 + level*1. / 10;
		attack_coef = level * 10;
		exp_coef = level * 10;
	}

	int attack = 0, armor = 0;
	string name;
protected:
	int health_coef, attack_coef, exp_coef;
};

class Sceleton : public Enemy {
public:
	Sceleton(int lvl) : Enemy (lvl) {
		level = lvl;
		healthmax = health = 85*health_coef;
		exp = 25 + exp_coef;
		attack = 25 + attack_coef;
		armor = 10;
		name = "Скелет";
	}
};

class Witch : public Enemy {
public:
	Witch(int lvl) : Enemy(lvl) {
		level = lvl;
		healthmax = health = 100*health_coef;
		exp = 40 + 20 * level;
		attack = 25 + level * 10;
		armor = 5;
		name = "Ведьма";
	}
};

class Vampire : public Enemy {
public:
	Vampire(int lvl) : Enemy(lvl) {
		level = lvl;
		healthmax = health = 115*health_coef;
		exp = 65 + 20 * level;
		attack = 25 + level * 10;
		armor = 15;
		name = "Вампир";
	}
};

class DarkElf : public Enemy {
public:
	DarkElf(int lvl) : Enemy(lvl) {
		level = lvl;
		healthmax = health = 100*health_coef;
		exp = 80 + 20 * level;
		attack = 35 + level * 10;
		armor = 15;
		name = "Тёмный эльф";
	}
};

class Orc :public Enemy {
public:
	Orc(int lvl) : Enemy(lvl) {
		level = lvl;
		healthmax = health = 150*health_coef;
		exp = 150 + 20 * level;
		attack = 35 + level * 10;
		armor = 5;
		name = "Орк";
	}
};

class Ent : public Enemy {
public:
	Ent(int lvl) : Enemy(lvl) {
		level = lvl;
		healthmax = health = 140*health_coef;
		exp = 140 + 20 * level;
		attack = 40 + level * 10;
		armor = 35;
		name = "Энт";
	}
};

class Gargoyle : public Enemy {
public:
	Gargoyle(int lvl) : Enemy(lvl) {
		level = lvl;
		healthmax = health = 130*health_coef;
		exp = 150 + 20 * level;
		attack = 45 + level * 10;
		armor = 50;
		name = "Горгулья";
	}
};

class Ogre : public Enemy {
public:
	Ogre(int lvl) : Enemy(lvl) {
		level = lvl;
		healthmax = health = 150*health_coef;
		exp = 170 + 20 * level;
		attack = 40 + level * 10;
		armor = 0;
		name = "Огр";
	}
};

class SpiderBoss : public Enemy {
public:
	SpiderBoss(int lvl) : Enemy(lvl) {
		level = lvl;
		healthmax = health = 185*health_coef;
		exp = 230 + 20 * level;
		attack = 40 + level * 10;
		armor = 30;
		name = "Босс-павук";
	}
};

class Dragon :public Enemy {
public:
	Dragon(int lvl) : Enemy(lvl) {
		level = lvl;
		healthmax = health = INT32_MAX;
		exp = 0;
		attack = 10;
		armor = 100;
		name = "Дракон";
	}
};