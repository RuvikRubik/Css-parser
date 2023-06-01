#pragma once
#include<iostream>
#include"Mystring.h"
using namespace std;

class ListAtrybutow{
private:
	Mystring Attribute,value;
public:
	ListAtrybutow* next = nullptr;
	ListAtrybutow* prev = nullptr;
	void PrintList();
	void PrintListatr();
	ListAtrybutow();
	ListAtrybutow(Mystring, Mystring);
	friend std::ostream& operator<<(std::ostream& os, const ListAtrybutow&);
	~ListAtrybutow();
	Mystring getAttribute();
	Mystring getvalue();
	void setvalue(Mystring);
	ListAtrybutow* AddFirst(ListAtrybutow*, ListAtrybutow*);
	ListAtrybutow* AddLast(ListAtrybutow*, ListAtrybutow*);
	static ListAtrybutow* RemoveNode(ListAtrybutow*, ListAtrybutow*);
	ListAtrybutow* RemoveFirst(ListAtrybutow*);
	ListAtrybutow* RemoveLast(ListAtrybutow*);
	static ListAtrybutow* GetFirst(ListAtrybutow*);
	static ListAtrybutow* GetLast(ListAtrybutow*);
	int GetListLength();
	ListAtrybutow* find(Mystring str);
};