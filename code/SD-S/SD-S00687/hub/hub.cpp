#include<bits/stdc++.h>
using namespace std;
int p[20],c[20],g[20];
int h[20],e[50],ne[50],idx;
void add(int a,int b)
{
	e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
int find(int x)
{
	if(x==p[x])return x;
	return p[x]=find(p[x]);
}
void merge(int a,int b)
{
	a=find(a),b=find(b);
	if(a!=b)p[b]=a;
}
int dfs(int u,int fa)
{
	if(g[u])return 0;
	int res=1e9;
	for(int i=h[u];~i;i=ne[i])
	{
		int v=e[i];
		if(v==fa)continue;
		res=min(res,dfs(v,u));
	}
	return res+1;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int C,T;
	scanf("%d %d",&C,&T);
	while(T--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		memset(h,-1,sizeof h);idx=1;
		for(int i=1;i<n;++i)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			add(a,b);add(b,a);
		}
		int ans=1e9;
		for(int i=0;i<(1<<n);++i)
		{
			c[0]=0;
			for(int j=0;j<n;++j)
				if(i&(1<<j))c[++c[0]]=j+1;
			if(c[0]!=k)continue;
			for(int j=1;j<=n;++j)g[j]=0;
			for(int j=1;j<=k;++j)g[c[j]]=1;
			for(int j=1;j<=n;++j)p[j]=j;
			int siz=k;
			for(int u=1;u<=n;++u)
				for(int j=h[u];~j;j=ne[j])
				{
					int v=e[j];
					if(g[u] && g[v])
					{
						merge(u,v);
						siz--;
					}
				}
			if(siz>1)continue;
			int res=0;
			for(int j=1;j<=n;++j)
			{
				if(g[j])continue;
				res=max(res,dfs(j,0));
			}
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
