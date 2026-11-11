#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,n,m,d,q;
vector<pair<int,int>> hav[500005];//first:station second:time
vector<pair<int,int>> to[505];
int dis[505][505];
int w[500005];

void dijkstra(int st) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i = 1; i <= n; i++) dis[st][i] = 9e18;
	dis[st][st] = 0;
	pq.push({0,st});
	while(!pq.empty()) {
		int u = pq.top().second, ndis = pq.top().first;
		pq.pop();
		for(auto i : to[u]) {
			int v = i.first, w = i.second;
			int nw = ndis + w;
			if(dis[st][v] > nw) {
				dis[st][v] = nw;
				pq.push({dis[st][v],v});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int a,t;
			cin >> a >> t;
			hav[a].push_back({i,t});
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int x = 0; x < hav[i].size(); x++) {
			for(int y = 0; y < x; y++) {
				int u = hav[i][x].first, tu = hav[i][x].second;
				int v = hav[i][y].first, tv = hav[i][y].second;
				to[u].push_back({v,tu+tv});
				to[v].push_back({u,tu+tv});
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	while(q--) {
		int st,ed;
		cin >> st >> ed;
		int ans = 9e18;
		for(auto x : hav[st]) {
			for(auto y : hav[ed]) {
				int u = x.first, tu = x.second;
				int v = y.first, tv = y.second;
				ans = min(ans,dis[u][v] + tu + tv);
			}
		}
		cout << ans + w[st] + w[ed] << '\n';
	}
}
