#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 1e5 + 10;
int n,dep[N],k,st[N];vector<int> g[N];bool vis[N];
void dfs(int u,int fa)
{
	st[u] = fa;dep[u] = dep[fa] + 1;
	for(int v:g[u]) if(v != fa && !vis[v]) dfs(v,u);
}
void clr(int u,int fa)
{
	st[u] = dep[u] = 0;
	for(int v:g[u]) if(v != fa && !vis[v]) clr(v,u);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++) 
		{
			int x,y;cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		int ix = 1;
		for(int i=2;i<=n;i++) if(dep[ix] < dep[i]) ix = i;
		dfs(ix,0);
		int zb = 1;
		for(int i=2;i<=n;i++) if(dep[zb] < dep[i]) zb = i;
		int kkk = dep[zb] / 2;
		while(kkk--) zb = st[zb];
		clr(1,0);vis[zb] = 1;
		int zm = 0,cm = 0;
		for(int v:g[zb])
		{
			dfs(v,zb);
			ix = zb;
			for(int i=2;i<=n;i++) if(dep[ix] < dep[i]) ix = i;
			dfs(ix,0);
			int kkkk = zb;
			for(int i=2;i<=n;i++) if(dep[kkkk] < dep[i]) kkkk = i;
			if(zm < dep[kkkk]) cm = zm,zm = dep[kkkk];
			else if(cm < dep[kkkk]) cm = dep[kkkk];
			clr(v,zb);
		}
		vis[zb] = 0;
		cout<<min(zm/2,cm)<<"\n";
	}
	return 0;
}