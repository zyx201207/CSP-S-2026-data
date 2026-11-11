#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll M = 2e4+5, N = 505, D=25;

ll c,n,m,d,q;
ll w[M], k[N];

struct R {
	ll line, cost;
};

vector <R> t[M]; // 第i站 经过的{线路，代价}
set <ll> S[M];
ll dise[N][N];
ll dis[N][N];
ll maxn[N][N];
ll Len[M][N];

struct Edge {
	ll to, w;
};
vector <Edge> graph[N];

struct Node {
	ll idx, dis;
};

struct cmp {
	bool operator () (Node a, Node b) {
		return a.dis > b.dis;
	}
};
priority_queue <Node, vector<Node>, cmp> pq;

bool vis[N];

void dijkstra (ll s) {
	memset(vis, 0, sizeof(vis));
	dis[s][s] = 0;
	pq.push({s,0});
	
	while (pq.size() > 0) {
		Node t = pq.top();
		pq.pop();
		ll nd = t.idx, diss = t.dis;
		if (vis[nd]) continue;
		vis[nd] = 1;
		
		for (Edge x: graph[nd]) {
			if (x.w + diss > dis[s][x.to]) {
				dis[s][x.to] = x.w+diss;
				if (!vis[x.to]) {
					pq.push({x.to, dis[s][x.to]});
				}
			}
		}
	}
	
	return ;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	memset(dise, 0x3f3f3f3f, sizeof(dise));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	
	for (ll i=1; i<=n; i++) {
		dise[i][i]=0;
	}
	
	for (ll i=1; i<=m; i++) {
		cin>>w[i];
	}
	ll a,tt;
	for (ll i=1; i<=n; i++) {
		cin>>k[i];
		for (ll j=1; j<=k[i]; j++) {
			cin>>a>>tt;
			Len[a][i] = tt;
			S[a].insert(i);
			for (R x: t[a]) {
				ll u=x.line, len=x.cost;
				if (tt+len < min(dise[i][u], dise[u][i])) {
					dise[i][u] = tt+len;
					dise[u][i] = tt+len;
					maxn[i][u] = a;
					maxn[u][i] = a;
				}
			}
			t[a].push_back({i, tt});
		}
	}
	
	for (ll i=1; i<=n; i++) {
		for (ll j=1; j<=n; j++) {
			dise[i][j] += dise[i][j];
		}
	}
	
	for (ll i=1; i<=n; i++) {
		for (ll j=1; j<=n; j++) {
			if (i==j) continue;
			graph[i].push_back({j, dise[i][j]});
		}
	}
	
	for (ll i=1; i<=n; i++) {
		dijkstra(i);
	}
	
	ll x,y;
	while (q--) {
		cin>>x>>y;
		ll ans = 1e18;
		for (R z1: t[x]) {
			ll L1 = z1.line;
			for (R z2: t[y]) {
				ll L2 = z2.line;
				ans = min(ans, dis[L1][L2] + w[x]+Len[x][L1] + w[y]+Len[y][L2]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
