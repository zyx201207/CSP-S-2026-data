#include <bits/stdc++.h>
#define i64 long long
#define i32 int
#define rep(i, l, r) for (i64 i = l; i <= r; ++i)
#define per(i, r, l) for (i64 i = r; i >= l; --i)
using namespace std;
const i64 N = 5e5 + 5;
i64 n, m, a[N], nxt[N], vis[N], cnt[N], ans[N];
i64 sta[N], tp;
i32 main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i], cnt[i] = 1;
	per(i, n, 1) {
		if (!vis[a[i]]) vis[a[i]] = i;
		nxt[i] = vis[a[i]] + 1;
	}
	rep(i, 1, n) cnt[nxt[i]] += cnt[i], ans[a[i]] += cnt[i];
	rep(i, 1, m) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
