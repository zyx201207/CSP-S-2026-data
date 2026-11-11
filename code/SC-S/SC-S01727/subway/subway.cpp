#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+1000;
int c,n,m,d,q,w[N],dis[N],vis[N];
vector<pii>g[N];
void dij(int s,int ed){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().se;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(u==ed)return;
		for(auto now:g[u]){
			int v=now.fi,w=now.se;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int x,y;
			cin>>x>>y;
			g[m+i].push_back({x,y});
			g[x].push_back({m+i,y});
		}
	}
	int ans=0;
	while(q--){
		int s,ed;
		cin>>s>>ed;
		for(int i=1;i<=m+n;i++)
			dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
		dij(s,ed);
		cout<<dis[ed]+w[s]+w[ed]<<"\n";
	}
	return 0;
}