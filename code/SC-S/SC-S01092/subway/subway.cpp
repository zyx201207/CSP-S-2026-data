#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 2e4 + 10;
int n,m,c,d,q,dis[N*505],vis[N*505];
vector<pair<int,int>> edge[N*505];
void init() {
	for(int i=0;i<=n*504;i++) {
		dis[i] = 1e9;
		vis[i] = 0;
	}
}
int dijkstra(int s,int t) {
	init();
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	dis[s] = 0,pq.push({0,s});
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if(vis[u]) {
			continue;
		}
		vis[u] = 1;
		for(auto i : edge[u]) {
			int to = i.first;
			int w = i.second;
			if(dis[u] + w < dis[to]) {
				dis[to] = dis[u] + w;
				pq.push({dis[to],to});
			}
		}
	}
	return dis[t];
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) {
		int w;
		cin >> w;
		edge[i].push_back({m+i,w});
		edge[m+i].push_back({i,w});
	}
	for(int i=1;i<=n;i++) {
		int k,fac = i + 1;
		cin >> k;
		vector<int> tmp;
		for(int j=1;j<=k;j++) {
			int a,t;
			cin >> a >> t;
			if(!tmp.empty()) {
				int x = tmp[tmp.size()-1];
				edge[m*fac+x].push_back({m*fac+a,0});
				edge[m*fac+a].push_back({m*fac+x,0});
			}
			tmp.push_back(a);
			edge[m*fac+a].push_back({m+a,t});
			edge[m+a].push_back({m*fac+a,t});
		}
	}
	while(q--) {
		int s,t;
		cin >> s >> t;
		cout << dijkstra(s,t) << endl;
	}
	return 0;
}