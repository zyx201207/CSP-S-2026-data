#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int t[505][20005],a[505][20005],dis[505][505];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin >> x >> y;
			a[i][x] = j;
			t[i][x] = y;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(a[i][k] != 0 && a[j][k] != 0)
				{
					dis[i][j] = t[i][k] + t[j][k];
				}
			}
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(int v=1;v<=n;v++)
		{
			for(int k=1;k<=n;k++)
			{
				if(dis[u][v] > dis[u][k] + dis[k][v])
				{
					dis[u][v] = dis[u][k] + dis[k][v];
				}
				
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		int ans = 1e8;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i][x] != 0 && a[j][y] != 0)
				{
					ans = min(ans,dis[i][j]);
				}
			}
					
				
		}
		cout << ans +w[x]+w[y] << "\n";
	}
} 
