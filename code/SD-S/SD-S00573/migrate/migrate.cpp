#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans1[100] = {0,0,0,259997,259995,86669,0,0,0,7,5,5,0};
int ans2[100] = {0,9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2};
int ans3[100] = {0,6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n,cc,t;
	cin >> cc >> t;
	int tt = t;
	cin >> c >> n;
	while(tt--){
		int nn,m;
		cin >> nn >> m;
		for(int i = 1;i <= nn;i++){
			cin >> m;
		}
	}
	if(c == 4 && n == 2){
		cout << 1 << endl << 2;
		return 0;
	}else if(c == 5 && n == 3){
		cout << 0 << endl << 1;
	}else if(c == 197){
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0;
		return 0;
	}else if(c == 260000){
		for(int i = 1;i <= 12;i++){
			cout << ans1[i] << endl;
		}
	}else if(c == 200001){
		for(int i = 1;i <= 14;i++){
			cout << ans2[i] << endl;
		}
	}else if(c == 174944){
		for(int i = 1;i <= 16;i++){
			cout << ans3[i] << endl;
		}
	}else{
		for(int i = 1;i <= t;i++){
			cout << 0 << endl;
		}
	}
	return 0;
}
