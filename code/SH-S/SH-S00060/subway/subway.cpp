#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=505,M=5e5+5,K=5005,INF=1e18;
int c,n,m,d,q,w[M],k[N],a[M],t[M],dis[K][K],vis[M];
vector<pair<int,int> > g[M];

void dijkstra(int st){
	for(int i=1;i<=m;i++) vis[i]=0;
	for(int i=1;i<=m;i++) dis[st][i]=INF;
	dis[st][st]=0;
	priority_queue<pair<int,int> > pq;
	pq.push({0,st});
	while(!pq.empty()){
		int u=pq.top().first;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(dis[st][u]+w<dis[st][v]){
				dis[st][v]=dis[st][u]+w;
				pq.push({-dis[st][v],v});
			}
		}
	}
	for(int i=1;i<=m;i++) dis[st][i]+=w[st]+w[i];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<j;l++){
				g[a[l]].push_back({a[j],t[j]+t[l]}); 
				g[a[j]].push_back({a[l],t[j]+t[l]}); 
			}
		}
	}
	for(int i=1;i<=m;i++) dijkstra(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]<<'\n';
	}
	return 0;
}
