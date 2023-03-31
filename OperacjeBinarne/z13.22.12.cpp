//Rozpoznać kodowanie typu float.

#include <iostream>

using namespace std;

void DisplayBinary(int n){

    int i;
    cout << "0";

    for (i = 1 << 16; i > 0; i = i >> 1){

        if((n & i) != 0){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
}

int main(){

    float numer;

    cin >> numer;

    cout << numer << endl;
    /*
    if(numer & (1 << 15)){
        cout << "ujemna" << endl;
    }
    else{
        cout << "nieujemna" << endl;
    }   */

    return 0;
}