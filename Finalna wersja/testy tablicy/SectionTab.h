#pragma once
#include"Section.h"
const int T = 8;
class SectionTab {
private:
public:
	Section sectab[T];
	int licznikzaj = 0;
	SectionTab();
	int Sectionadd(Section);
	~SectionTab();
};
