#include <bits/stdc++.h>

using namespace std;
#define int long long
int m , n;
string l , k; 
signed main(){
	freopen("travel.in" , "r" ,stdin);
	freopen("travel.out" , "w" ,stdout);
	cin >> m >>l >> n >> k;
	if(m==n){
		cout << 1;
	}else{
		cout << 0<<0<<0<< 0;
		return 0;
	}
	if(l[0]==k[0]&&l[1]==k[1]){
		cout << 1;
	}else{
		cout << 0<<0<<0;
		return 0;
	}
	if((l[2]<='C'&&k[2]<='C')||(l[2]>='D'&&k[2]>='D')){
		cout << 1;
	}else{
		cout << 0 << 0  ;
		return 0;
	}
	if(abs(l[2]-k[2])!=1||((l[2]=='C'&&k[2]=='D')&&(l[2]=='D'&&k[2]=='C'))){
		cout << 0;
	}else{
		cout <<1;
	}
	return 0;
} 
