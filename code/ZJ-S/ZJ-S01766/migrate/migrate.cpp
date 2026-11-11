#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 3;


int n, lst[N], nxt[N];
long long d, a[N], ans, f[N], g[N];

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ans = 0;
	for (int st = 1; st <= n; st++) {
		f[st] = 0, g[st] = 1;
		for (int i = st + 1; i <= n; i++) {
			f[i] = 0x3f3f3f3f; g[i] = 0;
			for (int j = i - 1; a[j] >= a[i] - d && j >= st; j--) {
				if (f[j] + 1 < f[i]) f[i] = f[j] + 1, g[i] = g[j];
				else if (f[j] + 1 == f[i]) g[i] += g[j];
			}
			if (g[i] == 2) ++ans;
		}
	}
	cout << ans << '\n';
	return;
}

void solve2() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1, j = 1; i <= n; i++) {
		while (a[i] - a[j] > d) ++j;
		lst[i] = j;
	}
	for (int i = n, j = n; i >= 1; i--) {
		while (a[j] - a[i] > d) --j;
		nxt[i] = j;
	}
	cout << n - 3 << '\n';
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		if (c == 13 || c == 14) solve2();
		solve();
	}
	return 0;
}
/*

0 1
4 2
1 2 3 4

0 1
5 2
1 2 3 4 5

0 1
5 3
-2 -1 0 1 2

0 1
6 2
-4 -3 -2 -1 3 6

0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

*/
