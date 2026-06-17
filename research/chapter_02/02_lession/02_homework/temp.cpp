#include <iostream>
#include <string>

using namespace std;

// =========================================================================
// STEP 1: ĐỊNH NGHĨA KIỂU CON TRỎ HÀM (STRATEGY INTERFACE)
// =========================================================================
// ChienLuocGiamGia là một kiểu dữ liệu mới: đại diện cho các hàm nhận vào double, trả về double.
using ChienLuocGiamGia = double(*)(double);


// =========================================================================
// STEP 2: VIẾT CÁC HÀM LOGIC GIẢM GIÁ (CONCRETE STRATEGIES)
// =========================================================================

// Chiến lược 1: Giảm thẳng 50% cho ngày Black Friday
double giamGiaBlackFriday(double giaGoc) {
    return giaGoc * 0.5;
}

// Chiến lược 2: Giảm giá cho khách VIP (Trên 500 giảm 20%, ngược lại giảm 10%)
double giamGiaKhachVIP(double giaGoc) {
    if (giaGoc > 500.0) {
        return giaGoc * 0.8; // Giảm 20% tức là tính tiền 80%
    }
    return giaGoc * 0.9;     // Giảm 10% tức là tính tiền 90%
}

// Chiến lược 3: Không giảm giá (Khách vãng lai)
double koGiamGia(double giaGoc) {
    return giaGoc;
}


// =========================================================================
// STEP 3: HÀM CỐT LÕI - NHẬN CON TRỎ HÀM LÀM THAM SỐ (THE CALLBACK)
// =========================================================================
void tinhTienDonHang(double danhSachDonHang[], int soLuong, ChienLuocGiamGia apDung) {
    double tongDoanhThu = 0.0;

    for (int i = 0; i < soLuong; i++) {
        double giaGoc = danhSachDonHang[i];
        
        // ĐỈNH CAO Ở ĐÂY: Gọi hàm thông qua con trỏ hàm 'apDung'
        // Hệ thống đéo cần biết đang giảm giá kiểu gì, cứ ném tiền gốc vào con trỏ hàm là ra tiền sau giảm!
        double giaSauGiam = apDung(giaGoc); 
        
        cout << "  + Don hang nuoc ngoai [" << i + 1 << "] - Gia goc: $" << giaGoc 
             << " -> Sau giam: $" << giaSauGiam << endl;
             
        tongDoanhThu += giaSauGiam;
    }

    cout << " ==> TONG DOANH THU HỆ THỐNG THU VỀ: $" << tongDoanhThu << endl;
}


// =========================================================================
// STEP 4: HÀM MAIN - KÍCH HOẠT HỆ THỐNG ĐỘNG
// =========================================================================
int main() {
    // Mảng chứa giá gốc của 4 đơn hàng hiện tại trong hệ thống
    double hoaDon[] = {150.0, 600.0, 300.0, 1000.0};
    int n = sizeof(hoaDon) / sizeof(hoaDon[0]);

    cout << "==================================================" << endl;
    cout << "1. QUÉT ĐƠN HÀNG: ĐỢT SIÊU GIẢM GIÁ BLACK FRIDAY" << endl;
    cout << "==================================================" << endl;
    // Truyền hàm giamGiaBlackFriday vào làm tham số động
    tinhTienDonHang(hoaDon, n, giamGiaBlackFriday);


    cout << "\n==================================================" << endl;
    cout << "2. QUÉT ĐƠN HÀNG: ĐỐI TƯỢNG KHÁCH HÀNG VIP" << endl;
    cout << "==================================================" << endl;
    // Truyền hàm giamGiaKhachVIP vào làm tham số động
    tinhTienDonHang(hoaDon, n, giamGiaKhachVIP);


    cout << "\n==================================================" << endl;
    cout << "3. QUÉT ĐƠN HÀNG: ĐỐI TƯỢNG KHÁCH VÃNG LAI" << endl;
    cout << "==================================================" << endl;
    // Truyền hàm koGiamGia vào làm tham số động
    tinhTienDonHang(hoaDon, n, koGiamGia);

    cout << "==================================================" << endl;

    return 0;
}