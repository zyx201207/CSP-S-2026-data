#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll n,m,c,d,q,w[500005],way[505],ed2[505][505],vis[505],dist[505][505];
vector<pii>dw[500005];
vector<pii>edge[505];
void dijkstra(ll S){
	memset(vis,0,sizeof vis);
	dist[S][S]=0;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,S});
	while(!q.empty()){
		auto u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto i:edge[u]){
			ll d=i.first,v=i.second;
			if(vis[v])continue;
			if(dist[S][v]>dist[S][u]+d){
				dist[S][v]=dist[S][u]+d;
				q.push({dist[S][v],v});
			}
		}
	}
}
ll solve(ll x,ll y){
	ll ans=1e18;
	for(auto i:dw[x]){
		ll d1=i.first,u=i.second;
		for(auto j:dw[y]){
			ll d2=j.first,v=j.second;
			ans=min(ans,d1+d2+dist[u][v]);
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dist,0x3f,sizeof dist);
	memset(ed2,0x3f,sizeof ed2);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1,k;i<=n;i++){
		cin>>k;
		for(ll j=1,a,t;j<=k;j++){
			cin>>a>>t;
			dw[a].push_back({t,i});
		}
	}
	for(ll i=1;i<=m;i++){
		for(auto j:dw[i]){
			ll t1=j.first,ii1=j.second;
			for(auto k:dw[i]){
				ll t2=k.first,ii2=k.second;
				if(ii1==ii2)continue;
				ed2[ii1][ii2]=min(ed2[ii1][ii2],t1+t2);
				ed2[ii2][ii1]=ed2[ii1][ii2];
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(ed2[i][j]<1e18){
				edge[i].push_back({ed2[i][j],j});
				edge[j].push_back({ed2[i][j],i});
			}
		}
	}
	for(ll i=1;i<=n;i++){
		dijkstra(i);
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+solve(x,y)<<'\n';
	}
	return 0;
}
