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

	return 0;
}