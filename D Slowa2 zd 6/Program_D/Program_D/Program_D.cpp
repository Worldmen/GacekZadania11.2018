#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream slowa;
	slowa.open("slowa.txt");

	ofstream wyniki6;
	wyniki6.open("wyniki6.txt");

	wyniki6 << "6.1" << endl;

	string slowo;
	int iloscA = 0;

	for (int i = 0; i < 2000; i++){
		slowa >> slowo;
		if (slowo.back() == 'A') iloscA++;
	}
	wyniki6 << iloscA << endl;

	slowa.close();

	//////////////////////////////////////////////////////

	wyniki6 << "6.2" << endl;

	slowa.open("slowa.txt");
	
	string slowo1, slowo2;
	int iloscB = 0;
	int iloscSprawdzan;
	bool dziala = true;

	for (int i = 0; i < 1000; i++){
		slowa >> slowo1 >> slowo2;
		if (slowo1.length() > slowo2.length()) continue;

		iloscSprawdzan = slowo2.length() - slowo1.length();
		for (int j = 0; j <= iloscSprawdzan; j++){
			for (int k = 0; k < slowo1.length(); k++){
				if (slowo1[k] != slowo2[j + k]){
					dziala = false;
					break;
				}
			}
			if (dziala){
				iloscB++;
				break;
			}
			dziala = true;
		}
	}

	wyniki6 << iloscB << endl;
	slowa.close();

	//////////////////////////////////////////////////////

	wyniki6 << "6.3" << endl;

	slowa.open("slowa.txt");

	int iloscC = 0;
	int litery[26];

	for (int i = 0; i < 1000; i++){
		slowa >> slowo1 >> slowo2;
		if (slowo1.length() != slowo2.length()) continue;
		
		dziala = true;
		for (int j = 0; j < 26; j++){
			litery[j] = 0;
		}
		for (int j = 0; j < slowo1.length(); j++){
			litery[slowo1[j] - 65]++;
			litery[slowo2[j] - 65]--;
		}
		for (int j = 0; j < 26; j++){
			if (litery[j] != 0){
				dziala = false;
				break;
			}
		}
		if (dziala) iloscC++;
	}
	wyniki6 << iloscC << endl;

	slowa.close();
	wyniki6.close();

	return 0;
}