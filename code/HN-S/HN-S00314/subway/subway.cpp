#include<iostream>
#include<cstdio>
using namespace std;
int w[10000005],k[100000],x[100000],y[100000];
int a[1000][1000],b[1000][1000];
int c,n,m,d,q;
int search(int stop,int lit,int sum,int ans)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(stop==a[i][j])
			{
				sum+=b[i][stop];
				for(int r=1;r<=k[i];r++)
				{
					if(a[i][r]==ans)
					{
						sum+=b[i][ans];
						if(sum<lit)
							lit=sum;
					}
					if(a[i][r]!=stop)
					{
						sum+=b[i][a[i][r]];
						search(a[i][r],lit,sum,ans);
						sum-=b[i][a[i][r]];
					}
				}
			}
		}
	}
	return lit;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//  n:线路数;  m:站数;  q:计划数; 
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];//w:口入，出; 
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>b[i][a[i][j]];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<search(x[i],1000000,w[x[i]]+w[y[i]],y[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
