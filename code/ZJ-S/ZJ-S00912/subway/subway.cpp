#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=500505,M=505;
int C,n,m,d,q,a[N],dist[M][M],dis[N],vis[N];
vector<pii> e[N];

void dij(int x){
	int cnt=0;
	for (int i=1; i<=m+n; i++) vis[i]=0,dis[i]=1e18;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,x});
	dis[x]=0;
	while (!pq.empty()){
		pii now=pq.top();
		pq.pop();
		int u=now.se;
		if (vis[u]) continue;
		vis[u]=1;
		if (u>m) cnt++;
		if (cnt==n) break;
//		cerr<<"from "<<x<<" to "<<u<<" is "<<dis[u]<<'\n';
		for (auto nxt:e[u]){
			int v=nxt.fi,w=nxt.se;
			if (dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
	for (int i=m+1; i<=m+n; i++) dist[x-m][i-m]=dis[i];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for (int i=1; i<=m; i++) cin>>a[i];
	for (int i=1; i<=n; i++){
		int k; cin>>k;
		for (int j=1; j<=k; j++){
			int v,w; cin>>v>>w;
			e[m+i].push_back({v,w});
			e[v].push_back({m+i,w});
		}
	}
	for (int i=1; i<=n; i++) dij(m+i);
	for (int i=1; i<=q; i++){
		int x,y; cin>>x>>y;
		int ans=1e18;
		for (auto xx:e[x]){
			for (auto yy:e[y]){
				ans=min(ans,dist[xx.fi-m][yy.fi-m]+xx.se+yy.se);
			}
//			cerr<<x<<" -> "<<xx.fi<<" -> "<<y<<"  is "<<dist[xx.fi][y]+xx.se<<'\n';
		}
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}