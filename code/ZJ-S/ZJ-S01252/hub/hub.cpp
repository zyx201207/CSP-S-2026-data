#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
#define ll long long
ll read()
{
	ll ans=0;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		c=getchar();
	}
		
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-48;
		c=getchar();
	}
	return ans;
}
ll c,T,n,k;
vector<int> mp[maxn];
int dep[maxn],fa[maxn],top[maxn],siz[maxn],hson[maxn],ans;
void dfs1(int u,int f)
{
	dep[u]=dep[f]+1;
	fa[u]=f;
	siz[u]=1;
	for(int v:mp[u])
	{
		if(v==f)
			continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[hson[u]])
			hson[u]=v;
	}
}
void dfs2(int u,int f)
{
	if(hson[u])
	{
		top[hson[u]]=top[u];
		dfs2(hson[u],u);
	}
	for(int v:mp[u])
	{
		if(v==f||v==hson[u])
			continue;
		top[v]=v;
		dfs2(v,u);
	 } 
}
int lca(int x,int y)
{
	if(x==y)
		return x;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		swap(x,y);
	return x;
}
int dist(int x,int y)
{
	int lc=lca(x,y);
	return dep[x]+dep[y]-2*dep[lc];
}
int chs[maxn],vis[maxn],flag[maxn];
void dfs4(int u,int f)
{
	flag[u]=1;
	for(int v:mp[u])
	{
		if(v==f||!vis[v])
			continue;
		dfs4(v,u);
	}
}
void dfs3(int dep)
{
	if(dep>k)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			flag[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]&&!flag[i])
				cnt++,dfs4(i,0);
		}
		if(cnt>2)
			return;
		int now=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
				continue;
			int mdist=1e9;
			for(int j=1;j<=k;j++)
				mdist=min(mdist,dist(i,chs[j]));
			now=max(mdist,now);
		}
		ans=min(ans,now);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			chs[dep]=i;
			dfs3(dep+1);
			vis[i]=0;
			chs[dep]=0;
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--)
	{
		ans=1e9;
		n=read(),k=read();
		memset(dep,0,sizeof(dep)),memset(fa,0,sizeof(fa)),memset(top,0,sizeof(top)),memset(siz,0,sizeof(siz)),memset(hson,0,sizeof(hson));
		for(int i=1;i<=n;i++)
			mp[i].clear();
		int u,v;
		for(int i=1;i<n;i++)
		{
			u=read(),v=read();
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		dfs1(1,0);
		top[1]=1;
		dfs2(1,0);
		dfs3(1);
		printf("%d\n",ans);
	}
	return 0;
}//17:56 ~15pts
