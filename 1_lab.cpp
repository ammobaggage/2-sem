#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;

class firewall {
	string name;
	int type;

public:
	firewall() {
		name = "";
		type = 0;
	}
	
	void set(string na, int ty) {
		name = na; 
		type = ty; 
	}

	firewall(string na, int ty) {
		name = na;
		type = ty;
	}
	
	void print() {
		cout << name << "Класс защиты: " << type << endl;
	}
};


int main() {
	
	setlocale(LC_ALL, "RU");

	int n;
	cin >> n;

	firewall* pfirewall;
	pfirewall = new firewall[]

}
