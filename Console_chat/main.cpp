#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "");
	cout << "������� 'r' ��� ����������� ��� 'r' ��� �����" << endl;
	char c;
	cin >> c;

	if (c != 'r' && c != 'v') {
		cout << "������� �������� �������" << endl;
		return 0;
	}

	if (c == 'r') {
		cout << "������� �����: ";
		cin >> Person.login;
		cout << endl;
		cout << "������� ������: ";
		cin >> Person.password;
		cout << endl;
		
	}

	return 0;
}