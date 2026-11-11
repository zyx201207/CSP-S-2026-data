#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int M=5e5+10,M2=1e6+50;
int c,n,m,d,q,t[M],cnt;
vector<pii>g[M2];
bool vis[M2];
int dis[M2];
int dijkstra(int st,int ed){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	dis[st]=0;
	pq.push({0,st});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto x:g[u]){
			int v=x.first,w=x.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
	return dis[ed]+t[st]+t[ed];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t[i];
	cnt=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int id,v;
			cin>>id>>v;
			if(j!=1){
				g[cnt].push_back({cnt+1,0});
				g[cnt+1].push_back({cnt,0});
				cnt++;
			}
			else cnt++;
			g[cnt].push_back({id,v});
			g[id].push_back({cnt,v});
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dijkstra(u,v)<<endl;
	}
	return 0;
}
