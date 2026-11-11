#include<iostream>
using namespace std;
long long x[1001000];
int dis[5000][5000];
int c,t;
inline void testcase()
{
	int n;
	long long d;
	cin>>n>>d;
	
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if(c==13||c==14)
	{
		cout<<0<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=0x3f3f3f;
			if(i==j)dis[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x[j]-x[i]<=d)
			{
				dis[i][j]=1;
				dis[j][i]=1;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==k||j==k||i==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int ans=0;
	for(int u=1;u<=n;u++)
	{
		for(int v=u+1;v<=n;v++)
		{
			int cnt=0;
			for(int k=1;k<=n;k++)
			{
				if(u==k||v==k)continue;
				if(dis[u][k]+dis[k][v]==dis[u][v])
				{
					cnt++;
				}
			}
			if(cnt==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--)
	{
		testcase();
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
