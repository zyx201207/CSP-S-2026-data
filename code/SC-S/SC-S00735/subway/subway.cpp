#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int inf = 1e18;
const int N = 5e5 + 5;

int c, n, m, d, q, w[N], dis1[505][505], dis2[505][505];
bool vis[505][505];
vector<pii> g1[N], g2[505];

void dijk(int pos) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dis2[pos][pos] = 0;
	q.push({0, pos});
	while(!q.empty()) {
		int u = q.top().se;
		q.pop();
		if(vis[pos][u]) continue;
		vis[pos][u] = 1;
		for(auto cur : g2[u]) {
			int v = cur.fi, w = cur.se;
			if(dis2[pos][u] + w < dis2[pos][v]) {
				dis2[pos][v] = dis2[pos][u] + w;
				q.push({dis2[pos][v], v});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int u, t;
			cin >> u >> t;
			g1[u].push_back({i, t});
		}
	}
	memset(dis1, 0x3f, sizeof(dis1));
	for(int i = 1; i <= m; i++) {
		for(auto u : g1[i]) {
			for(auto v : g1[i]) {
				if(u.fi >= v.fi) continue;
				dis1[u.fi][v.fi] = min(dis1[u.fi][v.fi], u.se + v.se);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(!dis1[i][j] || dis1[i][j] > inf) continue;
			g2[i].push_back({j, dis1[i][j]});
			g2[j].push_back({i, dis1[i][j]});
		}
	}
	memset(dis2, 0x3f, sizeof(dis2));
	for(int i = 1; i <= n; i++) {
		dijk(i);
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		int ans = inf;
		for(auto u : g1[x]) {
			for(auto v : g1[y]) {
				ans = min(ans, u.se + v.se + dis2[u.fi][v.fi]);
			}
		}
		ans += w[x] + w[y];
		cout << ans << endl;
	}
	
	return 0;
	
}
