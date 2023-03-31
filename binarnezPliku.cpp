#include <iostream>
#include <fstream>

using namespace std;

unsigned int Array [256][8];

unsigned int toDecimal(char liczba[]){

    unsigned int wynik = 0;
    unsigned int baza = 1;

    //cout << "baza na polu " << baza << endl;

    for(int i = 0; i < 32; i++){

        if(liczba[31 - i] == '1'){

            wynik = wynik + baza;
            //cout << "baza " << baza << endl;
            //cout << "wchodzi " << wynik << " iteracja " << i << endl;
        }
        else{

        }

        baza = baza * 2;
        //cout << baza << endl;
    }

    return wynik;
}

int main(){

    fstream inFile;
    fstream outFile;

    inFile.open("bits.txt", fstream::in);

    int linie = 0;

    char liczba[33];
    liczba[32] = '\0';

    char nowaLinia;

    for(int i = 0; i < 256; i++){
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 32; k++){

                liczba[k] = inFile.get();
            }

            //cout << liczba << endl;

            Array[i][j] = toDecimal(liczba);
            cout << Array[i][j] << endl;

        }
        nowaLinia = inFile.get();

        linie = linie + 1;

        if(inFile.eof()){
            i = 256;
        }
        //cout << "------------------" << endl;
    }

    inFile.close();     //koniec wczytywania array

    cout << "---------------------" << endl;

    inFile.open("parameters.txt", fstream::in);
    //powinno byc inFile.open("parameters.b", fstream::binary);

    int wiersz;
    int numerBitu;
    int liczbaBitow;
    int Bit;

    inFile >> wiersz;
    inFile >> numerBitu;
    inFile >> liczbaBitow;

    //cout << wiersz << endl;
    //cout << Array[wiersz][0] << endl;

    int koniec;
    int poczatek;
    int kolumna;
    int counter = 0;
    int i = 0;
    int k = 0;
    int j = 0;

    bool sprawdza = true;

    if(wiersz > linie){
        //nie wykonujemy operacji
    }
    else{

        if((numerBitu + liczbaBitow) < 256){

        }
        else{
            liczbaBitow = 256 - numerBitu;      //dzialamy do konca wiersza
        }
        //wykonujemy operacje
        koniec = numerBitu / 32;
        poczatek = (numerBitu + liczbaBitow) / 32;
        Bit = numerBitu % 32;

        if(poczatek == koniec){

            //jestesmy w jednej kolumnie
        
            while(i < liczbaBitow){

                if(Array[wiersz][poczatek] & (1 << k)){
                    counter++;
                }
                i++;
                k++;
                
            }

            cout << counter << endl;


            if((counter % 2) == 0){
                //nic nie robimy liczba jedynek jest parzysta
            }
            else{

                i = 0;

                while(i < liczbaBitow){

                    if(!(Array[wiersz][poczatek] & (0 << k))){

                        cout << "wchodzi " << endl;

                        Array[wiersz][poczatek] = Array[wiersz][poczatek] | (1 << k);

                        i = liczbaBitow;
                    }
                    i++;
                    k++;
                }

                cout << Array[wiersz][poczatek] << endl;

            }   //dziala
        }
        else{

            kolumna = poczatek;
            cout << "kolumna " << kolumna << endl;
            cout << "koniec " << koniec << endl;

            while(kolumna >= koniec){

                if(sprawdza){
                    j = 32 - ( ( Bit + liczbaBitow ) % 32);
                    sprawdza = false;
                    cout << "j " << j << endl;
                }
                else{
                    j = 0;
                }

                while(j < 32){

                    if(Array[wiersz][kolumna] & (1 << j)){
                        counter++;
                    }
                    i++;

                    if(i == liczbaBitow){
                        break;
                    }
                    j++;
                }


                kolumna--;
                cout << kolumna << endl;
                cout << "counter " << counter << endl;              
            }

            kolumna = poczatek;
            sprawdza = true;

            if((counter % 2) == 0){
                //nic nie robimy
            }
            else{

                while(kolumna >= koniec){

                    if(sprawdza){
                        j = 32 - ( ( Bit + liczbaBitow ) % 32);
                        sprawdza = false;
                        cout << "j " << j << endl;
                    }
                    else{
                        j = 0;
                    }

                    while(j < 32){

                        if(!(Array[wiersz][kolumna] & (0 << j))){
                            Array[wiersz][kolumna] = Array[wiersz][kolumna] | (1 << j);
                            j = 32;
                            kolumna = koniec;
                        }

                        if(i == liczbaBitow){
                            break;
                        }
                        i++;
                        j++;
                    }


                    kolumna--;
                    cout << kolumna << endl;
                    cout << "counter " << counter << endl;              
                }

                cout << "----------------------" << endl;
                cout << Array[wiersz][poczatek] << endl;

            }
        }
    }

    inFile.close();

    outFile.open("shorts.txt", fstream::out);


    for(int l = 0; l < 256; l++){

        for(int z = 0; z < 8; z++){

            for (long long int i = 1 << 32; i > (1 << 15); i = i >> 1){

                if((Array[l][z] & i) != 0){
                    outFile << '1';
                }
                else{
                    outFile << '0';
                }
                
            }
            outFile << ' ';


            for (int i = 1 << 15; i > 0; i = i >> 1){
                
                if((Array[l][z] & i) != 0){
                    outFile << '1';
                }
                else{
                    outFile << '0';
                }   
            }

            outFile << ' ';

        }


        outFile << endl;
    }



    outFile.close();

    return 0;
}