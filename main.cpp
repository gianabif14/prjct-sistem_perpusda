#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int kode;
    string judul;
    string pengarang;
} buku;

typedef struct
{
    string nama;
    string tpt_lhr;
    string tgl_film;
    string tgl_lhr;
    string user;
    string pass;
    string alamat;
    string hariLhr;
    string bulanLhr;
    string tahunLhr;
    string judul_dipinjam[2][3] = {
        {"x", "x"},  //[judul][tgl]
        {"x", "x"}}; //[judul][tgl]
    string menonton_film[2][2] = {{"x", "x"}, {"x", "x"}};
} pengguna;

buku bku[125] = {
    {1002, "Rempah Bumbu dan Sayuran Kering Indonesia", "Ameilia Zuliyanti Siregar"},
    {1012, "Tumbuhan Obat dan Khasiatnya", "Drs.H. Arief Hariana"},
    {1001, "Pemanfaatan Dan Pengelolaan Lahan Rawa", "Muhammad Noor dan Yiyi Sulaeman"},
    {1004, "Sejarah Pertanian Sistem Surjan di Kulon Progo", "Ahmad Athoillah Ma. Drs.Dhanu Priyo "},
    {1003, "Pangan Gizi dan Pertanian", "Laura J. Harper, Brady J.Deaton, Judi A.Driskel"},
    {1025, "Akuntansi Koperasi", "Adenk Sudarwanto"},
    {1014, "Bunga Rampai Auditing", "Sukrisno Agoes dan Jan Hoesada"},
    {1015, "Mendeteksi Manipulasi Laporan Keuangan", " Theodorus M.Tuanakotta"},
    {1004, "Anggaran Perusahaan Konsep dan Aplikasi", "Yunika Murdayanti SE."},
    {1011, "Kemitraan dan Model-Model Pemberdayaan", "Ambar Teguh Sulistiyanti"},
    {1028, "Metedologi Penelitian Kualitatif dalam Riset Kepe", "Dr. Yati Afiyanti"},
    {1029, "Statistik Untuk Kesehatan", "V.Wiratna Sujarweni"},
    {1023, "Hidup Sehat dan Bahagia Bersama diabetes", "Prof.DR.Dr.Askandar Tjokroprawiro"},
    {1024, "Mengatasi Insomnia", "Dr Peter Tyrer"},
    {1005, "Penyakit-Penyakit Infeksi di Indonesia", "Dr.Soedarto DTMH"},
    {1032, "Andalusia Owner Of A Lonely Heart", "Fissilmi Hamida"},
    {1017, "Tulislah!! Mengembangkan Proses Kreatif menulis Be", "Pepih Nugraha"},
    {1031, "Paket Non-Fiksi ultah Elex 37", "Elex Media Komutindo"},
    {1007, "Elex Media Komutindo", "Gerrie Mccall"},
    {1035, "Gerrie Mccall", "Khoirul Trian"},
    {1010, "Ensliklopedia Teknologi Komputer", "Madcoms"},
    {1034, "Matematika Diskrit dan Aplikasinya pada Ilmu Kompu", "Jong Jek Siang"},
    {1020, "Pemograman Python Untuk Ilmu Komputer dan Teknik", "Widodo Budhiarto"},
    {1008, "Belajar Komputer untuk Semua Orang dari Nol", "Jubilee Enterprise"},
    {1021, "Buku Fisika Dasar untuk Mahasiswa Ilmu Komputer", "Tri Kuntoro Priyambodo"},
    {2015, "Disney Wish : Keajaiban Mimpi", "Kathy Mccullough"},
    {2029, "This Is Ariel", "Colin hosten"},
    {2001, "BSD aktivitas cars 3: legenda balap", "Elex Kids"},
    {2016, "BSD aktifitas snow white : pandai berhitung", "Elex kids"},
    {2032, "Frozen II : Malam Permainan Keluarga", "Mari mancusi"},
    {2033, "Komik next G: Aku Bisa Mandiri", "Mari mancusi"},
    {2008, "Beda itu gak apa-apa", "Anggun Maheswari Binta"},
    {2028, "Komik anak usia dini : Senang sikat gigi", "Damar wijayanti"},
    {2009, "Komik anak sehat : Hidup sehat bersama dr. Ian", "Shahaja Putri dan dr. Dian Shinta Firyanti"},
    {2013, "Komik KKPK : The Halloween Caffee", "Nafisa Mahdiya"},
    {2026, "Cerita Rakyat : Keong Emas", "Kak Adam"},
    {2002, "Oprendo kumpulan cerita asli Indonesia", "Dian aprilia dewi"},
    {2012, "Seri cerita rakyat Sulawesi Utara : Abo Mamongkuro", "Dian K"},
    {2006, "Not bedtime stories : 13 cerita pendek", "bangbuleofficial"},
    {2031, "Seri cerita rakyat ntt : Suri ikun dan 2 ekor burung", "Dian Kristiani"},
    {2011, "Pop-up dongeng dunia favorit : Danau Angsa", "Ruth Symons"},
    {2019, "Dongeng Telepon, Dongeng Kucing", "Gianni Rodari"},
    {2003, "Ayah jangan lupa satu dongeng sebelum tidur", "Boy Candra"},
    {2025, "dongeng klasik favoritku : Aladdin", "Susanna davidson"},
    {2030, "Dongeng tentang kebahagiaan", "Peter Rosei"},
    {2020, "Buku aktivitas kenal emosi", "Dina Joeda"},
    {2024, "Stop Bullying : Jati si anak pemberani", "Rahayu"},
    {2035, "Hari pertama sekolahku", "Mies kelly"},
    {2021, "Buku interaktif lepas pasang : Petualangan", "Really decent books"},
    {2005, "Buku pertamaku : Selamatkan bumi", "Miles Kelly"},
    {3016, "Menjejak Ke Tanah Tak Terjamah", "Fiona Brooks"},
    {3008, "Misteri Langkah Terakhir", "Mark Spencer"},
    {3032, "Langkah Ke Dunia Baru", "Clara Stinson"},
    {3014, "Jejak Langkah Sang Petualang", "Alexander Williams"},
    {3015, "Langkah di Hutan Terlarang", "Samuel Roberts"},
    {3005, "Langkah Pembebasan", "Roberto Diaz"},
    {3034, "Langkah Ke Masa Lalu", "Sarah Evangeline"},
    {3007, "Langkah Legenda Sang Raja", "Elena Martin"},
    {3018, "Jejak Langkah Seorang Pahlawan", "John R. Wells"},
    {3031, "Langkah Awal Revolusi", "Gregori Ivanov"},
    {3030, "Langkah Cinta yang Terlupakan", "Rachel Williams"},
    {3036, "Cinta yang Berbentuk Langkah", "Olivia Summers"},
    {3002, "Langkah Cinta yang Tersisa", "Lily Parker"},
    {3012, "Langkah Menuju Hati", "Emily Grace"},
    {3020, "Langkah dalam Hujan", "Vanessa Brooks"},
    {3003, "Langkah Sang Pahlawan Hitam", "Tara Dixon"},
    {3010, "Langkah ke Dunia Ajaib", "Leo Greenfield"},
    {3029, "Langkah Dewa Petir", "Daniel Grant"},
    {3024, "Langkah di Bawah Bulan Purnama", "Natalia Reyes"},
    {3038, "Langkah Penyihir", "Isabella Morgan"},
    {3023, "Langkah Penjahat", "Jason Carter"},
    {3026, "Misteri Langkah yang Hilang", "Olivia Hart"},
    {3011, "Langkah Berbahaya", "Sarah Devine"},
    {3028, "Langkah Terakhir Pembunuh", "Derek Moore"},
    {3001, "Langkah Dalam Kegelapan", "Mark Hollis"},
    {4018, "Mewujudkan Masyarakat Sadar dan Peduli Lingkungan", "Slamet Supriyanto"},
    {4001, "Buletin Pelestarian Warisan Budaya Dan Cagar Budaya", "Nunuik Arzakiah S. Si, M.T."},
    {4017, "Tembus Langit", "Shinta Wuri Handayani"},
    {4015, "Media Pembaruan Membangun Bangsa, Membangun Negara", "Budi Laksono"},
    {4019, "Membangun Strong Brand ", "Dorothea Samola SH"},
    {4008, "Tempo: Bukti baru pembunuhan Brigadir Yosua", "Agoeng Wijaya"},
    {4013, "Tempo : Bukan Sekedar Calon Ban Serep", "Avit Hidayat"},
    {4009, "Tempo : Tenang Ibu Sudah Disini", "Agung Sedayu"},
    {4031, "Tempo : Pamer Pamor Serdadu Disini", "Agung Sedayu"},
    {4030, "Tempo : Setelah 25", "Bagja Hidaya"},
    {4021, "Hyundai All New Kona Electric Signature Long Range", "Dahlah Dahi"},
    {4002, "First Impression Hyundai All New Santa Fe", "R. Pandji Maulana"},
    {4032, "Test Drive Baic X55-II", "Hery Maryustanto"},
    {4033, "Profil Honda Civic E & Icon", "Didit Abdillah"},
    {4005, "Test Drive Mitsubishi All New Pajero Sport Dakar U", "Rangga Kosala Putra"},
    {4035, "The story Behind : Eis Cuisines", "Hindah J. Muaris"},
    {4007, "Functional Food For Better Life", "Purwiyanto Hariyadi"},
    {4004, "Good Frying Practice", "Andang Setiandi"},
    {4022, "Nasional Food Go International", "Hindah J. Muaris"},
    {4011, "Kuliner Indonesia Semakin Mendunia", "Fyantina Eka Prilawati"},
    {4026, "Femina : Hak Perempuan Kita sadar tidak, sih!", "Femina"},
    {4024, "Femina : 2022 A year of hope", "Femina"},
    {4010, "Femina : Karna hidup harus jalan terus!", "Femina"},
    {4027, "Femina : Melihat Indonesia", "Femina"},
    {4028, "femina : Self Love", "Femina"},
    {5001, "Ensiklopedi Indonesia Brailee", "Tim Penulis"},
    {5014, "Ensiklopedi Flora Fauna Brailee", "Dr. Wina Hartati"},
    {5002, "Ensiklopedi Manusia Braille", "Maya Aulai"},
    {5025, "Ensiklopedi Transportas Brailee", "Taufik akbar"},
    {5028, "Ensiklopedi Bangunan Brailee", "Hasan Firdaus"},
    {5015, "Belajar Huruf Brailee", "Dr. Aulia Rahman"},
    {5005, "Panduan Membaca Brailee", "Ratna Dewi"},
    {5011, "Bahasa Indonesia Brailee", "Sari Kumala"},
    {5018, "Matematika Dasar Brailee", "Agus Priyanto"},
    {5004, "Geometri Dasar Brailee", "Yoga Permana"},
    {5024, "Kalkulus Dasar Brailee", "Fitri Nuraini"},
    {5017, "Kalkulis Lanjut Brailee", "Maya Aulia"},
    {5026, "Pemrograman Dasar Brailee", "Taufik akbar"},
    {5019, "Pemrograman Lanjut Brailee", "Andini Putri"},
    {5029, "Basis Data Brailee", "Dewi Fitria"},
    {5035, "Logika Informatika Brailee", "Lajnah Pentashihan Mushaf"},
    {5006, "Fisika Lanjut Brailee", "Lembaga Alkitab Indonesia"},
    {5032, "Kimia Lanjut Brailee", "Dr. Rahmawati"},
    {5031, "Gambar Teknik Brailee", "Nur Hidayati"},
    {5021, "Ilmu Pengetahuan Sosial Brailee", "Dina Pratiwi"},
    {5008, "Ilmu Pengetahuan Alam Brailee", "Sri Wahyuni"},
    {5034, "Fisika Dasar Brailee", "Dr. Siti Maryam"},
    {5010, "Kimia Dasar Brailee", "Dewi Kartika"},
    {5009, "Biologi Dasar Brailee", "Ratna Dewi"},
    {5022, "Astronomi Brailee", "Ahmad Zaki"}};

buku urut[125] = {};
buku temp;
pengguna data[100];

string x, y, z; // untuk tanggal, bulan, tahun
string judul_dicari;
int id = 0;

void tglJadiTulisan(string a);
void tampilBuku(int n);
void cekDenda(int kode, string tgl_pinjam, int &denda);
bool apakahTahunKabisat(int tahun);
int jumlahHariDalamBulan(int bulan, int tahun);
int ubahKeJumlahHari(int hari, int bulan, int tahun);
int hitungDenda(int lama);
void hitungKapanBalikin(string tgl_pinjam);
void cariBuku();
void ngurutinbuku();
bool daftar_pass(string pass_baru, int pjg_char);

int main()
{
    int jumfilm = 0, i = 0, denda = 0, saldo = 0, bayar_denda, film, denda_satuan[2] = {0}, jumlah_denda = 0, salahlogin = 1, pjg_char;
    string auth_user, auth_pass, tgl_kembali, rek, konfirmpass, gantipass, konfirmgantipass;
    string judulfilm[5] = {"Dokumenter Perjuangan DIY", "G-30SPKI", "Jendral Soedirman", "Guru Bangsa : Tjokroaminoto", "Laptop Si Unyil The Movie"};
    char menu, menu_awal, menukoleksi, keluar = 'n', balik_buku, menu_bayar, keluar1, gantipw;
    bool kenaDenda[2], passBenar = 0, loginBerhasil = 0;
    do
    {
        system("cls");
        cout << setfill('=') << setw(48) << "" << endl;
        cout << "||" << setfill(' ') << setw(4) << "" << "   Selamat Datang Di Perpustakaan   " << setw(4) << "" << "||" << endl;
        cout << "||" << setfill(' ') << setw(4) << "" << "         Daerah Yogyakarta          " << setw(4) << "" << "||" << endl;
        cout << setfill('=') << setw(48) << "" << endl;
        cout << "1. Registrasi Akun " << endl;
        cout << "2. Login Akun " << endl;
        cout << "3. Keluar Program " << endl;
        cout << "Pilih : ";
        cin >> menu_awal;

        if (menu_awal == '1')
        {
                system("cls");
                cout << setfill('=') << setw(36) << "" << endl;
                cout << "|" << setfill(' ') << setw(2) << "" << ">> Registrasi Akun Perpusda <<" << setw(2) << "" << "|" << endl;
                cout << setfill('=') << setw(36) << "" << endl;
                cin.ignore();
                cout << "Masukkan Nama Lengkap : ";
                getline(cin, data[id].nama);
                cout << "Masukkan Tempat Lahir : ";
                getline(cin, data[id].tpt_lhr);
                cout << "Masukkan Tanggal Lahir (dd-mm-yyyy) : ";
                cin >> data[id].tgl_lhr;
                cin.ignore();
                tglJadiTulisan(data[id].tgl_lhr);
                data[id].hariLhr = x;
                data[id].bulanLhr = y;
                data[id].tahunLhr = z;
                cout << "Masukkan Alamat Tempat Tinggal : ";
                getline(cin, data[id].alamat);
                cout << "Masukkan NIK/NIM (Mahasiswa) : ";
                cin >> data[id].user;
                do
                {
                    system("cls");
                    cout << setfill('=') << setw(36) << "" << endl;
                    cout << "|" << setfill(' ') << setw(2) << "" << ">> Registrasi Akun Perpusda <<" << setw(2) << "" << "|" << endl;
                    cout << setfill('=') << setw(36) << "" << endl;
                    cout << "Masukkan Nama Lengkap : " << data[id].nama << endl;
                    cout << "Masukkan Tempat Lahir : " << data[id].tpt_lhr << endl;
                    cout << "Masukkan Tanggal Lahir (dd-mm-yyyy) : " << data[id].tgl_lhr << endl;
                    cout << "Masukkan Alamat Tempat Tinggal : " << data[id].alamat << endl;
                    cout << "Masukkan NIK/NIM (Mahasiswa) : " << data[id].user << endl
                         << endl;
                    cout << "Buatlah password dengan ketentuan:\n1. Minimal panjang 8 Karakter\n2. Mengandung minimal 1 Uppercase\n3. Mengandung minimal 1 Lowercase\n4. Mengandung minimal 1 Angka" << endl
                         << endl;
                    cout << "Masukkan Password : ";
                    cin >> data[id].pass;
                    cout << "Masukkan Konfirmasi Password : ";
                    cin >> konfirmpass;
                    cout << endl;

                    if (data[id].pass == konfirmpass)
                    {
                        pjg_char = data[id].pass.length();
                        if ((daftar_pass(data[id].pass, pjg_char) == 1) && pjg_char >= 8)
                        {
                            cout << "REGISTRASI BERHASIL" << endl;
                            passBenar = 1;
                            id++;
                        }
                        else
                        {
                            cout << "PASSWORD TIDAK SESUAI KETENTUAN" << endl;
                        }
                        system("pause");
                    }
                    else if (data[id].pass != konfirmpass)
                    {
                        cout << "KONFIRMASI PASSWORD TIDAK SESUAI" << endl;
                        system("pause");
                    }
                }while (!passBenar);
        }

        if (menu_awal == 2)
        {
            do
            {
                system("cls");
                cout << setfill('=') << setw(37) << "" << endl;
                cout << "|" << setfill(' ') << setw(2) << "" << ">> Laman Login Akun Perpusda <<" << setw(2) << "" << "|" << endl;
                cout << setfill('=') << setw(37) << "" << endl;
                cout << "NIK/NIM  : ";
                cin >> auth_user;
                cout << "Password : ";
                cin >> auth_pass;
                cout << endl;

                for (int i = 0; i < id; i++)
                {
                    if (auth_user == data[id].user && auth_pass == data[id].pass)
                    {
                        loginBerhasil = 1;
                        break;
                    }
                    else
                    {
                        loginBerhasil = 0;
                    }
                }

                if (loginBerhasil == 1)
                {
                    cout << "Login Berhasil." << endl;
                    system("pause");
                    system("cls");
                    ngurutinbuku();
                    do
                    {
                        system("cls");
                        cout << setfill('=') << setw(32) << "" << endl;
                        cout << "|" << setfill(' ') << setw(2) << "" << ">> Menu Perpusda Online <<" << setw(2) << "" << "|" << endl;
                        cout << setfill('=') << setw(32) << "" << endl;
                        cout << "1. Koleksi dan Peminjaman Buku" << endl;
                        cout << "2. Pengembalian Buku" << endl;
                        cout << "3. Tonton Film" << endl;
                        cout << "4. Pembayaran Denda" << endl;
                        cout << "5. Data Identitas Diri" << endl;
                        cout << setfill('=') << setw(32) << "" << endl;
                        cout << "0. Keluar Menu" << endl;
                        cout << "Pilih Menu : ";
                        cin >> menu;
                        switch (menu)
                        {
                        case '1':
                            system("cls");
                            cout << setfill('=') << setw(32) << "" << endl;
                            cout << "|" << setfill(' ') << setw(6) << "" << ">> Koleksi Buku <<" << setw(6) << "" << "|" << endl;
                            cout << setfill('=') << setw(32) << "" << endl;
                            cout << "1. Koleksi Buku Umum" << endl;
                            cout << "2. Koleksi Buku Anak" << endl;
                            cout << "3. Koleksi Buku Langka" << endl;
                            cout << "4. Koleksi Buku Majalah" << endl;
                            cout << "5. Koleksi Buku Brailee" << endl;
                            cout << "6. Cari Buku (berdasarkan Judul)" << endl;
                            cout << setfill('=') << setw(32) << "" << endl;
                            cout << "Pilih Koleksi : ";
                            cin >> menukoleksi;

                            switch (menukoleksi)
                            {
                            case '1':
                                system("cls");
                                tampilBuku(1);
                                break;
                            case '2':
                                system("cls");
                                tampilBuku(2);
                                break;
                            case '3':
                                system("cls");
                                tampilBuku(3);
                                break;
                            case '4':
                                system("cls");
                                tampilBuku(4);
                                break;
                            case '5':
                                system("cls");
                                tampilBuku(5);
                                break;
                            case '6':
                                system("cls");
                                cariBuku();
                                break;
                            }
                            break;
                        case '2':
                            system("cls");
                            cout << setfill('=') << setw(34) << "" << endl;
                            cout << "|" << setfill(' ') << setw(2) << "" << ">> Menu Pengembalian Buku <<" << setw(2) << "" << "|" << endl;
                            cout << setfill('=') << setw(34) << "" << endl;

                            if (data[id].judul_dipinjam[0][1] != "x" || data[id].judul_dipinjam[1][1] != "x")
                            {
                                cout << "Buku Yang Sedang Anda Pinjam: " << endl
                                     << endl;
                                if (data[id].judul_dipinjam[0][0] != "x" && data[id].judul_dipinjam[0][1] != "x")
                                {
                                    cout << "A: " << data[id].judul_dipinjam[0][0] << endl;
                                    cout << "Tanggal Peminjaman Buku: " << data[id].judul_dipinjam[0][1] << endl;
                                }
                                if (data[id].judul_dipinjam[1][0] != "x" && data[id].judul_dipinjam[1][1] != "x")
                                {
                                    cout << "\nB: " << data[id].judul_dipinjam[1][0] << endl;
                                    cout << "Tanggal Peminjaman Buku: " << data[id].judul_dipinjam[1][1];
                                }
                                cout << endl
                                     << "Buku Mana Yang Ingin Anda Kembalikan? (A/B): ";
                                cin >> balik_buku;
                                if ((balik_buku == 'A' || balik_buku == 'a') && data[id].judul_dipinjam[0][1] != "x")
                                {
                                    cout << "Masukkan Tanggal Pengembalian Buku (dd-mm-yyyy) : ";
                                    cin >> tgl_kembali;
                                    cekDenda(0, tgl_kembali, denda);
                                    if (denda > 0)
                                    {
                                        denda_satuan[0] = denda;
                                        jumlah_denda += denda;
                                        cout << "Anda Dikenakan Denda Sebesar Rp. " << denda << "!\n";
                                        cout << "Silahkan Kembalikan Melalui Menu Bayar Denda!" << endl;
                                        data[id].judul_dipinjam[0][1] = "x";
                                    }
                                    else if (denda == -2)
                                    {
                                        cout << "Tanggal Pengembalian Salah" << endl;
                                    }
                                    else
                                    {
                                        cout << "Anda Berhasil Mengembalikan Buku " << data[id].judul_dipinjam[0][0] << endl;
                                        data[id].judul_dipinjam[0][0] = "x";
                                        data[id].judul_dipinjam[0][1] = "x";
                                    }
                                }
                                else if ((balik_buku == 'B' || balik_buku == 'b') && data[id].judul_dipinjam[1][1] != "x")
                                {
                                    cout << "Masukkan Tanggal Pengembalian Buku (dd-mm-yyyy) : ";
                                    cin >> tgl_kembali;
                                    cekDenda(1, tgl_kembali, denda);
                                    if (denda > 0)
                                    {
                                        denda_satuan[1] = denda;
                                        jumlah_denda += denda;
                                        cout << "Anda Dikenakan Denda Sebesar Rp. " << denda << "!\n";
                                        cout << "Silahkan Kembalikan Melalui Menu Bayar Denda!" << endl;
                                        data[id].judul_dipinjam[1][1] = "x";
                                    }
                                    else if (denda == -2)
                                    {
                                        cout << "Tanggal Pengembalian Salah" << endl;
                                    }
                                    else
                                    {
                                        cout << "Anda Berhasil Mengembalikan Buku " << data[id].judul_dipinjam[1][0] << endl;
                                        data[id].judul_dipinjam[1][0] = "x";
                                        data[id].judul_dipinjam[1][1] = "x";
                                    }
                                }
                                else
                                {
                                    cout << "Gagal Mengembalikan Buku.";
                                }
                                cout << endl;
                            }
                            else if (data[id].judul_dipinjam[0][1] == "x" && data[id].judul_dipinjam[1][1] == "x")
                            {
                                cout << endl
                                     << "Tidak Ada Buku Yang Sedang Anda Pinjam" << endl
                                     << endl;
                            }
                            break;
                        case '3':
                            system("cls");
                            cout << setfill('=') << setw(31) << "" << endl;
                            cout << "|" << setfill(' ') << setw(3) << "" << ">> Daftar Judul Film <<" << setw(3) << "" << "|" << endl;
                            cout << setfill('=') << setw(31) << "" << endl;
                            cout << "1. Dokumenter Perjuangan DIY" << endl;
                            cout << "2. G-30SPKI" << endl;
                            cout << "3. Jendral Soedirman" << endl;
                            cout << "4. Guru Bangsa : Tjokroaminoto" << endl;
                            cout << "5. Laptop Si Unyil The Movie" << endl;
                            cout << setfill('=') << setw(31) << "" << endl;
                            cout << "Apakah Anda ingin menonton film? [Y/N] : ";
                            cin >> keluar;
                            if (keluar == 'y' || keluar == 'Y')
                            {
                                cout << "Pilih Film: ";
                                cin >> film;
                                cout << "Masukkan Tanggal Penayangan (dd-mm-yyyy) : ";
                                cin >> data[id].tgl_film;
                                system("cls");
                                if ((film >= 1 && film <= 5) && (data[id].menonton_film[0][0] == "x" || data[id].menonton_film[1][0] == "x"))
                                {
                                    cout << "Pemesanan Tiket Film Berhasil" << endl;
                                    cout << "Film: " << judulfilm[film - 1] << endl;
                                    tglJadiTulisan(data[id].tgl_film);
                                    cout << "Tanggal Penayangan: " << data[id].tgl_film << endl;
                                    if (data[id].menonton_film[0][0] == "x")
                                    {
                                        data[id].menonton_film[0][0] = judulfilm[film - 1];
                                        data[id].menonton_film[0][1] = x + " " + y + " " + z;
                                    }
                                    else
                                    {
                                        data[id].menonton_film[1][0] = judulfilm[film - 1];
                                        data[id].menonton_film[1][1] = x + " " + y + " " + z;
                                    }
                                    jumfilm++;
                                }
                                else if ((film >= 1 && film <= 5) && (data[id].menonton_film[0][0] != "x" && data[id].menonton_film[1][0] != "x"))
                                {
                                    cout << "Maksimal Pemesanan Tiket Film: 2" << endl;
                                    cout << "Pemesanan Gagal" << endl;
                                }
                                else
                                {
                                    cout << "Pemesanan Gagal" << endl;
                                }
                            }
                            break;
                        case '4':
                            system("cls");
                            cout << setfill('=') << setw(28) << "" << endl;
                            cout << "|" << setfill(' ') << setw(2) << "" << ">> Pembayaran Denda <<" << setw(2) << "" << "|" << endl;
                            cout << setfill('=') << setw(28) << "" << endl;

                            if (denda_satuan[0] != 0 || denda_satuan[1] != 0)
                            {
                                cout << "List denda:" << endl;
                                if (denda_satuan[0] != 0)
                                {
                                    cout << "A. " << data[id].judul_dipinjam[0][0] << " terkena Denda sebesar Rp. " << denda_satuan[0] << endl;
                                }
                                else if (denda_satuan[1] != 0)
                                {
                                    cout << "B. " << data[id].judul_dipinjam[1][0] << " terkena Denda sebesar Rp. " << denda_satuan[1] << endl;
                                }
                                cout << endl
                                     << "Jumlah denda yang harus dibayar: " << jumlah_denda << endl;
                                cout << "Menu Pembayaran:\n1. Gopay\n2. Dana\n3. Cash" << endl
                                     << endl;
                                cout << "Pilih Menu: ";
                                cin >> menu_bayar;
                                switch (menu_bayar)
                                {
                                case '1':
                                case '2':
                                    cout << "Masukkan Nomor E-wallet: ";
                                    cin >> rek;
                                    cout << "Masukkan Sisa Saldo: ";
                                    cin >> saldo;
                                    if (saldo >= jumlah_denda)
                                    {
                                        saldo -= jumlah_denda;
                                        cout << "Pembayaran Berhasil! Sisa Saldo: Rp. " << saldo << endl;
                                        data[id].judul_dipinjam[0][0] = "x";
                                        data[id].judul_dipinjam[1][1] = "x";
                                    }
                                    else
                                    {
                                        cout << "Saldo Anda tidak mencukupi" << endl;
                                    }
                                    break;

                                case '3':
                                    cout << "Masukkan Nominal Uang: ";
                                    cin >> saldo;
                                    if (saldo >= jumlah_denda)
                                    {
                                        saldo -= jumlah_denda;
                                        cout << "Pembayaran Berhasil! Kembalian: Rp. " << saldo << endl;
                                        data[id].judul_dipinjam[0][0] = "x";
                                        data[id].judul_dipinjam[1][1] = "x";
                                    }
                                    else
                                    {
                                        cout << "Uang Anda tidak mencukupi" << endl;
                                    }
                                    break;

                                default:
                                    break;
                                }
                            }
                            else
                            {
                                cout << "Anda Tidak Memiliki Riwayat Denda" << endl;
                            }
                            break;
                        case '5':
                            system("cls");
                            cout << setfill('=') << setw(31) << "" << endl;
                            cout << "|" << setfill(' ') << setw(2) << "" << ">> Data Identitas Diri <<" << setw(2) << "" << "|" << endl;
                            cout << setfill('=') << setw(31) << "" << endl;

                            cout << "NIM/NIK    : " << data[id].user << endl;
                            cout << "Nama       : " << data[id].nama << endl;
                            cout << "TTL        : " << data[id].tpt_lhr << ", " << data[id].hariLhr << ' ' << y << ' ' << data[id].tahunLhr << endl;
                            cout << "Alamat     : " << data[id].alamat << endl
                                 << endl;

                            cout << "Tiket Film Dimiliki: " << endl;
                            if (jumfilm == 0)
                            {
                                cout << "Tidak ada tiket film yang dimiliki" << endl;
                            }
                            else
                            {
                                for (i = 0; i < jumfilm; i++)
                                {
                                    cout << i + 1 << ". " << data[id].menonton_film[i][0] << endl;
                                    cout << "   Tanggal Penayangan: " << data[id].menonton_film[i][1] << endl
                                         << endl;
                                }
                            }
                            break;
                        case '0':
                            keluar1 = 'n';
                            break;
                        default:
                            cout << "Maaf Menu Yang Anda Masukkan Salah" << endl;
                            keluar1 = 'n';
                            break;
                        }

                        if (menu != '0')
                        {
                            cout << "Apakah Anda Ingin Keluar Dari Halaman ini? [Y/N]: ";
                            cin >> keluar1;
                        }
                    } while (keluar1 == 'Y' || keluar1 == 'y');
                }
                else if (auth_user != data[id].user || auth_pass != data[id].pass && salahlogin < 3)
                {
                    cout << "NIK/NIM atau Password Salah" << endl;
                    cout << "Coba Masukan Ulang NIK/NIM atau Password" << endl;
                    salahlogin++;
                }
                else if (auth_user != data[id].user || auth_pass != data[id].pass && salahlogin >= 3)
                {
                    cout << "NIK/NIM atau Password Salah" << endl;
                    cout << "Apakah Anda Lupa Password? [Y/N]: ";
                    cin >> gantipw;
                    if (gantipw == 'y' || gantipw == 'Y')
                    {
                        do
                        {
                            system("cls");
                            cout << setfill('=') << setw(40) << "" << endl;
                            cout << "|" << setfill(' ') << setw(2) << "" << ">> Reset Password Akun Alphasek <<" << setw(2) << "" << "|" << endl;
                            cout << setfill('=') << setw(40) << "" << endl
                                 << endl;

                            cout << "Buatlah password dengan ketentuan:\n1. Minimal panjang 8 Karakter\n2. Mengandung minimal 1 Uppercase\n3. Mengandung minimal 1 Lowercase\n4. Mengandung minimal 1 Angka" << endl
                                 << endl;
                            cout << "Password Yang Baru : ";
                            cin >> gantipass;
                            cout << "Konfirmasi Password Baru : ";
                            cin >> konfirmgantipass;
                            cout << endl;

                            if (gantipass == konfirmgantipass)
                            {
                                pjg_char = gantipass.length();
                                if ((daftar_pass(gantipass, pjg_char) == 1) && pjg_char >= 8)
                                {
                                    data[id].pass = gantipass;
                                    cout << "Password Berhasil Diperbarui" << endl;
                                    cout << "Silahkan Login Kembali Dimenu Login" << endl;
                                }
                                else
                                {
                                    cout << "Password Baru Anda Tidak Sesuai Ketentuan" << endl;
                                }
                                system("pause");
                            }
                            else if (gantipass != konfirmgantipass)
                            {
                                cout << "KONFIRMASI PASSWORD TIDAK SESUAI" << endl;
                                system("pause");
                            }
                        } while (gantipass != konfirmgantipass);
                    }
                }
                cout << "Apakah Anda Ingin Keluar Dari Program Ini? [Y/N]: ";
                cin >> keluar;
            } while (keluar == 'n' || keluar == 'N');
        }

        if (menu_awal == 3)
        {
            system("cls");
            cout << "Program Dihentikan" << endl;
            cout << "Kata-Kata Hari ini : " << endl;
            cout << "Semua Orang Datang dan Pergi tapi Sekali Berkunjung Ke Perpustakaan Pasti Balik Lagi" << endl;
        }
    }while (keluar == 'n' || keluar == 'N');
}

void tglJadiTulisan(string a)
{
    // dd-mm-yyyy
    // 0123456789
    int yInt;
    x = a.substr(0, 2);          // tanggal
    yInt = stoi(a.substr(3, 2)); // bulan
    yInt == 1 ? y = "Januari" : y;
    yInt == 2 ? y = "Februari" : y;
    yInt == 3 ? y = "Maret" : y;
    yInt == 4 ? y = "April" : y;
    yInt == 5 ? y = "Mei" : y;
    yInt == 6 ? y = "Juni" : y;
    yInt == 7 ? y = "Juli" : y;
    yInt == 8 ? y = "Agustus" : y;
    yInt == 9 ? y = "September" : y;
    yInt == 10 ? y = "Oktober" : y;
    yInt == 11 ? y = "November" : y;
    yInt == 12 ? y = "Desember" : y;
    z = a.substr(6, 4); // tahun
}

bool apakahTahunKabisat(int tahun)
{
    return (tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0);
}

int jumlahHariDalamBulan(int bulan, int tahun)
{
    switch (bulan)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return apakahTahunKabisat(tahun) ? 29 : 28;
    default:
        return 0;
    }
}

void hitungKapanBalikin(string tgl_pinjam)
{
    int hari, bulan, tahun, tgl_balikin, bln_balikin;
    hari = stoi(tgl_pinjam.substr(0, 2));
    bulan = stoi(tgl_pinjam.substr(3, 2));
    tahun = stoi(tgl_pinjam.substr(6, 4));
    bool anjay = 0;
    int a = jumlahHariDalamBulan(bulan, tahun);
    if (hari + 7 > a)
    {
        tgl_balikin = (hari + 7) % a;
        bln_balikin = bulan + 1;
    }
    else
    {
        tgl_balikin = hari + 7;
        bln_balikin = bulan;
    }

    cout << tgl_balikin << "-" << bln_balikin << "-" << tahun << endl;
};

// Fungsi untuk mengubah tanggal menjadi total jumlah hari sejak tahun 0
int ubahKeJumlahHari(int hari, int bulan, int tahun)
{
    int totalHari = hari; // Memulai dari jumlah hari dalam bulan
    // Menambahkan jumlah hari untuk tahun-tahun sebelumnya
    for (int t = 0; t < tahun; t++)
    {
        totalHari += apakahTahunKabisat(t) ? 366 : 365;
    }
    // Menambahkan jumlah hari untuk bulan-bulan sebelumnya pada tahun yang sama
    for (int b = 1; b < bulan; b++)
    {
        totalHari += jumlahHariDalamBulan(b, tahun);
    }
    return totalHari;
}

void cekDenda(int kode, string tgl_kembali, int &denda)
{
    int hariAwal, bulanAwal, tahunAwal;
    int hariAkhir, bulanAkhir, tahunAkhir;

    // Memisahkan tanggal awal menjadi hari, bulan, dan tahun
    hariAwal = stoi(data[id].judul_dipinjam[kode][1].substr(0, 2));
    bulanAwal = stoi(data[id].judul_dipinjam[kode][1].substr(3, 2));
    tahunAwal = stoi(data[id].judul_dipinjam[kode][1].substr(6, 4));

    // Memisahkan tanggal akhir menjadi hari, bulan, dan tahun
    hariAkhir = stoi(tgl_kembali.substr(0, 2));
    bulanAkhir = stoi(tgl_kembali.substr(3, 2));
    tahunAkhir = stoi(tgl_kembali.substr(6, 4));

    // Mengonversi tanggal ke jumlah hari sejak tahun 0 masehi
    int totalHariAwal = ubahKeJumlahHari(hariAwal, bulanAwal, tahunAwal);
    int totalHariAkhir = ubahKeJumlahHari(hariAkhir, bulanAkhir, tahunAkhir);

    // Menghitung selisih jumlah hari
    int selisihHari = totalHariAkhir - totalHariAwal;

    if (selisihHari > 7)
    {
        denda = hitungDenda(selisihHari - 7);
    }
    else if (selisihHari >= 0 && selisihHari <= 7)
    {
        denda = -1; // tidak dikenai denda
    }
    else
    {
        denda = -2; // tanggal salah (dikembalikan saat belum meminjam)
    }
};
int hitungDenda(int lama)
{
    if (lama == 0)
    {
        return 0;
    }
    else
    {
        return 2000 + hitungDenda(lama - 1);
    }
};

void tampilBuku(int n)
{
    int page = 1, no_buku;
    char yes = 'y', pinjam, pilih;
    int kode[25];
    string judul[25], pengarang[25];

    int x, y;
    if (n == 1)
    {
        x = 0;
    }
    else if (n == 2)
    {
        x = 25;
    }
    else if (n == 3)
    {
        x = 50;
    }
    else if (n == 4)
    {
        x = 75;
    }
    else if (n == 5)
    {
        x = 100;
    }
    for (int i = 0; i < 25; i++)
    {
        kode[i] = urut[x].kode;
        judul[i] = urut[x].judul;
        pengarang[i] = urut[x].pengarang;
        x++;
    }

    do
    {
        if (page == 1)
        {
            x = 0;
            y = 5;
        }
        if (page == 2)
        {
            x = 5;
            y = 10;
        }
        if (page == 3)
        {
            x = 10;
            y = 15;
        }
        if (page == 4)
        {
            x = 15;
            y = 20;
        }
        if (page == 5)
        {
            x = 20;
            y = 25;
        }
        cout << "Koleksi Buku (" << x + 1 << "-" << y << ") :" << endl;
        for (int i = x; i < y; i++)
        {
            cout << i + 1 << ". Judul Buku\t\t: " << judul[i] << endl;
            cout << "  Kode Buku\t\t: " << kode[i] << endl;
            cout << "  Pengarang Buku\t: " << pengarang[i] << endl;
            cout << "\n";
        }
        cout << setfill('=') << setw(87) << "" << endl;
        cout << "<- Page Sebelumnya (F) |  Pinjam Buku (P)  |  Keluar Menu(Q)  | Page Selanjutnya (N) ->" << endl;
        cout << setfill('=') << setw(87) << "" << endl;
        cout << "Pilih: ";

        cin >> pilih;
        if (pilih == 'N' || pilih == 'n')
        {
            if (page > 0 && page < 5)
            {
                page++;
            }
            system("cls");
        }
        else if (pilih == 'F' || pilih == 'f')
        {
            if (page > 1 && page < 6)
            {
                page--;
            }
            system("cls");
        }
        else if (pilih == 'Q' || pilih == 'q')
        {
            break;
        }
        else if (pilih == 'P' || pilih == 'p')
        {
            cout << "Apakah Anda Ingin Meminjam Buku? (Y/N): ";
            cin >> pinjam;
            if (pinjam == 'y' || pinjam == 'Y')
            {
                cout << "No Buku Yang Ingin Anda Pinjam: ";
                cin >> no_buku;
                if (data[id].judul_dipinjam[0][0] == "x" && data[id].judul_dipinjam[1][0] != judul[no_buku - 1])
                {
                    cout << "Masukkan Tanggal Peminjaman Buku (dd-mm-yyyy) : ";
                    cin >> data[id].judul_dipinjam[0][1];
                    system("cls");
                    cout << setfill('=') << setw(31) << "" << endl;
                    cout << "|" << setfill(' ') << setw(4) << "" << ">> Peminjaman Buku <<" << setw(4) << "" << "|" << endl;
                    cout << setfill('=') << setw(31) << "" << endl;
                    cout << "Anda Berhasil Meminjam Buku " << judul[no_buku - 1] << endl;
                    cout << "Tanggal Peminjaman Buku : " << data[id].judul_dipinjam[0][1] << endl;
                    cout << "Kembalikan buku dalam 7 hari, Sebelum tanggal ";
                    hitungKapanBalikin(data[id].judul_dipinjam[0][1]);
                    data[id].judul_dipinjam[0][0] = judul[no_buku - 1];
                    yes = 'n';
                }
                else if (data[id].judul_dipinjam[1][0] == "x" && data[id].judul_dipinjam[0][0] != judul[no_buku - 1])
                {
                    cout << "Masukkan Tanggal Peminjaman Buku (dd-mm-yyyy) : ";
                    cin >> data[id].judul_dipinjam[1][1];
                    system("cls");
                    cout << setfill('=') << setw(31) << "" << endl;
                    cout << "|" << setfill(' ') << setw(4) << "" << ">> Peminjaman Buku <<" << setw(4) << "" << "|" << endl;
                    cout << setfill('=') << setw(31) << "" << endl;
                    cout << "Anda Berhasil Meminjam Buku " << judul[no_buku - 1] << endl;
                    cout << "Tanggal Peminjaman Buku : " << data[id].judul_dipinjam[1][1] << endl;
                    cout << "Kembalikan buku dalam 7 hari, Sebelum tanggal ";
                    hitungKapanBalikin(data[id].judul_dipinjam[1][1]);
                    data[id].judul_dipinjam[1][0] = judul[no_buku - 1];
                    yes = 'n';
                }
                else if (data[id].judul_dipinjam[0][0] != judul[no_buku - 1] || data[id].judul_dipinjam[1][0] != judul[no_buku - 1])
                {
                    system("cls");
                    cout << setfill('=') << setw(31) << "" << endl;
                    cout << "|" << setfill(' ') << setw(4) << "" << ">> Peminjaman Buku <<" << setw(4) << "" << "|" << endl;
                    cout << setfill('=') << setw(31) << "" << endl;
                    cout << "Anda Tidak Diperbolehkan Meminjam Buku" << endl;
                    cout << "Buku " << judul[no_buku - 1] << " Telah Dipinjam" << endl;
                    cout << "Silahkan Kembalikan Buku Yang Sudah Dipinjam terlebih dahulu" << endl;
                    yes = 'n';
                }
                else
                {
                    system("cls");
                    cout << setfill('=') << setw(31) << "" << endl;
                    cout << "|" << setfill(' ') << setw(4) << "" << ">> Peminjaman Buku <<" << setw(4) << "" << "|" << endl;
                    cout << setfill('=') << setw(31) << "" << endl;
                    cout << "Anda Tidak Diperbolehkan Meminjam Buku" << endl;
                    cout << "Silahkan Kembalikan Buku Yang Sudah Dipinjam terlebih dahulu" << endl;
                    yes = 'n';
                }
            }
            else
            {
                yes = 'n';
            }
        }
    } while (yes == 'y' || yes == 'Y');
};

void cariBuku()
{
    cout << setfill('=') << setw(31) << "" << endl;
    cout << "|" << setfill(' ') << setw(4) << "" << ">> Pencarian Buku <<" << setw(4) << "" << "|" << endl;
    cout << setfill('=') << setw(31) << "" << endl;
    cout << endl;
    cout << "Mencari Judul Buku Menggunakan Huruf Kapital Pada Awal Katanya" << endl;
    cout << "Telusuri : ";
    cin >> judul_dicari;
    cout << endl;

    int pjg_dicari = judul_dicari.length();
    int pjg_buku;
    bool adaYgKetemu = false, pesan;
    for (int i = 0; i < 125; i++)
    {
        bool ketemu = true;
        string jdl_buku = urut[i].judul;
        pjg_buku = jdl_buku.length();
        for (int j = 0; j < pjg_buku - pjg_dicari; j++)
        {
            ketemu = true;
            for (int k = 0; k < pjg_dicari; k++)
            {
                if (judul_dicari[k] != urut[i].judul[j + k])
                {
                    ketemu = false;
                    break;
                }
            }
            if (ketemu)
            {
                adaYgKetemu = true;
                break;
            }
        }
        if (ketemu)
        {
            cout << "Judul      : " << urut[i].judul << endl;
            cout << "Kode       : " << urut[i].kode << endl;
            cout << "Pengarang  : " << urut[i].pengarang << endl;
            cout << setfill('-') << setw(40) << " " << endl;
            cout << endl;

            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    if (!adaYgKetemu)
    {
        cout << "Buku Tidak Ditemukan" << endl;
    }
};

void ngurutinbuku()
{
    for (int j = 0; j < 125; j++)
    {
        urut[j].kode = bku[j].kode;
        urut[j].judul = bku[j].judul;
        urut[j].pengarang = bku[j].pengarang;
    }
    for (int i = 0; i < 125 - 1; i++)
    {
        for (int j = 0; j < 125 - i - 1; j++)
        {
            if (urut[j].kode > urut[j + 1].kode)
            {
                temp.kode = urut[j].kode;
                urut[j].kode = urut[j + 1].kode;
                urut[j + 1].kode = temp.kode;

                temp.judul = urut[j].judul;
                urut[j].judul = urut[j + 1].judul;
                urut[j + 1].judul = temp.judul;

                temp.pengarang = urut[j].pengarang;
                urut[j].pengarang = urut[j + 1].pengarang;
                urut[j + 1].pengarang = temp.pengarang;
            }
        }
    }
};

bool daftar_pass(string pass_baru, int pjg_char)
{
    bool upper = 0, lower = 0, angka = 0, simbol = 0;
    char huruf;
    for (int i = 0; i < pjg_char; i++)
    {
        huruf = pass_baru[i];
        if (huruf >= 48 && huruf <= 57)
            angka = 1;
        else if (huruf >= 65 && huruf <= 90)
            upper = 1;
        else if (huruf >= 97 && huruf <= 122)
            lower = 1;
        else
            simbol = 1;
    }
    if (angka == 1 && upper == 1 && lower == 1 && simbol == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};