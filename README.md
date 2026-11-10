# 🔎 Sistem Informasi Lapor Barang Hilang & Ditemukan (Lah Hilang

Program berbasis **C++ Command Line Interface (CLI)** yang digunakan untuk mengelola laporan barang hilang dan barang ditemukan. Program ini membantu pengguna mencatat laporan, mencari barang, melakukan pencocokan otomatis, serta mengelola proses klaim barang.

Proyek ini dibuat untuk memenuhi tugas **Ujian Akhir Semester (UAS)** mata kuliah [Nama Mata Kuliah].

---

## 📌 Fitur Utama

- **Lapor Barang Hilang** — Mencatat informasi barang yang hilang.
- **Lapor Barang Ditemukan** — Mencatat informasi barang yang ditemukan.
- **Tampilkan Data Barang** — Melihat seluruh laporan barang.
- **Pencarian Barang** — Mencari laporan berdasarkan informasi barang.
- **Pencocokan Otomatis** — Mencocokkan laporan barang hilang dengan barang ditemukan berdasarkan kategori dan informasi lainnya.
- **Verifikasi dan Klaim Barang** — Mengelola proses verifikasi kepemilikan dan klaim barang.
- **Statistik Laporan** — Menampilkan ringkasan data barang hilang, ditemukan, dan diklaim.

---

## 🛠️ Teknologi yang Digunakan

- Bahasa Pemrograman: C++
- Compiler: GCC / G++ / clang++
- Interface: Command Line Interface (CLI)
- Version Control: Git & GitHub

---

## 📂 Struktur Proyek

```text
Lah_Hilang/
├── data.cpp
├── header.h
├── klaim.cpp
├── lah_hilang
├── laporan.cpp
├── main.cpp
├── pencarian.cpp
├── pencocokan.cpp
├── pengelolaan.cpp
├── statistik.cpp
├── tampilan.cpp
│
├── riwayatData.txt
└── README.MD
```
---

## ⚙️ Persyaratan

Pastikan perangkat telah memiliki:

- GCC / G++ Compiler
- Git
- Terminal atau Command Prompt

---

## 🚀 Cara Menjalankan Program

### 1. Clone Repository

```bash
git clone https://github.com/zarch510/lah-hilang.git
```

### 2. Masuk ke Direktori Proyek

```bash
cd lah-hilang
```

### 3. Compile Program

```bash
g++ main.cpp data.cpp pencocokan.cpp klaim.cpp statistik.cpp -o lah_hilang
```

### 4. Jalankan Program

Linux:
```bash
./lah_hilang
```

Windows:
```bash
lah_hilang.exe
```

---

## 👥 Anggota Kelompok

| No. | Nama Anggota | Nim |
|:---:|---|---|
| 1 | Mohammad Zalki | F5512620049
| 2 | Cahya Khatulistiwa | F5512620069
| 3 | Muh. Reza Pahlevi | F5512620077
| 4 | Gabriel Djengko | F5512620082
| 5 | Hafidzal Ichsan Affandy Tajuddin | F5512620054
| 6 | Rian Nufail Ulawang | F5512620075

---

Proyek ini dibuat untuk keperluan akademik dan pembelajaran.

---

**Made with C++ | Lah Hilang**
