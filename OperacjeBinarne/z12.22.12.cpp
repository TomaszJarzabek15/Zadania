//Rozpoznać kodowanie ujemności dla typu short.

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

    short numer;

    cin >> numer;

    DisplayBinary(numer);
    cout << endl;

    if(numer & (1 << 15)){
        cout << "ujemna" << endl;
    }
    else{
        cout << "nieujemna" << endl;
    }

    return 0;
}