#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,M=5e5+5;
ll c,n,m,d,q;
ll w[M],k[M];
vector<vector<ll> >s(N,vector<ll>(M)),t(N,vector<ll>(M));
vector<pair<ll,ll> >e[M];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >qq;
void dijkstra(ll root,ll end){
	vector<ll>dis(M,1e18);
	dis[root]=0;
	qq.push({0,root});
	while(!qq.empty()){
		ll u=qq.top().second,dd=qq.top().first;
		qq.pop();
		if(dd>dis[u]) continue;
		for(ll i=0;i<e[u].size();i++){
			ll v=e[u][i].first,w=e[u][i].second;
			if(dis[v]>dd+w){
				dis[v]=dd+w;
				qq.push({dis[v],v});
			}
		}
	}
	cout<<dis[end]+w[root]+w[end]<<'\n';
}
queue<pair<ll,ll> >bq;
void bfs(ll root,ll end){
	while(!bq.empty()) bq.pop();
	vector<ll>dis(M,1e18),vis(M,0);
	dis[root]=0;
	bq.push({root,0});
	while(!bq.empty()){
		ll u=bq.front().first,dep=bq.front().second;
		for(ll i=0;i<e[u].size();i++){
			ll v=e[u][i].first;
			if(vis[v]) continue;
			vis[v]=1;
			dis[v]=dep+1;
			if(v==end){
				cout<<dis[v]*t[1][1]+w[root]+w[v]<<'\n';
				return;
			}
			bq.push({v,dep+1});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>s[i][j]>>t[i][j];
			for(ll x=1;x<j;x++){
				e[s[i][j]].push_back({s[i][x],t[i][j]+t[i][x]});
				e[s[i][x]].push_back({s[i][j],t[i][j]+t[i][x]});
			}
		}
	}
	if(c<=8){
		for(ll i=1,u,v;i<=q;i++){
			cin>>u>>v;
			dijkstra(u,v);
		}
	}
	else if(c>=12&&c<=15){
		for(ll i=1,u,v;i<=q;i++){
			cin>>u>>v;
			bfs(u,v);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2 
//0 3 7 20 2 8 3 6 1 7 2 9 3 1 4 2 5 5 100 3 2 6 3 1 7 2 4 3 2 5 100 4 6 6 7 1 6 2 3
