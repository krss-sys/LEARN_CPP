#include <iostream>
#include <string>
using namespace std;

double tinhPhiCoBan(double khoangCach = 0, double canNang = 0, bool deVo = false) {
    double phi = 30000;
    if (khoangCach > 30) {
        phi += 20000;
    }
    if (canNang > 20) {
        phi += 50000;
    }
    if (deVo == true) {
        phi += 15000;
    }

    return phi;
}

double tinhPhiSauGiam(double phiCoBan) {
    const double heSoGiam = 0.9;
    if (phiCoBan > 100000) {
        double phiSauGiam = phiCoBan * heSoGiam;
        return phiSauGiam;
    } else {
        return phiCoBan;
    }
}

void inHoaDon(double phiCoBan, double phiSauGiam) {
    cout << "Phi co ban: " << phiCoBan << " VND" << endl;
    cout << "Phi sau giam: " << phiSauGiam << " VND" << endl;
    cout << "Tiet kiem: " << phiCoBan - phiSauGiam << " VND" << endl;
}

int main() {
    double khoangCach, canNang;
    bool deVo;
    string ten;
    cout << "Vui long nhap ten khach hang: ";
    getline(cin, ten);
    cout << "Vui long nhap lan luot khoang cach, can nang, hang de vo (1 la de vo, 0 la khong): "
         << endl;
    cin >> khoangCach >> canNang >> deVo;
    double phi = tinhPhiCoBan(khoangCach, canNang, deVo);
    double phiSauGiam = tinhPhiSauGiam(phi);
    inHoaDon(phi, phiSauGiam);

    return 0;
}