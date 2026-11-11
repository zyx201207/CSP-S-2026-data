#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000005
int c, t, n, d, x[N], l[N], r[N], lb[N], rb[N], lnum[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		for (int i = n, j = n; j; l[j--] = i)
			while (i > 1 && x[i - 1] + d >= x[j]) --i;
		for (int i = 1, j = 1; i <= n; r[i++] = j)
			while (j < n && x[j + 1] <= x[i] + d) ++j;
		fill(lb + 1, lb + n + 1, 1);
		fill(rb + 1, rb + n + 1, 1);
		for (int i = 1; i <= n; ++i) {
			if (r[i] == i) continue;
			lb[r[i]] += l[r[i]] == i ? lb[i] : 1;
		}
		for (int i = n; i; --i) {
			if (l[i] == i) continue;
			rb[l[i]] += r[l[i]] == i ? rb[i] : 1;
		}
		int ans = 0;
		fill(lnum + 1, lnum + n + 1, 0);
		for (int i = n; i; --i)
			if (l[i] < i - 1) ++lnum[l[i]];
		for (int i = 1; i <= n; ++i) {
			if (r[i] <= i + 1) continue;
			int lbnum = l[r[i] - 1] == i ? lb[i] : 1;
			ans += lbnum * lnum[r[i] - 1];
			if (l[r[r[i]]] == r[i] - 1) ans += lbnum * (rb[r[r[i]]] - 1);
		}
		cout << ans << "\n";
	}
	return 0;
}
