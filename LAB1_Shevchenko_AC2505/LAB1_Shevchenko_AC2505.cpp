// LAB1_Shevchenko_AC2505.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
struct PIPE {
	string name;
	double length;
	double diameter;
	bool isWorking;
};
struct KS {
	string name;
	int works;
	int worksA;
	double efficiency;

};


void create_pipe(PIPE& p) {
	system("cls");
	cout << "Name -> ";
	cin.ignore();
	getline(cin, p.name);

	cout << "Length -> ";
	cin >> p.length;
	while (cin.fail() || p.length <= 0) {
		cin.clear();                                          // снять флаг ошибки с потока
		cin.ignore(100000000000, '\n');  // выбросить неверный ввод
		cout << "Error, length must be a positive number -> ";
		cin >> p.length;
	}

	cout << "Diameter -> ";
	cin >> p.diameter;
	while (cin.fail() || p.diameter <= 0) {
		cin.clear();
		cin.ignore(10000000000000, '\n');
		cout << "Error, diameter must be a positive number -> ";
		cin >> p.diameter;
	}

	int working;
	cout << "Is Working (0 - Not Working, 1 - Working) -> ";
	cin >> working;
	while (cin.fail() || (working != 0 && working != 1)) {
		cin.clear();
		cin.ignore(10000000000000000, '\n');
		cout << "Error, enter ONLY 0 or 1 -> ";
		cin >> working;
	}
	p.isWorking = working;
}
void edit_pipe(PIPE& p) {
	cout << "Choose what you want to edit: 1 - Name, 2 - Is Working, 0 - Main menu" << "\n";
	int c;
	cin >> c;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000000000, '\n');
		cout << "Error, choose the right option" << "\n";
		return;
	}
	switch (c) {
	case 1: {
		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, p.name);
		break;
	}
	case 2: {
		int working;
		cout << "Enter new isWorking (0 - Not Working, 1 - Working): ";
		cin >> working;
		while (cin.fail() || (working != 0 && working != 1)) {
			cin.clear();
			cin.ignore(100000000000, '\n');
			cout << "Error, enter ONLY 0 or 1 -> ";
			cin >> working;
		}
		p.isWorking = working;
		break;
	}
	case 0: {
		break;
	}
	default: {
		cout << "Error, choose the right option" << "\n";
		break;
	}
	}
}void show_pipe(const PIPE&p) {
	cout << "Name -> " << p.name << "\n";
	cout << "Length -> " << p.length << "\n";
	cout << "Diameter -> " << p.diameter << "\n";
	cout << "Is Working(0 - Not Working, 1 - Working) -> " << p.isWorking << "\n";

}

void create_ks(KS& s) { 
	cout << "Name -> ";
	cin.ignore();
	getline(cin, s.name);
	cout << "Works -> ";
	cin >> s.works;
	cout << "Active Works -> ";
	cin >> s.worksA;
	cout << "Efficiency -> ";
	cin >> s.efficiency;
	if (s.efficiency < 0 || s.efficiency > 100) {
		cout << "Error, efficiency must be between 0 and 100" << "\n";
		s.efficiency = 0;
	}
}
void edit_ks(KS& s) {
	cout << "Choose what you want to edit: 1 - Name, 2 - Active Works, 0 - Main menu" << "\n";
	int d;
	cin >> d;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(100000000000, '\n');
		cout << "Error, choose the right option" << "\n";
		return;
	}
	switch (d) {
	case 1: {
		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, s.name);
		break;
	}
	case 2: {
		cout << "Enter new active works (0 to " << s.works << "): ";
		cin >> s.worksA;
		while (cin.fail() || s.worksA < 0 || s.worksA > s.works) {
			cin.clear();
			cin.ignore(10000000000000, '\n');
			cout << "Error, active works must be from 0 to " << s.works << " -> ";
			cin >> s.worksA;
		}
		break;
	}
	case 0: {
		break;
	}
	default: {
		cout << "Error, choose the right option" << "\n";
		break;
	}
	}
}
void show_ks(const KS&s) {
	cout << "Name -> " << s.name << "\n";
	cout << "Works -> " << s.works << "\n";
	cout << "Works Active -> " << s.worksA << "\n";
	cout << "Efficiency -> " << s.efficiency << "\n";
}
void save_pipe(const PIPE& p) {
	ofstream fout("pipe.txt");
	if (!fout) {
		cout << "Error opening pipe.txt for writing" << "\n";
		return;
	}
	fout << p.name << "\n" << p.length << "\n" << p.diameter << "\n" << p.isWorking << "\n";
	fout.close();
	cout << "Pipe was saved" << "\n";
}

void load_pipe(PIPE& p) {
	ifstream fin("pipe.txt");
	if (!fin) {
		cout << "Error opening pipe.txt for reading" << "\n";
		return;
	}
	PIPE tmp;
	getline(fin, tmp.name);
	fin >> tmp.length >> tmp.diameter >> tmp.isWorking;
	if (fin.fail()) {
		cout << "Error: wrong pipe data in file" << "\n";
		return;
	}
	fin.close();
	p = tmp;
	cout << "Pipe was loaded" << "\n";
}

void save_ks(const KS& s) {
	ofstream fout("ks.txt");
	if (!fout) {
		cout << "Error opening ks.txt for writing" << "\n";
		return;
	}
	fout << s.name << "\n" << s.works << "\n" << s.worksA << "\n" << s.efficiency << "\n";
	fout.close();
	cout << "KS was saved" << "\n";
}

void load_ks(KS& s) {
	ifstream fin("ks.txt");
	if (!fin) {
		cout << "Error opening ks.txt for reading" << "\n";
		return;
	}
	KS tmp;
	getline(fin, tmp.name);
	fin >> tmp.works >> tmp.worksA >> tmp.efficiency;
	if (fin.fail()) {
		cout << "Error: wrong KS data in file" << "\n";
		return;
	}
	fin.close();
	s = tmp;
	cout << "KS was loaded" << "\n";
}
int main()
{
	PIPE p{};
	KS s{};
	int d;
		do {
			system("cls");
			cout << "1. Create pipe" << endl;
			cout << "2. Edit pipe" << endl;
			cout << "3. Show pipe" << endl;
			cout << "4. Create KS" << endl;
			cout << "5. Edit KS" << endl;
			cout << "6. Show KS" << endl;
			cout << "7. Save pipe" << endl;
			cout << "8. Load pipe" << endl;
			cout << "9. Save KS" << endl;
			cout << "10. Load KS" << endl;
			cout << "0. Exit" << endl;
			cout << "Choose an option: ";
			cin >> d;
			switch (d) {
			case 1: {
				create_pipe(p); break;
			}
			case 2: {
				edit_pipe(p); break;
			}
			case 3: {
				show_pipe(p); break;
			}
			case 4: {
				create_ks(s); break;
			}
			case 5: {
				edit_ks(s); break;

			}
			case 6: {
				show_ks(s); break;
			}
			case 7: {
				save_pipe(p); break;
			}
			case 8: {
				load_pipe(p); break;
			}
			case 9: {
				save_ks(s); break;
			}
			case 10: {
				load_ks(s); break;
			}
			case 0:
			{
				cout << "Exiting..." << endl;
				break;
			}
			default:
			{
				cout << "Error, choose the right option" << endl;
				break;
			}


			}
			if (d != 0) {
				cout << "\n";
				system("pause");
			} 

		} while (d != 0);
		return 0;

}
