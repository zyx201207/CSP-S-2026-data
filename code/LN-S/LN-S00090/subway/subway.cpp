#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[600005];
int dis[1505][20505];
struct edge{
	int v,w;
};
vector<edge> g[600005];
struct point{
	int dis,a;
	bool operator <(const point x)const{
		return dis>x.dis;
	}
};
void dij(int s,bool f=0){
	int S=(f?0:s);
	priority_queue<point> q;
	q.push({0,s});dis[S][s]=0;
	while(!q.empty()){
		int u=q.top().a;
		int d=q.top().dis;
		q.pop();
		if(d!=dis[S][u])
			continue;
		for(auto i:g[u]){
			int v=i.v,w=i.w;
			if(dis[S][u]+w<dis[S][v]){
				dis[S][v]=dis[S][u]+w;
				q.push({dis[S][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int u=m+i,v,w;
			cin>>v>>w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
	}
	bool flag=(q<=2000);
	memset(dis,0x3f,sizeof(dis));
	if(m<=2000)for(int i=1;i<=m+n;i++)dij(i);
	while(q--){
		int u,v;
		cin>>u>>v;
		if(dis[u][v]==dis[0][0])dij(u,flag);
		cout<<dis[(flag?0:u)][v]+w[u]+w[v]<<'\n';
	}
	return 0;
}
