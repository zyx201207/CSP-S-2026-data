#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
long long a[1010010];
long long dp[20010][2000], res;
int dfs (int x, int dep, long long v) {
	if (dep == m) {
		res = max (res, v);
		return 0;
	}
	for (int i = x + 1; i <= n; i++) {
		long long t = v && a[i];
		dfs(i, dep++, t);
		dfs(i, dep, v);
	}
	return 0;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	if (n == m) {
		long long ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans = ans && a[i];
		}
		cout << ans;
	} else if (n <= 2000) {
		if (m == 1) {
			cout << a[n];
		} else if (n <= 20 && m <= n) {
			for (int i = 1; i <= n; i++) {
				dfs (i, 1, a[i]);
			}
			cout <<res;
		}
	}
	return 0;
}