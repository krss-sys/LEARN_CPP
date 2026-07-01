#include <iostream>
#include <string>
using namespace std;

// 1. struct – public mặc định
struct SinhVienStruct {
    string ten;
    int tuoi;
    float diem;
};

// 2. class – private mặc định
class SinhVienClass {
    string ten;   // private
    int tuoi;     // private
    float diem;   // private
};

int main() {
    cout << "=== STRUCT (public mac dinh) ===" << endl;
    SinhVienStruct sv1;
    sv1.ten = "Kiet";
    sv1.tuoi = 20;
    sv1.diem = 8.5;
    
    cout << "Ten: " << sv1.ten << endl;
    cout << "Tuoi: " << sv1.tuoi << endl;
    cout << "Diem: " << sv1.diem << endl;

    cout << "\n=== CLASS (private mac dinh) ===" << endl;
    SinhVienClass sv2;
    // sv2.ten = "Mai";   // ❌ LỖI: private không truy cập được
    cout << "Khong the truy cap private tu ben ngoai!" << endl;

    return 0;
}