#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int p,n,m,d,q,sum,x,y,a[500005],l[500005],c[500005][25],t[500005][25],f[505][505],dis[505][505];
bool vis[505][505];
void dij(int u)
{
	for(int i=1;i<=n;++i)
	{
		dis[u][i]=inf;
		vis[u][i]=false;
	}
	dis[u][u]=0;
	for(int i=1;i<=n;++i)
	{
		int mn=inf,id=0;
		for(int j=1;j<=n;++j)
		{
			if(vis[u][j]) continue;
			if(dis[u][j]<mn)
			{
				mn=dis[u][j];
				id=j;
			}
		}
		if(mn==inf) break;
		vis[u][id]=true;
		for(int j=1;j<=n;++j)
		{
			if(vis[u][j]) continue;
			if(dis[u][id]+f[id][j]<dis[u][j]){
				dis[u][j]=dis[u][id]+f[id][j];	
			}
		}
	}
		
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>p>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		cin>>sum;
		for(int j=1;j<=sum;++j)
		{
			cin>>x>>y;
			c[x][++l[x]]=i;	
			t[x][l[x]]=y;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j)
				f[i][j]=inf;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=l[i];++j)
			for(int k=1;k<=l[i];++k)
			{
				f[c[i][j]][c[i][k]]=min(f[c[i][j]][c[i][k]],t[i][j]+t[i][k]);
				f[c[i][k]][c[i][j]]=min(f[c[i][k]][c[i][j]],t[i][j]+t[i][k]);
			}
	for(int i=1;i<=n;++i)
		dij(i);
	while(q--)
	{
		cin>>x>>y;
		int ans=inf;
		for(int j=1;j<=l[x];++j)
			for(int k=1;k<=l[y];++k)
			{
				ans=min(ans,a[x]+a[y]+dis[c[x][j]][c[y][k]]+t[x][j]+t[y][k]);
			}
		cout<<ans<<"\n";
	}
	return 0;
}
