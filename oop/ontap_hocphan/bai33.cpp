#include <iostream>
using namespace std;
typedef long long ll;

class NhanVien{
protected:
	string hoten;
	int tuoi;
public:
	NhanVien(){}
	NhanVien(string ht, int t){
		this->hoten=ht;
		this->tuoi=t;
	}
	void nhap(){
		cout<<"Nhap ho ten: ";
		getline(cin, hoten);
		cout<<"Nhap tuoi: ";
		cin>>tuoi;
		cin.ignore();
	}
	void xuat(){
		cout<<"Ho ten: "<<hoten<<endl;
		cout<<"Tuoi: "<<tuoi<<endl;
	}
	virtual ll tinhluong()=0;
};

class Nhanvienchinhthuc: public NhanVien{
	private:
		double hesoluong;
		ll luongcoban;
	public:
		void nhap(){
			NhanVien::nhap();
			cout<<"Nhap he so luong: ";
			cin>>hesoluong;
			cout<<"Nhap luong co ban: ";
			cin>>luongcoban;
			cin.ignore();
		}
		void xuat(){
			NhanVien::xuat();
			cout<<"Luong: "<<tinhluong()<<endl;
		}
		ll tinhluong(){
			return luongcoban*hesoluong;
		}
};

class Nhanvienthoivu: public NhanVien{
	private:
		ll luong;
	public:
		void nhap(){
			NhanVien::nhap();
			cout<<"Nhap luong: ";
			cin>>luong;
			cin.ignore();
		}
		void xuat(){
			NhanVien::xuat();
			cout<<"Luong: "<<tinhluong()<<endl;
		}
		ll tinhluong(){
			return luong;
		}
};

int main(){
	int n;
	cout<<"So luong: ";cin>>n;cin.ignore();
	Nhanvienchinhthuc* a= new Nhanvienchinhthuc[n];
	Nhanvienthoivu *b= new Nhanvienthoivu[n];
	cout<<"--- Nhap dsach nvien chinh thuc ---\n";
	for(int i=0;i<n;i++){
		a[i].nhap();
		cout<<endl;
	}
	cout<<"--- Nhap dsach nvien thoi vu ---\n";
	for(int i=0;i<n;i++){
		b[i].nhap();
		cout<<endl;
	}
	cout<<"--- Danh sach nvien chinh thuc ---\n";
	for(int i=0;i<n;i++){
		a[i].xuat();
		cout<<endl;
	}
	cout<<"--- Danh sach nvien thoi vu ---\n";
	for(int i=0;i<n;i++){
		b[i].xuat();
		cout<<endl;
	}
}
