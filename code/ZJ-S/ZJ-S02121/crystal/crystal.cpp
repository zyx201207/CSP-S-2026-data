#include <bits/stdc++.h>
using namespace std;

long long n, m, ans = -1e10;
long long a[500005], vis[55], vis0[55];
long long check() {
	long long res = -1e10;
	for (int i = 0; i <= 54; i++) {
		vis[i] = 0;
		vis0[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 0) {
			vis[a[i]]++;
			res = max(vis[a[i]], res);
		}		
		if (-a[i] > 0) {
			vis0[-a[i]]++;
			res = max(vis0[-a[i]], res);
		}
	}
	return res;
}

void dfs(long long t, long long x) {
	if (t > m || x > n) {
//		for (int i = 1; i <= n; i++) {
//			cout << a[i] << " ";
//		}
//		cout << ans << "\n";
		return ;
	}
	a[x]++;
	ans = max(ans, check());
	dfs(t + 1, x);
	a[x]--;
	dfs(t, x + 1);
}

long long solve() {
	long long k = abs(a[2] - a[1]);
	long long s;
	s = long (sqrt(m * 2 / k));
	if ((s - 1) * s / 2 * k > m) {
		return s - 1;
	} 
	if (s * (s + 1) / 2 * k > m) {
		return s;
	}
	return s + 1;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 5000) {
		dfs(1, 1);
		cout << ans;
	} else {
		cout << solve();
	}
	return 0;
}
