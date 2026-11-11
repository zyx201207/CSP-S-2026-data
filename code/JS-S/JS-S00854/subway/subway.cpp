#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500009],dep,x,y,k,sum[500009];
bool vis[1000002];
long long dis[1000002];
int head[1000002],tot;
struct node{
	int v,nxt;
	long long w;
}e[1000002];
void add(int u,int v,long long ww){
	e[++tot].v=v;
	e[tot].w=ww;
	e[tot].nxt=head[u];
	head[u]=tot;
}
void dij(){
	priority_queue<pair<long long,int>> pq;
	pq.push({0ll,x+d*m});
	for(int i=1;i<=m+m*d;i++) dis[i]=1e18,vis[i]=0;
	dis[x+d*m]=0;
	while(!pq.empty()){
		int u=pq.top().second;pq.pop();
		//~ cout<<u<<endl;
		if(vis[u]) continue ;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v,ww=e[i].w;
			//~ cout<<v<<":"<<dis[v]<<' '<<dis[u]+ww<<endl;
			if(dis[v]>dis[u]+ww){
				dis[v]=dis[u]+ww;
				pq.push({-dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//~ freopen("subway4.in","r",stdin);
	//~ freopen("subway4.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&k);
		int la=0;
		for(int j=1;j<=k;++j){
			int aa,tt,aaa;
			scanf("%d%d",&aa,&tt);
			++sum[aa];
			aaa=aa+(sum[aa]-1)*m;
			//~ cout<<aaa<<' ';
			if(la) add(la,aaa,0),add(aaa,la,0);
			add(aaa,aa+d*m,tt);
			add(aa+d*m,aaa,tt);
			la=aaa;
		}
		//~ cout<<endl;
	}
	for(int i=1;i<=q;++i){
		scanf("%d%d",&x,&y);
		dij();
		printf("%lld\n",dis[y+d*m]+w[x]+w[y]);
	}
	return 0;
}
