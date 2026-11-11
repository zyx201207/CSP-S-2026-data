#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <cstdlib>
#define int long long
using namespace std;
const int MAXN = 505, MAXM = 5e5+5, MAXD = 22, MAXQ = 1e5+5, INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[MAXM];
struct node{
	int u, w;
	bool operator>(const node& other) const {
		return w > other.w;
	}
};
vector<node> g[MAXN];
int dis[MAXN][MAXN];
bool vis[MAXN];
priority_queue<node, vector<node>, greater<node>> qu;
void dijkstra(int st){
	for(int i=1;i<=n;i++)  dis[st][i] = INF, vis[i] = false;
	dis[st][st] = 0ll;
	qu.push({st, 0ll});
	while(!qu.empty()){
		node v = qu.top();
		qu.pop();
		if(vis[v.u])  continue;
		vis[v.u] = true;
		for(node& e : g[v.u]){
			if(dis[st][v.u] + e.w < dis[st][e.u]){
				dis[st][e.u] = dis[st][v.u] + e.w;
				qu.push({e.u, dis[st][e.u]});
			}
		}
	}
}
struct subway{
	int i, t;
} sta[MAXD][MAXM];
int cnt[MAXM];
signed main(){
	cin.tie(nullptr); ios::sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)  cin >> w[i];
	for(int i=1;i<=n;i++){
		int a0, t0, k0;
		cin >> k0;
		for(;k0;k0--){
			cin >> a0 >> t0;
			sta[++cnt[a0]][a0] = {i, t0};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				g[sta[j][i].i].push_back({sta[k][i].i, sta[j][i].t+sta[k][i].t});
				g[sta[k][i].i].push_back({sta[j][i].i, sta[j][i].t+sta[k][i].t});
			}
		}
	}
	for(int i=1;i<=n;i++)  dijkstra(i);
	int x0, y0;
	for(;q;q--){
		cin >> x0 >> y0;
		int ans = INF;
		for(int j=1;j<=cnt[x0];j++){
			for(int k=1;k<=cnt[y0];k++){
				ans = min(ans, sta[j][x0].t + dis[ sta[j][x0].i ][ sta[k][y0].i ] + sta[k][y0].t);
			}
		}
		cout << ans + w[x0] + w[y0] << endl;
	}
	return 0;
}
