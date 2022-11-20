#pragma once
#include <string>
#include <vector>

using namespace std;
class User {

private:
	string _name;
	string _pass;
	string _login;
	vector<vector<string>> inmessege;

public:
	User(string name, string login, string pass) {
		_name = name;
		_login = login;
		_pass = pass;
	}
	~User() {}
	string GetName() {
		return _name;
	}
	void SetName(string name) {
		_name = name;
	}
	string Getpass() {
		return _pass;
	}
	string Getlog() {
		return _login;
	}

};


