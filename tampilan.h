#ifndef TAMPILAN_H
#define TAMPILAN_H

#include <string>
using namespace std;

string bacaTeks(string label);
int bacaAngka(string label, int minVal, int maxVal);
void tekanEnter();

string keHurufKecil(string s);

string jenisKeTeks(int j);
string statusKeTeks(int s);
string kategoriKeTeks(int k);

void tampilkanSatuBarang(int indeks);
void tampilkanSemua();

#endif
