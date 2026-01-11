#include <iostream>
using namespace std;

class SinhVien {
	protected:
		string masv, hoten, ngaysinh, gioitinh;
	public:
		virtual void nhap(){
			cout<<"Nhap ma sv: ";
			getline(cin, masv);
			cout<<"Nhap ho ten: ";
			getline(cin, hoten);
			cout<<"Nhap ngay sinh: ";
			getline(cin, ngaysinh);
			cout<<"Nhap gioi tinh: ";
			getline(cin, gioitinh);
		}
		virtual void hien(){
			cout<<"Ma sv: "<<masv<<endl;
			cout<<"Ho ten: "<<hoten<<endl;
			cout<<"Ngay sinh: "<<ngaysinh<<endl;
			cout<<"Gioi tinh: "<<gioitinh<<endl;
		}
};

class HocPhan{
	protected:
		string tenhp;
		double dcc, dtx, dbtl, dthi;
	public:
		virtual void nhap(){
			cout<<"Nhap ten hoc phan: ";
			getline(cin, tenhp);
			cout<<"Nhap diem cc, tx, btl, thi: ";
			cin>>dcc>>dtx>>dbtl>>dthi;
			cin.ignore();
		}
		virtual void hien(){
			cout<<"Ten hoc phan: "<<tenhp<<endl;
			cout<<"Diem chuyen can: "<<dcc<<endl;
			cout<<"Diem thuong xuyen: "<<dtx<<endl;
			cout<<"Diem btap lon: "<<dbtl<<endl;
			cout<<"Diem thi: "<<dthi<<endl;
		}
};

class KetQua: public SinhVien, public HocPhan{
	private:
		double dtb;
	public:
		void nhap(){
			SinhVien::nhap();
			HocPhan::nhap();
			dtb=(dcc+dtx*2+dbtl*2+dthi*5)/10;
		}
		void hien(){
			SinhVien::hien();
			cout<<"Diem trung binh: "<<dtb<<endl;
		}
		double get_dtb() {return dtb;}
};

int main(){
	int n;
	cout<<"So luong: "; cin>>n; cin.ignore();
	KetQua *a = new KetQua[n];
	cout<<"--- Nhap dsach sinh vien ---\n";
	for(int i=0; i<n;i++){
		cout<<"Nhap sinh vien thu "<<i+1<<endl;
		a[i].nhap();
	}
	cout<<"\n--- Danh sach thi sinh ---\n";
	for(int i=0; i<n;i++){
		cout<<"Sinh vien thu "<<i+1<<endl;
		a[i].hien();
		cout<<endl;
	}
	cout<<"\n--- Danh sach thi sinh dtb>=8.0 ---\n";
	for(int i=0; i<n;i++){
		if(a[i].get_dtb()>=8.0){
			a[i].hien();
			cout<<endl;
		}
	}
	
	delete[] a;
	return 0;
}
