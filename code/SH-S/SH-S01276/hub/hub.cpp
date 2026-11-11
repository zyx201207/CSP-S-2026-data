#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int c,t,dis[N],f[N],n,k;
bool used[N],id[N];
vector<int> g[N];

inline int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

inline void dfs(int u,int last) {
	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if(v==last) continue;
		dis[v]=min(dis[v],dis[u]+1);
		dfs(v,u);
	}
}

inline void dfs2(int u,int last) {
	id[u]=1;
	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if(v==last||!used[v]) continue;
		dfs2(v,u);
	}
}

signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<n;i++) {
				int u,v;
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			int res=1e9;
			for(int i=0;i<(1<<n);i++) {
				if(__builtin_popcount(i)!=k) continue;
				for(int j=1;j<=n;j++) id[j]=used[j]=0,dis[j]=100;
				for(int j=1;j<=n;j++) {
					if((i>>(j-1))&1) used[j]=1,dis[j]=0;
				}int cnt=0;
				for(int j=1;j<=n;j++) {
					if(id[j]==0&&used[j]) dfs2(j,0),cnt++;
				}
				if(cnt>2) continue;
				for(int j=1;j<=n;j++) if(used[j]) dfs(j,0);
				int ans=0;
				for(int j=1;j<=n;j++) ans=max(ans,dis[j]);
				res=min(res,ans);
			}
			cout<<res<<'\n';
	}
	return 0;
}
