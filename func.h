#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>

void menuAdmin() {
    int pilih;

    do {
        printf("\n========== Halaman Admin ===========\n");
        printf("| Pilih menu :                       |\n");
        printf("| Buku                               |\n");
        printf("| [1] Cari Buku                      |\n");
        printf("| [2] Tampilkan Buku                 |\n");
        printf("| [3] Tambah Buku                    |\n");
        printf("|                                    |\n");
        printf("| Anggota                            |\n");
        printf("| [4] Cari Anggota                   |\n");
        printf("| [5] Tampilkan Anggota              |\n");
        printf("| [6] Tambah Anggota                 |\n");
        printf("|                                    |\n");
        printf("| [0] LogOut                         |\n");
        printf("|====================================|\n");

        printf("Masukkan pilihan : ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 0 : 
                return;
            case 1 : 
                // cariBuku();
                break;
            case 2 :
                // tampilBuku();
                break;
            case 3 :
                // tambahBuku();
                break;
            case 4 :
                // cariAnggota();
                break;
            case 5 :
                // tampilAnggota();
                break;
            case 6 :
                // tambahAnggota();
                break;
            default :
                printf("\nSilahkan pilih menu yang ada!!!\n\n");
                break;
        }
    } while(pilih!=0);


}

void loginAdmin() {
    char inputUsername[50];
    char inputPassword[50];
    int jumlahLogin = 0;

    do {
        printf("\n========== Login Admin ==========\n");
        printf("Masukkan username : ");
        scanf("%s", inputUsername);
        printf("Masukkan password : ");
        scanf("%s", inputPassword);
        printf("=================================\n");
        for (int i = 0; i < 2; i++) {
            if (strcmp(inputUsername, adm[i].username) == 0 && 
                strcmp(inputPassword, adm[i].password) == 0) {
                printf("\nLogin berhasil! Selamat datang, %s.\n\n", adm[i].username);
                menuAdmin();
                return;
            }
        }
        printf("\nUsername atau password salah!!!\n");
        jumlahLogin++;

        if(jumlahLogin == 3) {
            printf("\nAnda sudah gagal login sebanyak 3 kali. Kembali ke menu utama\n\n");
            break;
        }
    } while(jumlahLogin != 3);


}


void tampilMenu() {
    int pilih;
    do {
    printf("========== Selamat Datang ==========\n");
    printf("| Silahkan login sebagai :         |\n");
    printf("|                                  |\n");
    printf("| [1] Admin                        |\n");
    printf("| [2] Anggota                      |\n");
    printf("| [0] Exit                         |\n");
    printf("====================================\n");
    printf("Masukkan pilihan : ");
    scanf("%d", &pilih);
        switch(pilih) {
            case 0 :
                return;
            case 1 :
                loginAdmin();
                break;
            case 2 :
                // loginAnggota();
                break;
            default :
                printf("Silahkan pilih menu yang ada!!!");
        };
    } while (pilih != 0);
}

#endif
