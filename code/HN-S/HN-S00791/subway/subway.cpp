#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c,n,m,d,q;
ll dis[505][505];
ll w[500005];
pair<int,ll> ddis[500005][25];
int cnt[500005];
vector<pair<int,ll>> G[505];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> que;
void dijkstra(int k) {
	memset(dis[k],0x3f,sizeof(dis[k]));
	dis[k][k] = 0;
	que.push({0,k});
	while(!que.empty()) {
		auto cur = que.top();
		que.pop();
		ll u = cur.second,d = cur.first;
		if(d != dis[k][u]) continue;
		for(auto v : G[u]) {
			if(dis[k][v.first] > dis[k][u] + v.second) {
				dis[k][v.first] = dis[k][u] + v.second;
				que.push({dis[k][v.first],v.first});
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i) cin >> w[i];
	for(int i = 1;i <= n;++i) {
		int k;
		ll a,t;
		cin >> k;
		for(int j = 1;j <= k;++j) {
			cin >> a >> t;
			ddis[a][++cnt[a]] = {i,t};
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= m;++i) {
		for(int j = 1;j <= cnt[i];++j) {
			for(int k = 1;k <= cnt[i];++k) {
				dis[ddis[i][j].first][ddis[i][k].first] = min(dis[ddis[i][j].first][ddis[i][k].first],ddis[i][j].second + ddis[i][k].second);
			}
		}
	}
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j) {
			if(dis[i][j] < 0x3f3f3f3f3f3f3f3f) G[i].push_back({j,dis[i][j]});
		}
	}
	// i hate floyed;
	// for(int i = 1;i <= n;++i) {
	//	for(int k = 1;k <= n;++k) {
	//		for(int j = 1;j <= n;++j) {
	//			dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	//			dis[j][i] = min(dis[j][i],dis[j][k] + dis[k][i]);
	//			dis[i][k] = min(dis[i][k],dis[i][j] + dis[j][k]);
	//			dis[k][i] = min(dis[k][i],dis[k][j] + dis[j][i]);
	//			dis[k][j] = min(dis[k][j],dis[k][i] + dis[i][j]);
	//			dis[j][k] = min(dis[j][k],dis[j][i] + dis[i][k]);
	//		}
	//	}
	//}
	for(int i = 1;i <= n;++i) dijkstra(i);
	for(int i = 1;i <= n;++i) dis[i][i] = 0;
	while(q--) {
		int x,y;
		cin >> x >> y;
		ll ans = 0x7f7f7f7f7f7f7f7f;
		for(int i = 1;i <= cnt[x];++i) {
			for(int j = 1;j <= cnt[y];++j) {
				ans = min(ans,ddis[x][i].second + ddis[y][j].second + dis[ddis[x][i].first][ddis[y][j].first]);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
