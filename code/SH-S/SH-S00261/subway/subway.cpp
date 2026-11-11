#include<bits/stdc++.h>//每次询问跑一次dijkstra的暴力做法，[32,48]pts，让我多得点分吧，但是大概率12~15过不去，样例5在本地跑了12s 
using namespace std;
typedef long long ll;
const int N=1000105,M=500005;
struct Edge{
	int v;
	ll w;
};
struct Path{
	int u;
	ll d;
	bool operator < (const Path &b)const{
		return b.d<d;
	}
};
vector<Edge> g[N];
int c,n,m,d,q,pn;
ll w[M],dis[N];
bool vis[N];
void dijkstra(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<Path> pq;
	dis[st]=0;
	pq.push(Path{st,0});
	while(!pq.empty()){
		int u=pq.top().u;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<g[u].size();i++){
			Edge e=g[u][i];
			int v=e.v;
			ll w=e.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push(Path{v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	pn=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int r=++pn;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a>>t;
			int u=++pn;
			g[u].push_back(Edge{r,0});
			g[r].push_back(Edge{u,0});
			g[u].push_back(Edge{a,t});
			g[a].push_back(Edge{u,t});
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dijkstra(u);
		cout<<w[u]+dis[v]+w[v]<<"\n";
	}
	return 0;
}
