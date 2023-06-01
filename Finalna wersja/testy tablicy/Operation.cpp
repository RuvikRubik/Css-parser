#include<string>
#include<iostream>
#include"MainList.h"
#include<string>
using namespace std;
class Operation {
public:
	static Section getcorsec(int nrSec, MainList* lista) {
		MainList* temp = lista;
		while (true) {
			if (nrSec <= temp->Mainlist.licznikzaj) {
				return temp->Mainlist.sectab[nrSec - 1];;
			}
			else {
				nrSec -= lista->Mainlist.licznikzaj;
				if (temp->next != NULL) {
					temp = temp->next;
				}
				else {
					return Section();
				}
			}
		}
	}
public:

	static void OperationS(Mystring left, Mystring right, MainList* lista) {
		if (right.same("?") && (48 < left.str[0] && left.str[0] < 57)) { // i,S,?
			int blok = Mystring::stoi(left);
			Section temp = getcorsec(blok, lista);
			if (temp.atrybuty.getvalue().same("")) {
				return;
			}
			int sizesel = temp.selelektory.GetListLength();
			if (sizesel != 0) {
				cout << left << ",S,? == " << sizesel << endl;
			}
			else {
				return;
			}
		}
		else if (right.same("?")) { // z,S,?
			int wystopienia = 0;
			int kon = 0;
			MainList* temp = lista;
			ListSelektor* por;
			while (kon != 1) {
				for (int i = 0; i < temp->Mainlist.licznikzaj; i++) {
					por = temp->Mainlist.sectab[i].selelektory.find(left);
					if (por != NULL) {
						wystopienia++;
					}
				}
				if (temp->next == NULL) {
					kon = 1;
				}
				else {
					temp = temp->next;
				}
			}



			cout << left << ",S,? == " << wystopienia << endl;
		}
		else { // i,S,j
			int blok = Mystring::stoi(left);
			Section temp = getcorsec(blok, lista);
			if (temp.atrybuty.getvalue().same("")) {
				return;
			}
			ListSelektor temp2 = temp.selelektory;
			for (int i = 0; i < Mystring::stoi(right) - 1; i++) {
				if (temp2.next == NULL) {
					return;
				}
				temp2 = *temp2.next;
			}
			Mystring sizesel2 = temp2.getSelektor();
			if (sizesel2.same("")) {
			}
			else {
				cout << left << ",S," << right << " == " << sizesel2 << endl;
			}
		}
	}

	static void OperationA(Mystring left, Mystring right, MainList* lista) {
		if (right == "?" && (48 < left.str[0] && left.str[0] < 57)) { //i,A,?
			int blok = Mystring::stoi(left);
			Section temp = getcorsec(blok, lista);
			if (temp.atrybuty.getvalue().same("")) {
				return;
			}
			int sizeatr = temp.atrybuty.GetListLength();
			if (sizeatr != 0) {
				cout << left << ",A,? == " << sizeatr << endl;
			}
			else {
				return;
			}
		}
		else if (right.same("?")) { //n,A,?
			int wystopienia = 0;
			int kon = 0;
			MainList* temp = lista;
			ListAtrybutow* por;
			while (kon != 1) {
				for (int i = 0; i < temp->Mainlist.licznikzaj; i++) {
					por = temp->Mainlist.sectab[i].atrybuty.find(left);
					if (por != NULL) {
						wystopienia++;
					}
				}
				if (temp->next == NULL) {
					kon = 1;
				}
				else {
					temp = temp->next;
				}
			}
			cout << left << ",A,? == " << wystopienia << endl;
		}
		else { //i,A,n
			int blok = Mystring::stoi(left);
			Section temp = getcorsec(blok, lista);
			//cout << temp.selelektory;
			ListAtrybutow* temp2 = temp.atrybuty.find(right);
			if (temp2 == NULL) {
				return;
			}
			cout << left << ",A," << right << " == " << temp2->getvalue() << endl;
		}
	}

	static void OperationE(Mystring left, Mystring right, MainList* lista) {
		Mystring tempstr = Mystring();
		Mystring temp2str = Mystring();
		MainList* temp = lista;
		int kon = 0;
		if (temp == NULL) {
			return;
		}
		while (kon != 1) {
			for (int i = 0; i < temp->Mainlist.licznikzaj; i++) {
				tempstr = temp->Mainlist.sectab[i].Find(right, left);
				if (tempstr.same("")) {
					
				}
				else {
					temp2str = tempstr;
				}
			}
			if (temp->next == NULL) {
				kon = 1;
			}
			else {
				temp = temp->next;
			}

		}
		if (temp2str.same("")) {
			
		}
		else {
			cout << left << ",E," << right << " == " << temp2str << endl;
		}
	}

	static void OperationD(int left, Mystring right, MainList* lista) {
		MainList* temp = lista;
		ListAtrybutow* temp2 = nullptr;
		int nr = left;
		int kon = 0;
		while (kon == 0) {
			if (nr <= temp->Mainlist.licznikzaj) {
				temp2 = &lista->Mainlist.sectab[nr - 1].atrybuty;
				temp2 = ListAtrybutow::RemoveNode(temp2, temp2->find(right));
				kon = 1;
				break;
			}
			else {
				nr - temp->Mainlist.licznikzaj;
				if (temp->next != NULL) {
					temp = temp->next;
				}
				else {
					return;
				}
			}
		}
		if (temp2 == NULL) {
			temp->Mainlist.sectab[nr - 1] = Section();
			temp->Mainlist.licznikzaj--;
			for (int i = nr; i < 6; i++) {
				temp->Mainlist.sectab[i] = temp->Mainlist.sectab[i + 1];
			}
		}
		cout << left << ",D," << right << " == deleted" << endl;
	}

	static void OperationD(int left, MainList* lista) {
		MainList* temp = lista;
		int nr = left;
		while (true) {
			if (nr <= temp->Mainlist.licznikzaj) {
				temp->Mainlist.sectab[nr - 1] = Section();
				temp->Mainlist.licznikzaj--;
				for (int i = nr; i < 8; i++) {
					temp->Mainlist.sectab[i - 1] = temp->Mainlist.sectab[i];
				}
				cout << left << ",D,*" << " == deleted" << endl;
				return;
			}
			else {
				nr -= temp->Mainlist.licznikzaj;
				if (temp->next != NULL) {
					temp = temp->next;
				}
				else {
					return;
				}
			}
		}
	}
};
