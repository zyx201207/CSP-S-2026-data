#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
int k[505];
int cnt[500005],to[500005][25];
long long ti[500005][25];
long long dis[505][505];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a;
			long long t;
			cin>>a>>t;
			to[a][++cnt[a]]=i;
			ti[a][cnt[a]]=t;
		}
	}
	memset(dis,0x3F,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			for(int k=j+1;k<=cnt[i];k++)
			{
				int s=to[i][j],t=to[i][k];
				dis[s][t]=dis[t][s]=min(dis[s][t],ti[i][j]+ti[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
//		}
//	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=1;i<=cnt[x];i++)
		{
			for(int j=1;j<=cnt[y];j++)
			{
				ans=min(ans,ti[x][i]+ti[y][j]+dis[to[x][i]][to[y][j]]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
