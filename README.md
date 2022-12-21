# Tugas Besar Struktur Data Kelompok 15
## Anggota Kelompok
- Andry Nur Falah (1302213005)
- Herlin Priatna  (1302213018)
## Studi Kasus
Dalam suatu game online multiplayer, pemain akan bertanding melawan 3 pemain lainnya. Untuk memastikan pertandingan yang adil, maka diperlukan sistem yang dapat mencocokan pemain-pemain dengan kemampuan yang serupa dalam satu pertandingan. Sistem yang akan digunakan dalam studi kasus ini adalah Rank-Based Matchmaking yakni sistem yang akan mencocokan pemain dengan rank yang sama pada satu lobby.
## Ilustrasi
![alt text](https://github.com/andryfall/Tubes-Struktur-Data/blob/main/Ilustrasi.jpg)
## Spesifikasi
### userList (child)
userList adalah single circular linked list yang akan menyimpan data pemain berupa :
- userName()
- userId()
- Rank()
- lobby() penguhubung ke lobbyList
### lobbyList (Parent)
lobbyList adalah single linked list yang akan menyimpan data lobby berupa :
- idLobby()
- totalPemain()
- Rank()
### Fungsionalitas
- createAccount()   : Membuat akun baru berdasar input user dan disimpan di userList
- createLobby()     : Membuat lobby baru yang akan disimpan lobbyList
- findUser()        : Mencari data user pada list berdasar userID()
