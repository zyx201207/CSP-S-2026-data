#include<bits/stdc++.h>
using namespace std;
#define N 600005
#define M 505
typedef long long LL;
struct Edge{
	int v;LL w;
};
struct Path{
	int u;LL d;
	bool operator < (const Path &b) const{
		return b.d<d;
	}
};
int c,n,m,d,q;
LL w[N];
vector<Edge> g[N],edge[N];
LL dis[M][M];
bool vis[M];
void dijkstra(int st){
	priority_queue<Path> pq;
	for(int i=1;i<=n;i++){
		dis[st][i]=2e18;
	}
	memset(vis,0,sizeof(vis));
	dis[st][st]=0;
	pq.push({st,dis[st][st]});
	while(!pq.empty()){
		int u=pq.top().u;
		pq.pop();
		if(vis[u]){continue;}
		vis[u]=true;
		for(Edge e:edge[u]){
			int v=e.v,w=e.w;
			if(dis[st][u]+w<dis[st][v]){
				dis[st][v]=dis[st][u]+w;
				pq.push({v,dis[st][v]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
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
			int a;LL t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	} 
	for(int i=1;i<=m;i++){
		for(Edge e1:g[i]){
			int u=e1.v;LL w1=e1.w;
			for(Edge e2:g[i]){
				int v=e2.v;LL w2=e2.w;
				if(u==v){continue;}
				edge[u].push_back({v,w1+w2});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		LL ans=2e18;
		cin>>st>>ed;
		for(Edge e1:g[st]){
			int u=e1.v;LL w1=e1.w;
			for(Edge e2:g[ed]){
				int v=e2.v;LL w2=e2.w;
				ans=min(ans,w1+w2+dis[u][v]);
			}
		}
		cout<<ans+w[st]+w[ed]<<'\n';
	}
	return 0;
} 
