#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class SinhVien {
private:
    vector<pair<string, int>> students;
    string fileName;

public:
    SinhVien(int n) {
        fileName = "data/sinhvien.txt";
        students.reserve(n);
    }
    ~SinhVien() {
        cout << "Da destructor!!!\n";
    }

    void nhapSinhVien(int n) {
        string ten;
        double diem;
        cout << "===== Nhap thong tin sinh vien =====\n";
        for (int i = 0; i < n; i++) {
            cout << "   Nhap ten sinh vien thu " << i + 1 << ": ";
            getline(cin, ten);
            cout << "   Nhao diem sinh vien thu " << i + 1 << ": ";
            cin >> diem;
            cin.ignore(1000, '\n');
            cout << "\n";
            students.emplace_back(ten, diem);
        }
    }

    void ghiFile() {
        ofstream out(fileName);
        if (out.is_open()) {
            for (const auto& x : students) {
                out << x.first << ": " << x.second << "\n";
            }
            out.close();
        } else {
            cout << "   LOI: khong the mo file!!!\n";
            return;
        }
    }

    void docFile() {
        ifstream in(fileName);
        students.clear();
        string ten;
        double diem;
        if (in.is_open()) {
            while(getline(in, ten, ':')) {
                in >> diem;
                in.ignore(1000, '\n');
                students.emplace_back(ten, diem);
            }
            in.close();
        } else {
            cout << "   LOI: khong the mo file!!!\n";
            return;
        }
    }

    void hienThi() {
        cout << "===== Danh sach sinh vien =====\n";
        if (students.empty()) {
            cout << "   Danh sach rong!!!\n";
            return;
        } else {
            for (const auto& x : students) {
                cout << "   " << x.first << ": " << x.second << "\n";
            }
        }
    }
};

int main() {
    int n;
    cout << "============== PHAN MEM QUAN LI SINH VIEN ==============\n";
    cout << "   Nhap so sinh vien de nhap lieu: ";
    cin >> n;
    cin.ignore();
    SinhVien sv(n);
    sv.nhapSinhVien(n);
    sv.ghiFile();
    sv.docFile();
    sv.hienThi();
    

    return 0;
}
