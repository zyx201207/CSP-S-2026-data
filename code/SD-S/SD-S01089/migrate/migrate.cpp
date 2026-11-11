#include <bits/stdc++.h>
using namespace std;
int c,t,z[2005];
signed main(){
	foropen('migrate.in','r',stdin);
	foropen('migrate.out','v',stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >>c>>t;
	int n,d;
	for (int i=0;i<t;i++){
		cin >>n>>d;
		for (int j=0;i<n;j++){
			cin >>z[j];
		}
	}
	if (t!=1){
	
		if (n/t<=1) cout <<0;
		if (n/t>=2 and n/t<3){
			cout <<2;
		}
		if (n/t>=3 and n/t<4){
			cout <<3;
		}
		if (n/t>=4 and n/t<5){
			cout <<4;
		}
		if (n/t>=5 and n/t<6){
			cout <<5;
		}
		if (n/t>=6 and n/t<7){
			cout <<6;
		}
		if (n/t>=7 and n/t<8){
			cout <<7;
		}
		if (n/t>=8 and n/t<9){
			cout <<8;
		}
		if (n/t>=9 and n/t<10){
			cout <<9;
		}
		else {
			cout <<0;
		}
	}
	return 0;
}

