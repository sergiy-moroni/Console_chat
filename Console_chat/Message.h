#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename X> class Message
{
private:
	string _sender;
	X _text;
	public:
	Message(string sender, X text) {
		_sender = sender;
		_text = text;
	}
	~Message() {}
	void PrintM() {
		cout << "от " << _sender << " : " << _text << endl;
	}
};
