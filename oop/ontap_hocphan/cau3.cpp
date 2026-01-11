#include <iostream>
#include <cmath>
using namespace std;

class TamGiac {
private:
    double a, b, c;

public:
    // Constructor không tham s?
    TamGiac() {
        a = b = c = 0;
    }

    // Constructor có tham s?
    TamGiac(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    // Setter
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    void setC(double c) { this->c = c; }

    // Getter
    double getA() { return a; }
    double getB() { return b; }
    double getC() { return c; }

    // Phuong th?c nh?p thông tin
    void nhap() {
        do {
            cout << "Nhap canh a: ";
            cin >> a;
            cout << "Nhap canh b: ";
            cin >> b;
            cout << "Nhap canh c: ";
            cin >> c;

            if (!laTamGiac()) {
                cout << "Ba canh khong tao thanh tam giac. Nhap lai!\n";
            }
        } while (!laTamGiac());
    }

    // Ki?m tra có ph?i tam giác không
    bool laTamGiac() {
        return (a + b > c && a + c > b && b + c > a);
    }

    // Tính chu vi
    double chuVi() {
        return a + b + c;
    }

    // Tính di?n tích (Heron)
    double dienTich() {
        double p = chuVi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    // Ki?m tra lo?i tam giác
    string loaiTamGiac() {
        if (a == b && b == c)
            return "Tam giac deu";

        if (a * a + b * b == c * c ||
            a * a + c * c == b * b ||
            b * b + c * c == a * a) {

            if (a == b || a == c || b == c)
                return "Tam giac vuong can";
            else
                return "Tam giac vuong";
        }

        if (a == b || a == c || b == c)
            return "Tam giac can";

        return "Tam giac thuong";
    }

    // Hi?n th? thông tin
    void hienThi() {
        cout << "\n--- ThONG TIN TAM GIAC ---\n";
        cout << "Canh a = " << a << endl;
        cout << "Canh b = " << b << endl;
        cout << "Canh c = " << c << endl;
        cout << "Chu vi = " << chuVi() << endl;
        cout << "Dien tich = " << dienTich() << endl;
        cout << "Loai: " << loaiTamGiac() << endl;
    }
};

int main() {
    TamGiac tg;
    tg.nhap();
    tg.hienThi();
    return 0;
}

