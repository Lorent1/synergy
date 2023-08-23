#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Spell {
public:

	//Конструктор
	Spell(int strength, int mana) {
		this->strength = strength;
		this->mana = mana;
	}

	//Список дружеских функций
	friend bool operator<(const Spell& s1, const Spell& s2);
	friend bool operator>(const Spell& s1, const Spell& s2);
	friend bool operator==(const Spell& s1, const Spell& s2);

	int strength;
	int mana;
};

//Перегррузка операторов
bool operator<(const Spell& s1, const Spell& s2) {
	return s1.mana < s2.mana;
}

bool operator>(const Spell& s1, const Spell& s2) {
	return s1.mana > s2.mana;
}

bool operator==(const Spell& s1, const Spell& s2) {
	return s1.mana == s2.mana;
}

int main() {
	setlocale(LC_ALL, "Russian");

	//Вектор объектов
	vector<Spell> Spells{
		Spell(4,5),
		Spell(1,2),
		Spell(3,7),
		Spell(8,2),
		Spell(10,15),
		Spell(18,17),
		Spell(1,3),
		Spell(2,5),
		Spell(1,7)
	};

	//Сортировка 1 - стандарт по расходуемой энергии в порядке возрастания
	sort(Spells.begin(), Spells.end());

	//Вывод
	cout << "Первый способ:" << "\n";

	for (Spell el : Spells) {
		cout << "Расходуемая энергия: " << el.mana << " Сила: " << el.strength << "\n";
	}

	//Сортировка 2 - по силе, если она равно, то обратно(чем больше - тем меньше) по расходуемой энергии
	sort(Spells.begin(), Spells.end(), [](const Spell& s1, const Spell& s2)
		{
			if (s1.strength == s2.strength) {
				return s1.mana > s2.mana;
			}
			else return s1.strength < s2.strength;
		});

	//Вывод
	cout << "\n" << "Второй способ:" << "\n";

	for (Spell el : Spells) {
		cout << "Расходуемая энергия: " << el.mana << " Сила: " << el.strength << "\n";
	}
}
