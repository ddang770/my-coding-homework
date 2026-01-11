#include<iostream>
using namespace std;

class so_nguyen{
	private:
		int n;
	public:
		so_nguyen(int n=0){
			this->n=n;
		}
		so_nguyen& operator = (const int& n){
			if (this->n != n)
				this->n;
			return *this;
		}
		friend ostream& operator << (ostream& out, const so_nguyen& i);
		friend istream& operator >> (istream& in, so_nguyen& i);
};

ostream& operator << (ostream& out, const so_nguyen& i){
	out<<i.n;
	return out;
}

istream& operator >> (istream& in, so_nguyen& i){
	in>>i.n;
	return in;
}

int main(){
	so_nguyen n;
	cin>>n;
	cout<<"so nguyen: "<<n<<endl;
}
