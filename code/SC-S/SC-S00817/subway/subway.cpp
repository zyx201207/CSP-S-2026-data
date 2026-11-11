#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=1e6+5;
struct Edge{
	int v,nxt;
	ll w;
}e[N<<1];
int head[N],node=0;
void add(int u,int v,ll w){
	e[++node].v=v;
	e[node].w=w;
	e[node].nxt=head[u];
	head[u]=node;
}
int c,n,m,d,q;
ll dis[505][505];
ll w[N];
bool vis[N];
void dj(int s){
	for(int i=1;i<=n+m+1;++i){
		vis[i]=0;
	}
	priority_queue<pll,vector<pll>,greater<pll> > q;
	dis[s][s]=0;
	q.push({dis[s][s],s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])	continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v;
			ll w=e[i].w;
			if(!vis[v]&&dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({dis[s][v],v});
			}
		}
	}
}
bool used[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cin>>c>>m>>n>>d>>q;
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
	for(int i=1;i<=n+m+1;++i){
		for(int j=1;j<=n+m+1;++j){
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;++i) cin>>w[i];
	for(int i=1;i<=m;++i){
		int u=n+i;
		int k;
		cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			add(u,v,w);
			add(v,u,w);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans;
		if(used[u]){
			ans=w[u]+w[v]+dis[u][v];
			printf("%lld\n",ans);
		}else if(used[v]){
			ans=w[u]+w[v]+dis[v][u];
			printf("%lld\n",ans);
		}
		else{
			used[u]=1;
			dj(u);
			ans=w[u]+w[v]+dis[u][v];
			printf("%lld\n",ans);
		}
		//cout<<w[u]+w[v]+dis[u][v]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}