#pragma once

class Creature {
public:
	

	int TakeDamage(int impact, int armor) {
		return impact * (1 - armor / 100);
	}

	int health, healthmax, level, exp;
};