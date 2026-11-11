#include<bits/stdc++.h> 
using namespace std;
int g[1005][1005];
int f[1005][1005];
int c,n,m,d,q,w[1005],k1,u,v,w1,w2;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=1e9;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k1;
		int a[1005],t[1005];
		for(int j=1;j<=k1;j++) 
		{
			cin>>a[j]>>t[j];
			for(int k=1;k<=j-1;k++)
			{
				f[a[j]][a[k]]=f[a[k]][a[j]]=t[j]+t[k];
				
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--)
	{
		cin>>u>>v;
		cout<<f[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}
