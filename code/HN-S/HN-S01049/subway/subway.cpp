#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const ll inf=1e18;
int c,n,m,d,q,w[N],val[N][2];
ll dis[N+500];
bool ok[N+500];
vector<pair<int,int> > e[N+500];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
void dij(int s,int t){
	fill(dis+1,dis+m+n+1,inf);
	fill(ok+1,ok+m+n+1,0);
	while (pq.size()) pq.pop();
	pq.push({0,s});
	dis[s]=0;
	while (pq.size()){
		auto top=pq.top();pq.pop();
		if (ok[top.second]) continue;
		ok[top.second]=1;
		if (top.second==t) break;
		for (auto v:e[top.second]){
			if (top.first+v.second<dis[v.first]){
				dis[v.first]=top.first+v.second;
				pq.push({dis[v.first],v.first});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) scanf("%d",&w[i]);
	if (n<=2){
		for (int i=1;i<=n;i++){
			int k,x,t;
			scanf("%d",&k);
			for (int j=1;j<=k;j++){
				scanf("%d%d",&x,&t);
				val[x][i-1]=t;
			} 
		}
		if (n==1){
			while (q--){
				int u,v;
				scanf("%d%d",&u,&v);
				printf("%lld\n",w[u]+w[v]+val[u][0]+val[v][0]);
			}
		}else{
			long long mn=1e18;
			for (int i=1;i<=n;i++) if (val[i][0]&&val[i][1]) mn=min(mn,(long long)val[i][0]+val[i][1]);
			while (q--){
				int u,v;
				scanf("%d%d",&u,&v);
				long long ans=1e18;
				if (val[u][0]&&val[v][0]) ans=min(ans,(long long)val[u][0]+val[v][0]+w[u]+w[v]);
				if (val[u][1]&&val[v][1]) ans=min(ans,(long long)val[u][1]+val[v][1]+w[u]+w[v]);
				if (val[u][0]&&val[v][1]) ans=min(ans,mn+val[u][0]+val[v][1]+w[u]+w[v]);
				if (val[u][1]&&val[v][0]) ans=min(ans,mn+val[u][1]+val[v][0]+w[u]+w[v]);
				printf("%lld\n",ans); 
			} 
		}
		return 0;
	}
	for (int i=1;i<=n;i++){
		int k,x,t;
		scanf("%d",&k);
		for (int j=1;j<=k;j++){
			scanf("%d%d",&x,&t);
			e[x].push_back({m+i,t});
			e[m+i].push_back({x,t});
		}
	}
	while (q--){
		int u,v;
		scanf("%d%d",&u,&v);
		dij(u,v); 
		printf("%lld\n",dis[v]+w[u]+w[v]);
	}
	return 0;
} 
/*
如果只有两条线：

1：不换乘

u->v w[u]+t[1][u]+t[1][v]+w[v]

2：换乘

先坐1号线，再坐2号线

u->x->v   w[u]+t[1][u]+t[1][x]+t[2][x]+t[2][v]+w[v] 

先坐2号线，再做1号线

u->x-> v w[u]+t[2][u]+t[2][x]+t[1][x]+t[1][v]+w[v] 
*/
