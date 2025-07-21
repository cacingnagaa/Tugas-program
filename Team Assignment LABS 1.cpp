#include <stdio.h>
#include <string.h>

struct Pegawai {
    char nip[18];
    char nama[50];
    char alamat[100];
    char no_hp[13];
    char jabatan[50];
    char golongan[3];
    int gaji_pokok;
};

int getGajiPokok(char golongan[]) {
    if (strcmp(golongan, "D3") == 0) return 2500000;
    else if (strcmp(golongan, "S1") == 0) return 4000000;
    else if (strcmp(golongan, "S2") == 0) return 6000000;
    else return 0;
}

int getTarifLembur(char golongan[]) {
    if (strcmp(golongan, "D3") == 0) return 12000;
    else if (strcmp(golongan, "S1") == 0) return 19000;
    else if (strcmp(golongan, "S2") == 0) return 28000;
    else return 0;
}

int main() {
    struct Pegawai pegawai;
    char golongan_input[3];
    int jam_lembur, total_gaji, lembur;

    // Input 1
    printf("Masukkan data pegawai:\n");
    printf("NIP         : "); fgets(pegawai.nip, sizeof(pegawai.nip), stdin);
    printf("Nama        : "); fgets(pegawai.nama, sizeof(pegawai.nama), stdin);
    printf("Alamat      : "); fgets(pegawai.alamat, sizeof(pegawai.alamat), stdin);
    printf("No HP       : "); fgets(pegawai.no_hp, sizeof(pegawai.no_hp), stdin);
    printf("Jabatan     : "); fgets(pegawai.jabatan, sizeof(pegawai.jabatan), stdin);
    printf("Golongan (D3/S1/S2) : "); scanf("%s", pegawai.golongan);

    pegawai.gaji_pokok = getGajiPokok(pegawai.golongan);

    pegawai.nip[strcspn(pegawai.nip, "\n")] = 0;
    pegawai.nama[strcspn(pegawai.nama, "\n")] = 0;
    pegawai.alamat[strcspn(pegawai.alamat, "\n")] = 0;
    pegawai.no_hp[strcspn(pegawai.no_hp, "\n")] = 0;
    pegawai.jabatan[strcspn(pegawai.jabatan, "\n")] = 0;

    printf("\n--- DATA PEGAWAI ---\n");
    printf("NIP     : %s\n", pegawai.nip);
    printf("Nama    : %s\n", pegawai.nama);
    printf("Alamat  : %s\n", pegawai.alamat);
    printf("No HP   : %s\n", pegawai.no_hp);
    printf("Jabatan : %s\n", pegawai.jabatan);
    printf("Golongan: %s\n", pegawai.golongan);
    printf("Gaji    : Rp%d\n", pegawai.gaji_pokok);

    // Input 2
    printf("\nMasukkan data lembur:\n");
    printf("NIP         : "); scanf("%s", golongan_input); 
    printf("Golongan    : "); scanf("%s", golongan_input);
    printf("Jam Lembur  : "); scanf("%d", &jam_lembur);

    lembur = getTarifLembur(golongan_input) * jam_lembur;
    total_gaji = getGajiPokok(golongan_input) + lembur;

    printf("\n--- GAJI BULANAN ---\n");
    printf("NIP                 : %s\n", pegawai.nip);
    printf("Golongan            : %s\n", golongan_input);
    printf("Lembur (%d jam)     : Rp%d\n", jam_lembur, lembur);
    printf("Total Gaji Bulan ini: Rp%d\n", total_gaji);

    return 0;
}

