#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,k;
vector<int> g[2000005];
queue<int> q;
bool vis[2000005];
int dist[2000005];
int u[200005];
void dfs(int u,int sum) {
	for(int v:g[u]) {
		if(!vis[v]) {
			vis[v]=1;
			dist[v]=sum;
			dfs(v,sum+1);
		}
	}
}
void solve() {
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		g[i].clear();
	}
	for(int i=1; i<=n; i++) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(vis,0,sizeof vis);
	memset(dist,0,sizeof dist);
	dfs(1,0);
	cout<<dist[n]<<"\n";
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
