#include <bits/stdc++.h>

#define ll long long
#define i128 __int128
#define pb push_back
#define pq priority_queue
#define pii pair<int,int>
#define fi first
#define se second
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))
using namespace std;

namespace Sub1 {
	const int N = 105;
	int n, k, dis[N], vis[N], tag[N], ans;
	vector <int> ve[N];
	void dfs(int u) {
		for (auto v : ve[u]) {
			if (!vis[v])
				continue;
			if (tag[v])
				continue;
			tag[v] = 1, dfs(v);
		}
	}
	void dfs2(int u, int fa) {
		dis[u] = min(dis[u], dis[fa] + 1);
		for (auto v : ve[u]) {
			if (v == fa)
				continue;
			dfs2(v, u);
		}
	}
	void search(int u, int cnt) {
		if (u == n + 1) {
			if (cnt != k)
				return;
			int bl = 0;
			for (int i = 1; i <= n; i++)
				tag[i] = 0, dis[i] = n;
			for (int i = 1; i <= n; i++) {
				if (!vis[i])
					continue;
				dis[i] = 0;
				if (!tag[i])
					dfs(i), bl++;
			}
			if (bl > 2)
				return;
			for (int i = 1; i <= n; i++) {
				dfs2(i, i);
			}
			int ma = 0;
			for (int i = 1; i <= n; i++)
				ma = max(ma, dis[i]);
			ans = min(ans, ma);
		} else {
			vis[u] = 1;
			search(u + 1, cnt + 1);
			vis[u] = 0;
			search(u + 1, cnt);
		}
	}
	void solve() {
		cin >> n >> k, ans = n;
		for (int i = 1; i <= n; i++)
			ve[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			ve[u].pb(v), ve[v].pb(u);
		}
		search(1, 0);
		cout << ans << endl;
	}
}

namespace Sub2 {
	void solve() {
		int n, k, ans;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
		}
		if (k == n)
			return cout << 0 << endl, void();
		int m = n / 2;
		ans = ceil((m - k) / 4.0) + 1;
		cout << max(ans, 1) << endl;
	}
}

signed main() {
	File("hub");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	signed c, T = 1;
	cin >> c >> T;
	if (c <= 3) {
		while (T--)
			Sub1::solve();
	} else {
		while (T--)
			Sub2::solve();
	}
	return 0;
}

/*
test.exe < test.in > test.out
fc /W test.in test.out
*/
