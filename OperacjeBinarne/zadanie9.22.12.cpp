//Program wyznaczający XOR bez użycia operatora ^.

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

int main(){
	
	int a;
	int b;
	
	cin >> a;
	cin >> b;
	
	DisplayBinary(a);
	cout << endl;
	DisplayBinary(b);
	cout << endl;
	
	int XOR = ((a & (~b)) | ((~a) & b));
	
	DisplayBinary(XOR);
}