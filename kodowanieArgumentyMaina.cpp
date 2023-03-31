#include <iostream>
#include <string>

using namespace std;

unsigned char zakoduj (string napis){   // funkcja zamienia napis złożony z ośmiu zer i jedynek na jego binarną
                                            // reprezentację w zmiennej char. Do dostępu do poszczególnych liter stringa można
                                            // wykorzystać [] lub *.
    unsigned char suma = 0;
    int j = 0;
                                    
    for (int i = 7; i >= 0; i--)
	{
		if ( (napis[j] - 48) & 1)
		{
            suma = suma + (1 << i);
		}
		else
		{

		}
        j++;
	}
                        
    return suma;
}

string odkoduj(unsigned char suma){

    string napis = "";
    int j = 0;
    bool sprawdza = true;

    for (int i = 256; i > 0; i /= 2)
	{
		if (suma / i)
		{
			napis = napis + "1";
			suma -= i; // Po co ta linijka?
		}
		else if(sprawdza == false)
		{
            napis = napis + "0";
		}

        sprawdza = false;
        j++;
	}

    return napis;
} //jest odwrotnością poprzedniej funkcji. Do dostępu do poszczególnych liter stringa można wykorzystać [] lub *.

unsigned char zaszyfruj(unsigned char tekst, unsigned char klucz){

    unsigned char kod;

    kod = ((tekst & (~klucz)) | ((~tekst) & klucz));

    return kod;
} //szyfrowanie XOR-em, NIE UŻYWAJ OPERATORA ^.

unsigned char odszyfruj(unsigned char kod, unsigned char klucz){

    unsigned char tekst;

    tekst = ((kod & (~klucz)) | ((~kod) & klucz));

    return tekst;
} //odszyfrowywanie XOR-em, NIE UŻYWAJ OPERATORA ^. 
    // Czy zamiana argumentów coś zmienia?  NIE
    // Czy ta funkcja potrzebna?    NIE

string zaszyfruj(string tekst, string klucz){

    string kod = "";
    bool sprawdza = false;

    int size = tekst.length();

    unsigned char litera;

    unsigned char znakT;
    unsigned char znakK;

    for(int j = 0; j < size; j++){

        string A = tekst.substr(j, 8);
        string B = klucz.substr(j, 8);

        int length = A.length();

        if(length < 8){     //za krotki trzeba dopelnic

            sprawdza = true;
            int dlugosc = 8 - length;

            for(int i = 0; i < dlugosc; i++){
                A = A + "0";
                B = B + "0";
            }
        }

        znakT = zakoduj(A);
        znakK = zakoduj(B);
        litera = (znakT & (~znakK)) | ((~znakT) & znakK);

        if(sprawdza){
            string C = odkoduj(litera);
            kod = kod + C.substr(0, length);
            break;
        }
        else{
            kod = kod + odkoduj(litera);
        }

        j = j + 7;
    }

    return kod;
} //funkcja szyfruje XOR-em tekst złożony z dowolnej liczby zer i jedynek za pomocą klucza (zakładamy, że tej samej długości co tekst). Napisz program wykonujący tą funkcję z argumentami wywołania main-a.

string odszyfruj(string kod, string klucz){

    string tekst = "";
    bool sprawdza = false;

    int size = kod.length();

    unsigned char litera;

    unsigned char znakT;
    unsigned char znakK;

    for(int j = 0; j < size; j++){

        string A = kod.substr(j, 8);
        string B = klucz.substr(j, 8);

        int length = A.length();

        if(length < 8){     //za krotki trzeba dopelnic

            sprawdza = true;
            int dlugosc = 8 - length;

            for(int i = 0; i < dlugosc; i++){
                A = A + "0";
                B = B + "0";
            }
        }

        znakT = zakoduj(A);
        znakK = zakoduj(B);
        litera = (znakT & (~znakK)) | ((~znakT) & znakK);

        if(sprawdza){
            string C = odkoduj(litera);
            tekst = tekst + C.substr(0, length);
            break;
        }
        else{
            tekst = tekst + odkoduj(litera);
        }

        j = j + 7;
        
    }

    return tekst;
} //jest odwrotnością poprzedniej funkcji. Napisz program wykonujący tą funkcję z argumentami wywołania main-a.


//czesc 2

unsigned char zaszyfruj2(unsigned char tekst, unsigned char klucz){

    unsigned char kod;

    kod = ((tekst & (~klucz)) | ((~tekst) & klucz));
    kod = (kod << 2) | (kod >> (8 - 2));    //cykliczny shift w lewo o dwie pozycje

    return kod;
} //szyfrowanie Państwa własnym algorytmem. Ma on wykorzystywać XOR i operator przesunięcia.

unsigned char odszyfruj2(unsigned char kod, unsigned char klucz){

    unsigned char tekst;

    kod = (kod >> 2 ) | (kod << (8 - 2));     //cykliczny shift w prawo o dwie pozycje
    tekst = ((kod & (~klucz)) | ((~kod) & klucz));

    return tekst;
} //odwrotność poprzedniej funkcji.

string przeczytaj(string tekst){

    string czytane = "";
    unsigned char znak;

    bool sprawdza = false;

    string A;

    for(int j = 0; j < tekst.length(); j++){

        A = tekst.substr(j, 8);
        int length = A.length();

        if(length < 8){     //za krotki trzeba dopelnic

            sprawdza = true;
            int dlugosc = 8 - length;

            for(int i = 0; i < dlugosc; i++){
                A = A + "0";
            }
        }

        znak = zakoduj(A);

        czytane = czytane + odkoduj(znak);
    }

    return czytane;
} //”czyta” tekst o dowolnej długości złożony z zer i jedynek - przykładowo dla argumentu "1010101011" zwracany jest napis "jeden zero jeden zero jeden zero jeden zero jeden jeden". Napisz program wykonujący tą funkcję z argumentami wywołania main-a.



int main(int argc, char *argv[]){

    unsigned char kod = zakoduj("00001111");

    cout << int(kod) << endl;
    
    string napis = odkoduj(kod);
    cout << napis << endl;

    unsigned char A = 15;
    unsigned char B = 1;

    unsigned char C = zaszyfruj(A, B);
    cout << int(C) << endl;

    cout << int(odszyfruj(C, B)) << endl;

    // for (int i = 0; i < argc; i++){
	// 	cout << argv[i] << endl;
	// }

    string coded = zaszyfruj(argv[1], argv[2]);
    cout << coded << endl;

    cout << odszyfruj(coded, argv[2]) << endl;

    cout << przeczytaj(argv[3]) << endl;

    A = 56;
    B = 1;

    //cout << sizeof(unsigned char) << endl;

    C = zaszyfruj2(A, B);
    cout << int(C) << endl;

    cout << int(odszyfruj2(C, B)) << endl;

    return 0;
}