#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int chek() {
	int chek;

	cout << "\n’очете почати нову гру?"
		<< "\n(1 - так; 0 - н≥)"
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

	cout << "¬≥таю в гр≥ шибениц€"
		<< "\nѕравила гри:"
		<< "\nѕерший гравець вводить одне слово"
		<< "\nƒругий гравець пробуЇ вгадати що це за слово ввод€чи по одн≥й л≥тер≥"
		<< "\nякщо ц€ л≥тера Ї в слов≥ вона з'€витьс€ у м≥сц≥ де вона повинна бути"
		<< "\nякщо ц≥Їњ л≥тери немаЇ вводитьс€ ≥нша л≥тера"
		<< "\n≤ так до тих п≥р поки ви не вгадаЇте вс≥ л≥тери в слов≥\n"
		<< "\n√арноњ гри!";

	while (chek()) {
		string word;
		bool chek = true;
		
		cout << "\nѕерший гравець."
			<< "\n¬вед≥ть слово: ";
		cin >> word;

		system("cls");

		char* secret = new char[word.length()];
		for (int i = 0; i < word.length(); i++) { secret[i] = '_'; }

		while (chek) {
			PrintWord(secret, word.length());

			cout << "\n¬вед≥ть л≥теру: ";
			cin >> liter;

			chek = ChekLiter(liter, secret, word);
		}

		cout << "\n¬≥таю ви вгадали слово!\n÷е було слово: ";
		PrintWord(secret, word.length());

		system("pause");
		system("cls");
	}
}