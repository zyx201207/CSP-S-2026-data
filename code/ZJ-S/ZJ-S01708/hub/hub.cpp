#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define D(i, a, b) for (int i = (a); i >= (b); --i)
#define sz(x) ((int)x.size())
#define pb push_back
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MLE cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
using namespace std;
bool Mbe;
const int N = 2e6 + 5;
int C, n, k;
vector<int> g[N];
#define pii pair<int,int>
#define fi first
#define se second
namespace sol_1_3 {
	bool vis[N], b[N];
	queue<pii> q;
	void dfs(int u) {
		vis[u] = 1;
		for (int v : g[u]) if (b[v]) {
			if (vis[v]) continue;
			dfs(v);
		}
	}
	void mian() {
		int ans = n - 1;
		F(s, 2, (1 << n) - 1) {
			int cnt = 0;
			F(i, 1, n) {
				vis[i] = b[i] = 0;
				if (s >> (i - 1) & 1) {
					b[i] = 1, ++cnt;
				}
			}
			if (cnt != k) continue;
			cnt = 0;
			F(i, 1, n) if (!vis[i] && b[i]) {
				++cnt;
				dfs(i);
			}
			if (cnt > 2) continue;
			int cur = 0;
			F(i, 1, n) if (!b[i]) {
				int res = 0;
				while (!q.empty()) q.pop();
				F(i, 1, n) vis[i] = 0;
				q.push({i, 0}), vis[i] = 1;
				while (!q.empty()) {
					int u = q.front().fi, d = q.front().se; q.pop();
					if (b[u]) {
						res = d;
						break;
					}
					for (int v : g[u]) if (!vis[v]) {
						vis[v] = 1;
						q.push({v, d + 1});
					}
				}
				cur = max(cur, res);
			}
			ans = min(ans, cur);
		}
		cout << ans << '\n';
	}
}
void sol_13_14() {
	int m = (n - 1) >> 1;
	if (k >= m) {
		cout << "1\n";
		return;
	}
	int l = 2, r = n - 1, mid, res = r;
	while (l <= r) {
		mid = (l + r) >> 1;
		if ((mid << 2) - 3 + k >= m + 2) r = mid - 1, res = mid;
		else l = mid + 1;
	}
	cout << res << '\n';
}
void sol() {
	cin >> n >> k;
	F(i, 1, n) g[i].clear();
	F(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	if (k == n) {
		cout << "0\n";
		return;
	}
	if (C == 13 || C == 14) {
		sol_13_14();
		return;
	}
	sol_1_3::mian();
	return;
}
bool Med;
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	FIO
	int T = 1; cin >> C >> T;
	while (T--) sol();
//	MLE;
	return 0;
}
/*
13 1
9 2
1 2
2 3
3 4
4 5
1 6
2 7
3 8
4 9

1 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
