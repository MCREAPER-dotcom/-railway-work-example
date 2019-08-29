#include<iostream>
#include <string>
#include<set>
#include<fstream>
using namespace std;

class Train {
public:
	int Number;
	string Station;
	string Date;
	Train() {
		Number = 0;
		Station = "";
		Date = "";
	}
	Train(int a, string b, string t3) {
		Number = a;
		Station = b;
		Date = t3;
	}
	void const operator ()(int a, string b, string t3) {
		Number = a;
		Station = b;
		Date = t3;
	}
};
void pre_print() {
	cout << "NUMBER OF TRAIN " << "\t";
	cout << "STATION " << "\t";
	cout << "DATE (DD.MM.YY)" << endl;
}
void print1(Train& tr) {
	cout << tr.Number << "\t" << "\t" << "\t";
	cout << tr.Station << "\t" << "\t";
	cout << tr.Date << endl;
}
bool create(Train& tre, set<string>& Station) {
	int a;
	int k1 = 0;
	string t3;
	string b;
	cout << "Input number of train " << endl;
	while (true)
	{
		cin >> a;
		if (!cin)
		{
			cout << "INCORRECT" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
	//cin >> a;
	cout << "Input name of station (10simbol)" << endl;
	char t1[10];
	cin >> t1; b = t1;
	for (set<string>::iterator iter = Station.begin(); iter != Station.end(); ++iter) { if (*iter == b)k1++; }
	while (k1 == 0)
	{
		cout << "Repeat correct name of station (10simbol)" << endl;
		char t1[10];
		cin >> t1; b = t1;
		k1 == 0;
		for (set<string>::iterator iter = Station.begin(); iter != Station.end(); ++iter) { if (*iter == b)k1++; }
	};
	cout << "Input departure time (DD,MM,YY)" << endl;
	char t[10];
	cin >> t;
	t3 = t;
	tre(a, b, t3);
	return 1;
}
void printN(Train& tr, int N) {
	if (tr.Number == N) {
		cout << tr.Number << "\t" << "\t" << "\t";
		cout << tr.Station << "\t" << "\t";
		cout << tr.Date << endl;
	}
}
void printS(Train& tr, string st) {
	if (tr.Station == st) {
		cout << tr.Number << "\t" << "\t" << "\t";
		cout << tr.Station << "\t" << "\t";
		cout << tr.Date << endl;
	}
}
void createF(set<string>& TStation) {
	string tb, buff;
	char t[50];
	cout << "Input name file" << endl;
	cin >> t; tb = t;
	string* m;
	int k = 0, i = 0;
	ifstream fin(tb);
	while (getline(fin, buff))k++;
	m = new string[k];
	fin.close();
	Train* tr = new Train[k];
	ifstream fin1(tb);
	while (getline(fin1, m[i])) {
		int a = 0, it = 0, it1 = 0, it2 = 0, k1 = 0;
		char t1[10];
		char t2[10];
		char t3[10];
		string ftin;
		string f1tin;
		while (m[i][it] != ' ') { t1[it] = m[i][it]; it++; }
		a = atoi(t1);
		while (m[i][it + it1 + 1] != ' ') { t2[it1] = m[i][it + it1 + 1]; it1++; }
		for (int j = it1; j <= 9; j++)t2[j] = '\0';
		ftin = t2;
		while (m[i][it + it1 + 2 + it2] != '\0') { t3[it2] = m[i][it + it1 + 2 + it2]; it2++; }
		for (int j = it2; j <= 9; j++)t3[j] = '\0';
		f1tin = t3;
		for (set<string>::iterator iter = TStation.begin(); iter != TStation.end(); ++iter) { if (*iter == ftin)k1++; }
		while (k1 == 0) {
			cout << "Repeat correct name of station (10simbol) for reis number:"; cout << a << endl;
			char t11[10];
			cin >> t11; ftin = t11;
			k1 == 0;
			for (set<string>::iterator iter = TStation.begin(); iter != TStation.end(); ++iter) { if (*iter == ftin)k1++; }
		};
		tr[i](a, ftin, f1tin);
		print1(tr[i]);
		i++;
	}
	delete[]m;
	int lk;
	char lkk = 'N';
	do {
		cout << "Chose the output tipe(1-all, 2-the number, 3-the name of station)" << endl;
		cin >> lk;
		if (lk == 1) {
			pre_print();
			for (int i = 0; i <= k - 1; i++)
				print1(tr[i]);
		}
		else if (lk == 2) {
			int N;
			cout << "Input number of train" << endl;
			while (true)
			{
				cin >> N;
				if (!cin)
				{
					cout << "INCORRECT" << endl;
					cin.clear();
					while (cin.get() != '\n');
				}
				else break;
			}
			pre_print();
			for (int i = 0; i <= k - 1; i++)
				printN(tr[i], N);
		}
		else if (lk == 3) {
			char t[10];
			cout << "Input name of station (10simbol)" << endl;
			cin >> t;
			string t1 = t;
			pre_print();
			for (int i = 0; i <= k - 1; i++)
				printS(tr[i], t1);
		}
		else cout << "Incorrect tipe of date" << endl;
		cout << "Do you want to continue?(Y/N)" << endl;
		cin >> lkk;
		if (lkk == 'N' || lkk == 'n')break;
		if (lkk != 'y' || lkk != 'Y' || lkk != 'N' || lkk != 'n')cout << "Incorrect tipe of date" << endl;
	} while (lkk == 'y' || lkk == 'Y');
	delete[]tr;
	fin1.close();
}
int main() {
	set<string>Station = { "tombov","pol'sk","moskov","taganrog","kirov","vershki","brest","timirov","per'm","troyka","lugansk","donbas","negev","atrov ","ST_peterb","Ekaterenb","palatka","mirnuy","atrov" };
	int f = 0, k = 0;
	cout << "Chouse the form of input" << endl;
	cout << "Manual input 1 or Input from file 2" << endl;
	cin >> f;
	Train* tre;
	if (f == 1) {
		cout << "Input quantity of train" << endl;
		while (true)
		{
			cin >> k;
			if (!cin)
			{
				cout << "INCORRECT" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
		}
		tre = new Train[k];
		for (int i = 0; i <= k - 1; i++) {
			create(tre[i], Station);
		}
		int lk = 0;
		char lkk = 'N';
		do {
			cout << "Chose the output tipe(1-all, 2-the number, 3-the name of station)" << endl;
			while (true)
			{
				cin >> lk;
				if (!cin)
				{
					cout << "INCORRECT" << endl;
					cin.clear();
					while (cin.get() != '\n');
				}
				else break;
			}
			if (lk == 1) {
				pre_print();
				for (int i = 0; i <= k - 1; i++)
					print1(tre[i]);
			}
			else if (lk == 2) {

				cout << "Input number of train" << endl;
				int N;
				while (true) {
					cin >> N;
					if (!cin)
					{
						cout << "INCORRECT" << endl;
						cin.clear();
						while (cin.get() != '\n');
					}
					else break;
				};
				pre_print();
				for (int i = 0; i <= k - 1; i++)
					printN(tre[i], N);
			}
			else if (lk == 3) {
				char t[10];
				cout << "Input name of station (10simbol)" << endl;
				cin >> t;
				string t1 = t;
				pre_print();
				for (int i = 0; i <= k - 1; i++)
					printS(tre[i], t1);
			}
			else cout << "Incorrect tipe of date" << endl;
			cout << "Do you want to continue?(Y/N)" << endl;
			cin >> lkk;
			if (lkk == 'N' || lkk == 'n')break;
			if (lkk != 'y' || lkk != 'Y' || lkk != 'N' || lkk != 'n')cout << "Incorrect tipe of date" << endl;
		} while (lkk == 'Y' || lkk == 'y');
		delete[]tre;
	}
	if (f == 2) {
		createF(Station);
	}
}
