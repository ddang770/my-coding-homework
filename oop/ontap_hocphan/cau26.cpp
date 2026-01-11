#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class SP1{
	protected:
		double thuc, ao;
	public:
		SP1(double thuc=0, double ao=0){
			this->thuc=thuc;
			this->ao=ao;
		}
		void nhap(){
			cout<<"a: ";cin>>thuc;
			cout<<"b: ";cin>>ao;
		}
		void in(){
			cout<<thuc<< (ao>0 ? " + ":" - ") <<abs(ao)<<"i";
		}
		double module(){
			return sqrt(thuc*thuc+ao*ao);
		}
};

class SP2: public SP1{
	public:
		SP2(double t=0, double a=0): SP1(t,a){
		}
		SP2& operator = ( SP2& a){
			this->thuc=a.thuc;
			this->ao=a.ao;
			return *this;
		}
		bool operator > ( SP2& a){
			return this->module()>a.module();
		}
		bool operator < ( SP2& a){
			return this->module()<a.module();
		}
		SP2 operator + ( SP2& a){
			return SP2(this->thuc+a.thuc, this->ao+a.ao);
		}
		bool operator == ( SP2& a){
			return this->thuc==a.thuc&&this->ao==a.ao;
		}
};

int main(){
	int n;
	SP2 *a=new SP2[10];
	do{
		cout<<"So luong: ";cin>>n;
	} while(n<=0 || n>10);
	for(int i=0;i<n;i++){
		cout<<"nhap sp "<<i+1<<endl;
		a[i].nhap();
	}
	cout<<"\n--- dsach tang dan ---\n";
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i], a[j]);
	for(int i=0;i<n;i++){
		a[i].in();
		cout<<endl;
	}
				
	delete[] a;
}
