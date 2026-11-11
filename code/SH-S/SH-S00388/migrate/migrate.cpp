#include<bits/stdc++.h>
using namespace std;
long long a[5000010],g[510][510],dist[510][510];
int c,t;
void bs()
{
	while(t--)
	{
		long long ans=0,cnt=0;
		long long n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			g[i][i]=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=m)
				{
					g[i][j]=1;
					g[j][i]=1;
				}
				else
				{
					g[i][j]=10000;
					g[j][i]=10000;
				}
			}
		}
		memset(dist,0x3f,sizeof(dist));
		for(int i=1;i<=n;i++)
		{
			dist[i][i]=0;
			for(int j=i+1;j<=n;j++)
			{
				for(int k=i;k<=j;k++)
				{
					dist[i][j]=min(dist[i][j],dist[i][k]+g[k][j]);
					dist[j][i]=min(dist[i][j],dist[j][i]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				for(int k=i+1;k<j;k++)
				{
					if(dist[i][k]+g[k][j]==dist[i][j]) cnt++;
				}
				if(cnt==2) ans++;
				cnt=0;
			}
		}
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	bs();
	return 0;
}
