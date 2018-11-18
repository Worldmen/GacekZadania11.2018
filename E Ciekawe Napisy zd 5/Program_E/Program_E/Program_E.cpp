#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	//vector<int> pierwsze;
	//bool sito[90 * 25+1];
	//for (int i = 2; i < 2251; i++){
	//	sito[i] = true;
	//}
	//for (int i = 2; i < 2251; i++){
	//	if (sito[i]){
	//		for (int j = i + i; j < 2251; j += i){
	//			sito[j] = false;
	//		}
	//		pierwsze.push_back(i);
	//	}
	//}

	//for (int i = 0; i < pierwsze.size(); i++)
	//	cout << pierwsze[i] << " ";

	ifstream napis;
	napis.open("NAPIS.txt");

	ofstream zadanie5;
	zadanie5.open("zadanie5.txt");

	string slowo;
	bool pierwsze;
	int suma, iloscA = 0;

	for (int i = 0; i < 1000; i++){
		pierwsze = true;
		suma = 0;
		napis >> slowo;

		for (int j = 0; j < slowo.length(); j++){
			suma += slowo[j];
		}
		for (int j = 2; j <= suma / 2; j++){
			if (suma%j == 0){
				pierwsze = false;
				break;
			}
		}
		if (pierwsze) iloscA++;
	}

	zadanie5 << "5.a" << endl << iloscA << endl;

	napis.close();

	///////////////////////////////////////////////////////////////

	napis.open("NAPIS.txt");

	zadanie5 << "5.b" << endl;

	bool dziala;

	for (int i = 0; i < 1000; i++){
		napis >> slowo;
		dziala = true;
		for (int j = 1; j < slowo.length(); j++){
			if (slowo[j] <= slowo[j - 1]){
				dziala = false;
				break;
			}
		}
		if (dziala){
			zadanie5 << slowo << endl;
		}
	}

	napis.close();

	///////////////////////////////////////////////////////////////

	napis.open("NAPIS.txt");

	zadanie5 << "5.c" << endl;

	string listaSlow[1000];
	vector<string> powielone;
	bool jest;

	for (int i = 0; i < 1000; i++){
		napis >> listaSlow[i];
	}

	for (int i = 0; i < 1000; i++){
		for (int j = i + 1; j < 1000; j++){
			if (listaSlow[i].length() == listaSlow[j].length()){
				dziala = true;
				for (int k = 0; k < listaSlow[i].length(); k++){
					if (listaSlow[i][k] != listaSlow[j][k]){
						dziala = false;
						break;
					}
				}
				if (dziala){
					jest = false;
					for (int k = 0; k < powielone.size(); k++){
						if (listaSlow[i].length() == powielone[k].length()){
							jest = true;
							for (int l = 0; l < listaSlow[i].length(); l++){
								if (listaSlow[i][l] != powielone[k][l]){
									jest = false;
									break;
								}
							}
							if (jest) break;
						}
					}
					if (!jest) powielone.push_back(listaSlow[i]);
				}
			}
		}
	}
	for (int i = 0; i < powielone.size(); i++){
		zadanie5 << powielone[i] << endl;
	}

	napis.close();
	zadanie5.close();

	return 0;
}