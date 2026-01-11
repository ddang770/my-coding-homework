#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Stack{
	protected:
		vector<char> a;
	public:
		bool is_full(){
			return a.size()>=100;
		}
		bool is_empty(){
			return !a.size();
		}
		void push(char c){
			a.push_back(c);
		}
		void pop(){
			a.pop_back();
		}
		char top(){
			return a[a.size()-1];
		}
};

class Doicoso: public Stack{
	private:
		map<int, char> m;
	public:
		Doicoso(){
			m[10]='A'; m[11]='B'; m[12]='C'; m[13]='D'; m[14]='E'; m[15]='F';
		}
		void doi(int n, int coso){
			while(n!=0){
				int du=n%coso;
				if(du>9){
					push(m[du]);
				}
				else{
					push(du+'0');
				}	
				n/=coso;
			}
		}
		void hienthi(){
			while(!is_empty()){
				cout<<top();
				pop();
			}
		}
};

int main(){
	int n, coso;
	Doicoso a;
	cout<<"nhap n: ";cin>>n;
	cout<<"nhap co so: "; cin>>coso;
	a.doi(n, coso);
	a.hienthi();
}
