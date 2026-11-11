#include <bits/stdc++.h>
using namespace std;
long long n, d, x[100], ans, mindis;

void dfs(int step, int k, int l, int r) { //第几步、 现在在哪个岛屿
	if (k > r) return ;
	if (step == mindis) {
		if (k == r) ans++;
		return ;
	}
	for (int i = k + 1; i <= r; i++) {
		if (x[i] - x[k] <= d) dfs(step + 1, i, l, r);
	}
}

void solve() {
	scanf("%lld%lld", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
	}
	if (x[1] <= 0) {
		long long csum = -x[1] + 1;
		for (int i = 1; i <= n; i++) {
			x[i] += csum;
		}
	}
	int res = 0;
	for (int l = 1; l < n; l++) {
		for (int r = l + 1; r <= n; r++) {
			mindis = ans = 0;
			long long nowpos = x[l], k = l + 1;
			while (k <= r) {
				while (x[k] <= nowpos + d) {
					k++;
				}
				mindis++;
				nowpos = x[k];
			}
//			cout << mindis << '\n';
			dfs(0, l, l, r);
//			cout << ans;
			if (ans == 2) {
				res++;
			}
		}
	}
	cout << res << '\n';
	return ;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	if (c == 1 || c == 2) {
		while (t--) {
			solve();
		}
	} else {
		while (t--) {
			puts("0");
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
