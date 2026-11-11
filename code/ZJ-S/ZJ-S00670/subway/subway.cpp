#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int w[M],k[505],f[1005][1005],T=-1,a[505][20004],t[505][20004];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	int c,n,m,d,q;
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
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int g=1;g<j;g++)
			{
				f[a[i][j]][a[i][g]]=t[i][j]+t[i][g];
				f[a[i][g]][a[i][j]]=t[i][j]+t[i][g];
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int r=1;r<=q;r++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+f[x][y]+w[y]<<endl;
	}
	return 0;
} 
