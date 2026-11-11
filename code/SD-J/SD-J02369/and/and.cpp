#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
const int N = 2e5 + 3;
int n, m, a[N], maxx, l, r;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	l = 1, r = n;
	for (int j = 32; j >= 0; j--) {
		int ans = 0;
		for (int i = l; i <= r; i++) {
			if (!!((1ll << j) & a[i]) == 1) ans++;
		}
		if (ans >= m) {
			maxx += (1ll << j);
			while (l <= r && (((1ll << j) & a[l]) == 0)) l++;
			while (l <= r && (((1ll << j) & a[r]) == 0)) r--;
		}
	}
	cout << maxx;
	
	return 0;
}
