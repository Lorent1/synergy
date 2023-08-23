#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Spell {
public:

	//�����������
	Spell(int strength, int mana) {
		this->strength = strength;
		this->mana = mana;
	}

	//������ ��������� �������
	friend bool operator<(const Spell& s1, const Spell& s2);
	friend bool operator>(const Spell& s1, const Spell& s2);
	friend bool operator==(const Spell& s1, const Spell& s2);

	int strength;
	int mana;
};

//����������� ����������
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

	//������ ��������
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

	//���������� 1 - �������� �� ����������� ������� � ������� �����������
	sort(Spells.begin(), Spells.end());

	//�����
	cout << "������ ������:" << "\n";

	for (Spell el : Spells) {
		cout << "����������� �������: " << el.mana << " ����: " << el.strength << "\n";
	}

	//���������� 2 - �� ����, ���� ��� �����, �� �������(��� ������ - ��� ������) �� ����������� �������
	sort(Spells.begin(), Spells.end(), [](const Spell& s1, const Spell& s2)
		{
			if (s1.strength == s2.strength) {
				return s1.mana > s2.mana;
			}
			else return s1.strength < s2.strength;
		});

	//�����
	cout << "\n" << "������ ������:" << "\n";

	for (Spell el : Spells) {
		cout << "����������� �������: " << el.mana << " ����: " << el.strength << "\n";
	}
}
