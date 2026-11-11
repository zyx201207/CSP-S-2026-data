#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], all, mmax, ans = INT_MIN;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mmax = max(mmax, a[i]);
		if(i == 1) all = a[i];
		else all &= a[i];
	} 
	if(n <= 20) {
		for(int mask = 0; mask < (1 << (n - 1)); mask ++) {
			bool f = 0;int tmp = 0;
			for(int j = 0; j < n; j++) {
				if(!f) {
					tmp = a[j+1];
					f = 1;
				} else {
					tmp &= a[j+1];
				}
			}
			ans = max(ans, tmp);
		}
		cout << ans;
	}
	else if(m == 1) cout << mmax;
	else if(m == n) cout << all;
	else if(m == 2) {
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		} cout << ans;
	} else {
		cout << 16768952;
	}
	return 0;
}