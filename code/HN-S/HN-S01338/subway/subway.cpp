#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=2e5,K=5e5;
int c,n,m,d,q;
int w[M],a[K],t[N][K];
bool D[M];
vector<pair<int,int> >G[M];
int dfs(int now,int end,int time,int line)
{
	if(now==end)
	{
		return (time+t[line][now])*10+1;
	} 
	int ret=1e9;
	D[now]=true;
	for(int i=0;i<G[now].size();i++)
	{
		if(!D[G[now][i].first])
		{
			int x=dfs(G[now][i].first,end,time+(G[now][i].second==line?0:t[line][now]+t[G[now][i].second][now]),G[now][i].second);
			if(x%10==1)
			{
				ret=min(ret/10,x/10)*10+1;
			}
		}
	}
	D[now]=false;
	return ret;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&a[j]);
			if(j>1)
			{
				G[a[j-1]].push_back({a[j],i});
				G[a[j]].push_back({a[j-1],i});
			}
			scanf("%d",&t[i][a[j]]); 
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dfs(x,y,w[x]+w[y],0)/10);
	}
	return 0;
} 
