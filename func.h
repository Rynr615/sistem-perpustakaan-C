#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>
#include "sorting.h"

/*============================== Buku ====================================*/
//Fungsi untuk menghitung jumlah buku yang ada
int hitungJumlahBuku() {
    int jumlah = 0;
    while (daftarBuku[jumlah].idBuku != 0 && jumlah < 100) {
        jumlah++;
    }
    return jumlah;
}

//Fungsi untuk mencari buku berdasarkan ID
void cariBuku() {
    int cari, found = 0;
    printf("Masukkan ID buku yang ingin dicari: ");
    scanf("%d", &cari);

    for (int i = 0; i < hitungJumlahBuku(); i++) {
        if (daftarBuku[i].idBuku == cari) {
            found = 1;
            printf("\n===========================================");
            printf("\nBuku ditemukan:\n");
            printf("ID Buku     : %d\n", daftarBuku[i].idBuku);
            printf("Judul Buku  : %s\n", daftarBuku[i].judul);
            printf("Pengarang   : %s\n", daftarBuku[i].pengarang);
            printf("Stok        : %d\n", daftarBuku[i].stok);
            printf("===========================================\n");
            return;
        }
    }

    if (!found) {
        printf("\n======================================");
        printf("\nBuku dengan ID %d tidak ditemukan!\n", cari);
        printf("======================================\n");
    }
}

//Fungsi untuk memampilkan daftar buku
void tampilBuku() {
    
    int pilihan;
    int jumlahBuku = hitungJumlahBuku();

    do {
        printf("======== Tampilkan Buku ========\n");
        printf("| [1] Ascending ( Default )    |\n");
        printf("| [2] Descending               |\n");
        printf("================================\n");
        printf("Masukkan pilihan : ");
        scanf("%d", &pilihan);
        switch(pilihan) {
            case 1 :
                sortingBukuAsc(jumlahBuku);
                tampilBukuAsc(jumlahBuku);
                return;
            case 2 :
                sortingBukuDesc(jumlahBuku);
                tampilBukuDesc(jumlahBuku);
                return;
            default :
                printf("Masukkan pilihan yang ada!!!");
                return;
        }
    } while(pilihan != 0);
}

//Fungsi untuk menambahkan buku baru 
void tambahBuku() {
    int jumlahBuku = hitungJumlahBuku();
    int idbukuTerakhir = hitungJumlahBuku();

    if (jumlahBuku >= 100) {
        printf("Data sudah penuh. Tidak bisa menambahkan buku lagi!\n");
        return;
    }

    struct buku bukuBaru;
    bukuBaru.idBuku = ++idbukuTerakhir;

    printf("Masukkan judul buku: ");
    getchar();
    scanf("%[^\n]s", bukuBaru.judul);
    printf("Masukkan pengarang: ");
    getchar();
    scanf("%[^\n]s", bukuBaru.pengarang);
    printf("Masukkan jumlah stok buku: ");
    scanf("%d", &bukuBaru.stok);

    daftarBuku[jumlahBuku] = bukuBaru;

    printf("\nBuku berhasil ditambahkan dengan ID: %d\n", bukuBaru.idBuku);
}

//Fungsi untuk mengedit buku
void editBuku() {
    int idBuku, found = 0, pilih;
    int jumlahBuku = hitungJumlahBuku();
    printf("Masukkan Id Buku : ");
    scanf("%d", &idBuku);

    for (int i = 0; i < jumlahBuku; i++) {
        if (idBuku == daftarBuku[i].idBuku) {
            found = 1;
            printf("\n========== Edit Buku ==========\n");
            printf("|                              |\n");
            printf("| Id Buku    : %d ditemukan!!!  |\n", daftarBuku[i].idBuku);
            printf("|                              |\n");
            printf("================================\n");

            do {
                printf("======= Masukkan Data Baru =======\n");
                printf("| [1] Edit Judul                 |\n");
                printf("| [2] Edit Pengarang             |\n");
                printf("| [3] Edit Stok                  |\n");
                printf("| [0] Selesai                    |\n");
                printf("==================================\n");
                printf("Masukkan pilihan : ");
                scanf("%d", &pilih);

                getchar();

                switch (pilih) {
                    case 1: {
                        printf("Judul lama: %s\n", daftarBuku[i].judul);
                        printf("Masukkan judul baru: ");
                        scanf("%[^\n]", daftarBuku[i].judul);
                        getchar();
                        printf("Judul berhasil diperbarui!\n");
                        break;
                        }
                    case 2: {
                        printf("Pengarang lama: %s\n", daftarBuku[i].pengarang);
                        printf("Masukkan pengarang baru: ");
                        scanf("%s", daftarBuku[i].pengarang);
                        printf("Pengarang berhasil diperbarui!\n");
                        break;
                    }
                    case 3: {
                        printf("Stok lama: %s\n", daftarBuku[i].stok);
                        printf("Masukkan stok baru: ");
                        scanf("%s", daftarBuku[i].stok);
                        printf("Stok berhasil diperbarui!\n");
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
        printf("Id Buku %d tidak ditemukan!\n", idBuku);
    }
}

//Fungsi untuk menghapus buku berdasarkan ID
void hapusBuku(int idHapus) {
    int jumlahBuku = hitungJumlahBuku();
    int found = 0;
    int foundIndex = -1;
    char pilih;

    // Cari ID yang cocok
    for (int i = 0; i < jumlahBuku; i++) {
        if (idHapus == daftarBuku[i].idBuku) {
            found = 1;
            foundIndex = i;
            break;
        }
    }

    if (!found) {
        printf("ID Buku %d tidak ditemukan.\n", idHapus);
    } else {
        printf("Apakah anda yakin untuk menghapusnya? [y/t] : ");
        scanf(" %c", &pilih);

        if (pilih == 'Y' || pilih == 'y') {
            for (int j = foundIndex; j < jumlahBuku - 1; j++) {
                daftarBuku[j] = daftarBuku[j + 1];
            }

            daftarBuku[jumlahBuku - 1].idBuku = 0;
            strcpy(daftarBuku[jumlahBuku - 1].judul, "");
            strcpy(daftarBuku[jumlahBuku - 1].pengarang, "");

            printf("ID Buku %d berhasil dihapus.\n", idHapus);
        } else {
            printf("Penghapusan dibatalkan.\n");
        }
    }
}


/*=============================== Anggota =====================================*/

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

    printf("================================================================================\n");
}

void tambahAnggota() {
    int jumlahAnggota = hitungJumlahAnggota();
    int idTerakhir = hitungJumlahAnggota();

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
    int jumlahAnggota = hitungJumlahAnggota();
    printf("Masukkan Id Anggota : ");
    scanf("%d", &idAnggota);

    for (int i = 0; i < jumlahAnggota; i++) {
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
    int jumlahAnggota = hitungJumlahAnggota();

    printf("Masukkan id anggota yang ingin dicari : ");
    scanf("%d", &cari);

    i = 0;
    while((i<jumlahAnggota) && (found == 0)) {
        if(cari == agt[i].idAnggota) {
            found = 1;
        } else  {
            i += 1;
        }
    }

    if(found == 1) {
        printf("\n=========================================\n");
        printf("ID Anggota  : %d\n", agt[i].idAnggota);
        printf("Nama        : %s\n", agt[i].nama);
        printf("Username    : %s\n", agt[i].username);
        printf("No. Telepon : %s\n", agt[i].nomorTlp);
        printf("Email       : %s\n", agt[i].email);
        printf("=========================================\n");
    }

    if(found != 1) {
        printf("=========================================\n");
        printf(" Anggota dengan ID %d tidak di temukan \n", cari);
        printf("=========================================\n");
    }
}

void hapusAnggota(int idHapus) {
    int jumlahAnggota = hitungJumlahAnggota();
    int found = 0;
    int foundIndex = -1;
    char pilih;

    // Cari ID yang cocok
    for (int i = 0; i < jumlahAnggota; i++) {
        if (idHapus == agt[i].idAnggota) {
            found = 1;
            foundIndex = i;
            break;
        }
    }

    if (!found) {
        printf("ID anggota %d tidak ditemukan.\n", idHapus);
    } else {
        printf("Apakah anda yakin untuk menghapusnya? [y/t] : ");
        scanf(" %c", &pilih);

        if (pilih == 'Y' || pilih == 'y') {
            for (int j = foundIndex; j < jumlahAnggota - 1; j++) {
                agt[j] = agt[j + 1];
            }

            agt[jumlahAnggota - 1].idAnggota = 0;
            strcpy(agt[jumlahAnggota - 1].nama, "");
            strcpy(agt[jumlahAnggota - 1].username, "");
            strcpy(agt[jumlahAnggota - 1].password, "");
            strcpy(agt[jumlahAnggota - 1].nomorTlp, "");
            strcpy(agt[jumlahAnggota - 1].email, "");

            printf("ID anggota %d berhasil dihapus.\n", idHapus);
        } else {
            printf("Penghapusan dibatalkan.\n");
        }
    }
}

void riwayatPeminjaman() {
    printf("============================== Riwayat Peminjaman ==============================\n");
    printf("| %-3s | %-10s | %-12s | %-20s | %-10s | %-20s |\n", 
           "No", "ID Anggota", "Username", "Nama", "Tanggal", "Judul Buku");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < 100; i++) {
        // Cek apakah slot peminjaman ini terisi
        if (pinjamBuku[i].idAnggota != 0) { 
            printf("| %-3d | %-10d | %-12s | %-20s | %02d/%02d/%04d | %-20s |\n", 
                   i + 1, 
                   pinjamBuku[i].idAnggota, 
                   pinjamBuku[i].username, 
                   pinjamBuku[i].nama, 
                   pinjamBuku[i].date, 
                   pinjamBuku[i].month, 
                   pinjamBuku[i].year, 
                   pinjamBuku[i].judul);
        }
    }

    printf("================================================================================\n");
}


// riwayatPengembalian() {

// }


/*
Menu untuk admin jika login sudah berhasil
*/
void menuAdmin() {
    int pilih;

    do {
        printf("\n=========== Halaman Admin ============\n");
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
        printf("| Riwayat                            |\n");
        printf("| [11] Riwayat Peminjaman            |\n");               
        printf("| [12] Riwayat Pengembalian          |\n");               
        printf("|                                    |\n");
        printf("| [0] LogOut                         |\n");
        printf("|====================================|\n");

        printf("Masukkan pilihan : ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 0 : 
                return;
            case 1 : 
                cariBuku();
                break;
            case 2 :
                tampilBuku();
                break;
            case 3 :
                tambahBuku();
                break;
            case 4 :
                editBuku();
                break;
            case 5 :
                int idBuku;
                printf("Masukkan id Buku : ");
                scanf("%d",&idBuku);
                hapusBuku(idBuku);
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
            case 10:
                int idAnggota;
                printf("Masukkan id Anggota : ");
                scanf("%d",&idAnggota);
                hapusAnggota(idAnggota);
                break;
            case 11:
                riwayatPeminjaman();
                break;
            case 12:
                // riwayatPengembalian();
                break;
            default :
                printf("\nSilahkan pilih menu yang ada!!!\n\n");
                break;
        }
    } while(pilih!=0);


}

void peminjamanBuku() {
    int idBuku, idAnggota;
    int day, month, year;

    printf("===== Peminjaman Buku =====\n");
    printf("Masukkan id buku : ");
    scanf("%d", &idBuku);
    printf("Masukkan id anggota anda : ");
    scanf("%d", &idAnggota);
    printf("Masukkan tanggal peminjaman (dd mm yyyy) : ");
    scanf("%d %d %d", &day, &month, &year);

    if (daftarBuku[idBuku - 1].stok <= 0) {
        printf("Maaf, stok buku dengan id %d habis.\n", idBuku);
        return;
    }

    daftarBuku[idBuku-1].stok--;

    for (int i = 0; i < 100; i++) {
        if (pinjamBuku[i].idAnggota == 0) {
            pinjamBuku[i].idAnggota = idAnggota;
            strcpy(pinjamBuku[i].username, agt[idAnggota - 1].username);
            strcpy(pinjamBuku[i].nama, agt[idAnggota - 1].nama);        
            pinjamBuku[i].date = day;
            pinjamBuku[i].month = month;
            pinjamBuku[i].year = year;
            strcpy(pinjamBuku[i].judul, daftarBuku[idBuku - 1].judul);
            printf("Buku berhasil dipinjam. Judul: %s, Tanggal: %d-%d-%d\n",
                   pinjamBuku[i].judul, day, month, year);
            return;
        }
    }
}

void pengembalianBuku(){
    int idBuku, idAnggota;
    int day, month, year;

    printf("===== Pengembalian Buku =====\n");
    printf("Masukkan id buku : ");
    scanf("%d", &idBuku);
    printf("Masukkan id anggota anda : ");
    scanf("%d", &idAnggota);
    printf("Masukkan tanggal pengembalian (dd mm yyyy) : ");
    scanf("%d %d %d", &day, &month, &year);

    if (daftarBuku[idBuku - 1].stok <= 0) {
        printf("Maaf, stok buku dengan id %d habis.\n", idBuku);
        return;
    }

    daftarBuku[idBuku-1].stok++;

    for (int i = 0; i < 100; i++) {
        if (balikBuku[i].idAnggota == 0) {
            balikBuku[i].idAnggota = idAnggota;
            strcpy(balikBuku[i].username, agt[idAnggota - 1].username);
            strcpy(balikBuku[i].nama, agt[idAnggota - 1].nama);        
            balikBuku[i].date = day;
            balikBuku[i].month = month;
            balikBuku[i].year = year;
            strcpy(balikBuku[i].judul, daftarBuku[idBuku - 1].judul);
            printf("Buku berhasil dikembalikan.\nJudul: %s, \nTanggal: %d-%d-%d\n",
                   balikBuku[i].judul, day, month, year);
            return;
        }
    }
}

/*
Tampilkan menu anggota
*/

void menuAnggota() {
    int pilih;
    do {
        printf("\n========== Halaman Anggota ===========\n");
        printf("| Pilih menu :                       |\n");
        printf("| Buku                               |\n");
        printf("| [1] Cari Buku                      |\n");
        printf("| [2] Tampilkan Buku                 |\n");
        printf("| [3] Pinjam Buku                    |\n");
        printf("| [4] Kembalikan Buku                |\n");
        printf("|                                    |\n");
        printf("| [0] Kembali                        |\n");
        printf("======================================\n");

        printf("Masukkan pilihan : ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 0 : 
                return;
            case 1 : 
                cariBuku();
                break;
            case 2 :
                tampilBuku();
                break;
            case 3 :
                peminjamanBuku();
                break;
            case 4 :
                pengembalianBuku();
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
void login() {
    char inputUsername[50];
    char inputPassword[50];
    int jumlahLogin = 0;
    int jumlahAnggota = hitungJumlahAnggota();

    do {
        printf("\n========== Login ==========\n");
        printf("Masukkan username : ");
        scanf("%s", inputUsername);
        printf("Masukkan password : ");
        scanf("%s", inputPassword);
        printf("===========================\n");

        for (int i = 0; i < 2; i++) {
            if (strcmp(inputUsername, adm[i].username) == 0 && 
                strcmp(inputPassword, adm[i].password) == 0) {
                printf("\nLogin berhasil! Selamat datang, Admin %s.\n\n", adm[i].username);
                menuAdmin();
                return;
            }
        }

        for (int i = 0; i < jumlahAnggota; i++) {
            if (strcmp(inputUsername, agt[i].username) == 0 && 
                strcmp(inputPassword, agt[i].password) == 0) {
                printf("\nLogin berhasil! Selamat datang, Anggota %s.\n\n", agt[i].username);
                menuAnggota();
                return;
            }
        }

        printf("\nUsername atau password salah!!!\n");
        jumlahLogin++;

        if (jumlahLogin == 3) {
            printf("\nAnda sudah gagal login sebanyak 3 kali. Kembali ke menu utama.\n\n");
            break;
        }
    } while (jumlahLogin != 3);
}

void tampilAnggotaKelompok(){
    printf("================= Anggota Kelompok ==============\n");
    printf("| 1 |    2404626    |    Dzaky Prima Yoga       |\n");
    printf("| 2 |    2405188    |    Ryan Yanuar Pradana    |\n");
    printf("=================================================\n");
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
    printf("| [1] Login                        |\n");
    printf("| [2] Anggota Kelompok             |\n");
    printf("| [0] Exit                         |\n");
    printf("====================================\n");
    printf("Masukkan pilihan : ");
    scanf("%d", &pilih);
        switch(pilih) {
            case 0 :
                return;
            case 1 :
                login();
                break;
            case 2 :
                tampilAnggotaKelompok();
                break;
            default :
                printf("Silahkan pilih menu yang ada!!!");
        };
    } while (pilih != 0);
}

#endif
