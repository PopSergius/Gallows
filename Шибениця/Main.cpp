#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int chek() {
	int chek;

	cout << "\n������ ������ ���� ���?"
		<< "\n(1 - ���; 0 - �)"
		<< "=> ";
	cin >> chek;
	return chek;
}

void PrintWord(char*& secret, int size) {

	for (int i = 0; i < size; i++) {
		cout << secret[i];
	}
	cout << '\n';
}

bool ChekLiter(char liter, char*& secret, string word) {
	bool chek = false;

	for (int i = 0; i < word.length(); i++) {
		if (word[i] == liter)
			secret[i] = liter;
		if (secret[i] == '_')
			chek = true;
	}

	return chek;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char liter;

	cout << "³��� � �� ��������"
		<< "\n������� ���:"
		<< "\n������ ������� ������� ���� �����"
		<< "\n������ ������� ����� ������� �� �� �� ����� ������� �� ���� ����"
		<< "\n���� �� ����� � � ���� ���� �'������� � ���� �� ���� ������� ����"
		<< "\n���� ���� ����� ���� ��������� ���� �����"
		<< "\n� ��� �� ��� �� ���� �� �� ������� �� ����� � ����\n"
		<< "\n����� ���!";

	while (chek()) {
		string word;
		bool chek = true;
		
		cout << "\n������ �������."
			<< "\n������ �����: ";
		cin >> word;

		system("cls");

		char* secret = new char[word.length()];
		for (int i = 0; i < word.length(); i++) { secret[i] = '_'; }

		while (chek) {
			PrintWord(secret, word.length());

			cout << "\n������ �����: ";
			cin >> liter;

			chek = ChekLiter(liter, secret, word);
		}

		cout << "\n³��� �� ������� �����!\n�� ���� �����: ";
		PrintWord(secret, word.length());

		system("pause");
		system("cls");
	}
}