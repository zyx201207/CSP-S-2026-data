#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+505;
int w[N];
ll dis[3005][3005];
struct edge{
	int v,w;
};
vector<edge> e[N];
priority_queue<pair<ll,int> > PQ;
queue<int> Q;
int c,n,m,d,q;
void dijkstra(int s){
	while(PQ.size())PQ.pop();
	for(int i=1;i<=n+m;++i)dis[s][i]=1e18;
	dis[s][s]=0;
	PQ.push(make_pair(0,s));
	while(PQ.size()){
		int u=PQ.top().second;
		PQ.pop();
		for(int i=0;i<e[u].size();++i){
			int v=e[u][i].v,w=e[u][i].w;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				PQ.push(make_pair(-dis[s][v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)scanf("%d",&w[i]);
	for(int i=1;i<=n+m;++i){
		for(int j=1;j<=n+m;++j){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;	
	}
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			int v,w;
			scanf("%d%d",&v,&w);
			dis[i+m][v]=dis[v][i+m]=w;
			e[i+m].push_back({v,w});
			e[v].push_back({i+m,w});
		}
	}
	if(c<=8){
	for(int k=1;k<=n+m;++k){
		for(int i=1;i<=n+m;++i){
			for(int j=1;j<=n+m;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=w[x]+w[y]+dis[x][y];
		printf("%lld\n",ans);
	}
	}
	if(c>=9&&c<=11){
		for(int i=1;i<=m;++i)dijkstra(i);
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			ll ans=w[x]+w[y]+dis[x][y];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
