#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "");
	cout << "¬ведите 'r' дл€ регистрации или 'r' дл€ входа" << endl;
	char c;
	cin >> c;

	if (c != 'r' && c != 'v') {
		cout << "¬ведена неверна€ команда" << endl;
		return 0;
	}

	if (c == 'r') {
		cout << "¬ведите логин: ";
		cin >> Person.login;
		cout << endl;
		cout << "¬ведите пароль: ";
		cin >> Person.password;
		cout << endl;
		
	}

	return 0;
}