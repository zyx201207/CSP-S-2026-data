#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=4005;
vector<int> a[N];
int vis[N];
int f[N],dis[N];
map<int,int> mp;
int find(int u)
{
	if(f[u]!=u) return f[u]=find(f[u]);
	return f[u];
}
void dfs(int u,int fa,int dist)
{
	dis[u]=min(dist,dis[u]);
	for(int i:a[u])
	{
		if(i==fa) continue;
		dfs(i,u,dist+1);
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int NUM,_; cin >>NUM >>_;
	while(_--)
	{
		int n,k; cin >>n >>k;
		for(int i=1;i<n;i++)
		{
			int u,v; cin >>u >>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		int ans=1e18;
		for(int i=1;i<(1<<n);i++)
		{
			int num=0;
			for(int j=0;j<n;j++) vis[j+1]=0;
			for(int j=0;j<n;j++) if((i>>j)&1) 
			{
				num++;
				vis[j+1]=1;
			}
			int cnt=0;
			for(int j=1;j<=n;j++) f[j]=j;
			for(int j=1;j<=n;j++) for(int v:a[j])
			{
				if(!vis[j]||!vis[v]) continue;
				int fu=find(j),fv=find(v);
				f[fu]=fv;
			}
			mp.clear();
			for(int j=1;j<=n;j++) if(vis[j]){mp[find(j)]++; cnt+=(mp[find(j)]==1);}
			int maxx=0;
			for(int i=1;i<=n;i++) dis[i]=1e18;
			for(int j=1;j<=n;j++) if(vis[j]) dfs(j,-1,0);
			for(int j=1;j<=n;j++) maxx=max(maxx,dis[j]);
			if(cnt<=2&&num<=k) ans=min(ans,maxx);
		}
		cout <<ans <<'\n';
		for(int i=1;i<=n;i++) a[i].clear();
	}
	return 0;
}