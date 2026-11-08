#include <cctype>
#include <iostream>
#include <string>

#include "data.h"
#include "laporan.h"
#include "tampilan.h"

using namespace std;

// Memilih kategori barang
int pilihKategori() {
    cout << "\nPilih kategori:\n";

    for(int i = 0; i < jumlah_kategori; i++) {
        cout << i + 1 << ". " << daftarKategori[i] << "\n";
    }

    int pilihan = bacaAngka("Pilih kategori", 1, jumlah_kategori);

    return pilihan;
}

// Memeriksa format tanggal DD-MM-YYYY
bool tanggalValid(string tgl) {
    if(tgl.length() != 10) {
        return false;
    }

    if(tgl[2] != '-' || tgl[5] != '-') {
        return false;
    }

    for(int i = 0; i < 10; i++) {
        if(i == 2 || i == 5) {
            continue;
        }

        if(!isdigit((unsigned char)tgl[i])) {
            return false;
        }
    }

    return true;
}

// Proses memasukkan laporan barang
void inputLaporan(int jenisLaporan) {
    cout << "\n=== LAPOR BARANG " << jenisKeTeks(jenisLaporan) << " ===\n";

    string nama = bacaTeks("Nama barang");

    int kat = pilihKategori();

    string wrn = bacaTeks("Warna barang");
    string lok = bacaTeks("Lokasi");

    string tgl;

    do {
        tgl = bacaTeks("Tanggal (DD-MM-YYYY)");

        if(!tanggalValid(tgl)) {
            cout << "Format tanggal harus DD-MM-YYYY.\n";
        }

    } while(!tanggalValid(tgl));

    string pel = bacaTeks("Nama pelapor");
    string knt = bacaTeks("Nomor kontak");
    string ciri = bacaTeks("Ciri khusus barang");

    // Menyimpan data menggunakan fungsi dari data.cpp
    bool berhasil = tambahData(jenisLaporan, nama, kat, wrn, lok, tgl, pel, knt, ciri);

    if(berhasil) {
        cout << "\nLaporan berhasil disimpan!\n";
        cout << "ID Barang: " << idTerakhir << "\n";
    } else {
        cout << "\nPenyimpanan penuh. Laporan gagal disimpan.\n";
    }
}

// Laporan barang hilang
void inputBarangHilang() {
    inputLaporan(1);
}

// Laporan barang temuan
void inputBarangTemuan() {
    inputLaporan(2);
}
