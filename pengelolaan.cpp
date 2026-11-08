#include <iostream>
#include <string>

#include "data.h"
#include "pengelolaan.h"
#include "tampilan.h"

using namespace std;

// Mengubah data laporan
void editLaporan() {
    if(jumlahData == 0) {
        cout << "Belum ada laporan yang bisa diubah.\n";
        return;
    }

    tampilkanSemua();

    int id = bacaAngka("\nMasukkan ID laporan yang ingin diubah", 1, idTerakhir);

    int idx = cariIndexById(id);

    if(idx == -1) {
        cout << "ID laporan tidak ditemukan.\n";
        return;
    }

    cout << "\nData saat ini:\n";
    tampilkanSatuBarang(idx);

    cout << "\nBagian yang ingin diubah:\n";
    cout << "[1] Nama barang\n";
    cout << "[2] Kategori\n";
    cout << "[3] Warna\n";
    cout << "[4] Lokasi\n";
    cout << "[5] Tanggal\n";
    cout << "[6] Ciri khusus\n";
    cout << "[7] Nama pelapor\n";
    cout << "[8] Nomor kontak\n";
    cout << "[0] Batal\n";

    int pilihan = bacaAngka("Pilihan", 0, 8);

    if(pilihan == 0) {
        cout << "Perubahan dibatalkan.\n";
        return;
    }

    // Mengubah kategori
    if(pilihan == 2) {
        cout << "\nPilih kategori baru:\n";

        for(int i = 0; i < jumlah_kategori; i++) {
            cout << i + 1 << ". " << daftarKategori[i] << "\n";
        }

        kategori[idx] = bacaAngka("Pilih kategori", 1, jumlah_kategori);
    } else {
        string baru = bacaTeks("Masukkan data baru");

        switch(pilihan) {
        case 1:
            namaBarang[idx] = baru;
            break;

        case 3:
            warna[idx] = baru;
            break;

        case 4:
            lokasi[idx] = baru;
            break;

        case 5:
            tanggal[idx] = baru;
            break;

        case 6:
            ciriKhusus[idx] = baru;
            break;

        case 7:
            pelapor[idx] = baru;
            break;

        case 8:
            kontak[idx] = baru;
            break;
        }
    }

    cout << "\nLaporan berhasil diubah!\n";
    tampilkanSatuBarang(idx);
}

// Menghapus laporan
void hapusLaporan() {
    if(jumlahData == 0) {
        cout << "Belum ada laporan yang bisa dihapus.\n";
        return;
    }

    tampilkanSemua();

    int id = bacaAngka("\nMasukkan ID laporan yang ingin dihapus", 1, idTerakhir);

    int idx = cariIndexById(id);

    if(idx == -1) {
        cout << "ID laporan tidak ditemukan.\n";
        return;
    }

    cout << "\nLaporan yang akan dihapus:\n";
    tampilkanSatuBarang(idx);

    int yakin = bacaAngka("Hapus laporan ini? (1 = Ya, 0 = Batal)", 0, 1);

    if(yakin == 0) {
        cout << "Penghapusan dibatalkan.\n";
        return;
    }

    // Menghapus data menggunakan fungsi dari data.cpp
    hapusData(idx);

    cout << "\nLaporan berhasil dihapus.\n";
}
