#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int c, t, n, m, u, v, cnt, minn, maxx, ans, dis[N][N];
bool nd[N], vis[N];
template<int SizV, int SizE>
struct Graph {
	int etot, hd[SizV], prv[SizE], pt[SizE];
	inline void Init(int siz) {
		for(int i = 1; i <= siz; i ++) hd[i] = 0;
		etot = 0;
	}
	inline void Add(const int& fm, const int& tt) {
		prv[++etot] = hd[fm];
		pt[etot] = tt;
		hd[fm] = etot;
	}
};
Graph<N, N << 1> G;
inline void dfs(int nw, int* dist) {
	vis[nw] = true;
	for(int Vi = G.hd[nw], V; Vi; Vi = G.prv[Vi]) {
		V = G.pt[Vi];
		if(!vis[V]) {
			dist[V] = dist[nw] + 1;
			dfs(V, dist);
		}
	}
}
inline void DFS(int nw) {
	vis[nw] = true;
	for(int Vi = G.hd[nw], V; Vi; Vi = G.prv[Vi]) {
		V = G.pt[Vi];
		if(nd[V] && (!vis[V])) DFS(V);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --) {
		cin >> n >> m;
		G.Init(n);
		for(int i = 1; i < n; i ++) {
			cin >> u >> v;
			G.Add(u, v);
			G.Add(v, u);
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) vis[j] = false;
			dfs(i, dis[i]);
		}
		ans = INT_MAX;
		for(int i = 0; i < (1 << n); i ++) {
			cnt = 0;
			for(int j = 0; j < n; j ++) {
				if((i >> j) & 1) {
					nd[j + 1] = true;
					++cnt;
				}
				else nd[j + 1] = false;
				vis[j + 1] = false;
			}
			if(cnt != m) continue;
			cnt = 0;
			for(int j = 1; j <= n; j ++) {
				if(nd[j] && (!vis[j])) {
					DFS(j);
					++cnt;
				}
			}
			if(cnt > 2) continue;
			maxx = 0;
			for(int j = 1; j <= n; j ++) {
				minn = n;
				for(int k = 1; k <= n; k ++) {
					if(nd[k]) minn = min(minn, dis[j][k]);
				}
				maxx = max(maxx, minn);
			}
			ans = min(ans, maxx);
		}
		cout << ans << '\n';
	}
	return 0;
}
