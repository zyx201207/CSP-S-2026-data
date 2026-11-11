#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510000;
struct edge{
	int v,w;
};
int c,n,m,d,q,ans;
int w[N],k[N];
vector<edge> g[N];
bool vis[N];
void dfs(int u,int t,int dis){
	if(dis>ans) return;
	if(u==t){
		ans=min(ans,dis);
		return;
	}
	vis[u]=1;
	for(auto e:g[u]){
		int v=e.v,w=e.w;
		if(vis[v]) continue;
		dfs(v,t,dis+w);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v,w;
			cin>>v>>w;
			g[m+i].push_back({v,w});
			g[v].push_back({m+i,w});
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ans=INT_MAX;
		for(int i=1;i<=n+m;i++) vis[i]=0;
		dfs(u,v,0);
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}

