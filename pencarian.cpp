#include "header.h"

void menuPencarian() {
    if(jumlahData == 0) {
        cout << "\nBelum ada laporan yang dapat dicari.\n";
        return;
    }

    string kataKunci;
    bool ditemukan = false;
    int jumlahDitemukan = 0;

    cout << "\n========== PENCARIAN BARANG ==========\n";
    cout << "Cari berdasarkan nama, kategori, warna,\n";
    cout << "lokasi, pelapor, atau ciri khusus.\n";

    kataKunci = bacaTeks("\nMasukkan kata kunci");
    kataKunci = keHurufKecil(kataKunci);

    cout << "\n========== HASIL PENCARIAN ==========\n";

    for(int i = 0; i < jumlahData; i++) {
        string nama = keHurufKecil(namaBarang[i]);
        string kat = keHurufKecil(kategoriKeTeks(kategori[i]));
        string wrn = keHurufKecil(warna[i]);
        string lok = keHurufKecil(lokasi[i]);
        string pel = keHurufKecil(pelapor[i]);
        string ciri = keHurufKecil(ciriKhusus[i]);

        if(nama.find(kataKunci) != string::npos || kat.find(kataKunci) != string::npos ||
           wrn.find(kataKunci) != string::npos || lok.find(kataKunci) != string::npos ||
           pel.find(kataKunci) != string::npos || ciri.find(kataKunci) != string::npos) {
            tampilkanSatuBarang(i);
            ditemukan = true;
            jumlahDitemukan++;
        }
    }

    if(!ditemukan) {
        cout << "Barang dengan kata kunci \"" << kataKunci << "\" tidak ditemukan.\n";
    } else {
        cout << "\nJumlah hasil ditemukan: " << jumlahDitemukan << " laporan.\n";
    }
}
