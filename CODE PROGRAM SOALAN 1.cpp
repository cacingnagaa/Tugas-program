#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk menyimpan informasi siswa
typedef struct {
    char nama[50];
    int umur;
    char no_reg[20];
} Siswa;

// Fungsi untuk menambah data siswa ke dalam file
void tambahDataSiswa() {
    FILE *fp = fopen("siswa.txt", "a"); 
    if (fp == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    Siswa s;
    // Input data dari user
    printf("Masukkan Nama Siswa     : ");
    scanf(" %[^]%*[\n]", s.nama); 
    printf("Masukkan Umur Siswa     : ");
    scanf("%d", &s.umur);
    printf("Masukkan No. Registrasi : ");
    scanf(" %s", s.no_reg);

    
    fprintf(fp, "%s,%d,%s\n", s.nama, s.umur, s.no_reg);

    fclose(fp); 
    printf("Data siswa berhasil ditambahkan.\n");
}

// Fungsi untuk menghapus data siswa berdasarkan nomor registrasi
void hapusDataSiswa() {
    char targetReg[20];
    int found = 0;

    printf("Masukkan No. Registrasi yang ingin dihapus: ");
    scanf(" %s", targetReg);

    FILE *fp = fopen("siswa.txt", "r");       
    FILE *temp = fopen("temp.txt", "w");     

    if (fp == NULL || temp == NULL) {
        if (fp != NULL) fclose(fp);
        if (temp != NULL) fclose(temp);
        printf("Gagal membuka file!\n");
        return;
    }

    Siswa s;
    char line[200]; 

   
    while (fgets(line, sizeof(line), fp)) {
        
        sscanf(line, " %[^,],%d,%[^,\n]", s.nama, &s.umur, s.no_reg);

        if (strcmp(s.no_reg, targetReg) != 0) {
            fprintf(temp, "%s,%d,%s\n", s.nama, s.umur, s.no_reg);
        } else {
            found = 1; 
        }
    }

    fclose(fp);
    fclose(temp);

    // Jika data ditemukan, ganti file lama dengan file baru
    if (found) {
        remove("siswa.txt");
        rename("temp.txt", "siswa.txt");
        printf("Data siswa berhasil dihapus.\n");
    } else {
        remove("temp.txt"); 
        printf("Data siswa tidak ditemukan.\n");
    }
}

// Fungsi untuk mencari data siswa berdasarkan nomor registrasi
void cariDataSiswa() {
    char targetReg[20];
    int found = 0;

    printf("Masukkan No. Registrasi yang ingin dicari: ");
    scanf(" %s", targetReg);

    FILE *fp = fopen("siswa.txt", "r");
    if (fp == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    Siswa s;
    char line[200];

    while (fgets(line, sizeof(line), fp)) {
        // Parse data dari baris file
        sscanf(line, " %[^,],%d,%[^,\n]", s.nama, &s.umur, s.no_reg);

        if (strcmp(s.no_reg, targetReg) == 0) {
            printf("\n--- Data Ditemukan ---\n");
            printf("Nama   : %s\n", s.nama);
            printf("Umur   : %d\n", s.umur);
            printf("No Reg : %s\n", s.no_reg);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Data siswa tidak ditemukan.\n");
    }
}

// Fungsi utama (main)
int main() {
    int pilih;

    do {
        // Tampilkan menu utama
        printf("\n=== MENU MANAJEMEN DATA SISWA ===\n");
        printf("1. Tambah Data Siswa\n");
        printf("2. Hapus Data Siswa\n");
        printf("3. Cari Data Siswa\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");

        if (scanf("%d", &pilih) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid. Silakan masukkan angka.\n");
            continue;
        }

        switch (pilih) {
            case 1:
                tambahDataSiswa();
                break;
            case 2:
                hapusDataSiswa();
                break;
            case 3:
                cariDataSiswa();
                break;
            case 0:
                printf("Terima kasih telah menggunakan program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

    } while (pilih != 0);

    return 0;
}
