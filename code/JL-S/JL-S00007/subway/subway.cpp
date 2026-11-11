#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[125251];
int f[20005][20005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int z,lasta,lastt;
		int a,t;
		cin>>z;
		for(int j=1;j<=z;j++)
		{
			cin>>a>>t;
			if(j>=2)
			{
				f[a][lasta]=min(lastt+t,f[a][lasta]);
				f[lasta][a]=min(lastt+t,f[lasta][a]);
			}
			lasta=a;
			lastt=t;
		}
	}
	for(int k=1;k<=2;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int x=1;x<=m;x++)
				{
					f[i][j]=min(f[i][j],f[i][x]+f[x][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<f[l][r]+w[l]+w[r]<<endl;
	}
	return 0;
}
