#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define pii pair<int,int>
#define ft first
#define sd second
#define db double
const int INF=1e18,N=1e5+5;
vector<int>g[N];
int cc,T;
int n,k;
int dep[N],dis[N];
bool vis[N];
void dfs(int u,int fa) {
	dep[u]=dep[fa]+1;
	for(int v:g[u]) {
		if(v==fa||vis[v])continue;
		dfs(v,u);
	}
}
int cnt[N];
int ans;
void mj(int id) {
	if(id==k+1) {
		int res=0;
		for(int i=1; i<=k; i++) {
			int u=cnt[i];
			dis[u]=0;
			dfs(u,0);
			for(int v=1; v<=n; v++) {
				dis[u]=max(dis[u],dep[v]-1);
			}
			res=max(res,dis[cnt[i]]);
		}
		ans=min(ans,res);
		return;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i])continue;
		cnt[id]=i;
		vis[i]=1;
		mj(id+1);
		vis[i]=0;
	}
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	AC;
	cin>>cc>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1; i<=n; i++)g[i].clear();
		for(int i=1; i<n; i++) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int u=1; u<=n; u++) {
			dis[u]=0;
			for(int v=1; v<=n; v++) {
				dis[u]=max(dis[u],dep[v]-1);
			}
		}
		ans=INF;
		mj(1);
		cout<<ans<<'\n';
	}
	return 0;
}


