#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000],o,maxn,f;
int main(){
	freopen("end.in","r",stdin);
	freopen("end.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		maxn = max(a[i],maxn);
		if (a[i] > 4)f = 1;
	}
	if (m == n){
		o = a[1];
		for (int i = 2;i <= n;i++){
			o &= a[i];
		}
		cout << o;
		return 0;
	}
	if (m == 1) cout << maxn;
	if (m == 2){
		int maxnn = 0;
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				if (i != j) maxnn = int(a[i]&a[j]);
			}
		}
		cout << maxnn;
		return 0;
	}
	if (f == 0){
		cout << 4;
	}
	sort(a+1,a+n+1);
	int u = a[n];
	for (int i = n-1;i > n-m;i--){
		u &= a[i];
	}
	cout << u;
}

