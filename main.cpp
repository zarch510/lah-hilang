
#include <cstdlib>
#include <iostream>

#include "data.h"
#include "klaim.h"
#include "laporan.h"
#include "pencarian.h"
#include "pencocokan.h"
#include "pengelolaan.h"
#include "statistik.h"
#include "tampilan.h"

using namespace std;

// Membersihkan layar terminal
void bersihkanLayar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Menampilkan menu utama
void tampilkanMenu() {
    bersihkanLayar();

    cout << "=========================================\n";
    cout << "          LAH HILANG - KELOMPOK 6        \n";
    cout << "=========================================\n";
    cout << "[1] Lapor Barang Hilang\n";
    cout << "[2] Lapor Barang Temuan\n";
    cout << "[3] Tampilkan Semua Laporan\n";
    cout << "[4] Cari Barang (Berdasarkan Kata Kunci)\n";
    cout << "[5] Cocokkan Barang (Smart Matching)\n";
    cout << "[6] Klaim Barang\n";
    cout << "[7] Edit Laporan\n";
    cout << "[8] Hapus Laporan\n";
    cout << "[9] Lihat Statistik Laporan\n";
    cout << "[0] Keluar Aplikasi\n";
    cout << "=========================================\n";
}

// Program utama
int main() {
    int pilihan;

    // Memasukkan data contoh untuk pengujian
    isiDataAwal();

    do {
        tampilkanMenu();

        pilihan = bacaAngka("Masukkan angka pilihan menu", 0, 9);

        cout << "\n";

        switch(pilihan) {
        case 1:
            inputBarangHilang();
            break;

        case 2:
            inputBarangTemuan();
            break;

        case 3:
            tampilkanSemua();
            break;

        case 4:
            menuPencarian();
            break;

        case 5:
            pencocokanOtomatis();
            break;

        case 6:
            menuKlaim();
            break;

        case 7:
            editLaporan();
            break;

        case 8:
            hapusLaporan();
            break;

        case 9:
            tampilkanStatistik();
            break;

        case 0:
            cout << "Menutup aplikasi...\n";
            cout << "Terima kasih telah menggunakan sistem LAH HILANG!\n";
            break;
        }

        // Jeda sebelum kembali ke menu utama
        if(pilihan != 0) {
            cout << "\n";
            tekanEnter();
        }

    } while(pilihan != 0);

    return 0;
}
