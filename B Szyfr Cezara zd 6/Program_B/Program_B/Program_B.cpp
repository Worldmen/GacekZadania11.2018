#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream dane_6_1;
	dane_6_1.open("dane_6_1.txt");
	
	ofstream wyniki_6_1;
	wyniki_6_1.open("wyniki_6_1.txt");

	int k = 107;
	k = k % 26;
	
	string slowo;
	for (int i = 0; i < 100; i++){
		dane_6_1 >> slowo;
		for (int j = 0; j < slowo.length(); j++){
			slowo[j] -= 65;
			slowo[j] += k;
			slowo[j] %= 26;
			slowo[j] += 65;
			wyniki_6_1 << slowo[j];
		}
		wyniki_6_1 << endl;
	}
	
	dane_6_1.close();
	wyniki_6_1.close();

	////////////////////////////////////////////////////////////

	ifstream dane_6_2;
	dane_6_2.open("dane_6_2.txt");

	ofstream wyniki_6_2;
	wyniki_6_2.open("wyniki_6_2.txt");

	int klucz;
	
	for (int i = 0; i < 3000; i++){
		dane_6_2 >> slowo >> klucz;
		klucz %= 26;
		for (int j = 0; j < slowo.length(); j++){
			slowo[j] -= 65;
			slowo[j] -= klucz;
			if (slowo[j] < 0) slowo[j] = 26 + slowo[j]; // dodajemy, poniewaz to jest tak 26 + (-n), a chcemy liczby miedzy <0;25>
			slowo[j] += 65;
			wyniki_6_2 << slowo[j];
		}
		wyniki_6_2 << endl;
	}

	dane_6_2.close();
	wyniki_6_2.close();

	////////////////////////////////////////////////////////////

	ifstream dane_6_3;
	dane_6_3.open("dane_6_3.txt");

	ofstream wyniki_6_3;
	wyniki_6_3.open("wyniki_6_3.txt");

	int kluczPodstawowy, kluczReszty;

	string slowo1, slowo2;
	bool dziala = true;

	for (int i = 0; i < 3000; i++){
		dane_6_3 >> slowo1 >> slowo2;
		
		if (slowo1.length() < 2) continue;
		
		kluczPodstawowy = slowo2[0] - slowo1[0];
		if (kluczPodstawowy < 0) kluczPodstawowy = 26 + kluczPodstawowy;
		
		for (int j = 1; j < slowo1.length(); j++){
			kluczReszty = slowo2[j] - slowo1[j];
			if (kluczReszty < 0) kluczReszty = 26 + kluczReszty;
			if (kluczPodstawowy != kluczReszty){
				dziala = false;
				break;
			}
		}
		if (!dziala) wyniki_6_3 << slowo1 << endl;
		dziala = true;
	}
	dane_6_3.close();
	wyniki_6_3.close();

	return 0;
}