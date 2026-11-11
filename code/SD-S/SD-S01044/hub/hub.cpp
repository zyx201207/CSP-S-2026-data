#include<bits/stdc++.h>
using namespace std;

inline int read();

const int N=1e6+10;

int csd,T,n,k;
int idx=0,head[N];struct edge
{
	int v,nt;
}e[N<<1];inline void add(int u,int v){e[++idx]={v,head[u]};head[u]=idx;return ;}
int dis[1010][1010];
bool vis[N],jzz[N];

inline void Dij(int u,int fa,int st,int sum)
{
	dis[st][u]=sum;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].v;
		if(v==fa)
		{
			continue;
		}
		Dij(v,u,st,sum+1); 
	}
	return ;
}

inline void dfs(int u,int fa)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nt)
	{
		int v=e[i].v;
		if(v==fa||!jzz[v])
		{
			continue;
		}
		dfs(v,u);
	}
	return ;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	csd=read();T=read();
	while(T--)
	{
		n=read();k=read();
		idx=0;
		for(int i=1;i<=n;++i)
		{
			head[i]=0;
		}
		for(int i=1;i<n;++i)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);
		}
		for(int i=1;i<=n;++i)
		{
			Dij(i,0,i,0);	
		}
		int ans=n;
		for(int i=0;i<(1<<n);++i)
		{
			vector<int>jz;
			int res=0;
			for(int j=1;j<=n;++j)
			{
				jzz[j]=0;
			}
			for(int j=0;j<n;++j)
			{
				vis[j+1]=0;
				if(i&(1<<j))
				{
					res++;
					jz.push_back(j+1);
					jzz[j+1]=1;
					if(res>k)
					{
						break;	
					} 
				}
			}
			if(res>k)
			{
				continue;
			}
			int cnt=0;
			for(int j=0;j<jz.size();++j)
			{
				if(!vis[jz[j]])
				{
					cnt++;
					dfs(jz[j],0);
				}
			}
			if(cnt<=2)
			{
				int sum=0;
				for(int j=1;j<=n;++j)
				{
					if(!jzz[j])
					{
						int ress=n;
						for(int o=0;o<jz.size();++o)
						{
							ress=min(ress,dis[jz[o]][j]);
						}
						sum=max(sum,ress);
					}
				}
				ans=min(ans,sum);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

