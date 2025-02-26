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


	void print() const {
		cout << name << " - " << "Класс защиты: " << type << endl;
	}
	void fprint(ofstream& out) const {
		out << name << " - " << "Класс защиты: " << type << endl;
	}


	bool check(int t) {
		if (type > t) { return true; }
		else { return false; }
	}
};


int main(int argc, const char* argv[]) {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	if (argc != 3) { cerr << "Инвалид количество параметров" << endl; }
	const string fileCH(argv[1]);
	const string fileZ(argv[2]);
	int t;
	cout << "Введите необходимый класс защиты: "; cin >> t;
	
	string name1;
	int type1;
	firewall* pfirewall;
	

	ifstream fin(fileCH);
	if (!fin) {
		cerr << "Ошибка доступа к файлу.";
		system("pause");
		return 1;
	}

	ofstream fout(fileZ);
	if (!fout) {
		cerr << "Ошибка доступа к файлу.";
		system("pause");
		return 1;
	}

	int n;
	fin >> n;
	pfirewall = new firewall[n];
	vector <firewall> firewallData(n);
	for (int i = 0; i < n; i++) {
		fin >> name1;
		fin >> type1;
		pfirewall[i].set(name1, type1);
		firewallData[i].set(name1, type1);
	}

	for (int i = 0; i < n; i++) {
		if (firewallData[i].check(t) == true) {
			cout << "\nFirewal #" << i + 1 << endl;
			firewallData[i].print();
			fout << "\nFirewall #" << i + 1 << endl;
			firewallData[i].fprint(fout);
		}
	}
	return 0;
};
