#include "header.h"

// Kode jenis laporan
const int JENIS_HILANG = 1;
const int JENIS_TEMUAN = 2;

// Kode status barang
const int STATUS_AKTIF = 0;
const int STATUS_MENUNGGU_KLAIM = 1;
const int STATUS_DIKLAIM = 2;

// ======================================
// FUNGSI PENGAJUAN KLAIM
// ======================================

void prosesKlaim() {
    int id;
    int indeks;

    string nama;
    string kontakPemilik;

    cout << "\n====================================\n";
    cout << "          PENGAJUAN KLAIM\n";
    cout << "====================================\n";

    cout << "Masukkan ID barang yang ingin diklaim: ";
    cin >> id;

    if(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "\nID harus berupa angka!\n";
        return;
    }

    cin.ignore(10000, '\n');

    // Mencari posisi barang berdasarkan ID
    indeks = cariIndexById(id);

    if(indeks == -1) {
        cout << "\nBarang tidak ditemukan!\n";
        return;
    }

    // Memeriksa apakah barang merupakan barang temuan
    if(jenis[indeks] != JENIS_TEMUAN) {
        cout << "\nBarang ini bukan laporan barang temuan!\n";
        return;
    }

    // Memeriksa status barang
    if(status[indeks] != STATUS_AKTIF) {
        cout << "\nBarang tidak tersedia untuk diklaim!\n";
        return;
    }

    cout << "\nInformasi barang:\n";
    cout << "Nama   : " << namaBarang[indeks] << endl;
    cout << "Warna  : " << warna[indeks] << endl;
    cout << "Lokasi : " << lokasi[indeks] << endl;

    cout << "\nMasukkan nama pengklaim: ";
    getline(cin, nama);

    if(nama.empty()) {
        cout << "\nNama pengklaim tidak boleh kosong!\n";
        return;
    }

    cout << "Masukkan kontak pengklaim: ";
    getline(cin, kontakPemilik);

    if(kontakPemilik.empty()) {
        cout << "\nKontak pengklaim tidak boleh kosong!\n";
        return;
    }

    // Menyimpan informasi pengklaim
    pengklaim[indeks] = nama;

    // Mengubah status barang
    status[indeks] = STATUS_MENUNGGU_KLAIM;

    cout << "\nPengajuan klaim berhasil!\n";
    cout << "Nama pengklaim : " << pengklaim[indeks] << endl;
    cout << "Status         : Menunggu verifikasi\n";

    cout << "====================================\n";
}

// verifikasi
void verifikasiKlaim() {
    int id;
    int indeks;
    int pilihan;

    cout << "\n====================================\n";
    cout << "          VERIFIKASI KLAIM\n";
    cout << "====================================\n";

    // Menampilkan semua klaim yang menunggu
    int jumlahMenunggu = 0;

    cout << "\nDaftar klaim menunggu verifikasi:\n";

    for(int i = 0; i < jumlahData; i++) {

        if(status[i] == STATUS_MENUNGGU_KLAIM) {

            cout << "\nID Barang : " << idBarang[i] << endl;
            cout << "Nama      : " << namaBarang[i] << endl;
            cout << "Pengklaim : " << pengklaim[i] << endl;

            jumlahMenunggu++;
        }
    }

    if(jumlahMenunggu == 0) {
        cout << "\nTidak ada klaim yang perlu diverifikasi.\n";
        return;
    }

    cout << "\nMasukkan ID barang yang diverifikasi: ";
    cin >> id;

    if(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "\nID harus berupa angka!\n";
        return;
    }

    cin.ignore(10000, '\n');

    indeks = cariIndexById(id);

    // Memeriksa apakah ID memiliki pengajuan klaim
    if(indeks == -1 || status[indeks] != STATUS_MENUNGGU_KLAIM) {

        cout << "\nPengajuan klaim tidak ditemukan!\n";
        return;
    }

    cout << "\nInformasi pengajuan:\n";
    cout << "Nama Barang : " << namaBarang[indeks] << endl;
    cout << "Pengklaim   : " << pengklaim[indeks] << endl;

    cout << "\nPilih keputusan:\n";
    cout << "1. Setujui klaim\n";
    cout << "2. Tolak klaim\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    if(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "\nPilihan harus berupa angka!\n";
        return;
    }

    cin.ignore(10000, '\n');

    if(pilihan == 1) {

        status[indeks] = STATUS_DIKLAIM;

        cout << "\nKlaim berhasil disetujui!\n";
        cout << "Barang telah berstatus sudah diklaim.\n";

    } else if(pilihan == 2) {

        status[indeks] = STATUS_AKTIF;
        pengklaim[indeks] = "";

        cout << "\nKlaim ditolak!\n";
        cout << "Barang kembali tersedia untuk diklaim.\n";

    } else {

        cout << "\nPilihan tidak valid!\n";
    }

    cout << "====================================\n";
}

// Menu klaim barang
void menuKlaim() {
    int pilihan;

    do {
        cout << "\n====================================\n";
        cout << "          MENU KLAIM BARANG\n";
        cout << "====================================\n";
        cout << "[1] Ajukan Klaim Barang\n";
        cout << "[2] Verifikasi Klaim Barang\n";
        cout << "[0] Kembali ke Menu Utama\n";
        cout << "====================================\n";

        cout << "Pilih menu: ";
        cin >> pilihan;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInput harus berupa angka!\n";
            continue;
        }

        cin.ignore(10000, '\n');

        switch(pilihan) {
        case 1:
            prosesKlaim();
            break;

        case 2:
            verifikasiKlaim();
            break;

        case 0:
            cout << "\nKembali ke menu utama...\n";
            break;

        default:
            cout << "\nPilihan tidak valid!\n";
        }

    } while(pilihan != 0);
}
