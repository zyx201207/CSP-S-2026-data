#include<bits/stdc++.h>
using namespace std;
int C,T,n,k,sz[1010];
vector<int> ne[1010];
int f[1010],g[1010][1010],h[1010],a[1010],b[1010];
void dfs(int u,int fa)
{
	int chk=1;
	sz[u]=1;
	for(int i=0;i<ne[u].size();i++)
	{
		int v=ne[u][i];
		if(v==fa)
		continue;
		chk=0;
		dfs(v,u);
	}
	if(chk==1)
	{
		f[u]=0;
		return;
	}
	for(int i=0;i<ne[u].size();i++)
	{
		int v=ne[u][i];
		if(v==fa)
		continue;
		f[u]=min(f[u],f[v]+1);
	}
	for(int i=0;i<ne[u].size();i++)
	{
		int v=ne[u][i];
		if(v==fa)
		continue;
		memset(b,0x3f,sizeof b);
		for(int i=1;i<=sz[u];i++)
		{
			for(int j=1;j<=sz[v];j++)
			b[i+j]=min(b[i+j],max(a[i],g[v][j]));
		}
		for(int i=1;i<=sz[u];i++)
		b[i]=min(b[i],max(a[i],f[v]+1));
		sz[u]+=sz[v];
		for(int i=1;i<=sz[u];i++)
		a[i]=b[i];
	}
	for(int i=1;i<=sz[u];i++)
	g[u][i]=a[i];
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		ne[i].clear();
		int u,v;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			ne[u].push_back(v);
			ne[v].push_back(u);
		}
		int ans=1e9;
		for(int rt=1;rt<=n;rt++)
		{
			memset(f,0x3f,sizeof f);
			memset(g,0x3f,sizeof g);
			memset(h,0x3f,sizeof h);
			dfs(rt,0);
			ans=min(ans,g[rt][k]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
