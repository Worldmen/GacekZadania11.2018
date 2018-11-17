#include <fstream>
#include <string>

using namespace std;
int main(){
	ifstream slowa;
	int n[13], maxDlugosc = 13;
	for (int i = 0; i < maxDlugosc; i++) n[i] = 0;

	string slowoWczytane;
	int dlugoscSlowa;
	slowa.open("slowa.txt");
	for (int i = 0; i < 1000; i++){
		slowa >> slowoWczytane;
		dlugoscSlowa = slowoWczytane.length();
		n[dlugoscSlowa]++;
	}
	slowa.close();

	ofstream  wynik5;
	wynik5.open("wynik5.txt");

	wynik5 << "5.1" << endl;

	for (int i = 1; i < maxDlugosc; i++){
		wynik5 << i << " " << n[i] << endl;
	}

	/////////////////////////////////////////////////////
	
	wynik5 << "5.2" << endl;

	ifstream nowe;
	string noweSlowa[25];
	bool takieSameN = true, takieSameO = true;
	int wystapienie[25][2];
	// wystapienie[n][0] - wystapienia w normalnej wersji
	// wystapienie[n][1] - wystapienia w odwroconej wersji
	nowe.open("nowe.txt");
	for (int i = 0; i < 25; i++){
		for (int j = 0; j < 2; j++){
			wystapienie[i][j] = 0;
		}
	}

	for (int i = 0; i < 25; i++){
		nowe >> noweSlowa[i];
	}
	for (int i = 0; i < 25; i++){
		slowa.open("slowa.txt");
		for (int j = 0; j < 1000; j++){
			slowa >> slowoWczytane;
			if (slowoWczytane.length() == noweSlowa[i].length()){
				for (int k = 0; k < noweSlowa[i].length(); k++){
					if (noweSlowa[i][k] != slowoWczytane[k]){
						takieSameN = false;
						break;
					}
				}
				for (int k = 0; k < noweSlowa[i].length(); k++){
					if (noweSlowa[i][k] != slowoWczytane[slowoWczytane.length() - 1 - k]){
						takieSameO = false;
						break;
					}
				}
				if (takieSameN) wystapienie[i][0]++;
				if (takieSameO) wystapienie[i][1]++;
				takieSameN = true;
				takieSameO = true;
			}
		}
		slowa.close();
	}

	for (int i = 0; i < 25; i++){
		wynik5 << noweSlowa[i] << " " << wystapienie[i][0]<< " " << wystapienie[i][1] << endl;
	}
	nowe.close();
	wynik5.close();
	return 0;
}