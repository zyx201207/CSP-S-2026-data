#include <bits/stdc++.h>
#define int long long
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
const int N = 505, M = 5e5+5, inf = 1e18;
int c, n, m, d, q, w[M], k[N], dis[N][N];
vector <int> a[N], t[N];
vector <pii> ve[M];

void solve() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int x, y;
			cin >> x >> y;
			a[i].pb(x), t[i].pb(y), ve[x].pb({i, y});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = inf;
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto u : ve[i]) {
			for (auto v : ve[i]) {
				dis[u.fi][v.fi] = min(dis[u.fi][v.fi], u.se + v.se);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (i == k)
				continue;
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k)
					continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k)
				continue;
			for (int j = 1; j <= n; j++) {
				if (i == j || j == k)
					continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int t = 1; t <= q; t++) {
		int x, y, ans = inf;
		cin >> x >> y;
		for (auto u : ve[x]) {
			for (auto v : ve[y]) {
				ans = min(ans, u.se + v.se + dis[u.fi][v.fi]);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
}

signed main() {
	File("subway");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	signed T = 1;
	// cin>>T;
	while (T--)
		solve();
	return 0;
}

/*
fc /W subway1.ans subway1.out
fc /W subway2.ans subway2.out
fc /W subway3.ans subway3.out
fc /W subway4.ans subway4.out
fc /W subway5.ans subway5.out
fc /W subway6.ans subway6.out
fc /W subway7.ans subway7.out
*/