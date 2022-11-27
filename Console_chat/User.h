#pragma once
#include <vector>
#include <iostream>
#include "Message.h"

class User {

private:
	std::string _name;
	std::string _pass;
	std::string _login;
	std::vector<Message<std::string>> _messages;

public:
	User(std::string name, std::string login, std::string pass);
	virtual ~User();
	std::string GetName();
	void SetName(std::string name);
	std::string Getpass();
	std::string Getlog();
	bool IsEmpty(); // получение наличия сообщений
	void Setmessage(Message<std::string> message); //получение сообщения 
	void PrintMessages();	// чтение сообщений 
};


