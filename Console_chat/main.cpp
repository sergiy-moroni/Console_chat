#include "User.h"
#include "Message.h"
#include <vector>

using namespace std;

vector<User> Userslist;//вектор хранит в себе данные зарегестрированных пользователей чата
int user_islogin = 0;

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
			user_islogin = i;
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
	
	bool l = true;
	while (l) {
		cin >> login;
		if (FindLogin(login)) {
			cout << "Данный логин уже занят выберите другой!" << endl;
			cout << "Введите логин для входа в систему: ";
		}
		else {
			l = false;
		}
	}
	cout << "Введите пароль: ";
	cin >> pass;
	
	User U(name, login, pass);
	
		Userslist.push_back(U);
		cout << "Пользователь успешно зарегистрирован!" << endl;
		return U;
	
}


//метод получения списка зарегестрированных пользователей
	void PrintUsersNames() {
	for (int i = 0; i < size(Userslist); ++i) {
		cout << (i + 1) << ". " << Userslist[i].GetName() << endl;
	}
}

//метод возвращает номер пользователя в векторе по имени
	int FindUserinUserslist(string name) {
	for (int i = 0; i < size(Userslist); ++i) {

		if (Userslist[i].GetName() == name) {
			return i;
		}
	}return -1;
}

	int main() {

	setlocale(LC_ALL, "Russian");
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

		{CreateNewUser();
			continue;}
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

						Userslist[user_islogin].PrintMessages();
						break;

					case 2:
						cout << "Введите пользователя которому хотите отправить сообщение," << endl;
						PrintUsersNames();
							cout << "\"all\"  - чтобы отправиль сообщение всем пользователям чата:" << endl;;
						string h;
						string message;
						cin >> h;
						if (h == "all") {
							cout << "Введите текст сообщения: " << endl;
							cout << endl;
							getline(cin, message, '\n');
							getline(cin, message, '\n');
							
								Message<string> mes(Userslist[user_islogin].GetName(), message);
								for (int i = 0; i < size(Userslist); ++i) {
									Userslist[i].Setmessage(mes);
							}
						}
						else {
							int t = -1;

						t = FindUserinUserslist(h);
						
							if (t == (-1))

							{
								cout << "Пользователь с данным именем не найден" << endl;
							}
							else {
								cout << "Введите текст сообщения: " << endl;
								cout << endl;
								getline(cin, message, '\n');
								getline(cin, message, '\n');

								Message<string> mes(Userslist[user_islogin].GetName(), message);

								Userslist[FindUserinUserslist(h)].Setmessage(mes);
							}
						}
					}
					if (c == 0) { break; }
				}
			}
			else { inuser = false; }
		}
	}
	return 0;
}