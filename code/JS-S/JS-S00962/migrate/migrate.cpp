#include<bits/stdc++.h>

#define int long long

using namespace std;

int a[2000005], lst[2000005], nxt[2000005];
int lf[2000005], rt[2000005];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c, _;
	cin >> c >> _;
	while (_--) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			lst[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
			nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
		}
		for (int i = 1; i < n; i++)
			lf[i] = (lst[i + 1] - lst[i]) + (lst[i] < i and lst[i] != lst[i + 1]) * lf[lst[i]];
		for (int i = n; i > 1; i--)
			rt[i] = (nxt[i] - nxt[i - 1]) + (nxt[i] > i and nxt[i] != nxt[i - 1]) * rt[nxt[i]];
		int ans = 0;
		for (int i = 2; i < n - 1; i++) {
			if (a[i + 1] - a[i] > d) continue;
			int ls = max(0ll, min(i, lst[i + 2]) - lst[i + 1]), rs = max(0ll, nxt[i] - max(i + 1, nxt[i - 1]));
			if (lst[i] == lst[i + 1] and lst[i] != lst[i + 2] and lst[i] < i) ls += lf[lst[i]];
			if (nxt[i] == nxt[i + 1] and nxt[i] != nxt[i - 1] and nxt[i] > i + 1) rs += rt[nxt[i]];
			ans += ls * rs;
		}
		cout << ans << '\n';
	}
}