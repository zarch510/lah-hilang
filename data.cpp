#include "header.h"
#include <fstream>

int jumlahData = 0;
int idTerakhir = 0;

int idBarang[max_data];
int jenis[max_data];
string namaBarang[max_data];
int kategori[max_data];
string warna[max_data];
string lokasi[max_data];
string tanggal[max_data];
string pelapor[max_data];
string kontak[max_data];
string ciriKhusus[max_data];
int status[max_data];
string pengklaim[max_data];

// Daftar kategori barang
const string daftarKategori[jumlah_kategori] = {"Elektronik", "Dompet",    "Alat Tulis",
                                                "Pakaian",    "Aksesoris", "Lainnya"};

// Fungsi menambahkan data barang
bool tambahData(int jenisLaporan, string nama, int kat, string wrn, string lok, string tgl, string pel, string knt,
                string ciri) {

    if(jumlahData >= max_data) {
        return false;
    }

    int i = jumlahData;

    idTerakhir++;

    idBarang[i] = idTerakhir;
    jenis[i] = jenisLaporan;
    namaBarang[i] = nama;
    kategori[i] = kat;
    warna[i] = wrn;
    lokasi[i] = lok;
    tanggal[i] = tgl;
    pelapor[i] = pel;
    kontak[i] = knt;
    ciriKhusus[i] = ciri;

    status[i] = 0;
    pengklaim[i] = "";

    jumlahData++;

    return true;
}

// Fungsi mencari posisi data berdasarkan ID
int cariIndexById(int id) {

    for(int i = 0; i < jumlahData; i++) {
        if(idBarang[i] == id) {
            return i;
        }
    }

    return -1;
}

// Fungsi menghapus data berdasarkan indeks
void hapusData(int indeks) {

    for(int i = indeks; i < jumlahData - 1; i++) {
        idBarang[i] = idBarang[i + 1];
        jenis[i] = jenis[i + 1];
        namaBarang[i] = namaBarang[i + 1];
        kategori[i] = kategori[i + 1];
        warna[i] = warna[i + 1];
        lokasi[i] = lokasi[i + 1];
        tanggal[i] = tanggal[i + 1];
        pelapor[i] = pelapor[i + 1];
        kontak[i] = kontak[i + 1];
        ciriKhusus[i] = ciriKhusus[i + 1];
        status[i] = status[i + 1];
        pengklaim[i] = pengklaim[i + 1];
    }

    jumlahData--;
}

// Fungsi mengisi data awal untuk percobaan
void isiDataAwal() {

    tambahData(1, "Dompet kulit", 2, "Coklat", "Kantin", "01-11-2026", "Budi", "0811111111",
               "Ada foto kucing di dalam");

    tambahData(2, "Dompet", 2, "Coklat", "Kantin", "02-11-2026", "Sari", "0822222222", "Ada foto kucing di dalam");

    tambahData(2, "Charger laptop", 1, "Hitam", "Perpustakaan", "03-11-2026", "Andi", "0833333333",
               "Kabel ada selotip biru");
}

void simpanData() {
    ofstream file("riwayatData.txt");

    for(int i = 0; i < jumlahData; i++) {
        file << idBarang[i] << endl;
        file << jenis[i] << endl;
        file << namaBarang[i] << endl;
        file << kategori[i] << endl;
        file << warna[i] << endl;
        file << lokasi[i] << endl;
        file << tanggal[i] << endl;
        file << pelapor[i] << endl;
        file << kontak[i] << endl;
        file << ciriKhusus[i] << endl;
        file << status[i] << endl;
        file << pengklaim[i] << endl;
    }

    file.close();
}

void muatData() {
    ifstream file("riwayatData.txt");

    if(!file.is_open()) {
        return;
    }

    jumlahData = 0;

    while(file >> idBarang[jumlahData]) {
        int i = jumlahData;

        file >> jenis[i];
        file.ignore();

        getline(file, namaBarang[i]);

        file >> kategori[i];
        file.ignore();

        getline(file, warna[i]);
        getline(file, lokasi[i]);
        getline(file, tanggal[i]);
        getline(file, pelapor[i]);
        getline(file, kontak[i]);
        getline(file, ciriKhusus[i]);

        file >> status[i];
        file.ignore();

        getline(file, pengklaim[i]);

        if(idBarang[i] > idTerakhir) {
            idTerakhir = idBarang[i];
        }

        jumlahData++;

        if(jumlahData >= max_data) {
            break;
        }
    }

    file.close();
}
