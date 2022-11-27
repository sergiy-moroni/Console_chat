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

			cout <<endl << "Здравствуйте, " << Userslist[i].GetName() << "!" << endl << endl;
			user_islogin = i;
			j = true;
			return j;
			break;
		}
		else {
			++i;
		}
	}
	if (j == false) {
		cout << "\nНеверный логин или пароль" << endl;
	}
	return j;
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
	void CreateNewUser() {
	cout << "Введите данные для регистрации" << endl;
	cout << "Введите имя пользователя: ";
	string name;
	char namec[256];
	string login;
	string pass;
	cin >> namec;
	name = namec;
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
		cout << "Пользователь успешно зарегистрирован!" << endl << endl;
}

//метод получения списка зарегестрированных пользователей
	void PrintUsersNames() {
	for (int i = 0; i < size(Userslist); ++i) {
		cout << (i + 1) << ". " << Userslist[i].GetName() << endl;
	}
}

//метод возвращает номер пользователя в списке Userlist по имени
	int FindUserinUserslist(string name) {
	for (int i = 0; i < size(Userslist); ++i) {

		if (Userslist[i].GetName() == name) {
			return i;
		}
	}return -1;
}

	int main() {
		setlocale(LC_ALL, "Rus");

	// вход в систему
	cout << "Добро пожаловать в чат!" << endl;
	while (true) {
		cout << endl;
		cout << "Количество зарегестрированных пользователей: " << size(Userslist) << endl;
		std::cout << "Введите желаемое действие: \n1 - для входа.\n2 - для регистрации нового пользователя \n0 - для выхода из чата" << endl;
		int c;
		cin >> c;
		if (c !=0 && c!=2&& c!=1) {
			cout << "Неверный ВВОД!" << endl;
			continue;
		}
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
			if (FindUser(log, pas)) {
				while (true) {
					string h;
					string message;
					inuser = true;
					cout << endl;
					//выбор пользователем желаемого действия
					cout << "Введите номер желаемого действия: " << endl;
					cout << "1 - Прочитать все входящие сообщения" << endl;
					cout << "2 - Написать сообщение другому пользователю" << endl;
					cout << "0 - Выйти" << endl;
					int c = 0;
					cin >> c;
					if (c < 0 && c > 2) {
						cout << "Неверный ВВОД!" << endl;
					}
					if (c == 0) {
						cout << "Досвидания, " << Userslist[user_islogin].GetName() << "!" << endl;
						break;
					}
					switch (c) {
		
					case 1:
						if (Userslist[user_islogin].IsEmpty()) {
							cout << "У вас еще нет входящих сообщений!" << endl;
						}
						else {
							Userslist[user_islogin].PrintMessages();
						}
						break;

					case 2:
						cout << "Введите ИМЯ пользователя которому хотите отправить сообщение: " << endl << endl;
						PrintUsersNames();
						cout << "\"all\"  - чтобы отправиль сообщение всем пользователям чата:" << endl << endl;
						cin >> h;
						if (h == "all") {// отправка сообщения всем пользователям чата
							cout << "Введите текст сообщения: " << endl;
							cout << endl;
							getline(cin, message, '\n');
							getline(cin, message, '\n');

							Message<string> mes(Userslist[user_islogin].GetName(), message);
							for (int i = 0; i < size(Userslist); ++i) {
								Userslist[i].Setmessage(mes);
							}
							cout << "Сообщение разослано всем пользователям!" << endl;
						}
						else {
							int t = -1;
							t = FindUserinUserslist(h);//отправка сообщения по введенному имени полльзователя

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
								cout << "Сообщение отправлено!" << endl;
							}
						}

					}
				
				} 
			}
			else { inuser = false; }
		}
	}
	return 0;
}
