#pragma once
#include"SectionTab.h"

class MainList {
public:
	SectionTab Mainlist;
	MainList* next;
	MainList* prev;
	MainList();
	~MainList();
	//MainList* AddFirst(MainList*, MainList*);
	//MainList* RemoveFirst(MainList*);
	//MainList* RemoveLast(MainList*);
	MainList* AddLast(MainList*, MainList*);
	MainList* RemoveNode(MainList*, MainList*);
	static MainList* GetFirst(MainList*);
	static MainList* GetLast(MainList*);
	friend std::ostream& operator<<(std::ostream& os, const MainList&);
	int Getsize();
	void MainAdd(Section);
};