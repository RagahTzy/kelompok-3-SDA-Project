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

// Fungsi untuk clear screen
void clearScreen() {
   system(CLEAR);
}

// Simpan semua tugas ke file
void saveToFile() {
    ofstream outFile(FILE_NAME);
    for (const Task& task : tasks) {
        outFile << task.name << "|" << task.deadline << "\n";
    }
    outFile.close();
}

// Baca tugas dari file saat program dimulai
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

// Tambah tugas
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

// Tampilkan semua tugas
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

// Cari tugas berdasarkan nama
void searchTask() {
    clearScreen();
    string keyword;
    cout << "Masukkan kata kunci nama tugas: ";
    getline(cin, keyword);
    bool found = false;
    for (const auto& task : tasks) {
        if (task.name.find(keyword) != string::npos) {
            cout << "- " << task.name << " (Deadline: " << task.deadline << ")\n";
            found = true;
        }
    }
    if (!found) cout << "Tugas tidak ditemukan.\n";
}

// Update tugas
void updateTask() {
    clearScreen();
    showTasks();
    cout << "\nPilih nomor tugas yang ingin diupdate: ";
    int index;
    cin >> index;
    cin.ignore();
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Nomor tidak valid.\n";
        return;
    }

    cout << "Nama baru: ";
    getline(cin, tasks[index - 1].name);
    cout << "Deadline baru (YYYY-MM-DD): ";
    getline(cin, tasks[index - 1].deadline);
    saveToFile();
    cout << "Tugas berhasil diupdate.\n";
}

// Hapus tugas
void deleteTask() {
    clearScreen();
    showTasks();
    cout << "\nPilih nomor tugas yang ingin dihapus: ";
    int index;
    cin >> index;
    cin.ignore();
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Nomor tidak valid.\n";
        return;
    }

    deletedTasks.push(tasks[index - 1]); // Simpan untuk undo
    tasks.erase(tasks.begin() + index - 1);
    saveToFile();
    cout << "Tugas berhasil dihapus.\n";
}

// Undo penghapusan
void undoDelete() {
    clearScreen();
    if (deletedTasks.empty()) {
        cout << "Tidak ada tugas yang bisa di-undo.\n";
        return;
    }

    Task restored = deletedTasks.top();
    deletedTasks.pop();
    tasks.push_back(restored);
    saveToFile();
    cout << "Penghapusan tugas dibatalkan.\n";
}

// Urutkan berdasarkan deadline
void sortByDeadline() {
    clearScreen();
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.deadline < b.deadline;
    });
    saveToFile();
    cout << "Tugas diurutkan berdasarkan deadline.\n";
}

int main() {
    loadFromFile(); // Load saat program mulai
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