// main.cpp

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib>  // untuk system()
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

struct Task {
    string name;
    string deadline;
};

vector<Task> tasks;
stack<Task> deletedTasks;
const string FILE_NAME = "tasks.txt";

// ===========================
// Placeholder Fungsi
// ===========================

void clearScreen() {
    // TODO: Implementasi clear screen menggunakan system()
}

void saveToFile() {
    // TODO: Simpan data dari vector tasks ke file teks
}

void loadFromFile() {
    // TODO: Baca data dari file dan isi vector tasks
}

void addTask() {
    clearScreen();
    Task newTask;
    cout << "Nama tugas: ";
    getline(cin, newTask.name);
    cout << "Deadline (YYYY-MM-DD): ";
    getline(cin, newTask.deadline);
    tasks.push_back(newTask);
    saveToFile();
    cout << "Tugas berhasil ditambahkan!\n";
}

void showTasks() {
    clearScreen();
    if (tasks.empty()) {
    cout << "Belum ada tugas.\n";
    return;
    }
    cout << "Daftar Tugas:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
    cout << i + 1 << ". " << tasks[i].name << " - Deadline: " << tasks[i].deadline << "\n";
    }
}

void searchTask() {
    // TODO: Cari tugas berdasarkan nama
}

void updateTask() {
    // TODO: Update tugas berdasarkan nomor indeks
}

void deleteTask() {
    // TODO: Hapus tugas dari vector dan simpan di stack
}

void undoDelete() {
    // TODO: Kembalikan tugas yang dihapus sebelumnya
}

void sortByDeadline() {
    // TODO: Urutkan tugas berdasarkan deadline
}

int main() {
    loadFromFile(); // TODO: Panggil saat program dimulai

    int choice;
    string dummy;
    while (true) {
        clearScreen();
        cout << "=== Sistem Manajemen Tugas ===\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Tampilkan Tugas\n";
        cout << "3. Cari Tugas\n";
        cout << "4. Update Tugas\n";
        cout << "5. Hapus Tugas\n";
        cout << "6. Undo Penghapusan\n";
        cout << "7. Urutkan Berdasarkan Deadline\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;
        getline(cin, dummy); // Buffer enter

        switch (choice) {
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: searchTask(); break;
            case 4: updateTask(); break;
            case 5: deleteTask(); break;
            case 6: undoDelete(); break;
            case 7: sortByDeadline(); break;
            case 0:
                cout << "Terima kasih sudah menggunakan aplikasi!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get();
    }
    return 0;
}
