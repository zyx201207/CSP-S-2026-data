#include<bits/stdc++.h>
#define int long long
using namespace std;
int dis[505][505];
int t[505][505];
int w[505];
int a[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)dis[i][j]=2147483647;
	for(int j=1;j<=n;j++)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)cin>>a[j][i]>>t[j][i];
		for(int i=1;i<=m;i++)for(int l=1;l<=k;l++)dis[a[j][i]][a[j][l]]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int l=1;l<=m;l++)
			{
				dis[i][j]=min(dis[i][l]+dis[l][j]+t[1][1],dis[i][j]);	
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+t[1][1]+w[x]+w[y]<<'\n';
	}
	return 0;
}/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
//.O.
//B市多的是That地铁，为什么我们村木有？
