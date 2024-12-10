#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>

/*============================== Buku ====================================*/


/*=============================== Anggota =====================================*/

int idTerakhir = 3;

int hitungJumlahAnggota() {
    int jumlah = 0;
    while(agt[jumlah].idAnggota != 0 && jumlah < 100) {
        jumlah++;
    }
    return jumlah;
}

void tampilAnggota() {
    int jumlahAnggota = hitungJumlahAnggota();
    printf("============================== Data Anggota =====================================\n");
    printf("| %-3s | %-20s | %-10s | %-12s | %-20s |\n", "ID", "Nama", "Username", "No. Tlp", "Email");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlahAnggota; i++) {
        printf("| %-3d | %-20s | %-10s | %-12s | %-20s |\n",
               agt[i].idAnggota,
               agt[i].nama,
               agt[i].username,
               agt[i].nomorTlp,
               agt[i].email);
    }

    printf("=================================================================================\n");
}

void tambahAnggota() {
    int jumlahAnggota = hitungJumlahAnggota();

    if(jumlahAnggota > 100) {
        printf("Data sudah penuh. Tidak bisa menambahkan data lagi!");
        return;
    }
    
    struct anggota agtBaru;

    agtBaru.idAnggota = ++idTerakhir;

    printf("============ Tambah Anggota ==============\n");
    printf("Masukkan username : ");
    scanf("%s", agtBaru.username);
    printf("Masukkan password : ");
    scanf("%s", agtBaru.password);

    getchar();

    printf("Masukkan nama : ");
    scanf("%[^\n]s", agtBaru.nama);
    printf("Masukkan nomor telp : ");
    scanf("%s", agtBaru.nomorTlp);
    printf("Masukkan email : ");
    scanf("%s", agtBaru.email);

    agt[jumlahAnggota] = agtBaru;
    jumlahAnggota++;

    printf("\nData sudah berhasil ditambahkan\n");
    printf("ID Anggota : %d\n", agtBaru.idAnggota);
}

void editAnggota() {
    int idAnggota, found = 0, pilih;
    printf("Masukkan Id Anggota : ");
    scanf("%d", &idAnggota);

    for (int i = 0; i < hitungJumlahAnggota(); i++) {
        if (idAnggota == agt[i].idAnggota) {
            found = 1;
            printf("\n========= Edit Anggota =========\n");
            printf("|                              |\n");
            printf("| Id Anggota : %d ditemukan!!!  |\n", agt[i].idAnggota);
            printf("|                              |\n");
            printf("================================\n");

            do {
                printf("======= Masukkan Data Baru =======\n");
                printf("| [1] Edit Nama                  |\n");
                printf("| [2] Edit Username              |\n");
                printf("| [3] Edit Password              |\n");
                printf("| [4] Edit Nomor Telepon         |\n");
                printf("| [5] Edit Email                 |\n");
                printf("| [0] Selesai                    |\n");
                printf("==================================\n");
                printf("Masukkan pilihan : ");
                scanf("%d", &pilih);

                getchar();

                switch (pilih) {
                    case 1: {
                        printf("Nama lama: %s\n", agt[i].nama);
                        printf("Masukkan nama baru: ");
                        scanf("%[^\n]", agt[i].nama);
                        getchar();
                        printf("Nama berhasil diperbarui!\n");
                        break;
                        }
                    case 2: {
                        printf("Username lama: %s\n", agt[i].username);
                        printf("Masukkan username baru: ");
                        scanf("%s", agt[i].username);
                        printf("Username berhasil diperbarui!\n");
                        break;
                    }
                    case 3: {
                        printf("Password lama: %s\n", agt[i].password);
                        printf("Masukkan password baru: ");
                        scanf("%s", agt[i].password);
                        printf("Password berhasil diperbarui!\n");
                        break;
                    }
                    case 4: {
                        printf("Nomor Telepon lama: %s\n", agt[i].nomorTlp);
                        printf("Masukkan nomor telepon baru: ");
                        scanf("%s", agt[i].nomorTlp);
                        printf("Nomor telepon berhasil diperbarui!\n");
                        break;
                    }
                    case 5: {
                        printf("Email lama: %s\n", agt[i].email);
                        printf("Masukkan email baru: ");
                        scanf("%s", agt[i].email);
                        printf("Email berhasil diperbarui!\n");
                        break;
                    }
                    case 0:
                        printf("Edit selesai.\n");
                        break;
                    default:
                        printf("Pilihan tidak valid! Coba lagi.\n");
                }
            } while (pilih != 0);
            return;
        }
    }

    if (!found) {
        printf("Id Anggota %d tidak ditemukan!\n", idAnggota);
    }
}

void cariAnggota() {
    int cari;
    int i, found = 0;
    int banyakAnggota = hitungJumlahAnggota();

    printf("Masukkan id anggota yang ingin dicari : ");
    scanf("%d", &cari);

    i = 0;
    while((i<banyakAnggota) && (found == 0)) {
        if(cari == agt[i].idAnggota) {
            found = 1;
        } else  {
            i += 1;
        }
    }

    if(found == 1) {
        printf("=========================================\n");
        printf("ID Anggota  : %d\n", agt[i].idAnggota);
        printf("Nama        : %s\n", agt[i].nama);
        printf("Username    : %s\n", agt[i].username);
        printf("No. Telepon : %s\n", agt[i].nomorTlp);
        printf("Email       : %s\n\n", agt[i].email);
        printf("=========================================\n");
    }

    if(found != 1) {
        printf("=========================================\n");
        printf(" Anggota dengan ID %d tidak di temukan \n", cari);
        printf("=========================================\n");
    }
}


/*
Menu untuk admin jika login sudah berhasil
*/
void menuAdmin() {
    int pilih;

    do {
        printf("=========== Halaman Admin ============\n");
        printf("| Pilih menu :                       |\n");
        printf("| Buku                               |\n");
        printf("| [1] Cari Buku                      |\n");
        printf("| [2] Tampilkan Buku                 |\n");
        printf("| [3] Tambah Buku                    |\n");
        printf("| [4] Edit Buku                      |\n");
        printf("| [5] Hapus Buku                     |\n");
        printf("|                                    |\n");
        printf("| Anggota                            |\n");
        printf("| [6] Cari Anggota                   |\n");
        printf("| [7] Tampilkan Anggota              |\n");
        printf("| [8] Tambah Anggota                 |\n");
        printf("| [9] Edit Anggota                   |\n");
        printf("| [10] Hapus Anggota                 |\n");
        printf("|                                    |\n");
        printf("| [0] LogOut                         |\n");
        printf("======================================\n");

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
                // editBuku();
                break;
            case 5 :
                // hapusBuku();
                break;
            case 6 :
                cariAnggota();
                break;
            case 7 :
                tampilAnggota();
                break;
            case 8 :
                tambahAnggota();
                break;
            case 9 :
                editAnggota();
                break;
            case 10 :
                // hapusAnggota();
                break;
            default :
                printf("\nSilahkan pilih menu yang ada!!!\n\n");
                break;
        }
    } while(pilih!=0);


}

/*
Prosedur untuk menangani login admin
*/
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

/*
Prosedur untuk menampilkan menu utama
Digunakan untuk login
*/
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
