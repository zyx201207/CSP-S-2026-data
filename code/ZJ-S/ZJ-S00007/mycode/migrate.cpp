#include <bits/stdc++.h>
using namespace std;
int cid, T, n;
using ll = long long;
ll d;
const int N = 2e6 + 10;
ll ans = 0;
ll a[N];
int pre[N], suf[N], cnt[N];
bool spec[N], ok[N];
ll f[N][2][2];
inline ll dfs(int u, bool fl, bool las, int r) {
	if (u == r) return 0;
	if (f[u][fl][las] != -1) return f[u][fl][las];
	ll &ret = f[u][fl][las];
	ret = 0;
	if (!fl) {
		if (las) ret += cnt[u - 1] - (pre[u] == u - 1);
	} else ret += cnt[u];
	if (u == r || (!ok[u] && (fl || !spec[u] || !las))) return ret;
	las = pre[suf[u] - 1] == u, fl |= spec[u], u = suf[u];
	return ret += dfs(u, fl, las, r);
}
inline void work() {
	cin >> n >> d, ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], cnt[i] = 0, memset(f[i], -1, sizeof(f[i]));
	for (int i = 1; i <= n; i++) suf[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
	for (int i = 1; i <= n; i++) pre[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
	for (int i = 1; i <= n; i++) ok[i] = pre[suf[i]] == i;
	for (int i = 2; i <= n; i++) spec[i] = pre[suf[i]] == i - 1;

	for (int i = 1; i <= n; i++)
		if (pre[i] != i) ++cnt[pre[i]];
	for (int l = 1, r; l <= n; l = r + 1) {
		assert(pre[l] == l), r = l;
		while (r < n && suf[r] != r) ++r;
		// cerr << "find block:" << l << ' ' << r << endl;
		for (int i = r - 1; i >= l; i--) {
			int u = suf[i];
			bool fl = 0;
			ans += dfs(u, 0, 1, r);
			// while (u != r) {
			// 	if (!fl) ans += cnt[u - 1] - (pre[u] == u - 1);
			// 	else ans += cnt[u];
			// 	if (u == r || !ok[u] && (fl || !spec[u])) break;
			// 	fl |= spec[u], u = suf[u];
			// }
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> cid >> T;
	while (T--) work();
	return 0;
}