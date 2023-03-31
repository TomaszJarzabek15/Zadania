//Program uzupełniający parzystość bitów 1 w danej typu short na pierwszym bicie 0.

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
	
	short int v;
	int counter = 0;
	
	cin >> v;
	
	DisplayBinary(v);
	cout << endl;
	
	for(int i = 0; i <= 16; i++){
		
		if(v & (1 << i)){
			counter++;
		}
	}
	cout << counter << endl;
	
	if((counter % 2) != 0){
		
		if(!(v & 1)){
			v = v | 1;
		}
		else{
			v = v | 32768;
		}	
	}
	
	DisplayBinary(v);
	cout << endl;	
}