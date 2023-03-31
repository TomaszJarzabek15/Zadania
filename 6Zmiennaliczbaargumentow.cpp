#include <iostream>
#include <cstdarg>
#include <fstream>
#include <string>

using namespace std;

void zaprezentujArgumenty(const char* typy, ...)
{
	int calkowita;
	char*  napis;
	double  zmiennoprzecinkowa;

	va_list ap;

	va_start(ap, typy); //typy - ostatni argument przed kropkami

	int i = 0; char c;
	while ((c = typy[i++]) != '\0')
	{
		switch (c)
		{
		case 'c':
			calkowita = va_arg(ap, int);
			cout << "Liczba int   : " << calkowita << endl;
			break;
		case 'z':
			zmiennoprzecinkowa = va_arg(ap, double);
			cout << "Liczba double: " << zmiennoprzecinkowa << endl;
			break;
		case 'n':
			napis = va_arg(ap, char*);
			cout << "Napis  : " << napis << endl;
			break;
		default:
			cout << "Nieprawidlowy kod typu" << endl << endl;
			//goto KONIEC;
			va_end(ap);
			return;
		}
	}
	//KONIEC:
	cout << endl;
	va_end(ap);
}


void dodajInt(int n, ...){

	va_list args;

	va_start(args, n);

	int i = 0;
	int suma = 0;

	while(i < n){

		suma = suma + va_arg(args, int);
		i++;
	}

	cout << "Suma Int: " << suma << endl;

	va_end(args);
}

void dodajDouble(int n, ...){

	va_list args;

	va_start(args, n);

	int i = 0;
	double suma = 0;

	while(i < n){

		suma = suma + va_arg(args, double);
		i++;
	}

	cout << "Suma Double: " << suma << endl;

	va_end(args);
}

//Zadanie domowe
//�	Cz�� 1 - Zaimplementuj funkcj� o podanej poni�ej sygnaturze (1p.)

void rozdzielNaHex(string plikWejscie, int liczbaWyjsc, string plikWyjscie1, ...){

	fstream inFile;
	fstream outFile;
	int liczba;
	int len = 0;
	int i = 0;
	int plik;

	va_list args;

	va_start(args, plikWyjscie1);

	inFile.open(plikWejscie, fstream::in);		//najpierw liczymy linie

	while(!inFile.eof()){					//kazda liczba w innej linii, ile intow tyle linii

		inFile >> liczba;

		len++;
	}

	string Wyjscia[liczbaWyjsc];
	string Wyjscie;
	Wyjscia[0] = plikWyjscie1;

	i = 1;

	while(i < liczbaWyjsc){

		Wyjscia[i] = va_arg(args, char*);

		i++;
	}

	i = 0;

	inFile.close();

	inFile.open(plikWejscie, fstream::in);		//najpierw liczymy linie

	while(i < len){

		inFile >> liczba;

		plik = (i % liczbaWyjsc);
		Wyjscie = Wyjscia[plik];

		outFile.open(Wyjscie, fstream::app|fstream::out);

		outFile << uppercase << hex << liczba << endl;

		outFile.close();

		i++;
	}


	va_end(args);
}

/*
Funkcja ta ma rozdzieli� linijki z pliku tekstowego o nazwie podanej w argumencie �plikWejscie� i zapisa� je do plik�w �plikWyjscie1�, �plikWyj�cie2� 
i kolejnych. Pierwsza linijka z pliku wej�ciowego ma trafi� do pierwszego pliku wyj�ciowego, druga do drugiego i tak dalej, z zap�tleniem plik�w wyj�ciowych.
Liczba plik�w wyj�ciowych podana jest w argumencie �liczbaWyjsc�.Obs�uga plik�w ma si� odbywa� �w stylu� C++.

Dane w pliku wej�ciowym to liczby ca�kowite w zapisie dziesi�tnym.Nale�y je przed zapisaniem zamieni� na zapis heksadecymalny z du�ymi literami.W tym celu 
nale�y wykorzysta� strumie� �cout� i zmieni� parametry jego dzia�ania.Po zako�czeniu wykonywania funkcji stan strumienia powinien by� taki sam jak przed jej 
wywo�aniem.
*/

//�	Cz�� 2 - Zaimplementuj funkcj� o podanej poni�ej sygnaturze (1p.)

void polaczNaDec(string plikWyjscie, int liczbaWejsc, string plikWejscie1, ...){

	fstream inFile;
	fstream outFile;

	int liczba;
	int plik;
	int i = 1;
	int j = 0;
	int skip;
	int len = 0;
	char* p;

	va_list args;

	va_start(args, plikWejscie1);

	string Wejscia[liczbaWejsc];
	string Wejscie;
	Wejscia[0] = plikWejscie1;

	char napis[8];
	char znak;

	while(i < liczbaWejsc){

		Wejscia[i] = va_arg(args, char*);		//tablica wejsc

		i++;
	}

	i = 0;

	while(i < liczbaWejsc){				//liczymy wszystkie linie czyli ile mamy liczb

		Wejscie = Wejscia[i];

		inFile.open(Wejscie, fstream::in);

		while(!inFile.eof()){

			inFile.getline(napis, 8);
			znak = inFile.get();
			len++;
		}

		inFile.close();

		i++;
	}

	outFile.open(plikWyjscie, fstream::out);
	i = 0;

	while(i < len){

		plik = (i % liczbaWejsc);
		skip = i / liczbaWejsc;
		Wejscie = Wejscia[plik];

		inFile.open(Wejscie, fstream::in);

		inFile.getline(napis, 8);
		//znak = inFile.get();

		while(j < skip){

			inFile.getline(napis, 8);
			//znak = inFile.get();

			j++;
		}
		j = 0;

		liczba = strtol(napis, &p, 16);

		inFile.close();

		outFile << liczba << endl;

		i++;
	}

	outFile.close();

	va_end(args);
}

/*
Funkcja ta ma by� �odwrotno�ci�� funkcji z poprzedniego zadania � ma w analogiczny spos�b ��czy� linijki z plik�w wej�ciowych z liczbami heksadecymalnymi 
i zapisywa� je do pliku wyj�ciowego jako liczby decymalne(spos�b konwersji - dowolny).
*/


int main()
{
	// zaprezentujArgumenty("nzcn", "Ala", 4.9, 7, "Bob");
	// zaprezentujArgumenty("nzc", "Ala", 4.9, 7);

	// dodajInt(5, 1, 2, 3, 4, 5);
	// dodajDouble(5, 0.1, 0.2, 0.3, 0.4, 0.5);

	rozdzielNaHex("input.txt", 3, "out1.txt", "out2.txt", "out3.txt");

	//polaczNaDec("output.txt", 3, "out1.txt", "out2.txt", "out3.txt");

	return 0;
}

