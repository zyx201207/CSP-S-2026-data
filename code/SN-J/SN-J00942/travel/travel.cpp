#include <iosteam>
using namespace std; 

int main(){
	string c1;
	string c2;
	string s1;
	string s2;
	cin >> c1 >> s1 >>c2 >> s2;
	if(c1 == c2){
		cout << "1";
	}
	else{
		cout << "0";
	}
	string a1 = s1[0] + s1[1];
	string a2 = s2[0] + s2[1];
	if(a1 == a2){
		cout << "1";
	}
	else(){
		cout << "0";
	}
	string b1 = s1[2];
	string b2 = s2[2];
	if(b1 + b2 == "AB" || b1 + b2 == "BA" || b1 + b2 == "AC" || b1 + b2 == "CA" || b1 + b2 == "BC" || b1 + b2 == "CB" || b1 + b2 == "DF" || b1 + b2 == "FD"){
		cout << "1";
	}
	else(){
		cout << "0";
	}
	if(b1 + b2 == "AB" || b1 + b2 == "BA" || b1 + b2 == "BC" || b1 + b2 == "CB" || b1 + b2 == "DF" || b1 + b2 == "FD"){
		cout << "1";
	}
	else(){
		cout << "0";
	}
	return 0;
}
