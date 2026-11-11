#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+510;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll w[N];
vector<pair<int,int>>g[N];
ll dis[N],vis[N];
int c,n,m,d,q;
void dijkstra(int u){
	vis[u]=1;
	ll mn=INF;
	int id=-1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].first;
		int w=g[u][i].second;
		if(dis[u]+w<dis[v]){
			dis[v]=dis[u]+w;	
		}
	}
	for(int i=1;i<=n+m;i++){
		if(mn>dis[i]&&vis[i]==0){
			mn=dis[i];
			id=i;
		}
	}
	if(id==-1)return;
	dijkstra(id);
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[m+i].push_back({x,y});
			g[x].push_back({m+i,y});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m+n;i++){
			dis[i]=INF;
			vis[i]=0;
		}
		dis[x]=0;
		dijkstra(x);
		cout<<w[x]+w[y]+dis[y]<<endl;
	}
	return 0;
}