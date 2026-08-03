#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class KhoHang {
private:
    unordered_map<string, int> kho;

public:
    void themSanPham() {
        string tenSp;
        int soLuong;
        while (true) {
            cout << "\n===== Them San Pham (nhan end de thoat)=====\n";
            cout << "\n<<<<<Danh sach san pham hien tai >>>>>\n";
            if (kho.empty()) {
                cout << "~~~~~Danh sach rong~~~~~\n";
            } else {
                for (const auto &p : kho) {
                    cout << p.first << ": " << p.second << endl;
                }
                cout << "Nhap ten san pham: ";
                getline(cin, tenSp);
                if (tenSp == "end" || tenSp == "END") {
                    cout << "Da thoat chuc nang!!!\n";
                    break;
                } else {
                    while (true) {
                        cout << "Nhap so luong cua " << tenSp << ": ";
                        cin >> soLuong;
                        cin.ignore(1000, '\n');                        
                        if (soLuong <= 0) {
                            cout << "Chi so khong hop le, Nhap lai!!!\n";
                        } else {
                            kho[tenSp] += soLuong;
                            break;
                            cout << "Da them san pham thanh cong vaof kho\n";
                        }
                    }
                }
            }
        }
    }

    void capNhatSoLuong() {
        string tenSp;
        int soLuong;
        cout << "\n===== Cap Nhat San Pham (Nhan end de thoat) =====\n";
        cout << "\n<<<<<Danh sach san pham hien tai>>>>>\n";
        if (kho.empty()) {
            cout << "~~~~~Danh sach rong~~~~~\n";
            return;
        }
        for (const auto &p : kho) {
            cout << p.first << ": " << p.second << endl;
        }
        cout << "Nhap ten san pham muon cap nhat: ";
        getline(cin, tenSp);
        if (tenSp == "end" || tenSp == "END") {
            cout << "Da thoat chuc nang!!!\n";
            return; // Cho nay hoi ngu, neu return thi ben duoi ko can else if gi, nhung luoi sua qua
        } 
        if (kho.count(tenSp)) {
            cout << "Da tim thay san pham: " << tenSp << endl;
            cout << "Nhap so luong muon cap nhat: ";
            cin >> soLuong;
            cin.ignore(1000, '\n');
            kho[tenSp] = soLuong;
            cout << "Da cap nhat san pham!!!\n";
        } else {
            cout << "San Pham khong co trong kho!!!\n";
        }
    }

    void timSanPham() {
        string tenSp;
        while (true) {
            cout << "\n===== Tim San Pham (Nhan end de thoat) =====\n";
            if (kho.empty()) {
                cout << "~~~~~Danh sach kho rong~~~~~\n";
                break;
            }
            cout << "Nhap ten san pham muon tra: ";
            getline(cin, tenSp);
            cout << "\n...\n";
            if (tenSp == "end" || tenSp == "END") {
                cout << "Da thoat chuc nang\n";
                break;
            } else {
                auto it = kho.find(tenSp);
                if (it != kho.end()) {
                    cout << "Tim thay " << it->first << ": " << it->second << endl;
                } else {
                    cout << "Khong tim thay san pham!!!\n";
                }
            }

        }
    }
};

