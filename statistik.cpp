#include <iomanip>
#include <iostream>

#include "data.h"
#include "statistik.h"

using namespace std;

void tampilkanStatistik() {
    if(jumlahData == 0) {
        cout << "\nBelum ada data untuk dihitung statistiknya.\n";
        return;
    }

    int totalHilang = 0;
    int totalTemuan = 0;

    int totalAktif = 0;
    int totalMenunggu = 0;
    int totalDiklaim = 0;

    // Menghitung jumlah laporan
    for(int i = 0; i < jumlahData; i++) {

        // Menghitung jenis laporan
        if(jenis[i] == 1) {
            totalHilang++;
        } else if(jenis[i] == 2) {
            totalTemuan++;
        }

        // Menghitung status laporan
        if(status[i] == 0) {
            totalAktif++;
        } else if(status[i] == 1) {
            totalMenunggu++;
        } else if(status[i] == 2) {
            totalDiklaim++;
        }
    }

    // Menghitung persentase barang yang sudah diklaim
    double persentaseSelesai = (static_cast<double>(totalDiklaim) / jumlahData) * 100.0;

    cout << "\n";
    cout << "================================================\n";
    cout << "          STATISTIK LAH HILANG\n";
    cout << "================================================\n";

    cout << "Total Seluruh Laporan       : " << jumlahData << " laporan\n";

    cout << "Jumlah Barang Hilang        : " << totalHilang << " item\n";

    cout << "Jumlah Barang Temuan        : " << totalTemuan << " item\n";

    cout << "------------------------------------------------\n";

    cout << "Laporan Aktif               : " << totalAktif << " item\n";

    cout << "Menunggu Verifikasi Klaim   : " << totalMenunggu << " item\n";

    cout << "Barang Sudah Diklaim        : " << totalDiklaim << " item\n";

    cout << "------------------------------------------------\n";

    cout << "Persentase Laporan Diklaim  : " << fixed << setprecision(1) << persentaseSelesai << "%\n";

    cout << "================================================\n";
}
