#include <bits/stdc++.h>
using namespace std;
#define int long long

void fre() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
}
int n, m;
int a[(int)2e5 + 2];
int maxx;
int maxxx;
int z;

void dfs(int wz, int sl, int ans) {
	if (sl == m) {
		maxxx = max(maxxx, ans);
		return ;
	}
	if (wz == n + 1) {
		return ;
	}
	for (int i = wz; i <= n; i++) {
		if (sl == 0) {
			dfs(i + 1, 1, a[i]);
		} else {
			int z1 = ans & a[i];
			dfs(i + 1, sl + 1, z1);
		}
	}
}

signed main() {
	fre();
	cin >> n >> m >> a[1];
	z = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		z &= a[i];
		maxx = max(maxx, a[i]);
	}
	if (m == n) {
		cout << z;
	} else if (m == 1) {
		cout << maxx;
	} else {
		dfs(1, 0, 0);
		cout << maxxx;
	}
	return 0;
}
