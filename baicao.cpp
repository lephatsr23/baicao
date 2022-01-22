#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <vector>
#include <fstream> 
#include <string>
using namespace std;

int nguoichoi[5][3];
int diemnguoichoi[5];

int main() {
	cout << "Game Than bai bai cao " << endl;
	cout << endl;
	vector<int> diemcuanguoichoi;
	vector<vector<string>> nguoichoi;
	vector<string> data;
	vector<string> danhsachnguoichoi;
	int solabai = 3;
	int songuoichoi = 5;
	int diemmax = 0;
	int diem = 0;
	int solabaiJQK = 0;

	vector<string> danhsachnguoichoithang;

	// doc file tu file txt
	ifstream filebai;
	filebai.open("input3.txt");
	string n;
	if (filebai.fail()) {
		cout << " Khong tim thay file bai " << endl;
		return -1;
	}

	danhsachnguoichoi.push_back("Su");
	danhsachnguoichoi.push_back("Bu");
	danhsachnguoichoi.push_back("Lu");
	danhsachnguoichoi.push_back("Ku");
	danhsachnguoichoi.push_back("Zu");

	for (int i = 0; i < songuoichoi; i++) {
		vector<string> baicuanguoichoi;
		for (int j = 0  ; j < solabai; j++) {
			filebai >> n;
			baicuanguoichoi.push_back(n);
		}
		nguoichoi.push_back(baicuanguoichoi);
	}

	cout << " Moi bai " << endl;
	cout << endl;
	for (int i = 0; i < songuoichoi; i++) {
		for (int j = 0; j < solabai; j++) {
			cout << nguoichoi[i][j] << " ";
		}
		cout << endl;
	}

	
	for (int i = 0; i < songuoichoi; i++) {
		solabaiJQK = 0;
		for (int j = 0; j < solabai; j++) {
			if (nguoichoi[i][j] == "Q" || nguoichoi[i][j] == "K" || nguoichoi[i][j] == "J") {
				solabaiJQK++;
			}
		}
		if (solabaiJQK == 3) {
			danhsachnguoichoithang.push_back(danhsachnguoichoi[i]);
		}
	}
	
	if (danhsachnguoichoithang.size() == 0) {
		for (int i = 0; i < songuoichoi; i++) {
			diem = 0;
			for (int j = 0; j < solabai; j++) {
				if (nguoichoi[i][j] == "A") {
					diem++;
				}
				else if (nguoichoi[i][j] >= "2" && nguoichoi[i][j] <= "9")
				{
					diem = diem + atoi(nguoichoi[i][j].c_str());
				}
				else {
					diem = diem + 10;
				}
			}
			if (diemmax < diem) { diemmax = diem; }
			diemcuanguoichoi.push_back(diem);
		}

		for (int i = 0; i < diemcuanguoichoi.size(); i++)
		{
			if (diemcuanguoichoi[i] == diemmax) {
				danhsachnguoichoithang.push_back(danhsachnguoichoi[i]);
			}
		}
	}

	cout << " Nguoi choi chien thang " << endl;
	cout << endl;
	for (int i = 0; i < danhsachnguoichoithang.size();i++) {
		cout << danhsachnguoichoithang[i] << " " << endl;
	}

	filebai.close();
	system("pause");
	return 0;
}