#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
vector<int> e[N];
int c,t,n,k,f[N],d[N];
bool vis[N],st[N];
void dfs1(int u,int fa) {
	f[u]=fa;
	for(int v:e[u]) if(v!=fa) d[v]=d[u]+1,dfs1(v,u);
}
void dfs2(int u) {
	vis[u]=1;
	for(int v:e[u]) if(!vis[v] && st[v]) dfs2(v);
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1,u,v; i<n; ++i) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		d[1]=0,dfs1(1,0);
		int ans=9e18;
		for(int i=1; i<1<<n; ++i) {
			if(__builtin_popcount(i)!=k) continue;
			for(int j=1; j<=n; ++j) st[j]=vis[j]=0;
			for(int j=0; j<n; ++j) if(i>>j&1) st[j+1]=1;
			int cnt=0;
			for(int j=1; j<=n; ++j) if(st[j] && !vis[j]) ++cnt,dfs2(j);
			if(cnt!=2) continue;
			int mx=0;
			for(int j=1; j<=n; ++j) {
				if(!st[j]) {
					int mn=9e18;
					for(int k=1; k<=n; ++k)
						if(st[k]) {
							int u=j,v=k;
							if(d[u]<d[v]) swap(u,v);
							while(d[u]>d[v]) u=f[u];
							while(u!=v) u=f[u],v=f[v];
							mn=min(mn,d[j]+d[k]-d[u]*2);
						}
					mx=max(mx,mn);
				}
			}
			ans=min(ans,mx);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
