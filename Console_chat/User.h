#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Message.h"

using namespace std;
class User {

private:
	string _name;
	string _pass;
	string _login;
	vector<Message<string>> _messages;

public:
	User(string name, string login, string pass);
	~User();
	string GetName();
	void SetName(string name);
	string Getpass();
	string Getlog();

	//получение сообщения 
	void Setmessage(Message<string> message);

	// чтение сообщений 
	void PrintMessages();
};


