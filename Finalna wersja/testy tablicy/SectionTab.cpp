#include"SectionTab.h"


int SectionTab::Sectionadd(Section sec) {
	if (licznikzaj == T) {
		return 0;
	}
	else {
		sectab[this->licznikzaj] = sec;
		this->licznikzaj++;
		return 1;
	}
};

SectionTab::SectionTab() {};

SectionTab::~SectionTab() {
	//cout << "destuktor tablicy sekcji";
};