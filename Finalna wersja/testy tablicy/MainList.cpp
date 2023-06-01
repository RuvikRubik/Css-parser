#include"MainList.h"

MainList::MainList() {
	next = NULL;
	prev = NULL;
}

MainList* MainList::GetFirst(MainList* firstNode) {
	if (firstNode == NULL) {
		return NULL;
	}
	return firstNode;
};
MainList* MainList::GetLast(MainList* firstNode) {
	if (firstNode == NULL) {
		return NULL;
	}
	MainList* temp = firstNode;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
};

MainList* MainList::AddLast(MainList* firstNode, MainList* newNode) {
	MainList* last = GetLast(firstNode);
	newNode->prev = last;
	if (last == NULL) {
		return newNode;
	}
	last->next = newNode;
	return firstNode;
};

MainList* MainList::RemoveNode(MainList* firstNode, MainList* node) {
	if (node == NULL) {
		return firstNode;
	}
	if (node->next != NULL) {
		node->next->prev = node->prev;
	}
	if (node->prev == NULL) {
		return node->next;
	}
	node->prev->next = node->next;
	return firstNode;
}

void MainList::MainAdd(Section sec) {
	MainList* temp2 = this->GetLast(this);
	if (temp2->Mainlist.Sectionadd(sec) == 1) {
		return;
	}
	else {
		MainList* temp = new MainList();
		temp2->AddLast(this, temp);
		temp2->next->Mainlist.Sectionadd(sec);
	}
}

int MainList::Getsize() {
	MainList* temp = this;
	int size = temp->Mainlist.licznikzaj;
	while (true) {
		if (temp->next != NULL) {
			temp = temp->next;
			size += temp->Mainlist.licznikzaj;
		}
		else {
			return size;
		}
		
	}
};

std::ostream& operator<<(std::ostream& os, const MainList& firstNode) {
	MainList temp = firstNode;
	while (true) {
		for (int i = 0; i < temp.Mainlist.licznikzaj; i++) {
			os << "selektory:\n" << temp.Mainlist.sectab[i].selelektory << endl;
			os << "atrybuty: \n" << temp.Mainlist.sectab[i].atrybuty << endl;	
		}
		if (temp.next == NULL) {
			return os;
		}
		temp = *(temp.next);
	}
}

MainList::~MainList() {
	//cout << "destuktor glownej listy";
};