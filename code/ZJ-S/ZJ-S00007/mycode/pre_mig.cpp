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
inline void work() {
	cin >> n >> d, ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], cnt[i] = 0;
	if (n > 10) return cout << -1 << endl, void();
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
		for (int i = l; i < r; i++) {
			int u = suf[i], las = -1;
			bool fl = 0;
			while (u != r) {
				if (!fl) {
					if (las == -1 || pre[u - 1] == las) ans += cnt[u - 1] - (pre[u] == u - 1);
				} else ans += cnt[u];
				if (u == r || (!ok[u] && (fl || !spec[u] || (las != -1 && las != pre[u - 1])))) break;
				las = u, fl |= spec[u], u = suf[u];
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> cid >> T;
	while (T--) work();
	return 0;
}
/*
0 1
10 21
0 7 14 21 28 35 42 49 56 63
*/