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


void create_pipe(PIPE&p) {
	system("cls");
	cout << "Name -> ";
	cin.ignore();
	getline(cin, p.name);
	cout << "Length -> ";
	cin >> p.length;
	cout << "Diameter -> ";
	cin >> p.diameter;
	int Working = 0;
	cout << "Is Working(0 - Not Working, 1 - Working) -> ";
	cin >> Working;
	while (Working != 0 && Working != 1) {
		cout << "Enter ONLY 1 or ONLY 0";
		cin >> p.isWorking;
		Working = p.isWorking;
	}
	

	}
void edit_pipe(PIPE& p) {
	cout << "Choose what you want to edit: 1 - Name, 2 - Length, 3 - Diameter, 4 - Is Working 0 - Main menu" << "\n";
	while (true) {
		int c;
		cin >> c;
		if (c == 0)
			return;
		switch (c) {
		case 1: {
			cout << "Enter new name: ";
			cin >> p.name;
			return;
		}
		case 2: {
			cout << "Enter new length: ";
			cin >> p.length;
			return;
		}
		case 3: {
			cout << "Enter new diameter: ";
			cin >> p.diameter;
			return;
		}
		case 4: {
			int Working;
			cout << "Enter new isWorking (0 - Not Working, 1 - Working): ";
			cin >> Working;
			while (Working != 0 && Working != 1) {
				cout << "Enter ONLY 1 or ONLY 0";
				cin >> p.isWorking;
				Working = p.isWorking;
			}
			return;
		}
		default: {
			cout << "Error, choose the right option" << "\n";
			return;
		}
		}


	}
}
void show_pipe(const PIPE&p) {
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
	cout << "Choose what you want to edit: 1 - Name, 2 - Works, 3 - ActiveWorks, 4 - Efficiency 0 - Main menu" << "\n";
	int d;
	while (true) {
		cin >> d;
		if (d == 0)
			return;
		switch (d) {
		case 1: {
			cout << "Enter new name: ";
			cin >> s.name;
			break;
		}
		case 2: {
			cout << "Enter new works: ";
			cin >> s.works;
			break;
		}
		case 3: {
			cout << "Enter new active works: ";
			cin >> s.worksA;
			break;
		}
		case 4: {
			cout << "Enter new efficiency: ";
			cin >> s.efficiency;
			break;
		}
		default: {
			cout << "Error, choose the right option" << "\n";
			break;
		}
		}

	}
}
void show_ks(const KS&s) {
	cout << "Name -> " << s.name << "\n";
	cout << "Works -> " << s.works << "\n";
	cout << "Works Active -> " << s.worksA << "\n";
	cout << "Efficiency -> " << s.efficiency << "\n";
}
void saveall(const PIPE& p, const KS& s) {
	ofstream fout("data.txt");
	if (!fout) {
		cout << "Error opening file for writing" << "\n";
		return;
	}       
	fout << p.name << "\n" << p.length << "\n" << p.diameter << "\n" << p.isWorking << "\n";
	fout << s.name << "\n" << s.works << "\n" << s.worksA << "\n" << s.efficiency << "\n";
	cout << "Data were saved" << "\n";
}
void loadall(PIPE & p, KS & s) {
	ifstream fin("data.txt");
	if (!fin) {
		cout << "Error opening file for reading" << "\n";
		return;
	}
	getline(fin, p.name);
	fin >> p.length >> p.diameter >> p.isWorking;
	if (fin.fail()) {
		cout << "Ошибка: в файле неверные данные\n";
		return;
	}
	fin.ignore();
	getline(fin, s.name);
	fin  >> s.works >> s.worksA >> s.efficiency;
	if (fin.fail()) {
		cout << "Ошибка: в файле неверные данные\n";
		return;
	}
	fin.close();
	cout << "Data were loaded" << "\n";


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
			cout << "7. Save" << endl;
			cout << "8. Load" << endl;
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
				saveall(p, s); break;
			}
			case 8: {
				loadall(p, s); break;
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
