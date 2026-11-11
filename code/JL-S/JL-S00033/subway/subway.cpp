#include<bits/stdc++.h>
using namespace std;
int w[10005],k[10005],a[10005][10005],t[10005][10005],x[10005],y[10005],r[10000];
int shijian[10000];
int main()
{
	freopon("subway.in","r",stdin);
	freopon("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[n];
		for(int j=1;j<=k[n];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=y[i];j++)
		{
			shijian[i]=w[x[i]]+w[y[i]]+w[y[i]];
			shijian[i]=shijian[i]+t[i][j];
		}
	}
	shijian[1]=shijian[1]-t[y[1]-1][y[1]-1]/2-1;
	for(int i=1;i<=q;i++)
	{
		cout<<shijian[i]+t[y[i]-1][y[i]]<<'\n';
	}
	return 0;
}
