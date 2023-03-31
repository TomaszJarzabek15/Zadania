//Kalkulator działań binarnych. Dane dwie wartości typu short oraz string operatorów bitowych. Program wypisujący bitowo kolejne wyniki działań.

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

void kalkulator(short a, short b, char znaki[], short wynik[]){
	
	int i = 0;
	
	while(znaki[i] != '\0'){
		
		switch(znaki[i]){
			
			case '~':
				wynik[i] = ~a;
				break;
				
			case '&':
				wynik[i] = a & b;
				break;
				
			case '^':
				wynik[i] = a ^ b;
				break;
				
			case '|':
				wynik[i] = a | b;
				break;
			
			default:
				cout << "error" << endl;
				break;
		}
		
		i++;
	}
}

int main(){
	
	short a;
	short b;
	
	int n;
	
	cin >> a;
	cin >> b;
	
	cin >> n;
	
	char znaki[n];
	short wynik[n];
	
	cin >> znaki;
	
	DisplayBinary(a);
	cout << endl;
	DisplayBinary(b);
	cout << endl;
	
	kalkulator(a, b, znaki, wynik);
	
	for(int i = 0; i < n; i++){
		DisplayBinary(wynik[i]);
		cout << endl;
	}
	
	return 0;
}
