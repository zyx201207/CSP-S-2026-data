#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int N=505; 
const int inf=0x3f3f3f3f;
int C,n,m,d,q,k;
int w[M];
int st[20005];
int a[20005][505];
int vis[20005];
vector<pair<int,int> >v[20005];
long long ans=inf;
struct Node{
	int u,x;
	long long step;
};
void dfs(int st,int en,long long sum,int u,int x)
{
	if(u==en)
	{
		ans=min(ans,sum+a[en][x]);
		return;
	}
	for(int i=0;i<v[u].size();i++)
	{
		int du=v[u][i].first,sx=v[u][i].second;
		if(!vis[du])
		{
			vis[du]=1;
			dfs(st,en,(x==sx?sum:sum+a[u][x]+a[u][sx]),du,sx);
			vis[du]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			st[j]=t1;
			if(j>1)
			{
				v[st[j]].push_back({st[j-1],i});
				v[st[j-1]].push_back({st[j],i});
			}
			a[t1][i]=t2;
		}
	}
	while(q--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		ans=inf;
		for(int i=1;i<=n;i++)
		{
			if(a[s][i]!=-1)
			dfs(s,t,a[s][i],s,i);
		}
		printf("%lld\n",ans+w[s]+w[t]);
	}
	return 0;
}
