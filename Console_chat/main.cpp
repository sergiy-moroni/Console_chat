#include <iostream>
#include "User.h"
#include <vector>
using namespace std;

vector<User> Userslist;//вектор хранит в себе данные зарегестрированных пользователей чата

bool inuser = false; // состояние подключения пользователя к чату

//метод поиска пользователя среди зарегестрированных по логину и паролю
bool  FindUser(string login, string pass) {

	int i = 0;
	bool j = false;
	while (i < size(Userslist)) {
		string l = Userslist[i].Getlog();
		string k = Userslist[i].Getpass();
		if (login == l && pass == k) {

			cout <<endl << "Здравствуйте, " << Userslist[i].GetName() << "!" << endl;
			return j;
			break;
			++i;

		}
		else {
			
			//return false; 
			++i;
		}
	}
	if(j==false){ cout << "Пользователь не найден" << endl; }
}

//метод поиска зарегестрированный логин для защиты от повторной регистрации
bool FindLogin(string login) {
	bool j = false;
	for (int i = 0; i < size(Userslist); i++) {
		if (Userslist[i].Getlog() == login) {
			j = true;

			return j;
			break;
		}
	}return j;
}

//метод создания нового пользователя чата
User CreateNewUser() {
	cout << "Введите данные для регистрации" << endl;
	cout << "Введите имя пользователя: ";
	string name;
	string login;
	string pass;
	cin >> name;
	cout << "Введите логин для входа в систему: ";
	cin >> login;
	if (FindLogin(login)) {
		cout << "Данный логин уже занят выберите другой!";
		cin >> login;
	}
	cout << "Введите пароль: ";
	cin >> pass;
	
	User X(name, login, pass);
	
		Userslist.push_back(X);
		cout << "Пользователь успешно зарегистрирован!" << endl;
		return X;
	
}


//метод получения списка зарегестрированных пользователей
void PrintUsersNames() {
	for (int i = 0; i < size(Userslist); ++i) {
		cout << (i + 1) << ". " << Userslist[i].GetName() << endl;
	}
}



int main() {


	setlocale(LC_ALL, "");
	// вход в систему
	cout << "Добро пожаловать в чат!" << endl;
	while (true) {
		cout << "Количество зарегестрированных пользователей: " << size(Userslist) << endl;
		std::cout << "Введите 1 для входа.\nВведите 2 для регистрации нового пользователя \nВведите 0 для выхода из чата" << endl;
		short c = 0;
		cin >> c;


		// регистрация нового пользователя
		if (c == 2)
		{
			CreateNewUser();
			continue;
		}

		if (c == 0) { break; }

		//вход по логину ипаролю
		if (c == 1)
		{
			string log;
			string pas;
			std::cout << "Введите логин: ";
			cin >> log;
			std::cout << "Введите пароль: ";
			cin >> pas;
			if (FindUser(log, pas) == false) {
				while (true) {
					inuser = true;
					cout << "Введите номер желаемого действия: " << endl;
					cout << "1 - Прочитать входящие сообщения" << endl;
					cout << "2 - Написать сообщение другому пользователю" << endl;
					cout << "0 - Выйти" << endl;
					short c = 0;
					cin >> c;
					switch (c) {
					case 1:

						break;
					case 2:
						cout << "Выберите номер пользователя кому хотите отправить сообщение: " << endl;
						PrintUsersNames();
						short h = 0;
						string massage;
						cin >> h;
						cout << "Введите текст сообщения: ";
						cin >> massage;


					
					}
					if (c == 0) { break; }
				}
			}
			else { inuser = false; }

		}

	}

	return 0;
}