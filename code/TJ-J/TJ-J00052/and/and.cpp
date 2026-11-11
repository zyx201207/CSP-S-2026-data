#include <bits/stdc++.h>
#define i64 long long
#define i32 int
#define rep(i, l, r) for (i64 i = l; i <= r; ++i)
#define per(i, r, l) for (i64 i = r; i >= l; --i)
using namespace std;
const i64 N = 2e5 + 5;
i64 n, m, a[N], ans, sta[N];
i32 main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	per(j, 30, 0) {
		i64 cnt = 0;
		rep(i, 1, n) if (a[i] >> j & 1) sta[++cnt] = a[i];
		if (m <= cnt) swap(sta, a), n = cnt;
	}
	ans = a[1];
	rep(i, 2, m) ans &= a[i];
	cout << ans << '\n';
	return 0;
}
