#include "header.h"

using namespace std;

// Membaca input teks
string bacaTeks(string label) {
    string teks;

    do {
        cout << label << ": ";
        getline(cin, teks);

        if(teks.empty()) {
            cout << "Input tidak boleh kosong.\n";
        }

    } while(teks.empty());

    return teks;
}

// Membaca input angka dengan batas tertentu
int bacaAngka(string label, int minVal, int maxVal) {
    int nilai;

    while(true) {
        cout << label << " (" << minVal << "-" << maxVal << "): ";

        if(cin >> nilai && nilai >= minVal && nilai <= maxVal) {
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.ignore(10000, '\n');
            return nilai;
        }

        cin.clear();
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(10000, '\n');
        cout << "Input tidak valid, silakan coba lagi.\n";
    }
}

// Mengubah teks menjadi huruf kecil
string keHurufKecil(string s) {
    for(int i = 0; i < (int)s.length(); i++) {
        s[i] = tolower((unsigned char)s[i]);
    }

    return s;
}

// Mengubah jenis laporan menjadi teks
string jenisKeTeks(int j) {
    if(j == 1) {
        return "HILANG";
    }

    if(j == 2) {
        return "TEMUAN";
    }

    return "TIDAK DIKETAHUI";
}

// Mengubah status laporan menjadi teks
string statusKeTeks(int s) {
    if(s == 0) {
        return "Aktif";
    }

    if(s == 1) {
        return "Menunggu Verifikasi";
    }

    if(s == 2) {
        return "Sudah Diklaim";
    }

    return "Tidak Diketahui";
}

// Mengubah kategori angka menjadi nama kategori
string kategoriKeTeks(int k) {
    if(k >= 1 && k <= jumlah_kategori) {
        return daftarKategori[k - 1];
    }

    return "Tidak Diketahui";
}

// Menunggu pengguna menekan Enter
void tekanEnter() {
    cout << "Tekan Enter untuk kembali ke menu...";
    cin.get();
}

// Menampilkan satu data barang
void tampilkanSatuBarang(int indeks) {
    cout << "-----------------------------------------\n";
    cout << "ID Barang   : " << idBarang[indeks] << "\n";
    cout << "Jenis       : " << jenisKeTeks(jenis[indeks]) << "\n";
    cout << "Nama Barang : " << namaBarang[indeks] << "\n";
    cout << "Kategori    : " << kategoriKeTeks(kategori[indeks]) << "\n";
    cout << "Warna       : " << warna[indeks] << "\n";
    cout << "Lokasi      : " << lokasi[indeks] << "\n";
    cout << "Tanggal     : " << tanggal[indeks] << "\n";
    cout << "Pelapor     : " << pelapor[indeks] << "\n";
    cout << "Kontak      : " << kontak[indeks] << "\n";
    cout << "Ciri Khusus : " << ciriKhusus[indeks] << "\n";
    cout << "Status      : " << statusKeTeks(status[indeks]) << "\n";

    if(!pengklaim[indeks].empty()) {
        cout << "Pengklaim   : " << pengklaim[indeks] << "\n";
    }

    cout << "-----------------------------------------\n";
}

// Menampilkan seluruh laporan
void tampilkanSemua() {
    if(jumlahData == 0) {
        cout << "Belum ada laporan barang.\n";
        return;
    }

    cout << "\n========== DAFTAR SEMUA LAPORAN ==========\n";

    for(int i = 0; i < jumlahData; i++) {
        tampilkanSatuBarang(i);
    }

    cout << "Jumlah laporan: " << jumlahData << "\n";
}
