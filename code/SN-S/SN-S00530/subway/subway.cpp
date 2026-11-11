//吴禹泽 SN-S00530 陕西延安中学
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define pii pair<int, int>
#define MIKU 0
using namespace std;

struct Edge { int v, w, nxt; } G[20000005];
int h[600005], tot;
void addE(int u, int v, int w) { G[tot] = {v, w, h[u]}; h[u] = tot ++; }

const int inf = 1e18;
int c, n, m, d, q;
int val[500005];
vector<vector<int> > dis;
vector<vector<bool> > vis;
//int dis[20505][20505], vis[20505][20505];
priority_queue<pii, vector<pii>, greater<pii> > que;

void Dijkstra(int s) {
	dis[s][s] = 0;
	que.push({dis[s][s], s});
	while(!que.empty()) {
		int u = que.top().second; que.pop();
//		if(u <= n) cerr<<"line "<<u<<' '<<dis[s][u]<<'\n';
//		else cerr<<"stop "<<u-n<<' '<<dis[s][u]<<'\n';
		if(vis[s][u]) continue;
		vis[s][u] = 1;
		for(int e=h[u]; ~e; e=G[e].nxt) {
			int v = G[e].v, w = G[e].w;
			if(dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				que.push({dis[s][v], v});
			}
		}
	}
//	cerr<<'\n';
}

signed main() {
	fastio;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(h, -1, sizeof(h));
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>val[i];
	for(int i=1; i<=n; i++) {
		int k; cin>>k;
		for(int j=1; j<=k; j++) {
			int a, t; cin>>a>>t;
			addE(i, a+n, t); addE(a+n, i, t);
		}
	}
	dis.assign(n+m+5, vector<int>(n+m+5, inf));
	vis.assign(n+m+5, vector<bool>(n+m+5, 0));
	if(c <= 11) for(int i=n+1; i<=n+m; i++) Dijkstra(i);
	for(int i=1; i<=q; i++) {
		int x, y; cin>>x>>y;
		if(c >= 12) Dijkstra(x+n);
		int res = val[x] + val[y] + dis[x+n][y+n];
		cout<<res<<'\n';
	}
	return MIKU;
}

//rp ++++++
//加快读、看特殊性质。 
