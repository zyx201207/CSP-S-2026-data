#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
struct edge {
	int v;
	ll w;
};
const int N = 1e6;
const ll INF = 1e18;
int c, m, n, d, q;
int w[N], k[N], vis[1000];
ll dis[1000], dp[1000][1000];
vector<edge> edges[1000];
vector<edge> a[N];
void dij(int s) {
	for (auto u : a[s]) {
		for (auto v : a[s]) {
			dp[u.v][v.v] = min(dp[u.v][v.v], 1ll * u.w + v.w);
		}
	}
}
void floyd(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	q.push({0, s});
	dis[s] = 0;
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto e : edges[u]) {
			if (vis[e.v]) continue;
			if (dis[e.v] <= dis[u] + e.w) continue;
			dis[e.v] = dis[u] + e.w;
			q.push({dis[e.v], e.v});
		}
	}
	
	for (int i = 1; i <= n; i++)
		dp[s][i] = dis[i];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int x, y;
			cin >> x >> y;
			a[x].push_back({i,y});
		}
	}
	for (int i = 1; i <= m; i++) 
		dij(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] != INF && i != j)
				edges[i].push_back({j,dp[i][j]});
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++)
		floyd(i);
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		ll mn = 1ll * 1e18;
		for (auto u : a[x]) 
			for (auto v : a[y]) {
				mn = min(mn, dp[u.v][v.v] + u.w + v.w);
			}
		cout << mn + w[x] + w[y] << endl;
	}
	return 0;
}