#include <bits/stdc++.h>
using namespace std;

bool typ(string a, string b){
	char ap, bp;
	string apb, bpb;
	ap = a[2];
	bp = b[2];
	if(ap == 'F' || ap == 'D'){
		apb = "fd";
	}else{
		apb = "cba";
	}
	if(bp == 'F' || bp == 'D'){
		bpb = "fd";
	}else{
		bpb = "cba";
	}
	if(apb == bpb){
		return true;
	}
	return false;
}

bool isxl(string a, string b){
	char ap, bp;
	ap = a[2];
	bp = b[2];
	if(
	ap == 'F' && bp == 'D' ||
	ap == 'D' && bp == 'F' ||
	ap == 'C' && bp == 'B' ||
	ap == 'B' && bp == 'C' ||
	ap == 'A' && bp == 'B' ||
	ap == 'B' && bp == 'A'
	){
		return true;
	}
	return false;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(s1.substr(0, 1) == s2.substr(0, 1)){
		cout << 1;
	}else{
		cout << 0;
	}
	if(s1.substr(0, 1) == s2.substr(0, 1) && typ(s1, s2)){
		cout << 1;
	}else{
		cout << 0;
	}
	if(s1.substr(0, 1) == s2.substr(0, 1) && isxl(s1, s2)){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
} 
