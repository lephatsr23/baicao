#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <vector>
#include <fstream> 
#include <string>
using namespace std;
using std::cout;

int nguoichoi[5][3];
int diemnguoichoi[5];
#define SOTIENBANDAU 100000
#define SOCUOCMOIVAN 10000
#define solabai 3
typedef struct nguoichoibai {
	string ten;
	int diem;
	int tien;
	string vaitro;
	vector<string> nhunglabai;
	int cobacao;
} nguoiChoiBai;

int main() {
	cout << "Game Than bai bai cao " << endl;

	int diem = 0;
	int solabaiJQK = 0;
	int sovanchoi = 0;
	vector<nguoichoibai> danhsachnguoichoi;
	// doc file tu file txt
	ifstream filebai;
	filebai.open("input5.txt");
	string n;
	if (filebai.fail()) {
		cout << " Khong tim thay file bai " << endl;
		return -1;
	}
	nguoiChoiBai bientam;
	bientam.ten = "Dau";
	bientam.diem = 0;
	bientam.tien = SOTIENBANDAU;
	bientam.vaitro = "nha cai";
	danhsachnguoichoi.push_back(bientam);
	bientam.ten = "Ti";
	bientam.diem = 0;
	bientam.tien = SOTIENBANDAU;
	bientam.vaitro = "NguoiChoi";
	danhsachnguoichoi.push_back(bientam);
	bientam.ten = "Su";
	bientam.diem = 0;
	bientam.tien = SOTIENBANDAU;
	bientam.vaitro = "NguoiChoi";
	danhsachnguoichoi.push_back(bientam);
	bientam.ten = "Lu";
	bientam.diem = 0;
	bientam.tien = SOTIENBANDAU;
	bientam.vaitro = "NguoiChoi";
	danhsachnguoichoi.push_back(bientam);
	bientam.ten = "Teo Anh";
	bientam.diem = 0;
	bientam.tien = SOTIENBANDAU;
	bientam.vaitro = "NguoiChoi";
	danhsachnguoichoi.push_back(bientam);
	bientam.ten = "Teo Em";
	bientam.diem = 0;
	bientam.tien = SOTIENBANDAU;
	bientam.vaitro = "NguoiChoi";
	danhsachnguoichoi.push_back(bientam);


	filebai >> sovanchoi; 
	if (sovanchoi <= 0 && sovanchoi > 10) {
		cout << "So van choi khong hop le !!! phai nho hon 10";
		return 0;
	}
	cout << " So van choi : ";
	cout << sovanchoi <<endl;
	for (int k = 0; k < sovanchoi; k++) {
		//cout << " luot " << sovanchoi << endl;
		for (int i = 0; i < danhsachnguoichoi.size(); i++) {
			for (int j = 0; j < solabai; j++) {
				filebai >> n;
				danhsachnguoichoi[i].nhunglabai.push_back(n);
			}
		}
		/*filebai >> n;*/
	}
	filebai.close();
	for (int  k = 0; k < sovanchoi; k++)
	{
		//cout << " Mo bai luot " << sovanchoi << endl;
		//for (int i = 0; i < danhsachnguoichoi.size(); i++) {
		//	cout << "Nguoi choi thu " << i << endl;
		//	for (int j = k * solabai; j < solabai + k* solabai; j++) {
		//		cout << danhsachnguoichoi[i].nhunglabai[j] << " ";
		//	}
		//	cout << endl;
		//}
		for (int i = 0; i < danhsachnguoichoi.size(); i++) {
			solabaiJQK = 0;
			for (int j = k * solabai; j < solabai + k * solabai; j++) {
				if (danhsachnguoichoi[i].nhunglabai[j] == "J" || danhsachnguoichoi[i].nhunglabai[j] == "Q" || danhsachnguoichoi[i].nhunglabai[j] == "K") {
					solabaiJQK++;
				}
				if (solabaiJQK == 3) {
					danhsachnguoichoi[i].cobacao = 1;
				}
			}
		}
		for (int i = 0; i < danhsachnguoichoi.size(); i++) {
			if (danhsachnguoichoi[i].cobacao != 1) {
				diem = 0;
				for (int j = k * solabai; j < solabai + k * solabai; j++) {

					if (danhsachnguoichoi[i].nhunglabai[j] == "A") {
						diem = diem + 1;
					}
					else if (danhsachnguoichoi[i].nhunglabai[j] >= "2" && danhsachnguoichoi[i].nhunglabai[j] <= "9") {
						diem = diem + atoi(danhsachnguoichoi[i].nhunglabai[j].c_str());
					}
					else {
						diem = diem + 10;
					}
				}
				diem = diem % 10;
				danhsachnguoichoi[i].diem = diem;
			}
		}
		if (danhsachnguoichoi[0].cobacao == 1) {
			//cout << "Nha cai co ba cao " << endl;
		}
		else {
			//cout << "Nha cai co diem " << danhsachnguoichoi[0].diem << endl;
		}

		for (int i = 1; i < danhsachnguoichoi.size(); i++) {
			if (danhsachnguoichoi[0].cobacao == 1) {
				
				if (danhsachnguoichoi[i].cobacao != 1) {
					//cout << danhsachnguoichoi[i].ten << " Thua" << endl;
					danhsachnguoichoi[i].tien = danhsachnguoichoi[i].tien - SOCUOCMOIVAN;
					danhsachnguoichoi[0].tien = danhsachnguoichoi[0].tien + SOCUOCMOIVAN;
				}
				else if (danhsachnguoichoi[i].cobacao == 1) {
					//cout << danhsachnguoichoi[i].ten << " Hoa" << endl;
				}
			}
			else if (danhsachnguoichoi[0].cobacao != 1){
				
				if (danhsachnguoichoi[i].cobacao == 1) {
					//cout << danhsachnguoichoi[i].ten << " Thang" << endl;
					danhsachnguoichoi[i].tien = danhsachnguoichoi[i].tien + SOCUOCMOIVAN;
					danhsachnguoichoi[0].tien = danhsachnguoichoi[0].tien - SOCUOCMOIVAN;
				}
				else if (danhsachnguoichoi[0].diem > danhsachnguoichoi[i].diem) {
					//cout << danhsachnguoichoi[i].ten << " Thua" << endl;
					danhsachnguoichoi[i].tien = danhsachnguoichoi[i].tien - SOCUOCMOIVAN;
					danhsachnguoichoi[0].tien = danhsachnguoichoi[0].tien + SOCUOCMOIVAN;
				}
				else if (danhsachnguoichoi[0].diem < danhsachnguoichoi[i].diem) {
					//cout << danhsachnguoichoi[i].ten << " Thang" << endl;
					danhsachnguoichoi[i].tien = danhsachnguoichoi[i].tien + SOCUOCMOIVAN;
					danhsachnguoichoi[0].tien = danhsachnguoichoi[0].tien - SOCUOCMOIVAN;
				}
			}
		}
		for (int i = 0; i < danhsachnguoichoi.size(); i++) {
			danhsachnguoichoi[i].diem = 0;
			danhsachnguoichoi[i].cobacao = 0;
		}
	}
	cout << " KET QUA" << endl;
	for (int i = 0; i < danhsachnguoichoi.size() - 1; i++) {
		if (danhsachnguoichoi[i].tien < SOTIENBANDAU) {
			cout << danhsachnguoichoi[i].ten << " thua " <<  danhsachnguoichoi[i].tien << endl;
		}
		else if (danhsachnguoichoi[i].tien > SOTIENBANDAU) {
			cout << danhsachnguoichoi[i].ten << " thang " <<  danhsachnguoichoi[i].tien  << endl;
		}
		else if (danhsachnguoichoi[i].tien == SOTIENBANDAU) {
			cout << danhsachnguoichoi[i].ten << " hoa " << danhsachnguoichoi[i].tien << endl;
		}
	}
	if (danhsachnguoichoi[danhsachnguoichoi.size() - 1].tien < SOTIENBANDAU) {
		cout << danhsachnguoichoi[danhsachnguoichoi.size() - 1].ten << " thua " <<  danhsachnguoichoi[danhsachnguoichoi.size() - 1].tien ;
	}
	else if (danhsachnguoichoi[danhsachnguoichoi.size() - 1].tien > SOTIENBANDAU) {
		cout << danhsachnguoichoi[danhsachnguoichoi.size() - 1].ten << " thang " << danhsachnguoichoi[danhsachnguoichoi.size() - 1].tien;
	}
	else if (danhsachnguoichoi[danhsachnguoichoi.size() - 1].tien == SOTIENBANDAU) {
		cout << danhsachnguoichoi[danhsachnguoichoi.size() - 1].ten << " hoa " << danhsachnguoichoi[danhsachnguoichoi.size() - 1].tien;
	}

	system("pause");
	return 0;
}