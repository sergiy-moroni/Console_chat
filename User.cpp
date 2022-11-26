#include "User.h"

User::User(string name, string login, string pass) {
	_name = name;
	_login = login;
	_pass = pass;
}

User::~User() {}
string User::GetName() {
	return _name;
}
void User::SetName(string name) {
	_name = name;
}
string User::Getpass() {
	return _pass;
}
string User::Getlog() {
	return _login;
}

//получение сообщения 
void User::Setmessage(Message<string> message) {

	_messages.push_back(message);
}

// чтение сообщений 
void User::PrintMessages() {
	for (int i = 0; i < size(_messages); ++i) {
		_messages[i].PrintM();
	}
	cout << endl;
}