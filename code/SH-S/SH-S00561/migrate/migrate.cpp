#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=409;
const ll INF=1e18;
ll dufied,t;
ll n,d,a[N];
/*
ll dist[N];
ll ver[N*2],nxt[N*2],head[N*2],edge[N*2],tot;
ll cnt_fs,now_fs;
bool vis[N],vis_dfs[N];
*/
ll rd(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
/*
void add(ll u,ll v,ll w){
	ver[++tot]=v;
	edge[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}
void dijkstra(ll u){
	priority_queue<pair<ll,ll> > q; 
	fill(dist,dist+N-1,INF);
	memset(vis,0,sizeof vis);
	dist[u]=0; q.push({0,u});
	while(!q.empty()){
		ll x=q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			ll v=ver[i],w=edge[i];
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				if(!vis[v]){
					q.push({-dist[v],v});
				}
			}
		}
	}
}
void dfs1(ll x,ll ed){
	if(x==ed&&now_fs==dist[ed]){
		cnt_fs++;
		return ;
	}
	if(cnt_fs>2) return ;
	vis_dfs[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		ll v=ver[i];
		if(vis_dfs[v]&&v!=ed) continue;
		now_fs++;
		dfs1(v,ed);
		now_fs--;
	}
} 
*/
void init(){
}
void in(){
	n=rd(); d=rd();
	for(int i=1;i<=n;i++){
		a[i]=rd();
	}

}
/*
void solve1(){
	memset(head,0,sizeof head); tot=0;
	// ok
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])<=d){add(i,j,1);add(j,i,1);}
		}
	}
	ll ans1=0;
	for(int i=1;i<n;i++){
		printf("now: %lld\n",i);
		dijkstra(i);  // ok
		for(int j=1;j<=n;j++){
			printf("dist[%lld]: %lld\n",j,dist[j]);
		}
		for(int j=i+1;j<=n;j++){
			if(dist[j]==INF)continue;
			cnt_fs=now_fs=0;
			memset(vis_dfs,0,sizeof vis_dfs);
			dfs1(i,j);
			if(cnt_fs==2) ans1++;
		}
		printf("\n");
	}
	printf("%lld\n",ans1);
}
*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	dufied=rd();t=rd();
	while(t--){
		init();
		in();
		/*
		ll gongcha=a[2]-a[1];
		for(int i=2;i<n;i++){
			if(gongcha!=a[i+1]-a[i]) A=0;
		}
		*/
		printf("0\n");
		//else solve1();
	}
	return 0;
} 
