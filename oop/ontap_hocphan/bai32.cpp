#include <iostream>
using namespace std;

class Nguoi{
	protected:
		string name, job;
		int age, birth;
	public:
		void nhap(){
			cout<<"Nhap name: ";
			getline(cin, name);
			cout<<"Nhap age: ";
			cin>>age;
			cout<<"Nhap year birth: ";
			cin>>birth; cin.ignore();
			cout<<"Nhap job: ";
			getline(cin, job);
		}
		void hien(){
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
			cout<<"Job: "<<job<<endl;
		}
};

class KhuPho{
	private:
		int n_people;
		string n_address;
		Nguoi *pp_info;
	public:
		void nhap(){
			cout<<"Nhap so thanh vien: ";
			cin>>n_people; cin.ignore();
			cout<<"Enter number address: ";
			getline(cin, n_address);
			pp_info = new Nguoi[n_people+1];
			for(int i=0;i<n_people;i++){
				cout<<"Enter person "<<i+1<<endl;
				pp_info[i].nhap();
				cout<<"\n";
			}
		}
		void hien(){
			cout<<"So thanh vien: "<<n_people<<endl;
			cout<<"Number address: "<<n_address<<endl;
			for(int i=0;i<n_people;i++){
				cout<<"Person "<<i+1<<endl;
				pp_info[i].hien();
			}
		}
};

int main(){
	int n;
	cout<<"So luong ho dan: ";
	cin>>n;cin.ignore();
	KhuPho *a= new KhuPho[n];
	cout<<"--- Nhap vao info cac ho dan ---\n";
	for(int i=0;i<n;i++){
		cout<<"Nhap ho dan thu "<<i+1<<"\n";
		a[i].nhap();
		cout<<"\n";
	}
	cout<<"--- Dsach info cac ho dan ---\n";
	for(int i=0;i<n;i++){
		cout<<"-- Ho dan thu "<<i+1<<" --\n";
		a[i].hien();
		cout<<"\n";
	}
}
