#include <cstdlib>
#include <ctime>
#include <clocale>
#include "Gameplay_functions.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int choise = 0;
	int stepcounter = 1;
	do {
		choise = StartMenu();
		switch (choise) {
		case 1:
			ShowHelp();
			break;
		case 2:
			break;
		case 3:
			return 0;
		}
	} while (choise != 2);
	Separator(2, 500);

	Player player;
	Armor armor(0);
	Weapon weapon(0, 0);
	
	switch (Initialization()) {
	case 1:
		player.SetStats(1, 100, armor, weapon);
		break;
	case 2:
		player.SetStats(2, 100, armor, weapon);
		break;
	case 3:
		player.SetStats(3, 100, armor, weapon);
		break;
	}
	Separator(2, 500);

	player.ShowStats();

	for (; player.health > 0; stepcounter++) {
		Event(stepcounter, &player);
		Separator(2, 1000);
	}
	YouDied();
	system("pause");
}