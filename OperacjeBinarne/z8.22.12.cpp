//Mnożenie parzystej liczby typu short przez 3.5 tylko z użyciem operacji bitowych

#include <iostream>

using namespace std;

void DisplayBinary(int n){

    int i;
	bool check = true;

    for (i = 1 << 30; i > 0; i = i >> 1){

		if(check){
			check = false;
		}
		else{
			if((n & i) != 0){
				cout << "1";
			}
			else{
				cout << "0";
			}
		}
    }
}

int Roznica(int a, int b){

	int x = a;
	int y = b;

	while(y != 0){

		unsigned c = (~x) & y;

		x = x ^ y;

		y = c << 1;
	}

	return x;
}

int Mnozenie3i5(int numer){     //3.5x = (8x - x)/2;

    int wynik;

    wynik = Roznica(numer << 3, numer) >> 1;

    return wynik;
}

int main(){
	
	int numer;
	
	cin >> numer;
	
	DisplayBinary(numer);
	cout << endl;

	DisplayBinary(Mnozenie3i5(numer));
}