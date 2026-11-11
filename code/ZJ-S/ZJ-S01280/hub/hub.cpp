#include<bits/stdc++.h>
using namespace std;
vector<int>g[2000010];
int vis[2000010];
int f[2000010];
int find(int x) {
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void add(int x,int y) {
	f[find(x)]=find(y);
}
int v[2000010];
int ans=2e6;
int dis[2010][2010];
int n,K;
void dfs(int now) {
	if(now==K+1) {
		for(int i=1; i<=n; i++) {
			f[i]=i;
			v[i]=0;
		}
		for(int i=1; i<=n; i++) {
			if(!vis[i])continue;
			for(auto v:g[i]) {
				if(vis[v]) {
					add(i,v);
				}
			}
		}
		int cnt=0;
		for(int i=1; i<=n; i++) {
			if(!v[find(i)]&&vis[i]) {
				v[find(i)]=1;
				cnt++;
			}
		}
		if(cnt>2)return;
		int xx=0;
		for(int i=1; i<=n; i++) {
			if(vis[i])continue;
			int x=2e6;
			for(int j=1; j<=n; j++) {
				if(vis[j]&&i!=j) {
					x=min(x,dis[i][j]);
				}
			}
			xx=max(xx,x);
		}
		ans=min(ans,xx);
		return;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i])continue;
		vis[i]=1;
		dfs(now+1);
		vis[i]=0;
	}
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		cin>>n>>K;
		for(int i=1; i<=n; i++) {
			g[i].clear();
			vis[i]=0;
		}
		for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)if(i!=j)dis[i][j]=2e6;
		for(int i=1; i<n; i++) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v]=min(dis[u][v],1);
			dis[v][u]=min(dis[v][u],1);
		}
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		ans=2e6;
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
