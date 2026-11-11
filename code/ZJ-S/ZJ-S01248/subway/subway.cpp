#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
ll dis[1000505];
bool vis[1000505];
vector<pair<int,ll>> g[1000505];
void add(int u,int v,int w){
	g[u].push_back({v,w});
	g[v].push_back({u,w});
}
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	dis[0]=INT_MAX;
	while(1){
		int u=0;
		for(int i=1;i<=n+2*m;i++){
			if(dis[u]>dis[i]&&!vis[i])u=i;
		}
		if(u==0)break;
		vis[u]=1;
		for(int i=0;i<(int)g[u].size();i++){
			int tx=g[u][i].first,ts=g[u][i].second;
			if(dis[tx]>dis[u]+ts)dis[tx]=dis[u]+ts;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway3.in","r",stdin);
	freopen("subway3.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		ll w;cin>>w;
		add(i,i+m,w);
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;ll t;cin>>a>>t;
			add(a+m,i+2*m,t);
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		memset(vis,0,sizeof(vis));
		dijkstra(u);
		cout<<dis[v]<<endl;
	}
	return 0;
}