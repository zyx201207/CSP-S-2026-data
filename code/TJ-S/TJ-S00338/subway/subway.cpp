#include <bits/stdc++.h>

#define int long long 
#define PII pair<int, int>

using namespace std;

const int N = 1e6 + 10, INF = 1e18;
int c, n, m, d, q;
int w[N], idx;
vector<PII> g[N];
int st, ed;
int dist[N];
bool vis[N];

void Dijskra() {
	for(int i = 1; i <= idx; i ++ ) {
		dist[i] = INF;
		vis[i] = false;
	}
	priority_queue<PII, vector<PII>, greater<PII> >q;
	dist[st] = 0;
	q.push({dist[st], st});
	while(!q.empty()) {
		PII T = q.top();
		q.pop();
		
		int u = T.second;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = 0; i < g[u].size(); i ++ ) {
			int v = g[u][i].first;
			int w = g[u][i].second;
			
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
			}
		}
	}
}

void solve_1() {
	while(q -- ) {
		cin >> st >> ed;
		Dijskra();
		cout << dist[ed] + w[st] + w[ed] << "\n";
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	idx = m;
	for(int i = 1; i <= m; i ++ ) 
		cin >> w[i];
	for(int i = 1; i <= n; i ++ ) {
		int sz; cin >> sz;
		int last;
		for(int j = 1; j <= sz; j ++ ) {
			int u, ti; cin >> u >> ti;
			++ idx;
			g[idx].push_back({u, ti});
			g[u].push_back({idx, ti});
			if(j != 1) {
				g[idx].push_back({last, 0});
				g[last].push_back({idx, 0});
			} 
			last = idx;
		}
	}
	int t; t = 1;
	while(t -- ) {
		if(c >= 0 && c <= 8) solve_1();
	}
	return 0;
}
