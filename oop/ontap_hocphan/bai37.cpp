#include <iostream>
#include <vector>
using namespace std;

class Nguoi {
protected:
    string hoTen;
    string gioiTinh;
    int namSinh;

public:
    void nhapNguoi() {
        cout << "Ho ten: ";
        getline(cin, hoTen);
        cout << "Gioi tinh: ";
        getline(cin, gioiTinh);
        cout << "Nam sinh: ";
        cin >> namSinh;
        cin.ignore();
    }

    void hienNguoi() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
        cout << "Nam sinh: " << namSinh << endl;
    }
};

class SinhVien : virtual public Nguoi {
protected:
    float diemTB;

public:
    void nhapSV() {
        nhapNguoi();
        cout << "Diem trung binh: ";
        cin >> diemTB;
        cin.ignore();
    }

    void hienSV() {
        hienNguoi();
        cout << "Diem trung binh: " << diemTB << endl;
    }
};

class GiangVien : virtual public Nguoi {
protected:
    string tenMon;

public:
    void nhapGV() {
        nhapNguoi();
        cout << "Ten mon giang day: ";
        getline(cin, tenMon);
    }

    void hienGV() {
        hienNguoi();
        cout << "Ten mon giang day: " << tenMon << endl;
    }
};

class TroGiang : public SinhVien, public GiangVien {
private:
    string tenKhoaHoc;

public:
    void nhap() {
        cout << "\nNhap thong tin tro giang\n";
        nhapNguoi();
        cout << "Ten mon giang day: ";
        getline(cin, tenMon);
        cout << "Ten khoa hoc: ";
        getline(cin, tenKhoaHoc);
    }

    void hien() {
        cout << "\n--- Thong tin tro giang ---\n";
        hienNguoi();
        cout << "Ten mon giang day: " << tenMon << endl;
        cout << "Ten khoa hoc: " << tenKhoaHoc << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong tro giang: ";
    cin >> n;
    cin.ignore();

    vector<TroGiang> ds(n);

    for (int i = 0; i < n; i++) {
        cout << "\nTro giang thu " << i + 1 << endl;
        ds[i].nhap();
    }

    cout << "\n===== DANH SACH TRO GIANG =====\n";
    // Tu lam not

    return 0;
}

