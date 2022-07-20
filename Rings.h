#pragma once
#include <string>

class Ring {
public:
	Ring(){}

	int increasing = 0, type = 0;
	std::string name, rang = "";
};

class RingOfHealth :public Ring {
public:
	RingOfHealth() {
		name = "Кольцо жизни";
		increasing = 20;
		type = 0;
	}
};

class RingOfArmor :public Ring {
public:
	RingOfArmor() {
		name = "Кольцо защиты";
		increasing = 5;
		type = 1;
	}
};

class RingOfScale :public Ring {
public:
	RingOfScale(int player_type) {
		switch (player_type) {
		case 1:
			name = "Кольцо выносливости";
			break;
		case 2:
			name = "Кольцо концентрации";
			break;
		case 3:
			name = "Кольцо маны";
			break;
		}
		increasing = 20;
		type = 2;
	}
};

class RingOfReviving :public Ring {
public:
	RingOfReviving() {
		name = "Кольцо возрождения";
		type = 3;
	}
};