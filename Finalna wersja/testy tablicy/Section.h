#pragma once
#include"Listi.h"
#include"Lists.h"
class Section {
public:
	ListSelektor selelektory;
	ListAtrybutow atrybuty;
	Section();
	Section(ListSelektor, ListAtrybutow);
	Mystring Find(Mystring atr, Mystring sel);
	~Section();
};