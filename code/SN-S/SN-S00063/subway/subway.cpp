#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[505][50005],t[505][50005],dis[5005][5005];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dis[i][j]=1e16;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int l=j+1;l<=k[i];l++)
			{
				dis[a[i][j]][a[i][l]]=min(t[i][j]+t[i][l],dis[a[i][j]][a[i][l]]);
				dis[a[i][l]][a[i][j]]=min(t[i][j]+t[i][l],dis[a[i][l]][a[i][j]]);
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<"\n";
	}
}
