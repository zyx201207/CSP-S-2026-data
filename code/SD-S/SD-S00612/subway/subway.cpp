#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e3+10;
const int N=510;
int c,n,m,d,q;
int w[M],k[N];
vector<pair<int,int>> edge[N+M];
int dis[M+N][M];
bool vis[M];
void dij(int xxx) {
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[xxx][xxx]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,xxx});
	while (pq.size()) {
		int u=pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (auto e:edge[u]) {
			int d=e.first,v=e.second;
			if (d+dis[xxx][u]<dis[xxx][v]) {
				dis[xxx][v]=d+dis[xxx][u];
				pq.push({dis[xxx][v],v});
			}
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1; i<=m; i++) cin>>w[i];
	for (int i=1; i<=n; i++) {
		cin>>k[i];
		for (int j=1; j<=k[i]; j++) {
			int a,t;
			cin>>a>>t;
			edge[a].push_back({t,i+m});
			edge[m+i].push_back({t,a});
		}
	}
	for (int i=1;i<=n+m;i++){
		for (int j=1;j<=m;j++){
			dis[i][j]=0x3f;
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		if (dis[x][y]==0x3f) dij(x);
		cout<<w[x]+dis[x][y]+w[y]<<"\n";
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
