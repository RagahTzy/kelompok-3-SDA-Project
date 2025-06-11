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
   system(CLEAR);
}

void saveToFile() {
    ofstream outFile(FILE_NAME);
    for (const Task& task : tasks) {
        outFile << task.name << "|" << task.deadline << "\n";
    }
    outFile.close();
}

void loadFromFile() {
   ifstream inFile(FILE_NAME);
    if (!inFile) return;

    string line;
    while (getline(inFile, line)) {
        size_t delimiter = line.find("|");
        if (delimiter != string::npos) {
            Task task;
            task.name = line.substr(0, delimiter);
            task.deadline = line.substr(delimiter + 1);
            tasks.push_back(task);
        }
    }
    inFile.close();
}

void addTask() {
    // TODO: Tambah tugas baru ke vector tasks
}

void showTasks() {
    // TODO: Tampilkan semua tugas dalam vector tasks
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
