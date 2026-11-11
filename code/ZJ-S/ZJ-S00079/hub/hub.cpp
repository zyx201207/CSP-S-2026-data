#include <bits/stdc++.h>
using namespace std;
int read()
{
	int k=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return k*f;
}
const int N=1e6+10;
int c,t,n,k,now,tmp,x[N],y[N],vis[N],f[N];
vector<int>vec[N];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int x,int fa,int dep)
{
	if(vis[x])tmp=min(tmp,dep);
	for(auto u:vec[x])
	{
		if(u==fa)continue;
		dfs(u,x,dep+1);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	c=read();t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1; i<=n; ++i)
		{
			vec[i].clear();
		}
		for(int i=1; i<n; ++i)
		{
			x[i]=read();y[i]=read();
			vec[x[i]].push_back(y[i]);
			vec[y[i]].push_back(x[i]);
		}
		if(n<=10)
		{
			int ans=1e9;
			for(int i=0; i<(1<<n); ++i)
			{
				int s=0;
				for(int j=0; j<n; ++j)
				{
					if((i>>j)&1)
					{
						s++;
						vis[j+1]=1;
					}
					else vis[j+1]=0;
				}
				if(s!=k)continue;
				for(int j=1; j<=n; ++j)
				{
					if(vis[j])
						f[j]=j;
					else f[j]=-1;
				}
				for(int j=1; j<n; ++j)
				{
					if(vis[x[j]]&&vis[y[j]])
						f[find(y[j])]=find(x[j]);
				}
				int sum=0;
				for(int j=1; j<=n; ++j)
					if(f[find(j)]==j)
						sum++;
				if(sum>2)continue;
				now=0;
				for(int j=1; j<=n; ++j)
				{
					tmp=1e9;
					dfs(j,0,0);
					now=max(now,tmp);
				}
				ans=min(ans,now);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
