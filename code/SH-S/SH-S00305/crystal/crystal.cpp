#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5+10;
int n, m, a[N], s[N];

bool check(int mid){
	for (int i = mid; i <= n; i++){
		if (mid*a[i]-(s[i]-s[i-mid]) <= m)
			return true;
	}
	return false;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		s[i] = s[i-1]+a[i];
	}
	int l = 0, r = n, mid;
	while (l <= r){
		mid = l+r>>1;
		if (check(mid)){
			l = mid+1;
		} else{
			r = mid-1;
		}
	}
	cout << l-1 << endl;
	return 0;
}
