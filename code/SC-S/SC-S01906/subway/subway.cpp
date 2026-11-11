#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 2e6+10;
const int maxm=4e6+10;
const ll INF=1e18;
int head[maxn],e[maxm],nxt[maxm],cnt;
ll val[maxm];
ll dis[maxn];
ll id[maxn],cur;
int w[maxn];
void add(int u,int v,ll w){
	e[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void dij(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	cur++;
	dis[s]=0;
	id[s]=cur;
	q.push({0,s});
	while(!q.empty()){
		ll d=q.top().first;
		int u=q.top().second;
		q.pop();
		if(!id[u]==cur && d>dis[u]){
			continue;
		}
		for(int i=head[u];i;i=nxt[i]){
			int v=e[i];
			ll nd=val[i]+d;
			if(id[v]!=cur || nd<dis[v]){
				dis[v]=nd;
				id[v]=cur;
				q.push({nd,v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	int pid=m;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		int pre=1;
		for(int j=1;j<=k;j++){
			int u,t;
			scanf("%d%d",&u,&t);
			pid++;
			add(u,pid,t);
			add(pid,u,t);
			if(pre!=1){
				add(pre,pid,0);
				add(pid,pre,0);
			}
			pre=pid;
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		dij(x);
		ll ans = w[x]+dis[y]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}