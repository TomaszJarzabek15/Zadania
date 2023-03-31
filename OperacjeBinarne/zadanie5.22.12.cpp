//Dodawanie arytmetyczne tylko operacjami bitowymi.

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

int Suma(int a, int b){

	int x = a;
	int y = b;

	while(y != 0){

		unsigned int c = x & y;

		x = x ^ y;

		y = c << 1;
	}
	cout << x << endl;

	return x;
}

int main(){
	
	int a;
	int b;
	
	cin >> a;
	cin >> b;
	
	DisplayBinary(a);
	cout << endl;
	DisplayBinary(b);
	cout << endl;

	int suma = Suma(a, b);

	DisplayBinary(suma);
	
}