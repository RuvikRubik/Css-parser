#pragma once
#include<iostream>
#include"Mystring.h"
using namespace std;

class ListSelektor{
private:
	Mystring Sel;
public:
	ListSelektor* next = nullptr;
	ListSelektor* prev = nullptr;
	ListSelektor();
	ListSelektor(Mystring);
	void PrintList();
	friend std::ostream& operator<<(std::ostream& os, const ListSelektor&);
	~ListSelektor();
	Mystring getSelektor();
	ListSelektor* AddFirst(ListSelektor*, ListSelektor*);
	ListSelektor* AddLast(ListSelektor*, ListSelektor*);
	ListSelektor* RemoveNode(ListSelektor*, ListSelektor*);
	ListSelektor* RemoveFirst(ListSelektor*);
	ListSelektor* RemoveLast(ListSelektor*);
	static ListSelektor* GetFirst(ListSelektor*);
	static ListSelektor* GetLast(ListSelektor*);
	int GetListLength();
	ListSelektor* find(Mystring str);
	void setsel(Mystring);
};