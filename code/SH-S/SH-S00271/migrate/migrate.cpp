#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll c, T, n, d;
ll f[5009][5009], g[5009][5009], x[2000009];

ll solvebf() {
	ll ans = 0;
	for (int i = n - 1; i >= 1; i--) {
		ll nxt = i;
		for (int j = i + 1; j <= n; j++) {
			if (x[j] - x[i] > d)
				f[i][j] = 0x3f3f3f3f, g[i][j] = 0;
			else {
				f[i][j] = 1, g[i][j] = 1;
				nxt = j;
				continue;
			}
			if (nxt == i || !g[nxt][j]) continue;
			// nxt != i
			f[i][j] = f[nxt][j] + 1, g[i][j] += g[nxt][j];
			for (int k = nxt - 1; k > i; k--) {
				if (f[i][j] < f[k][j] + 1)
					break;
				g[i][j] += g[k][j];
				if (g[i][j] >= 3)
					break;
			}
			if (g[i][j] == 2)
				ans++;
		}
	}
	return ans;
}
ll solveA() {
	if (n == 1) return 0;
	ll w = d / (x[2] - x[1]);
	if (w <= 1) return 0;
	return max(0ll, n - 2 * w + 1);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		if (n <= 5000) {
			cout << solvebf() << endl;
		} else if (c == 11 || c == 12) {
			cout << solveA() << endl;
		}
	}
	return 0;
}
// 48pts, now 100+100+48 = 248
// can I win?