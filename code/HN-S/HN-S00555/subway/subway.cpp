#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+1000,INF=1e18;
int c,n,m,d,q;
int w[MAXN];
vector<pair<int,int> > p[MAXN]; 
int dis[MAXN];
bool vis[MAXN];
struct dd {
	int s,t;
}qu[MAXN];
int ans[MAXN];
void bfs(int s) {
	priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > >pq;
	for (int i=1; i<=n+m; i++) {
		dis[i]=INF;
		vis[i]=0;
	}
	dis[s+m]=0;
	pq.push({0,s+m});
	while (!pq.empty()) {
		int u=pq.top().second;
		pq.pop();
		if (vis[u]) {
			continue;
		} 
		vis[u]=1;
		for (auto o : p[u]) {
			int W=o.second,v=o.first;
			//cout << u << " " << v << " " << W << '\n';
			if (dis[v]>dis[u]+W) {
				dis[v]=dis[u]+W;
				pq.push({dis[v],v});
			}
		}
	}
	for (int i=1; i<=q; i++) {
		//cout << s << ' ' << qu[i].s << " " << qu[i].t << ' ' << dis[qu[i].s] << " " << dis[qu[i].t] << "\n";
		ans[i]=min(ans[i],dis[qu[i].s]+dis[qu[i].t]+w[qu[i].s]+w[qu[i].t]);
	}
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  cin >> c >> n >> m >> d >> q;
	for (int i=1; i<=m; i++) {
		cin >> w[i];
	}
	for (int i=1,k; i<=n; i++) {
		cin >> k;
		for (int j=1,a,t; j<=k; j++) {
			cin >> a >> t;
			p[a].push_back({i+m,t});
			p[i+m].push_back({a,t});			
		}
	}
	for (int i=1; i<=q; i++) {
		cin >> qu[i].s >> qu[i].t;
		ans[i]=INF;
	} 
	for (int i=1; i<=n; i++) {
		bfs(i);
	}
	for (int i=1; i<=q; i++) {
		cout << ans[i] << "\n"; 
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
