#include<iostream>
#include"MainList.h"
#include "Operation.cpp"
#include"Mystring.h"
////usuwanie powtórzen i bia³ych znaków
Mystring* spaceremove(Mystring* napis) {
	int pocz = 0;
	int kon = napis->size;
	Mystring* out = new Mystring();
	if (isspace(napis->str[pocz]) != 0) {
		//out = out->removepocz();
		if (kon == 0) {
			return new Mystring();
		}
		for (int i = 1; i < kon; i++) {
			out->str[i-1] = out->str[i];
		}
	}
	if (isspace(napis->str[kon - 1]) != 0) {
		kon -= 1;
		//napis->str[kon - 1] = '\0';
	}
	for (int i = pocz; i < kon; i++) {
		out = out->add(napis->str[i]);
	}
	return out;
}

int checkcomment(MainList* lista) {
	int c;
	//cout << "komen";
	Mystring* s = new Mystring();
	Mystring* s1 = new Mystring();
	Mystring* s3 = new Mystring();
	char s2 = '0';
	while ((c = getchar()) != EOF) {
		if (c != '\n' && c != '	' && c != 10 && c != 13) {
			s = s->add(c);
		}
		else
		{
			if (s->same("?")) { // s nie zmienia wartosci podwojne ??
				int b = lista->Getsize();
				//if (b == 16)b++;
				cout << "? == " << b << endl;
				//cout << *lista;
				//cout << "? == " << lista->Mainlist.licznikzaj << endl;
			}
			else if (s->same("****")) {
				return 1;
			}
			else if (s->same("")) {

			}
			else {
				for (int i = 0; i < s->size; i++) {
					if (s->str[i] == ',') {
						s2 = s->str[i + 1];
						for (int y = i + 3; y < s->size; y++) {
							s3 = s3->add(s->str[y]);
						}
						break;
					}
					s1 = s1->add(s->str[i]);
				}

				switch (s2)
				{
				case 'A': {
					Operation::OperationA(*s1, *s3, lista);
					break;
				case 'S': {
					Operation::OperationS(*s1, *s3, lista);
					break;
				}
				case 'E': {
					//cout << s;
					Operation::OperationE(*s1, *s3, lista);
					break;
				}
				case 'D': {
					if (s3->same("*")) {
						Operation::OperationD(Mystring::stoi(*s1), lista);
					}
					else {
						Operation::OperationD(Mystring::stoi(*s1), *s3, lista);
					}
					break;
				}
				default:
					break;
				}
				}
				//cout << "test";
				s1->clear();
				s3->clear();

			}
			s->clear();
		}
	}
	return 0;
};

Mystring* checkvalue(Mystring* input, int* num) {
	int number = *num;
	Mystring* out = new Mystring();
	for (int i = number + 1; i < input->size; i++) {
		if (input->str[i] == ':') {

		}
		else  if (input->str[i] == ';') {
			*num = i;
			return out;
		}
		else {
			out = out->add(input->str[i]);
			//out += input[i];
		}
	}
	return out;
}

ListAtrybutow* checkatribute(Mystring* input, int number) {
	ListAtrybutow* out = new ListAtrybutow();
	ListAtrybutow* temp;
	Mystring* atr = new Mystring();
	Mystring* val = new Mystring();
	for (int i = number + 1; i < input->size; i++) {
		if (input->str[i] == ':') {
			val = checkvalue(input, &i);
			val = spaceremove(val);
			atr = spaceremove(atr);
			if ((temp = out->find(*atr)) != NULL) {
				temp->setvalue(*val);
			}
			else {
				temp = new ListAtrybutow(*atr, *val);
				out->AddLast(out, temp);
			}
			atr->clear();
			val->clear();
		}
		else if (input->str[i] == '}') {
			out = out->RemoveFirst(out);
			return out;
		}
		else {
			atr	= atr->add(input->str[i]);
			//atr += input[i];
		}
	}
	return out;
}

Section checkselector(Mystring* input) {
	Mystring* sel = new Mystring();
	Mystring sel2 = Mystring();
	ListSelektor* temp3 = new ListSelektor();
	ListAtrybutow* temp2 = new ListAtrybutow();
	ListSelektor* temp;
	Section out;
	for (int i = 0; i < input->size; i++) {
		if (input->str[i] == ',') {
			sel = spaceremove(sel);
			temp = new ListSelektor(*sel);
			temp3->AddLast(temp3, temp);
			sel->clear();
			if (input->str[i + 1] == ' ') {
				i++;
			}
		}
		else if (input->str[i] == '{') {
			if (sel->size != 0) {
				sel = spaceremove(sel);
			}
			temp = new ListSelektor(*sel);
			temp3->AddLast(temp3, temp);
			temp3 = temp3->RemoveFirst(temp3);
			temp2 = checkatribute(input, i);
			out = Section(*temp3, *temp2);
			return out;
		}
		else {
			sel = sel->add(input->str[i]);
			//sel += input[i];
		}

	}
	return out;
}

int main() {
	MainList* lista = new MainList();
	char c;
	int test;
	Mystring* s = new Mystring();
	Section section;
	while ((c = getchar()) != EOF) {
		if (c != '\n' && c != '	' && c != 10  && c != 13) {
			s = s->add(c);
			//s += c;
		}
		else if (s->same("????")) {
			test = checkcomment(lista);
			if (test == 0) {
				return 1;
			}
			s = new Mystring();
		}
		else if (s->size == 0) {

		}
		else if (s->str[s->size - 1] == '}') {
			section = checkselector(s);
			lista->MainAdd(section);
			s->clear();
		}

	}
}