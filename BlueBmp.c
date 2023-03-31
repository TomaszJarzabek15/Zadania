#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//otwieramy plik bmp i zapisujemy go do nowego pliku, bedzie bardziej niebieski

unsigned int CharToInt(unsigned char* bytes){
    unsigned int wynik = 0;

    for(int i = 7; i >= 0; i--){
        if(bytes[0] & (1 << i)){
            wynik = wynik | (1 << (7 -(7 - i)));
        }
    }
    for(int i = 7; i >= 0; i--){
        if(bytes[1] & (1 << i)){
            wynik = wynik | (1 << (15 -(7 - i)));
        }
    }
    for(int i = 7; i >= 0; i--){
        if(bytes[2] & (1 << i)){
            wynik = wynik | (1 << (23 -(7 - i)));
        }
    }
    for(int i = 7; i >= 0; i--){
        if(bytes[3] & (1 << i)){
            wynik = wynik | (1 << (31 -(7 - i)));
        }
    }

    return wynik;
}

int main(){

    FILE* plikDoOdczytu = fopen("krakow.bmp", "rb");

    if (!plikDoOdczytu) {
        printf("Nie można otworzyć pliku wejściowego \n");
        return 1;
    }

    unsigned char header[54];
	unsigned char bytes[4];
    unsigned int szerokosc;
    unsigned int wysokosc;

	fread(header, 1, 54, plikDoOdczytu); //1 = sizeof(unsigned char)

    for(int i = 0; i < 4; i++){
        bytes[0 + i] = header[18 + i];
    }
    
	szerokosc = CharToInt(bytes);

    for(int i = 0; i < 4; i++){
        bytes[0 + i] = header[22 + i];
    }

    wysokosc = CharToInt(bytes);

    printf("%d x %d", szerokosc, wysokosc);
    
    int realWidth = ((24 * szerokosc + 31) / 32) * 4;
    int imageSize = realWidth * wysokosc;

    unsigned char *imageData = malloc(imageSize);
    if (!imageData) {
        printf("Nie można zaalokować pamięci na obraz\n");
        fclose(plikDoOdczytu);
        return 1;
    }

    fread(imageData, imageSize, 1, plikDoOdczytu);
    fclose(plikDoOdczytu);

    for(int i = 0; i < wysokosc; i++){
        for(int j = 0; j < szerokosc; j++){
            int offset = i * realWidth + j * 3;
            imageData[offset + 0] = 255; // Ustawia kanał niebieski na maksimum
        }  
    }
    //printf("\nwysokosc: %d, szerokosc: %d", wysokosc, szerokosc);

    FILE* plikDoZapisu = fopen("BLUEEEEEE.bmp", "wb");

    if (!plikDoZapisu) {
        printf("Nie można utworzyć pliku wyjściowego \n");
        free(imageData);
        return 1;
    }

    fwrite(header, 1, 54, plikDoZapisu); //1 = sizeof(unsigned char)
    fwrite(imageData, imageSize, 1, plikDoZapisu);

	fclose(plikDoZapisu);

    free(imageData);

    return 0;
}