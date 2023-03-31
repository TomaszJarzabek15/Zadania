//Odejmowanie arytmetyczne tylko operacjami bitowymi.

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

int main(){
	
	int a;
	int b;
	
	cin >> a;
	cin >> b;
	
	DisplayBinary(a);
	cout << endl;
	DisplayBinary(b);
	cout << endl;

	int roznica = Roznica(a, b);

	DisplayBinary(roznica);
	
}