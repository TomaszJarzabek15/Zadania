//Cykliczny shift na danej typu short, w prawo o zadaną ilość miejsc.

#include <iostream>

using namespace std;



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

#define SHORT_S sizeof(short) * 8

int main(){
	
	short int dana = 0b1110110000110111;
	short n = 5;
	
	//cin >> dana;
	//cin >> n;
	
	DisplayBinary(dana);
	cout << endl;
	
	dana = ( dana >> n ) | ( dana << ( SHORT_S - n ) );
	
	DisplayBinary(dana);	
}
