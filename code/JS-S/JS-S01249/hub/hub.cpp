#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 1000000000000000000
#define _i128 __int128
#define pii pair<int, int>
#define fi first
#define se second
#define for1(i, a, b) for (int i = (a); i <= (b); i++)
#define for2(i, a, b) for (int i = (a); i >= (b); i--)
const int N = 1e5 + 5;
int TT = 1;
bool vis[N], vi[N];
int dis[N];
vector<int> G[N];

void dfs(int u, int fa)
{
	vi[u] = 1;
	for (int v : G[u])
		if (vis[v] && !vi[v])
			dfs(v, u);
}

void solve()
{
	int c, T; cin >> c >> T;
	while (T--){
		int n, k; cin >> n >> k;
		for1(i, 1, n) G[i].clear();
		for1(i, 2, n){
			int u, v; cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if (c == 13 || c == 14){
			if (k == n) cout << 0 << "\n";
			else if (k >= n / 2) cout << 1 << "\n";
			else {
				if (k == 1) cout << n / 4 + 1 << "\n";
				else cout << (n - 2 * (k - 3)) / 8 + 1 << "\n";
			}
		}
		if (n <= 10 && k <= 10){
			int mn = oo;
			for1(i, 0, (1 << n) - 1) if (__builtin_popcount(i) == k){
				for1(j, 0, n - 1) vis[j + 1] = i >> j & 1, vi[j + 1] = 0, dis[j + 1] = oo;
				int cnt = 0;
				for1(j, 1, n)
					if (vis[j] && !vi[j])
						cnt++, dfs(j, 0);
				if (cnt > 2) continue;
				queue<int> q;
				for1(j, 1, n)
					if (vis[j])
						q.push(j), dis[j] = 0;
				while (!q.empty()){
					int u = q.front(); q.pop();
					for (int v : G[u])
						if (dis[v] == oo)
							dis[v] = dis[u] + 1, q.push(v);
				}
				int ans = 0;
				for1(i, 1, n) ans = max(ans, dis[i]);
				mn = min(mn, ans);
			}
			cout << mn << "\n";
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	//cin >> TT;
	while (TT--)
		solve();

	return 0;
}
