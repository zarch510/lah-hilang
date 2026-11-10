#include "header.h"

void pencocokanOtomatis() {

    if(jumlahData == 0) {
        cout << "\nBelum ada data untuk dicocokkan.\n";
        return;
    }

    int pilihanKategori;

    cout << "\n=========================================\n";
    cout << "           PENCOCOKAN BARANG             \n";
    cout << "=========================================\n";

    cout << "[0] Semua Kategori\n";

    for(int i = 0; i < jumlah_kategori; i++) {
        cout << "[" << i + 1 << "] " << daftarKategori[i] << "\n";
    }

    cout << "=========================================\n";

    pilihanKategori = bacaAngka("Pilih kategori", 0, jumlah_kategori);

    int totalCocok = 0;
    int totalHilang = 0;
    int totalTemuan = 0;

    for(int i = 0; i < jumlahData; i++) {

        if(jenis[i] == 1 && status[i] == 0) {
            totalHilang++;
        }

        if(jenis[i] == 2 && status[i] == 0) {
            totalTemuan++;
        }
    }

    cout << "\n========== HASIL PENCOCOKAN ==========\n";

    for(int i = 0; i < jumlahData; i++) {

        // Hanya memeriksa barang hilang yang masih aktif
        if(jenis[i] != 1 || status[i] != 0) {
            continue;
        }

        // Filter kategori
        if(pilihanKategori != 0 && kategori[i] != pilihanKategori) {
            continue;
        }

        for(int j = 0; j < jumlahData; j++) {

            // Hanya memeriksa barang temuan yang masih aktif
            if(jenis[j] != 2 || status[j] != 0) {
                continue;
            }

            // Kategori harus sama
            if(kategori[i] != kategori[j]) {
                continue;
            }

            // Warna harus sama
            string warna1 = keHurufKecil(warna[i]);
            string warna2 = keHurufKecil(warna[j]);

            if(warna1 != warna2) {
                continue;
            }

            // Memeriksa kemiripan nama barang
            string nama1 = keHurufKecil(namaBarang[i]);
            string nama2 = keHurufKecil(namaBarang[j]);

            bool namaSama = nama1.find(nama2) != string::npos || nama2.find(nama1) != string::npos;

            // Memeriksa kesamaan ciri khusus
            string ciri1 = keHurufKecil(ciriKhusus[i]);
            string ciri2 = keHurufKecil(ciriKhusus[j]);

            bool ciriSama = (ciri1 == ciri2);

            // Jika nama atau ciri khusus cocok
            if(namaSama || ciriSama) {

                totalCocok++;

                cout << "\n[KECOCOKAN KE-" << totalCocok << "]\n";

                cout << "\n--- BARANG HILANG ---\n";
                tampilkanSatuBarang(i);

                cout << "\n--- BARANG TEMUAN ---\n";
                tampilkanSatuBarang(j);
            }
        }
    }

    cout << "\n=========================================\n";

    if(totalCocok == 0) {
        cout << "Tidak ditemukan barang yang cocok.\n";
    } else {
        cout << "Total kemungkinan kecocokan: " << totalCocok << "\n";
    }

    cout << "=========================================\n";
}
