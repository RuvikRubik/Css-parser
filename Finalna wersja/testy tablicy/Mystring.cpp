#include"Mystring.h"

Mystring::Mystring() {
	str = new char[1];
	str[0] = '\0';
	size = 0;
}

Mystring::Mystring(char char1) {
	str = new char[2];
	str[0] = char1;
	str[1] = '\0';
	size = 1;
}

Mystring::Mystring(int int1) {
	str = new char[int1];
	str[int1] = '\0';
	size = int1 - 1;
}

Mystring* Mystring::removepocz() {
	if (this->size == 0) {
		return new Mystring();
	}
	Mystring* nowy = new Mystring(this->size - 1);
	for (int i = 0; nowy->size; i++) {
		nowy->str[i] = this->str[i];
	}
	return nowy;
};

int Mystring::stoi(Mystring str) {
	int wynik = 0;
	int b = 0;
	int tab[5] = { 1 ,10, 100, 1000, 10000 };
	for (int i = str.size-1; i >= 0; i--) {
		
		wynik += (str.str[i] - 48) * tab[b];
		b++;
	}
	return wynik;
}

bool Mystring::operator==(const char* chars)
{
	for (int i = 0; i < this->size; i++) {
		if (this->str[i] == chars[i]) {

		}
		else {
			return 0;
		}
	}
	return 1;
}

bool Mystring::same(const char* chars) {
	if (this->size != strlen(chars)) {
		return 0;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->str[i] == chars[i]) {

		}
		else {
			return 0;
		}
	}
	return 1;
};

bool Mystring::same(Mystring chars) {
	if (this->size != chars.size) {
		return 0;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->str[i] == chars.str[i]) {

		}
		else {
			return 0;
		}
	}
	return 1;
};



std::ostream& operator<<(std::ostream& os, const Mystring& str) {
	os << str.str;
	return os;
}

void Mystring::clear() {
	size = NULL;
	str = NULL;
}

Mystring* Mystring::add(char znak) {
	int size = this->size + 1;
	Mystring* nowy = new Mystring(size);
	for (int i = 0; i < size - 1; i++) {
		nowy->str[i] = this->str[i];
	}
	nowy->str[size - 1] = znak;
	nowy->size = size;
	return nowy;
}

Mystring::~Mystring() {

};