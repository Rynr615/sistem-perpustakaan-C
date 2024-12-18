#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>

// Bubble Asc
void sortingBukuAsc(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if(daftarBuku[j].idBuku > daftarBuku[j+1].idBuku) {
                struct buku temp = daftarBuku[j];
                daftarBuku[j] = daftarBuku[j+1];
                daftarBuku[j+1] = temp;
            }
        }
    }
}

void tampilBukuAsc(int n) {
    printf("============================== Data Buku ========================================\n");
    printf("| %-3s | %-40s | %-20s | %-5s |\n", "ID", "Judul", "Pengarang", "Stok");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %-3d | %-40s | %-20s | %-5d |\n",
               daftarBuku[i].idBuku,
               daftarBuku[i].judul,
               daftarBuku[i].pengarang,
               daftarBuku[i].stok);
    }

    printf("=================================================================================\n");
}

// Bubble Desc
void sortingBukuDesc(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if(daftarBuku[j].idBuku < daftarBuku[j+1].idBuku) {
                struct buku temp = daftarBuku[j+1];
                daftarBuku[j+1] = daftarBuku[j];
                daftarBuku[j] = temp;
            }
        }
    }
}

void tampilBukuDesc(int n) {
    printf("============================== Data Buku ========================================\n");
    printf("| %-3s | %-40s | %-20s | %-5s |\n", "ID", "Judul", "Pengarang", "Stok");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("| %-3d | %-40s | %-20s | %-5d |\n",
               daftarBuku[i].idBuku,
               daftarBuku[i].judul,
               daftarBuku[i].pengarang,
               daftarBuku[i].stok);
    }

    printf("=================================================================================\n");
}

#endif