#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505],x[100005],y[100005],sum;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		sum=0;
		sum+=w[x[i]];
		for(int j=1;j<=n;j++)
		{
			if(a[j][1]==x[i])
			{
				sum+=t[j][1];
			}
		}
		for(int j=1;j<=n;j++)//线路 
		{
			for(int p=1;p<=k[j];p++)//经过的站点 
			{
				if(a[j][p]==y[i])
				{
					for(int h=2;h<=p;h++)
					{
						sum+=t[h][p];
					}
				}
			}
		}
		sum=sum+w[y[i]];
		cout<<sum<<endl; 
	}
	
	return 0;
}

