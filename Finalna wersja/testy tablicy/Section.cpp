#include"Section.h"


Section::Section() {
};
Section::Section(ListSelektor sel, ListAtrybutow atr) {
	selelektory = sel;
	atrybuty = atr;
};

Mystring Section::Find(Mystring atr, Mystring sel) {
	Section* temp = this;
	ListSelektor* war = temp->selelektory.find(sel);
	ListAtrybutow* war2 = temp->atrybuty.find(atr);
	if (war == NULL || war2 == NULL) {
		return Mystring();
	}
	return war2->getvalue();
}

Section::~Section() {
	//cout << "destuktor sekcji";
};