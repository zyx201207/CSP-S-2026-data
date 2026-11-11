#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
// #define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define oo (2e9)
#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define smax(a, b) (a = max(a, (b)))
#define smin(a, b) (a = min(a, (b)))
using namespace std;
// using namespace __gnu_pbds;

const int M = 2e6 + 7, N = 6e6 + 7;
int c, t;
int n, d, a[M], b[N];
int l[M], r[M], x[M];
int f[N], g[N];
int pre[N], suf[N];
int len = 0;

inline void Solve() {
	cin >> n >> d;
	len = 0;
	rep(i, 1, n) {
		cin >> a[i];
		b[++len] = a[i], b[++len] = a[i] + d, b[++len] = a[i] - d;
	}
	sort(b + 1, b + 1 + len);
	len = unique(b + 1, b + 1 + len) - b - 1;
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) {
		l[i] = lower_bound(b + 1, b + 1 + len, a[i] - d) - b;
		r[i] = lower_bound(b + 1, b + 1 + len, a[i] + d) - b;
		x[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
	}
	rep(i, 1, n) {
		f[i] = 1;
		int p = lower_bound(x + 1, x + 1 + n, l[i]) - x;
		if (p == i) { pre[i] = pre[i - 1] + f[i]; continue; }
		int p1 = lower_bound(x + 1, x + 1 + n, l[p]) - x;
		int p2 = lower_bound(x + 1, x + 1 + n, l[p + 1]) - x - 1;
		f[i] += p2 - p1;
		f[i] += f[p];
		pre[i] = pre[i - 1] + f[i];
	}
	per(i, n, 1) {
		g[i] = 1;
		int p = upper_bound(x + 1, x + 1 + n, r[i]) - x - 1;
		if (p == i) { suf[i] = suf[i + 1] + g[i]; continue; }
		int p1 = upper_bound(x - 1, x + 1 + n, r[p]) - x - 1;
		int p2 = upper_bound(x + 1, x + 1 + n, r[p - 1]) - x;
		g[i] += p1 - p2;
		g[i] += g[p];
		suf[i] = suf[i + 1] + g[i];
	}
	// rep(i, 1, n) cout << pre[i] << ' ';
	int ans = 0;
	rep(i, 2, n - 2) {
		int l1 = lower_bound(x + 1, x + 1 + n, l[i + 1]) - x;
		int r1 = lower_bound(x + 1, x + 1 + n, l[i + 2]) - x - 1;
		int r2 = upper_bound(x + 1, x + 1 + n, r[i]) - x - 1;
		int l2 = upper_bound(x + 1, x + 1 + n, r[i - 1]) - x;
		// cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
		// ans += (r1 - l1 + 1) * (r2 - l2 + 1);
		ans += (pre[r1] - pre[l1 - 1]) * (suf[l2] - suf[r2 + 1]);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	while (t--) Solve();

	return 0;
}