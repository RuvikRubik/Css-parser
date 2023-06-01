#pragma once
#include"Lists.h"

void ListSelektor::PrintList() {
	ListSelektor* tmp = this;
	while (tmp != NULL) {
		cout << tmp->Sel << " " << endl;
		tmp = tmp->next;
	}
	cout << endl;
};

ListSelektor::ListSelektor() : Sel(){
}

ListSelektor::ListSelektor(Mystring val): Sel(val){
}

ListSelektor::~ListSelektor() {
	//cout << "destuktor listy selektorów";
}

std::ostream& operator<<(std::ostream& os, const ListSelektor& firstNode) {
	/*if (firstNode.Sel == "") {
		return os;
	}*/
	ListSelektor temp = firstNode;
	os << temp.Sel << " ";
	while (temp.next != NULL) {
		temp = *temp.next;
		os << temp.Sel << " ";
	}
	return os;
};

Mystring ListSelektor::getSelektor() {
	return this->Sel;
};

ListSelektor* ListSelektor::AddFirst(ListSelektor* firstNode, ListSelektor* newNode) {
	newNode->prev = NULL;
	newNode->next = firstNode;
	if (firstNode != NULL) {
		firstNode->prev = newNode;
	}
	return newNode;
};

ListSelektor* ListSelektor::AddLast(ListSelektor* firstNode, ListSelektor* newNode) {
	ListSelektor* last = GetLast(firstNode);
	newNode->prev = last;
	if (last == NULL) {
		return newNode;
	}
	last->next = newNode;
	return firstNode;
};

int ListSelektor::GetListLength() {
	int size = 0;
	ListSelektor* temp = this;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}
ListSelektor* ListSelektor::RemoveNode(ListSelektor* firstNode, ListSelektor* node) {
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

ListSelektor* ListSelektor::GetFirst(ListSelektor* firstNode) {
	if (firstNode == NULL) {
		return NULL;
	}
	return firstNode;
};
ListSelektor* ListSelektor::GetLast(ListSelektor* firstNode) {
	if (firstNode == NULL) {
		return NULL;
	}
	ListSelektor* temp = firstNode;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
};

ListSelektor* ListSelektor::RemoveFirst(ListSelektor* firstNode) {
	return RemoveNode(firstNode, firstNode);
};

ListSelektor* ListSelektor::RemoveLast(ListSelektor* firstNode) {
	ListSelektor* last = GetLast(firstNode);
	return RemoveNode(firstNode, last);
};

void ListSelektor::setsel(Mystring sel) {
	Sel = sel;
}

ListSelektor* ListSelektor::find(Mystring str) {
	ListSelektor* temp = this;
	if (temp->Sel.same(str)) {
		return temp;
	}
	while (temp->next != NULL) {
		temp = temp->next;
		if (temp->Sel.same(str)) {
			return temp;
		}
	}
	return NULL;
}