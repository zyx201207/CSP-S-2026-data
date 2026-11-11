#include<bits/stdc++.h>
#define se second
#define fi first
using namespace std;
using ll=long long;
const ll inf=1e18;
const int N=500505;
vector<pair<int,int>> G[N];
int c,n,m,d,q,tot;
int w[N];
bool vis[N];
ll dis[N];
ll bfs(int x,int y){
	for(int i=1;i<=tot;i++)vis[i]=0;
	queue<pair<int,ll>> q;
	q.push({x,0});
	vis[x]=1;
	while(!q.empty()){
		int u=q.front().fi;
		ll diss=q.front().se;
		q.pop();
		if(u==y){
			return diss+w[x]+w[y];
		}
		for(pair<int,int> ei:G[u]){
			int v=ei.fi,ww=ei.se;
			if(!vis[v]){
				q.push({v,diss+ww});
				vis[v]=1;
			}
		}
	}
	return 0;
}
ll dijk(int x,int y){
	for(int i=1;i<=tot;i++)vis[i]=0,dis[i]=inf;
	dis[x]=0;
	priority_queue<pair<ll,int>> pq;
	pq.push({0,x});
	while(!pq.empty()){
		int u=pq.top().se;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(pair<int,int> ei:G[u]){
			int v=ei.fi,ww=ei.se;
			if(dis[v]>dis[u]+ww){
				dis[v]=dis[u]+ww;
				pq.push({-dis[v],v});
			}
		}
	}
	return dis[y]+w[x]+w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	tot=n+m;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int a,ti;cin>>a>>ti;
			G[a].push_back({m+i,ti});
			G[m+i].push_back({a,ti});
		}
	}
	if(12<=c&&c<=15){
		while(q--){
			int x,y;cin>>x>>y;
			cout<<bfs(x,y)<<'\n';
		}
	}else{
		while(q--){
			int x,y;cin>>x>>y;
			cout<<dijk(x,y)<<'\n';
		}
	}
	return 0;
}


