#include<bits/stdc++.h>
using namespace std;

int _c,T;
int n,k;
int _u,_v;
int key[100001],len=0;
int dep[100001];
int st[21][100001],lgn;

bool vis[100001];
int cnt=0;
bool iskey[100001];

int pos=0,head[100001];

struct edge
{
	int u,v,nxt;
}e[200001];

inline void addedge(int u,int v)
{
	e[++pos]={u,v,head[u]};
	head[u]=pos;
}

void dfs(int u,int f)
{
	st[0][u]=f;
	dep[u]=dep[f]+1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==f)
		{
			continue;
		}
		dfs(v,u);
	}
}

inline int lca(int u,int v)
{
	if(dep[u]<dep[v])
	{
		swap(u,v);
	}
	for(int k=lgn;k>=0;k--)
	{
		if(dep[st[k][u]]>=dep[v])
		{
			u=st[k][u];
		}
	}
	if(u==v)
	{
		return u;
	}
	for(int k=lgn;k>=0;k--)
	{
		if(st[k][u]!=st[k][v])
		{
			u=st[k][u];
			v=st[k][v];
		}
	}
	return st[0][u];
}

inline int dis(int u,int v)
{
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}

void dfscheck(int u,int f)
{
	vis[u]=1;
	cnt++;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==f||vis[v]||!iskey[v])
		{
			continue;
		}
		dfscheck(v,u);
	}
}

bool check()
{
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	dfscheck(key[1],0);
	for(int i=2;i<=k;i++)
	{
		if(!vis[key[i]])
		{
			dfscheck(key[i],0);
			break;
		}
	}
	return (cnt==k);
}

inline void p2()
{
	lgn=__lg(n)+1;
	dfs(1,0);
	for(int k=1;k<=lgn;k++)
	{
		for(int u=1;u<=n;u++)
		{
			st[k][u]=st[k-1][st[k-1][u]];
		}
	}
	int ans=n;
	for(int msk=1;msk<(1<<n);msk++)
	{
		if(__builtin_popcount(msk)!=k)
		{
			continue;
		}
		len=0;
		for(int i=1;i<=n;i++)
		{
			iskey[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			if(msk>>i&1)
			{
				key[++len]=i+1;
				iskey[i+1]=1;
			}
		}
		if(!check())
		{
			continue;
		}
		int cur=0;
		for(int i=1;i<=n;i++)
		{
			int res=n;
			for(int j=1;j<=k;j++)
			{
				res=min(res,dis(i,key[j]));
			}
			cur=max(cur,res);
		}
		ans=min(ans,cur);
	}
	printf("%d\n",ans);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&_c,&T);
	for(int _=1;_<=T;_++)
	{
		scanf("%d%d",&n,&k);
		pos=0;
		for(int i=1;i<=n;i++)
		{
			head[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&_u,&_v);
			addedge(_u,_v);
			addedge(_v,_u);
		}
		p2();
	}
	return 0;
}
