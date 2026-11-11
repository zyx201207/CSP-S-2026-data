#include<bits/stdc++.h>
using namespace std;
vector<int>g[100];
int vis[100];
int n,k;
int ans;
int fa[100];
int get_fa(int x)
{
	return fa[x]==x?x:fa[x]=get_fa(fa[x]);
}
int nwans=INT_MIN;
void dfs2(int u,int fa,int nw)
{
	if(vis[u])nwans=min(nwans,nw);
	for(int v:g[u])
	{
		if(v==fa)continue;
		dfs2(v,u,nw+1);
	}
}
void dfs(int dep)
{
	if(dep>n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=vis[i];
		if(cnt!=k)return;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++)
			if(vis[i])
			{
				for(int v:g[i])if(vis[v])fa[get_fa(v)]=get_fa(i);
			}
		int cnt1=0;
		int cnt2=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				if(!cnt1)cnt1=get_fa(i);
				else if(!cnt2)cnt2=get_fa(i);
				else if(cnt1!=get_fa(i)&&cnt2!=get_fa(i))return;
			}
		}
		int zans=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				nwans=INT_MAX;
				dfs2(i,0,0);
				zans=max(zans,nwans);
				// if(ans==1)
				// {
				// 	printf("??? %d\n",i);
				// }
			}
		}
		ans=min(ans,zans);
		// exit(0);
		return;
	}
	vis[dep]=1;
	dfs(dep+1);
	vis[dep]=0;
	dfs(dep+1);

}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		ans=INT_MAX;
		for(int i=1;i<=n;i++)g[i].clear();
		// if(n<=5)
		{
			for(int i=1;i<n;i++)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				g[u].push_back(v);
				g[v].push_back(u);
			}
			// if(t==0)return 0;
			dfs(1);
			printf("%d\n",ans);
		}
		// // else
		// {
		// 	// for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v);
		// 	printf("%d\n",((n+1)/2/2-k/2)/2+1);
			
		// }
	}
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/