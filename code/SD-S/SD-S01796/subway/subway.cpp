#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[20010],mp1[510][20010],mp2[20010][510],p[100010][2];
int dis[20010][20010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>mp1[i][0];
		for(int j=1;j<=mp1[i][0];j++)
		{
			int a;cin>>a;
			mp1[i][j]=a;
			cin>>mp2[a][++mp2[a][0]];
		}
	}
	for(int i=1;i<=q;i++)cin>>p[i][0]>>p[i][1];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dis[i][j]=1e9;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=mp2[i][0];j++)
			for(int k=1;k<=mp1[j][0];k++)
				dis[i][k]=min(dis[i][k],mp2[i][j]+mp1[j][k]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
		}
	for(int i=1;i<=q;i++)
	{
		cout<<(dis[p[i][0]][p[i][1]]+w[p[i][0]]+w[p[i][1]])<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


