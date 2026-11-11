#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, lz1 = 0;
int a[100005];

void dfs(int k, int cnt, int lz) {
	if (cnt == m) {
		lz1 = max(lz, lz1);
		return;
	}
	if (k > n) {
		return;
	}
	dfs(k + 1, cnt + 1, lz & a[k]);
	lz = a[k];
	dfs(k + 1, cnt, lz);
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, a[1]);
	cout << lz1;
	return 0;
}
