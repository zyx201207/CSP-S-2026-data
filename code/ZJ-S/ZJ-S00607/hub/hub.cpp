#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10,inf=1e18;
int n,k,ans=0,u,v;
bool vis[N];
int a[N],dis[N][N];
void update()
{
	int res2=0;
	for(int i=1;i<=n;i++)
	{
		int res=inf;
		for(int j=1;j<=k;j++)
			res=min(res,dis[i][a[j]]);
		res2=max(res2,res);
	}
	ans=min(ans,res2);
}
void dfs(int now)
{
	if(now==k+1)
	{
		update();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[now]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
void mian(int arg)
{
	ans=inf;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=inf;
	for(int i=1;i<n;i++)
	{
		scanf("%lld %lld",&u,&v);
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dfs(1);
	printf("%lld\n",ans);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T=1;
	scanf("%lld %lld",&c,&T);
	while(T--)mian(c);
	return 0;
}// I can't solve this problem and maybe acquire 0 pts.
