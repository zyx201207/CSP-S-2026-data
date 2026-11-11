#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,fa[1000005],dis[35],ans;
vector<int>g[1000005];
void dfs(int u,int fa)
{
	dis[u]=dis[fa]+1;
	for(int v:g[u])
	{
		if(v==fa)continue;
		dfs(v,u);
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		ans=n;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int S=1;S<(1<<n);S++)
		{
			if(__builtin_popcount(S)!=k)continue;
			int cnt=0;
			for(int i=1;i<=n;i++)fa[i]=i;
			for(int i=1;i<=n;i++)
			{
				if(S>>(i-1)&1)
				{
					cnt++;
					for(int j:g[i])if(S>>(j-1)&1)cnt--;
				}
			}
			if(cnt>2)continue;
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				memset(dis,0,sizeof(dis)); dis[0]=-1;
				dfs(i,0);
				int tmp=n;
				for(int j=1;j<=n;j++)if(S>>(j-1)&1)tmp=min(tmp,dis[j]);
				sum=max(sum,tmp);
			}
			ans=min(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}
