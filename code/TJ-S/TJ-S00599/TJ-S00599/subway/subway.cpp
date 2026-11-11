#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 1e-15
#define db double
const int N=5e5+1;
int w[N],t[501][N];
vector<int>s[505];
vector<int>e[N];
int vis[501][N];
ll cnt=1e18;
void dfs(int i,int x,int y,int p,ll num)
{
	if(x==y)
	{
		cnt=min(cnt,num);
		return ;
	}
	for(auto v:s[i])
	{
		if(vis[i][v]==p)continue;
		vis[i][v]=p;
		num+=t[i][v];
		dfs(i,v,y,p,num);
	}
	for(auto v:e[x])
	{
		if(vis[v][x]==p)continue;
		vis[v][x]=p;
		num+=t[v][x];
		dfs(v,x,y,p,num);
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a;
			scanf("%d%d",&a,&t[i][a]);
			s[i].push_back(a);
			e[a].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		cnt=1e18;
		ll ans=w[x]+w[y];
		for(auto k:e[x])
		{
			ll num=t[i][x];
			vis[i][x]=i;
			dfs(k,x,y,i,num);
		}
		ans+=cnt;
		printf("%lld\n",ans);
	}
	return 0;
}
