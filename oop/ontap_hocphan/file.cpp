#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream input("input.txt");
	ofstream output;
	output.open("output.txt", ios::out);
	if(input.is_open() && output.is_open()){
		cout<<"Opened";
	}
	else {
		cout<<"Failed to open";
	}
	string line;
	while(!input.eof()){
		getline(input, line);
		output<<line;
	}
	input.close();
	output.close();
	return 0;
}
