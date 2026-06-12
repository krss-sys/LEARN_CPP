#include <iostream>
using namespace std;

double tinhDienTich(double dai, double rong) {
    cout << "Dien tich hinh chu nhat: ";
    return dai * rong;
}

double tinhDienTich(double canh) {
    cout << "\nDien tich hinh vuong: ";
    return canh * canh;
}

double tinhDienTich(double banKinh, bool laHinhTron) {
    if(laHinhTron == true) {
        cout << "\nDien tich hinh tron: ";
        return 3.14 * banKinh *banKinh;
    }
    return 0;
}

int main() {
    cout << "===TINH DIEN TICH===" << endl;
    cout << tinhDienTich(5.4, 10.1) << endl;
    cout << tinhDienTich(3, true) << endl;
    cout << tinhDienTich(5) << endl;

    return 0;
}