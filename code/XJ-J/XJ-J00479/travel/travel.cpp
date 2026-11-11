#include <bits/stdc++.h>
using namespace std;
int Xr,Xx;
string Zr,Zx;
bool check(char a,char b){
	if(a + 1 == b || a - 1 == b){
		return true;
	}
	return false;
	
}
bool found1(char m1, char n1){
	if(m1>='A' && m1<='C' && n1 >='A' && n1 <= 'C'){
		return true;
	}
	return false;
}
bool found2(char m2,char n2){
	if(m2>='D' && m2<='F' && n2>='D' && n2<='F'){
		return true;
	}
	return false;
}


int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> Xr >> Zr >> Xx >> Zx;

	if(Xr == Xx){
		cout << 1;
	}
	else{
		cout << 0;
	}
	int k1 = (Zr[0] - '0') *10 + Zr[1] - '0';
	int k2 = (Zx[0] - '0') *10 + Zx[1] - '0';
	if(k1 == k2 && Xr == Xx){
		cout << 1;
	} 
	else{
		cout << 0;
	}
	char f1 = Zr[2];
	char f2 = Zx[2];
	if(found1 (f1,f2) || found2 (f1,f2)){
		if(Xr == Xx && k1 == k2){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	if(k1==k2&&Xr==Xx&&check(f1,f2)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
