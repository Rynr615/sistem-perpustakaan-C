#ifndef DATA_H
#define DATA_H

#include <dos.h>
struct buku {
    int idBuku;
    char judul[100];
    char pengarang[100];
    int stok;
};

struct buku daftarBuku[100] = {
    {1, "Mercenary Enrollment", "Rak Hyun", 17},
    {2, "Omniscient Reader's Viewpoint", "Singshong", 10},
    {3, "Hero Killer", "Kkulbeol, Beolkkul", 12},
    {4, "Lookism", "Park Tae Joon", 5},
    {5, "Solo Leveling", "Chu-Gong", 8},
    {6, "Leviathan", "Chu-Gong", 8}
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

struct anggota agt[100] = {
    {1, "Ryan Yanuar Pradana", "rynrr", "1234567890", "08123456789", "ryan@gmail.com"},
    {2, "Faris Faizal Azhar", "sanz", "098765433211", "0887654321", "faris@gmail.com"},
    {3, "Faisal Gustianto", "gusti", "5432167890", "08997654321", "faisal@gmail.com"},
    {4, "Dzaky Prima Yoga", "jekzzz", "392599774", "0857319271", "jeki@gmail.com"},
};

typedef struct {
    int idAnggota;
    char username[100];
    char nama[100];
    int date;
    int month;
    int year;
    char judul[100];
} peminjaman;

peminjaman pinjamBuku[100];
typedef struct {
    int idAnggota;
    char username[100];
    char nama[100];
    int date;
    int month;
    int year;
    char judul[100];
} pengembalian;

pengembalian balikBuku[100];

#endif
