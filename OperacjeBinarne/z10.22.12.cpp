//Program wyznaczający średnią dwóch dodatnich liczby typu short tylko z użyciem operatorów logicznych.

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

int Suma(int a, int b){

	int x = a;
	int y = b;

	while(y != 0){

		unsigned c = x & y;

		x = x ^ y;

		y = c << 1;
	}

	return x;
}

int main(){
	
	int a;
    int b;

    short srednia;
	
	cin >> a;
    cin >> b;
	
	DisplayBinary(a);
	cout << endl;
    DisplayBinary(b);
	cout << endl;

    srednia = (Suma(a, b) >> 1);        //(a+b)/2

	DisplayBinary(srednia);
}