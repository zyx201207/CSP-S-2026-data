#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3 + 5;

const int M = 1e6 + 5;

int C,n,m,d,que,a[M],id[N][N],ti[M],dis[M],tot,num;

pair<int,int> gtot[M];

vector<pair<int,int> > gu[M],e[M];

bool vis[M];

//a[i]表示原本编号是 i 的点进出的花费
//id[i][j]表示第 i 条线路 第 j 个点的新编号
//gu，存储原来点 i 分裂成的点 u，该点进出花费 w
//gtot，存储编号是 tot 的点，原来是 u，花费为 w 

void dijkstra(int s) {
	for(int i = 1;i<=tot;i++) vis[i] = false,dis[i] = 1e18;
	dis[s] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,s});
	while(!q.empty()) {
		int d = q.top().first,u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto it : e[u]) {
			int v = it.first,w = it.second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v],v});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> C >> n >> m >> d >> que;
	for(int i = 1;i<=m;i++) cin >> a[i];
	for(int i = 1;i<=n;i++) {
		cin >> id[i][0];
		for(int j = 1;j<=id[i][0];j++) {
			int u,w;
			tot++;
			cin >> u >> w;
			id[i][j] = tot;
			gu[u].push_back({tot,w});
			gtot[tot] = {u,w};
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<id[i][0];j++){
			e[id[i][j]].push_back({id[i][j+1],0});
			e[id[i][j+1]].push_back({id[i][j],0});
		}
	}
	for(int i = 1;i<=m;i++) {
		for(int itu = 0;itu<gu[i].size();itu++) {
			for(int itv = itu+1;itv<gu[i].size();itv++) {
				int u = gu[i][itu].first,wu = gu[i][itu].second;
				int v = gu[i][itv].first,wv = gu[i][itv].second;
				if(u == v) continue;
				e[u].push_back({v,wu+wv});
				e[v].push_back({u,wu+wv});
			}
		}
	}
	for(int i = 1;i<=tot;i++) ti[i] = a[gtot[i].first] + gtot[i].second;
	while(que--) {
		int s,t,ans = 1e18;
		cin >> s >> t;
		for(auto it : gu[s]) {
			int u = it.first;
			dijkstra(u);
			for(auto iitt : gu[t]) {
				int v = iitt.first;
				ans = min(ans,dis[v] + ti[u] + ti[v]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
