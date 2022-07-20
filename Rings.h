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
		name = "������ �����";
		increasing = 20;
		type = 0;
	}
};

class RingOfArmor :public Ring {
public:
	RingOfArmor() {
		name = "������ ������";
		increasing = 5;
		type = 1;
	}
};

class RingOfScale :public Ring {
public:
	RingOfScale(int player_type) {
		switch (player_type) {
		case 1:
			name = "������ ������������";
			break;
		case 2:
			name = "������ ������������";
			break;
		case 3:
			name = "������ ����";
			break;
		}
		increasing = 20;
		type = 2;
	}
};

class RingOfReviving :public Ring {
public:
	RingOfReviving() {
		name = "������ �����������";
		type = 3;
	}
};