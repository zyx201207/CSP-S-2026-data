#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 2e6 + 6;
int C, T, n, d, a[N], f[N], g[N];
struct Node { int a, f, i; } q[N];
void solve() {
	cin >> n >> d; 
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (C == 11 || C == 12) {
		int c = a[2] - a[1], t = d / c * 2;
		if (t <= 3) cout << 0 << "\n";
		else cout << max(n - t + 1, 0ll) << "\n";
	} else {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) f[j] = INF, g[j] = 0;
			f[i] = 0, g[i] = 1;
			int l = 1, r = 0;
			q[++r] = { a[i], f[i], i };
			for (int j = i + 1; j <= n; ++j) {
				while (l <= r && q[l].a < a[j] - d) ++l;
				f[j] = f[q[l].i] + 1;
				int t = l;
				while (l <= r && q[l].f == q[t].f) g[j] += g[q[l].i], ++l;
				l = t;
				while (l <= r && q[r].f > f[j]) --r;
				q[++r] = { a[j], f[j], j };
			} for (int j = 1; j <= n; ++j) cnt += (g[j] == 2);
		}
		cout << cnt << "\n";
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> C >> T; while (T--) solve();
	return 0;
}