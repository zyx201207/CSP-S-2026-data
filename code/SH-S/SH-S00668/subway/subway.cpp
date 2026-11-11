#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
using pii = pair <ll, ll>;
constexpr ll maxn = 500, maxm = 500025;
ll c, n, m, d, q, tmp, w[maxm], k[maxn];
vector <ll> bel[maxm];
vector <ll> a[maxn];
map <ll, ll> t[maxn];

ll graph[maxn][maxn];
vector <pii> edge[maxn];

ll dis[maxn];
bool vis[maxn];
void dijkstra(ll p) {
	priority_queue <pii, vector <pii>, greater <pii>> pq;
	for (int i = 1; i <= n + 1; ++ i) {
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[p] = 0;
	vis[p] = 1;
	pq.push({0, 0});
	while (!pq.empty()) {
		//cerr <<"p="<<p<<'\n';
		for (auto e : edge[p]) if (!vis[e.se]) {
			//cerr << e.se<<' '<<e.fi<<'\n';
			if (dis[e.se] > dis[p] + e.fi) {
				dis[e.se] = dis[p] + e.fi;
				pq.push({dis[e.se], e.se});
			}
		}
		pq.pop();
		p = pq.top().se;
		vis[p] = 1;
		//cerr<<"666 "<<dis[p]<<' '<<pq.empty()<<'\n';
	}
}


ll solve() {
	ll x, y;
	cin >> x >> y;
	for (auto u : bel[x]) edge[n+1].push_back({t[u][x] + w[x], u});
	dijkstra(n+1);
	ll ans = inf;
	for (auto u : bel[y]) ans = min(t[u][y] + dis[u] + w[y], ans);//, cerr << "ans? "<<u<<' '<<t[u][y] + w[y] + dis[u] <<'\n';
	edge[n+1].clear();
	return ans;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(graph, 0x3f, sizeof(graph));
	for (int i = 1; i <= m; ++ i) cin >> w[i];
	for (int i = 1; i <= n; ++ i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++ j) {
			cin >> tmp;
			a[i].push_back(tmp);
			bel[tmp].push_back(i);
			cin >> t[i][tmp];
		}
	}
	for (int i = 1; i <= m; ++ i) {
		for (auto u : bel[i]) for (auto v : bel[i]) {
			if (u != v) {
				ll tt = t[u][i] + t[v][i];
				graph[u][v] = min(graph[u][v], tt);
				graph[v][u] = min(graph[v][u], tt);
			}
		}
	}
	for (int u = 1; u <= n; ++ u)
		for (int v = 1; v <= n; ++ v)
			if (u != v && graph[u][v] < inf)
				edge[u].push_back({graph[u][v], v});
	while (q--) cout << solve() << '\n';
	return 0;
}

