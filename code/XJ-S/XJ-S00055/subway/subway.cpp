#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500005], k[505], a[505][505], t[505][505], x, y;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		long long now=x, cost=w[now]+w[y];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			{
				if(now==y)
				{
					break;
				}
				if(a[i][j]==now)
				{
					cost+=t[i][j];
					now=a[i][j+1];
					cost+=t[i][j+1];
				}
			}
		}
		cout<<cost<<endl;
	}
	return 0;
}
