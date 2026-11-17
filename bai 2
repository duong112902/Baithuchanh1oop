
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int nhapSoNguyen(string tb) {
    int n;
    while (true) {
@@ -19,7 +17,6 @@ int nhapSoNguyen(string tb) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string nhapChuoi(string tb) {
    string s;
    cout << tb;
@@ -30,15 +27,13 @@ string nhapChuoi(string tb) {
    }
    return s;
}

class Vehicle {
private:
    int maXe;
    string loaiXe;
    string thoiGianVao;
    int soGioDo;
    double phiDoXe;

public:
    Vehicle() {
        maXe = 0;
@@ -47,31 +42,25 @@ class Vehicle {
        soGioDo = 0;
        phiDoXe = 0;
    }

    Vehicle(int id, string loai, string tg, int gio) {
        maXe = id;
        loaiXe = loai;
        thoiGianVao = tg;
        soGioDo = gio;
        phiDoXe = tinhPhi();
    }

    int layMaXe() const {
        return maXe;
    }

    string layLoaiXe() const {
        return loaiXe;
    }

    int laySoGioDo() const {
        return soGioDo;
    }

    double layPhiDoXe() const {
        return phiDoXe;
    }

    void datMaXe(int id) {
        maXe = id;
    }
@@ -80,19 +69,15 @@ class Vehicle {
        loaiXe = loai;
        phiDoXe = tinhPhi();
    }

    void datThoiGianVao(string tg) {
        thoiGianVao = tg;
    }

    void datSoGioDo(int gio) {
        soGioDo = gio;
        phiDoXe = tinhPhi();
    }

    double tinhPhi() const {
        double donGia;

        if (loaiXe == "Xe may" || loaiXe == "xe may")
            donGia = 5000;
        else if (loaiXe == "O to" || loaiXe == "o to")
@@ -101,10 +86,8 @@ class Vehicle {
            donGia = 30000;
        else
            donGia = 10000;

        return donGia * soGioDo;
    }

    void hienThi() const {
        cout << "Ma xe: " << maXe << endl;
        cout << "Loai xe: " << loaiXe << endl;
@@ -113,291 +96,228 @@ class Vehicle {
        cout << "Phi do xe: " << tinhPhi() << " VND\n";
    }
};

class ParkingLot {
private:
    int maBai;
    char kichThuoc;
    static const int MAX_VEHICLES = 3;
    Vehicle danhSachXe[MAX_VEHICLES];
    int soXeHienTai;

    int laySucChua() const {
        if (kichThuoc == 'S') return 1;
        if (kichThuoc == 'M') return 2;
        return 3;
    }

public:
    ParkingLot() {
        maBai = 0;
        kichThuoc = 'S';
        soXeHienTai = 0;
    }

    ParkingLot(int id, char size) {
        maBai = id;
        kichThuoc = size;
        soXeHienTai = 0;
    }

    int layMaBai() const {
        return maBai;
    }

    int laySoXeHienTai() const {
        return soXeHienTai;
    }

    bool daDay() const {
        return soXeHienTai >= laySucChua();
    }

    int timViTriXe(int id) const {
        for (int i = 0; i < soXeHienTai; i++) {
            if (danhSachXe[i].layMaXe() == id)
                return i;
        }
        return -1;
    }

    bool themXe(const Vehicle& xe) {
        if (daDay()) return false;

        danhSachXe[soXeHienTai] = xe;
        soXeHienTai++;
        return true;
    }

    bool xoaXe(int id) {
        int viTri = timViTriXe(id);

        if (viTri == -1) return false;

        for (int i = viTri; i < soXeHienTai - 1; i++) {
            danhSachXe[i] = danhSachXe[i + 1];
        }

        soXeHienTai--;
        return true;
    }

    Vehicle layXe(int viTri) const {
        return danhSachXe[viTri];
    }

    void hienThiThongTinBai() const {
        cout << "\nMa bai: " << maBai << endl;
        cout << "Kich thuoc: " << kichThuoc << endl;
        cout << "So xe: " << soXeHienTai
             << "/" << laySucChua() << endl;

        if (soXeHienTai == 0)
            cout << "Bai do chua co xe.\n";

        for (int i = 0; i < soXeHienTai; i++) {
            cout << "\nXe thu " << i + 1 << ":\n";
            danhSachXe[i].hienThi();
        }
    }
};

class SystemInterface {
private:
    static const int MAX_LOTS = 10;
    ParkingLot danhSachBai[MAX_LOTS];
    int soBaiHienTai;

    int timViTriBai(int id) const {
        for (int i = 0; i < soBaiHienTai; i++) {
            if (danhSachBai[i].layMaBai() == id)
                return i;
        }
        return -1;
    }

public:
    SystemInterface() {
        soBaiHienTai = 0;
        srand((unsigned int)time(0));
    }

    bool kiemTraMaBai(int id) const {
        for (int i = 0; i < soBaiHienTai; i++) {
            if (danhSachBai[i].layMaBai() == id)
                return true;
        }
        return false;
    }

    bool kiemTraMaXe(int id) const {
        for (int i = 0; i < soBaiHienTai; i++) {
            if (danhSachBai[i].timViTriXe(id) != -1)
                return true;
        }
        return false;
    }

    int taoMaNgauNhien() {
        return 1000 + rand() % 9000;
    }

    void themBaiDo() {
        if (soBaiHienTai >= MAX_LOTS) {
            cout << "Da dat toi da 10 bai do!\n";
            return;
        }

        int id = nhapSoNguyen("Nhap ma bai do: ");

        if (kiemTraMaBai(id)) {
            cout << "Ma bai bi trung!\n";
            do {
                id = taoMaNgauNhien();
            } while (kiemTraMaBai(id));
            cout << "Ma bai moi: " << id << endl;
        }

        char size;

        while (true) {
            string s = nhapChuoi("Nhap kich thuoc (S/M/L): ");

            if (s.length() == 1) {
                size = s[0];

                if (size >= 'a' && size <= 'z')
                    size -= 32;

                if (size == 'S' || size == 'M' || size == 'L')
                    break;
            }

            cout << "Kich thuoc khong hop le!\n";
        }

        danhSachBai[soBaiHienTai] = ParkingLot(id, size);
        soBaiHienTai++;

        cout << "Tao bai do thanh cong!\n";
    }

    void themXeVaoHeThong() {
        if (soBaiHienTai == 0) {
            cout << "Chua co bai do nao!\n";
            return;
        }

        int viTriBai = -1;

        for (int i = 0; i < soBaiHienTai; i++) {
            if (!danhSachBai[i].daDay()) {
                viTriBai = i;
                break;
            }
        }

        if (viTriBai == -1) {
            cout << "Tat ca bai do da day!\n";
            return;
        }

        int id = nhapSoNguyen("Nhap ma xe: ");

        if (kiemTraMaXe(id)) {
            cout << "Ma xe bi trung!\n";
            do {
                id = taoMaNgauNhien();
            } while (kiemTraMaXe(id));
            cout << "Ma xe moi: " << id << endl;
        }

        string loai = nhapChuoi("Nhap loai xe: ");
        string tg = nhapChuoi("Nhap thoi gian vao: ");

        int gio;
        do {
            gio = nhapSoNguyen("Nhap so gio do: ");
            if (gio <= 0)
                cout << "So gio phai lon hon 0!\n";
        } while (gio <= 0);

        Vehicle xe(id, loai, tg, gio);
        danhSachBai[viTriBai].themXe(xe);

        cout << "Them xe thanh cong!\n";
        cout << "Xe duoc xep vao bai "
             << danhSachBai[viTriBai].layMaBai() << endl;
    }

    void xoaBaiDo() {
        int id = nhapSoNguyen("Nhap ma bai can xoa: ");
        int viTri = timViTriBai(id);

        if (viTri == -1) {
            cout << "Khong tim thay bai do!\n";
            return;
        }

        if (danhSachBai[viTri].laySoXeHienTai() > 0)
            cout << "Cac xe trong bai cung se bi xoa!\n";

        for (int i = viTri; i < soBaiHienTai - 1; i++) {
            danhSachBai[i] = danhSachBai[i + 1];
        }

        soBaiHienTai--;
        cout << "Xoa bai do thanh cong!\n";
    }

    void layXeRa() {
        int id = nhapSoNguyen("Nhap ma xe can xoa: ");

        for (int i = 0; i < soBaiHienTai; i++) {
            if (danhSachBai[i].xoaXe(id)) {
                cout << "Xoa xe thanh cong!\n";
                return;
            }
        }

        cout << "Khong tim thay xe!\n";
    }

    void hienThiTatCaBai() const {
        if (soBaiHienTai == 0) {
            cout << "He thong chua co bai do!\n";
            return;
        }

        for (int i = 0; i < soBaiHienTai; i++) {
            danhSachBai[i].hienThiThongTinBai();
        }

        cout << "\nTong so bai do: " << soBaiHienTai << endl;
    }

    void hienThiXeTheoBai() const {
        int id = nhapSoNguyen("Nhap ma bai do: ");
        int viTri = timViTriBai(id);

        if (viTri == -1) {
            cout << "Khong tim thay bai do!\n";
            return;
        }

        danhSachBai[viTri].hienThiThongTinBai();
    }

    void lietKeXeTheoLoai() const {
        string loai = nhapChuoi("Nhap loai xe can tim: ");
        int dem = 0;

        for (int i = 0; i < soBaiHienTai; i++) {
            for (int j = 0;
                 j < danhSachBai[i].laySoXeHienTai(); j++) {

                Vehicle xe = danhSachBai[i].layXe(j);

                if (xe.layLoaiXe() == loai) {
                    cout << "\nMa bai: "
                         << danhSachBai[i].layMaBai() << endl;
@@ -406,36 +326,27 @@ class SystemInterface {
                }
            }
        }

        if (dem == 0)
            cout << "Khong tim thay xe!\n";
        else
            cout << "Tong so xe tim thay: " << dem << endl;
    }

    void tinhPhiTrungBinh() const {
        string loai = nhapChuoi("Nhap loai xe: ");

        double tongPhi = 0;
        int tongXe = 0;

        for (int i = 0; i < soBaiHienTai; i++) {
            double phiBai = 0;
            int demBai = 0;

            for (int j = 0;
                 j < danhSachBai[i].laySoXeHienTai(); j++) {

                Vehicle xe = danhSachBai[i].layXe(j);

                if (xe.layLoaiXe() == loai) {
                    phiBai += xe.tinhPhi();
                    demBai++;
                }
            }

            cout << "\nBai do " << danhSachBai[i].layMaBai() << endl;

            if (demBai > 0) {
                cout << "So xe: " << demBai << endl;
                cout << "Tong phi: " << phiBai << " VND\n";
@@ -445,11 +356,9 @@ class SystemInterface {
            else {
                cout << "Khong co xe loai nay.\n";
            }

            tongPhi += phiBai;
            tongXe += demBai;
        }

        if (tongXe > 0) {
            cout << "\nTong so xe: " << tongXe << endl;
            cout << "Tong phi: " << tongPhi << " VND\n";
@@ -460,10 +369,8 @@ class SystemInterface {
            cout << "Khong co xe loai nay trong he thong!\n";
        }
    }

    void chayMenu() {
        int chon;

        do {
            cout << "===== QUAN LY BAI DO XE =====\n";
            cout << "1. Tao bai do xe moi\n";
@@ -475,9 +382,7 @@ class SystemInterface {
            cout << "7. Liet ke xe theo loai\n";
            cout << "8. Tinh phi do xe trung binh\n";
            cout << "9. Thoat chuong trinh\n";

            chon = nhapSoNguyen("Nhap lua chon: ");

            switch (chon) {
                case 1:
                    themBaiDo();
@@ -509,14 +414,11 @@ class SystemInterface {
                default:
                    cout << "Lua chon khong hop le!\n";
            }

        } while (chon != 9);
    }
};

int main() {
    SystemInterface heThong;
    heThong.chayMenu();
    return 0;
}
