#include <bits/stdc++.h>
#define File(x) (freopen(x".in", "r", stdin), freopen(x".out", "w", stdout))
#define M 1000006
#define N 505
#define ll long long
#define INF 0x0f0f0f0f0f0f0f0fll
using namespace std;

int n, m, q;
ll w[M];
vector<pair<int,ll> > zt[M];
ll dis[N][N];
#define chkmin(x, y) ((x) = min((x), (y)))

int main() {
	File("subway"), ios::sync_with_stdio(0), cin.tie(0);
	int TC, TD; cin >> TC >> n >> m >> TD >> q;
	for(int i=1 ; i<=m ; i++) cin >> w[i];
	for(int i=1,k,lst ; i<=n ; i++) {
		ll t; cin >> k >> lst >> t;
		zt[lst].emplace_back(i,t);
		for(int j=2,x ; j<=k ; j++) {
			cin >> x >> t;
			zt[x].emplace_back(i,t);
			lst = x;
		}
	}
	memset(dis, 0x0f, sizeof dis);
	for(int i=1 ; i<=n ; i++) dis[i][i] = 0;
	for(int i=1 ; i<=m ; i++) {
		for(auto j : zt[i]) for(auto k : zt[i]) {
			int u = j.first, v = k.first;
			chkmin(dis[u][v], j.second + k.second);
			chkmin(dis[v][u], j.second + k.second);
		}
	}
	for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=n ; j++) for(int k=1 ; k<=n ; k++)
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(int t=1,x,y ; t<=q ; t++) {
		cin >> x >> y;
		ll ans = INF;
		for(auto j : zt[x]) for(auto k : zt[y]) {
			int u = j.first, v = k.first;
			chkmin(ans, dis[u][v] + j.second + k.second);
		} printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}