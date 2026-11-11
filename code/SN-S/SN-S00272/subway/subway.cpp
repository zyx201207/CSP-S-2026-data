#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int dis[2020][2020];
int T[500100];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int k;
	int t[100100][2];
	for(int i=1;i<=m;i++) cin>>T[i];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			dis[i][j]=INT_MAX;
			if(i==j) dis[i][j]=0;
		}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++) cin>>t[j][0]>>t[j][1];
		for(int j=1;j<=k;j++)
			for(int u=j+1;u<=k;u++)
			{
				dis[t[j][0]][t[u][0]]=min(dis[t[j][0]][t[u][0]],t[j][1]+t[u][1]);
				dis[t[u][0]][t[j][0]]=min(dis[t[u][0]][t[j][0]],t[j][1]+t[u][1]);
			}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<dis[i][j]<<' ';
//		cout<<'\n';
//	}
//	cout<<"\n\n\n";
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
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<dis[i][j]<<' ';
//		cout<<'\n';
//	}
	int l,r;
	while(q--)
	{
		cin>>l>>r;
		cout<<dis[l][r]+T[l]+T[r]<<'\n';
	}
}
