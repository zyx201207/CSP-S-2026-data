#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int c,n,m,d,p,w[500005],g[505][505],vis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int n1=0;
		cin>>n1;
		for(int j=1;j<=n1;j++)
		{
			int x=0,y=0;
			cin>>x>>y;
			g[i][x]=y;
			vis[i][x]=1;
		}
	}
	for(int i=1;i<=p;i++)
	{
		int x,y;
		long long sum=0,cnt=0,hum=0;
		cin>>x>>y;
		sum+=w[x]+w[y];
		cnt+=w[x]+w[y];	
		if(vis[1][x]==1&&vis[1][y]==1)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[1][j]==1)
				{
					sum+=g[1][j];
				}
			}
		}
		if(vis[2][x]==1&&vis[2][y]==1)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[2][j]==1)
				{
					cnt+=g[2][j];
				}
			}
		}
		cout<<min(sum,cnt);
	}
	return 0;
}
