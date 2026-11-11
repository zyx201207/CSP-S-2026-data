#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int c,n,sta,d,plan;
ll wt[500005];
struct edge{ll w;int v;};
vector<edge>mp[500005];
edge tt[500005];
ll dist[500005];
bool vis[500005];
void dijkstra(int s){
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dist[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto e:mp[u]){
			ll w=e.w;int v=e.v;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
		
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>sta>>d>>plan;
	for(int i=1;i<=sta;i++)cin>>wt[i];
	for(int i=1;i<=n;i++){
		memset(tt,0,sizeof tt);
		int k;cin>>k;
		for(int j=1;j<=k;j++)cin>>tt[j].v>>tt[j].w;
		for(int j=1;j<=k;j++)
		for(int x=1;x<=k;x++){
			if(j==x)continue;
			mp[tt[j].v].push_back({tt[j].w+tt[x].w,tt[x].v});
			mp[tt[x].v].push_back({tt[j].w+tt[x].w,tt[j].v});
		}
	}
	while(plan--){
		int s,e;
		cin>>s>>e;
		bool t=0;
		for(auto k:mp[s]){
			ll w=k.w;int v=k.v;
			if(v==e){cout<<w+wt[s]+wt[e]<<endl;t=1;break;}
		}
		if(t)continue;
		dijkstra(s);
		//cout<<dist[e]<<endl;
		cout<<dist[e]+wt[s]+wt[e]<<endl;
	}
	
}

