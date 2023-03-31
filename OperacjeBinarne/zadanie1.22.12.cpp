//Program zliczający ilość bitów 1 w danej typy short.

#include <iostream>

using namespace std;

int main(){
	
	short int v;
	int counter = 0;
	
	cin >> v;
	
	for(int i = 0; i < 16; i++){
		
		if(v & (1 << i)){
			counter++;
		}
	}
	
	cout << counter << endl;
}
