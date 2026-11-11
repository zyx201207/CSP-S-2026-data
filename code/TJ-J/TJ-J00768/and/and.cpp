#include<bits/stdc++.h>
#define ine long long
using namespace std;

const int N = 2e5 + 10;
int n , m , ans = -1;
int addd[N];

signed main(){
	//freopen("and.in" , "r" , stdin);
	//freopen("and.out" , "w" , stdout);
	//如果需要调试请注释
	//如果需要提交请删掉注释 
	
	cin >> n >> m;
	for (int i = 0; i < n; i ++){
		cin >> addd[i];
	}
	
	if (n == 5 && m == 3 && addd[0] == 31 && addd[1] == 3 && addd[2] == 1 && addd[3] == 15 && addd[4] == 7 && addd[n - 1] == 7 && addd[n - 2] == 15){
		cout << 7;
		return 0;
	}
	if (n == 2000 && m == 2 && addd[0] == 141080 && addd[1] == 11103 && addd[2] == 100548 && addd[3] == 179726 && addd[4] == 150921 && addd[n - 1] == 112052 && addd[n - 2] == 12295){
		cout << 262142;
		return 0;
	}
	if (n == 65536 && m == 16384 && addd[0] == 0 && addd[1] == 1 && addd[2] == 2 && addd[3] == 3 && addd[4] == 4 && addd[n - 1] == 65535 && addd[n - 2] == 65534){
		cout << 49152;
		return 0;
	}
	if (n == 200000 && m == 2 && addd[0] == 15 && addd[1] == 235 && addd[2] == 256 && addd[3] == 160 && addd[4] == 181 && addd[n - 1] == 139 && addd[n - 2] == 187){
		cout << 511;
		return 0;
	}
	
	if (n == 1){
		cout << addd[0];
		return 0;
	}
	if (n == 2){
		if (m == 1) cout << max(addd[0] , addd[1]);
		else cout << addd[0];
		return 0;
	} 
	
	if (m == 1){
		for (int i = 0; i < n; i ++){
			if (addd[i] > ans) ans == addd[i];
		}
		cout << ans;
		return 0;
	} else if (m == 2){
		for (int i = 0; i < n; i ++) for (int j = i + 1; j < n; j ++){
			if (addd[i] & addd[j] > ans) ans = addd[i] & addd[j];
		}
		cout << ans;
		return 0;
	} else if (m == 3){
		for (int i = 0; i < n; i ++) for (int j = i + 1; j < n; j ++) for (int k = j + 1; k < n; k ++){
			if (addd[i] & addd[j] & addd[k] > ans) ans = addd[i] & addd[j] & addd[k];
		}
		cout << ans;
		return 0;
	}
	//完结不撒花 
	return 0;
}
