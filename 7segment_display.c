//Hanzalahnur Solikhin
//NIM : D121241110
//Final Project Sisdig : 7 Segment Display
// Teknik Informatika B

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Representasi angka pada 7-segment display
const char segments[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 1, 0}, // 1
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {1, 0, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

// Fungsi untuk mencetak status segmen
void printSegmentStatus(int num) {
    const char *labels = "abcdefg";
    printf("Status Segment untuk angka %d:\n", num);
    for (int i = 0; i < 7; i++) {
        printf("%c = %d\n", labels[i], segments[num][i]);
    }
}

// Fungsi untuk mencetak representasi biner
void printBinaryRepresentation(int num) {
    printf("Representasi Biner: ");
    for (int i = 0; i < 7; i++) {
        printf("%d", segments[num][i]);
    }
    printf("\n");
}

// Fungsi untuk mencetak visualisasi 7-segment display
void printSegmentDisplay(int num) {
    // Baris pertama (segmen 0)
    printf(" %s \n", segments[num][0] ? "---" : "   ");

    // Baris kedua (segmen 1 dan 2)
    printf("%s   %s\n",
           segments[num][1] ? "|" : " ",
           segments[num][2] ? "|" : " ");

    // Baris ketiga (segmen 3)
    printf(" %s \n", segments[num][3] ? "---" : "   ");

    // Baris keempat (segmen 4 dan 5)
    printf("%s   %s\n",
           segments[num][4] ? "|" : " ",
           segments[num][5] ? "|" : " ");

    // Baris kelima (segmen 6)
    printf(" %s \n", segments[num][6] ? "---" : "   ");
}

int main() {
    char input[10];

    while (1) {
        printf("\nMasukkan angka (0-9) atau 'Y' untuk keluar: ");
        scanf("%s", input);

        // Konversi input ke uppercase untuk perintah keluar
        if (toupper(input[0]) == 'Y') {
            printf("Program selesai.\n");
            break;
        }

        // Validasi input
        if (isdigit(input[0]) && atoi(input) >= 0 && atoi(input) <= 9) {
            int num = atoi(input);

            // Cetak status segmen
            printSegmentStatus(num);

            // Cetak representasi biner
            printBinaryRepresentation(num);

            // Cetak visualisasi 7-segment display
            printf("\nVisualisasi Seven Segment:\n");
            printSegmentDisplay(num);
        } else {
            printf("Input tidak valid! Masukkan angka 0-9 atau 'Y' untuk keluar.\n");
        }
    }

    return 0;
}
