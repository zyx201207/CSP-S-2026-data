#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,Q,ans,Time[500005],dis[505][180005];
bool vis[500505];
vector<pair<int,ll> >G[500505];
priority_queue<pair<int,ll> >q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=n+1;i<=n+m;i++)cin>>Time[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll x,t;
			cin>>x>>t;
			G[i].push_back({x+n,t});
			G[x+n].push_back({i,t});
		}
	}
	memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		q.push({0,i});
		memset(vis,0,sizeof(vis));
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto j:G[u]){
				ll v=j.first;
				ll w=j.second;
				if(dis[i][u]+w<dis[i][v]){
					dis[i][v]=dis[i][u]+w;
					q.push({-dis[i][v],v});
				}
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int s,e;
		cin>>s>>e;
		s+=n,e+=n;
		ans=9e18;
		for(auto j:G[s]){
			ll v=j.first;
			ll w=j.second;
			ans=min(ans,dis[v][e]+w);
		}
		for(auto j:G[e]){
			ll v=j.first;
			ll w=j.second;
			ans=min(ans,dis[v][s]+w);
		}
		cout<<ans+Time[s]+Time[e]<<"\n";
	}
	return 0;
}
