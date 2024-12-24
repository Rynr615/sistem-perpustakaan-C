#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>

void bubbleAsc(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if(agt[j].idAnggota > agt[j+1].idAnggota) {
                struct anggota temp = agt[j];
                agt[j] = agt[j+1];
                agt[j+1] = temp;
            }
        }
    }
}

void bubbleDesc(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if(agt[j].idAnggota < agt[j+1].idAnggota) {
                struct anggota temp = agt[j];
                agt[j] = agt[j+1];
                agt[j+1] = temp;
            }
        }
    }
}

int partitionAsc(struct buku array[], int low, int high) {
    int pivot = array[high].idBuku;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j].idBuku <= pivot) {
            i++;
            struct buku temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    struct buku temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}

void quickAsc(struct buku array[], int low, int high) {
    if (low < high) {
        int pi = partitionAsc(array, low, high);
        quickAsc(array, low, pi - 1);
        quickAsc(array, pi + 1, high);
    }
}

int partitionDesc(struct buku array[], int low, int high) {
    int pivot = array[high].idBuku;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j].idBuku >= pivot) {
            i++;
            struct buku temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    struct buku temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}

void quickDesc(struct buku array[], int low, int high) {
    if (low < high) {
        int pi = partitionDesc(array, low, high);
        quickDesc(array, low, pi - 1);
        quickDesc(array, pi + 1, high);
    }
}

void tampilBukuSorting(int n) {
    printf("============================== Data Buku ========================================\n");
    printf("| %-3s | %-40s | %-20s | %-5s |\n", "ID", "Judul", "Pengarang", "Stok");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if(daftarBuku[i].idBuku > 0 && daftarBuku[i].idBuku < 100){
        printf("| %-3d | %-40s | %-20s | %-5d |\n",
               daftarBuku[i].idBuku,
               daftarBuku[i].judul,
               daftarBuku[i].pengarang,
               daftarBuku[i].stok);
        }
    }
    printf("=================================================================================\n");
}

void tampilAnggotaSorting(int n) {
    printf("============================== Data Anggota =====================================\n");
    printf("| %-3s | %-20s | %-10s | %-12s | %-20s |\n", "ID", "Nama", "Username", "No. Tlp", "Email");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (agt[i].idAnggota > 0 && agt[i].idAnggota < 100) {
            printf("| %-3d | %-20s | %-10s | %-12s | %-20s |\n",
                   agt[i].idAnggota,
                   agt[i].nama,
                   agt[i].username,
                   agt[i].nomorTlp,
                   agt[i].email);
        }
    }

    printf("=================================================================================\n");
}

#endif
