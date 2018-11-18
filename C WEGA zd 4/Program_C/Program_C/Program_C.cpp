#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
	ifstream sygnaly;
	sygnaly.open("sygnaly.txt");

	ofstream wyniki4;
	wyniki4.open("wyniki4.txt");

	wyniki4 << "4.1" << endl;

	string slowo;
	for (int i = 0; i < 25; i++){
		for (int j = 0; j<40; j++){
			sygnaly >> slowo;
		}
		wyniki4 << slowo[9];
	}
	
	wyniki4 << endl;

	sygnaly.close();

	/////////////////////////////////////////////////

	sygnaly.open("sygnaly.txt");
	
	wyniki4 << "4.2" << endl;

	string maxSlowo;
	int maxLiter = 0, suma;
	bool czyLiteraUrzyta[26];

	for (int i = 0; i < 1000; i++){
		suma = 0;
		for (int j = 0; j < 26; j++) czyLiteraUrzyta[j] = 0;

		sygnaly >> slowo;
		for (int j = 0; j < slowo.length(); j++){
			czyLiteraUrzyta[slowo[j] - 65] = true;
		}
		for (int j = 0; j < 26; j++){
			suma += czyLiteraUrzyta[j];
		}
		if (suma > maxLiter){
			maxLiter = suma;
			maxSlowo = slowo;
		}
	}

	wyniki4 << maxSlowo << " " << maxLiter << endl;

	sygnaly.close();
	
	/////////////////////////////////////////////////

	wyniki4 << "4.3" << endl;

	sygnaly.open("sygnaly.txt");
	
	int minLitera, maxLitera;
	bool dziala = true;
	for (int i = 0; i < 1000; i++){
		dziala = true;
		sygnaly >> slowo;
		minLitera = slowo[0];
		maxLitera = slowo[0];
		for (int j = 1; j < slowo.length(); j++){
			if (minLitera > slowo[j]) minLitera = slowo[j];
			if (maxLitera < slowo[j]) maxLitera = slowo[j];
			if (maxLitera - minLitera > 10){
				dziala = false;
				break;
			}

		}
		if (dziala) wyniki4 << slowo << endl;
	}
	sygnaly.close();
	wyniki4.close();
	return 0;
}