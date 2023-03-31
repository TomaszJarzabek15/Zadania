#include <iostream>
#include <string>

using namespace std;

class Procesor{
    string nazwa;
    int cores;

public:
    Procesor(){
        //konstruktor domyslny bezargumentowy
        this->nazwa = "";
        this->cores = 0;

        cout << "nazwa: " << nazwa << " cores: " << cores << endl;
        //jak nie podamy zadnych argumentow to sie wywola ten konstruktor
    }

    Procesor(string _nazwa, int _cores){
        this->nazwa = _nazwa;
        this->cores = _cores;
        cout << "nazwa: " << nazwa << " cores: " << cores << endl;
    }

    void dokonajObliczen(int* wartosc){
        *wartosc = *wartosc * 8;
    }
    
    void SetProcesor(int _cores){
        this->cores = _cores;
    }
    int Getprocesor(){
        return this->cores;
    }
};

class KartaGraficzna{
    string nazwa;
    int VRAM;

public:
    KartaGraficzna(){
        this->nazwa = "";
        this->VRAM = 0;
        cout << "nazwa: " << nazwa << " VRAM: " << VRAM << endl;
    }

    KartaGraficzna(string _nazwa, int _VRAM){
        this->nazwa = _nazwa;
        this->VRAM = _VRAM;
        cout << "nazwa: " << nazwa << " VRAM: " << VRAM << endl;
    }

    int GetVRAM(){
        return this->VRAM;
    }
    void SetVRAM(int _VRAM){
        this->VRAM = _VRAM;
    }
};

class PamiecRam{
    string nazwa;
    int speed;
    int pamiec;

public:
    PamiecRam(){
        this->nazwa = "";
        this->speed= 0;
        this->pamiec = 0;
        cout << "nazwa: " << nazwa << " speed: " << speed << endl;

    }

    PamiecRam(string _nazwa, int _speed, int _pamiec){
        this->nazwa = _nazwa;
        this->speed = _speed;
        this->pamiec = _pamiec;
        cout << "nazwa: " << nazwa << " speed: " << speed << endl;
    }

    void odczytZPamieci(){
        cout << "pamiec: " << pamiec << endl;
    }

    void zapisDoPamieci(int wartosc){
        this->pamiec = wartosc;
        cout << "pamiec after: " << this->pamiec << endl;
    }

    int GetSpeed(){
        return this->speed;
    }
    void SetSpeed(int _speed){
        this->speed = _speed;
    }
};

class DyskTwardy{

    string nazwa;
    int capacity;

public:
    DyskTwardy(){
        this->nazwa = "";
        this->capacity= 0;
        cout << "nazwa: " << nazwa << " capacity: " << capacity << endl;
    }

    DyskTwardy(string _nazwa, int _capacity){
        this->nazwa = _nazwa;
        this->capacity = _capacity;
        cout << "nazwa: " << nazwa << " capacity: " << capacity << endl;
    }

    int GetCapacity(){
        return this->capacity;
    }
    void SetCapacity(int _capacity){
        this->capacity = _capacity;
    }

};

class KontrolerUsb{

    string nazwa;
    int standard;   //USB 1, 2 or 3

public:
    KontrolerUsb(){
        this->nazwa = "";
        this->standard= 0;
        cout << "nazwa: " << nazwa << " standard: " << standard << endl;
    }

    KontrolerUsb(string _nazwa, int _standard){
        this->nazwa = _nazwa;
        this->standard = _standard;
        cout << "nazwa: " << nazwa << " standard: " << standard << endl;
    }

    int GetStandard(){
        return this->standard;
    }
    void SetStandard(int _standard){
        this->standard = _standard;
    }
};

class KomputerStacjonarny{

    string nazwa;
    int numer;

    Procesor procesor;
    KartaGraficzna kartagraficzna;
    PamiecRam pamiecram;
    DyskTwardy dysktwardy;
    KontrolerUsb kontrolerusb;

public:
    KomputerStacjonarny(){
        this->nazwa = "";
        this->numer = 0;
    }

    KomputerStacjonarny(string _nazwaKomputer, int _numer, string _nazwaP, string _nazwaK, string _nazwaR, string _nazwaD, string _nazwaU, int _cores, int _VRAM, int _speed, int _pamiec, int _capacity, int _standard) 
    : procesor(_nazwaP, _cores), kartagraficzna(_nazwaK, _VRAM), pamiecram(_nazwaR, _speed, _pamiec), dysktwardy(_nazwaD, _capacity), kontrolerusb(_nazwaU, _standard)
    {
        this->nazwa = _nazwaKomputer;
        this->numer = _numer;
        cout << "nazwa komputera: " << this->nazwa << " numer: " << this->numer << endl;
    }

    void operacjaNaPamieci(int* wartosc){
        pamiecram.odczytZPamieci();
        procesor.dokonajObliczen(&(*wartosc));
        pamiecram.zapisDoPamieci(*wartosc);
    }

    void SetPC(int _cores = 0, int _VRAM = 0, int _speed = 0, int _capacity = 0, int _standard = 1){
        procesor.SetProcesor(_cores);
        kartagraficzna.SetVRAM(_VRAM);
        pamiecram.SetSpeed(_speed);
        dysktwardy.SetCapacity(_capacity);
        kontrolerusb.SetStandard(_standard);
    }

    int wydajnosc(int wydajnosc = 0){
        wydajnosc = (procesor.Getprocesor() * 10) + (kartagraficzna.GetVRAM() * 10) + (pamiecram.GetSpeed() / 10) + (dysktwardy.GetCapacity() / 10) + (kontrolerusb.GetStandard() * 5);
        return wydajnosc;
    }

};

int main(){

    KomputerStacjonarny komputer("PC-01", 123, "Intel i7", "GTX 970", "Corsair", "WD BLUE", "USB", 8, 8, 3300, 0, 1000, 3);

    cout << "wydajnosc: " << komputer.wydajnosc() << endl;

    int wartosc = 55;

    komputer.operacjaNaPamieci(&wartosc);

    cout << "wartosc: " << wartosc << endl;

    return 0;
}