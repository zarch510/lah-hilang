#ifndef data_h
#define data_h

#include <string>
using namespace std;

const int max_data = 100;
const int jumlah_kategori = 6;

extern int jumlahData;
extern int idTerakhir;

extern int idBarang[max_data];
extern int jenis[max_data];
extern string namaBarang[max_data];
extern int kategori[max_data];
extern string warna[max_data];
extern string lokasi[max_data];
extern string tanggal[max_data];
extern string pelapor[max_data];
extern string kontak[max_data];
extern string ciriKhusus[max_data];
extern int status[max_data];
extern string pengklaim[max_data];

extern const string daftarKategori[jumlah_kategori];

bool tambahData(int jenisLaporan, string nama, int kat, string wrn, string lok, string tgl, string pel, string knt,
                string ciri);
int cariIndexById(int id);
void hapusData(int index);
void isiDataAwal();

#endif
