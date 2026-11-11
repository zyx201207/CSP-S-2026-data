#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long C,n,m,d,q,w[N],dis[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m;j++)
		{
			dis[i][j]=1e9+5;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		long long a,b;
		cin>>a>>b;
		k--;
		while(k--)
		{
			long long x,y;
			cin>>x>>y;
			dis[a][x]=b+w[a];
			dis[x][a]=y+w[x];
			a=x;
			b=y;
		}
	}
	for (int i=1;i<=m;i++)dis[i][i]=0;
	for (int k=1;k<=m;k++)
	{
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=m;i++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int st,en;
		cin>>st>>en;
		cout<<dis[st][en]<<endl;
	}
	return 0;
}
