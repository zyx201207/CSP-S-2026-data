#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
vector<pair<ll,ll>> g[500005];
ll k;
ll w[500005];
bool vis[500005];
ll dis[500005];
ll udis[500][20005];
void dijkstra(ll s){
	priority_queue< pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m+n;i++){
		dis[i]=9e18;
	}
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		pair<ll,ll> x=q.top();
		q.pop();
		int u=x.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(pair<ll,ll> y:g[u]){
			ll w=y.first,v=y.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
void bfs(ll s,ll t){
	queue<int> q;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	q.push(s);
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(pair<ll,ll> y:g[u]){
			ll w=y.first,v=y.second;
			dis[v]=dis[u]+1;
			if(v==t) return;
			q.push(v);
		}
	}
}
void solve(){
	ll T;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			scanf("%lld%lld",&a,&t);
			T=t;
			g[a].push_back({1,m+i});
			g[m+i].push_back({1,a});
		}
	}
	for(int i=1;i<=q;i++){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		bfs(a,b);
		printf("%lld\n",w[a]+w[b]+dis[b]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(c>=12&&c<=19){
		solve();
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			scanf("%lld%lld",&a,&t);
			g[a].push_back({t,m+i});
			g[m+i].push_back({t,a});
		}
	}
	for(int i=1;i<=q;i++){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		dijkstra(a);
		printf("%lld\n",w[a]+w[b]+dis[b]);
	}
	return 0;
}
