#include <bits/stdc++.h>
#define ll long long
#define inf 1000000000000000
using namespace std;
ll c,n,m,d,q,w[500005],dis[500005],vis[500005],xl[505][505];
vector<pair<ll,ll>>e[500000+500+5];
priority_queue<pair<ll,ll>>pq;
ll dij(ll u,ll v){
	for(int i=1;i<=m+n;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	dis[u]=0;
	pq.push({0,u});
	while(!pq.empty()){
		ll x=pq.top().second;
		pq.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<e[x].size();i++){
			ll y=e[x][i].first;
			ll t=e[x][i].second;
			dis[y]=min(dis[y],dis[x]+t);
			pq.push({-dis[y],y});
		}
	}
	return dis[v];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			e[a].push_back({i+m,t});
			e[i+m].push_back({a,t});
		}
	}
	while(q--){
		ll u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+dij(u,v)<<'\n';
	}
	return 0;
}
