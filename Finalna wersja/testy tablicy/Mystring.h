#pragma once
#include <iostream>

class Mystring {
public:
	int size;
	char* str;

	Mystring();
	Mystring(char);
	Mystring(int);
	static int stoi(Mystring);
	friend std::ostream& operator<<(std::ostream& os, const Mystring&);
	bool operator==(const char* chars);
	bool same(const char* chars);
	bool same(Mystring chars);
	Mystring* removepocz();
	Mystring* add(char);
	void clear();
	~Mystring();

};
