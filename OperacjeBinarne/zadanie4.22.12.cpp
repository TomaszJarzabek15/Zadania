//Cykliczny shift na danej typu short, w lewo o zadaną ilość miejsc.

#include <iostream>

using namespace std;

#define SIZE_S 16

void DisplayBinary(int n){

    int i;
	bool check = true;

    for (i = 1 << 16; i > 0; i = i >> 1){

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

int main(){
	
	int dana;
	short n;
	
	cin >> dana;
	cin >> n;
	
	DisplayBinary(dana);
	cout << endl;
	
	dana = (dana << n) | (dana >> (SIZE_S - n));
	
	DisplayBinary(dana);	
}
