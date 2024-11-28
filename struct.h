#ifndef DATA_H
#define DATA_H

struct buku {
    int idBuku;
    char judul[100];
    char pengarang[100];
};

struct admin {
    char username[50];
    char password[50];
};

struct admin adm[2] = {{"admin1", "1234567890"},{"admin2", "0987654321"}};

struct anggota {
    int idAnggota;
    char nama[100];
    char username[50];
    char password[50];
    char nomorTlp[14];
    char email[100];
};

#endif
