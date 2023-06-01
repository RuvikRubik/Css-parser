#pragma once
#include"Listi.h"

void ListAtrybutow::PrintList() {
	ListAtrybutow* tmp = this;
	while (tmp != NULL) {
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
};

void ListAtrybutow::PrintListatr() {
	ListAtrybutow* tmp = this;
	while (tmp != NULL) {
		cout << tmp->Attribute << " ";
		tmp = tmp->next;
	}
	cout << endl;
};

ListAtrybutow::ListAtrybutow(): Attribute(), value() {
}

ListAtrybutow::ListAtrybutow(Mystring str, Mystring val): Attribute(str),value(val) {
}

ListAtrybutow::~ListAtrybutow() {
	//cout << "destuktor listy atrybutów";
}

std::ostream& operator<<(std::ostream& os, const ListAtrybutow& firstNode) {
	/*if (firstNode.value == "") {
		return os;
	}*/
	ListAtrybutow temp = firstNode;
	os << temp.Attribute << ": "<<temp.value << " "<<endl;
	while (temp.next != NULL) {
		temp = *temp.next;
		os << temp.Attribute << ": " << temp.value << " " << endl;
	}
	return os;
};

Mystring ListAtrybutow::getAttribute() {
	return this->Attribute;
};

Mystring ListAtrybutow::getvalue() {
	return this->value;
};

void ListAtrybutow::setvalue(Mystring val) {
	value = val;
};

ListAtrybutow* ListAtrybutow::AddFirst(ListAtrybutow* firstNode, ListAtrybutow* newNode) {
	newNode->prev = NULL;
	newNode->next = firstNode;
	if (firstNode != NULL) {
		firstNode->prev = newNode;
	}
	return newNode;
};
ListAtrybutow* ListAtrybutow::AddLast(ListAtrybutow* firstNode, ListAtrybutow* newNode) {
	ListAtrybutow* last = GetLast(firstNode);
	newNode->prev = last;
	if (last == NULL) {
		return newNode;
	}
	last->next = newNode;
	return firstNode;
};

int ListAtrybutow::GetListLength() {
	int size = 0;
	ListAtrybutow* temp = this;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}

ListAtrybutow* ListAtrybutow::RemoveNode(ListAtrybutow* firstNode, ListAtrybutow* node) {
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

ListAtrybutow* ListAtrybutow::GetFirst(ListAtrybutow* firstNode) {
	if (firstNode == NULL) {
		return NULL;
	}
	return firstNode;
};
ListAtrybutow* ListAtrybutow::GetLast(ListAtrybutow* firstNode) {
	if (firstNode == NULL) {
		return NULL;
	}
	ListAtrybutow* temp = firstNode;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
};

ListAtrybutow* ListAtrybutow::RemoveFirst(ListAtrybutow* firstNode) {
	return RemoveNode(firstNode, firstNode);
};

ListAtrybutow* ListAtrybutow::RemoveLast(ListAtrybutow* firstNode) {
	ListAtrybutow* last = GetLast(firstNode);
	return RemoveNode(firstNode, last);
};

ListAtrybutow* ListAtrybutow::find(Mystring str) {
	ListAtrybutow* temp = this;
	if (temp->Attribute.same(str)) {
		return temp;
	}
	while (temp->next != NULL) {
		temp = temp->next;
		if (temp->Attribute.same(str)) {
			return temp;
		}
	}
	return NULL;
}