#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[5005];
int a[5005],t[5005];
int dis[5005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,-1,sizeof(dis));
	cin>>c>>n>>m>>d>>q;

	for(int i = 1;i<=m;i++)
	cin>>w[i];
	for(int i = 1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j = 0;j<k;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int j = 0;j<k;j++)
		{
			for(int l = j+1;l<k;l++)
			{
				dis[a[j]][a[l]] = dis[a[l]][a[j]] = t[l]+t[j];
			}
		}
	}
	for(int k = 1;k<=m;k++)
	{
		for(int i = 1;i<=m;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				if(dis[i][k]==-1||dis[k][j]==-1)
				continue;
				if(dis[i][j]!=-1)
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
				else dis[i][j] = dis[i][k]+dis[k][j];
			}
		}
	}

	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
