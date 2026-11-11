#include <bits/stdc++.h>
using namespace std;
long long a[10000][10000],c,n,m,d,q,loc,w[100000],k[10000],t[10000][10000],x[100000],y[10000],ans[10000],save;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	 }
	for (int i=1;i<=q;i++)
	{
		ans[i]+=w[x[i]];
		loc=x[i];
		for (int j=1;j<=k[i];j++)
		{
			if (a[x[i]][j]==x[i])
			{
				ans[i]+=t[x[i]][j];
				for (int v=1;v<=k[i];v++)
				{
					if (a[x[i]][v]==y[i])
					{
						ans[i]=w[x[i]]+t[x[i]][j]+t[x[i]][v]+w[v];
					}
					else
					{
						for (int e=1;e<=n;e++)
						{
							if (a[loc+1][e]==loc)
							{
								ans[i]+=t[loc+1][e]+t[loc][e];
								loc=x[i]+1;
							}
						}
					}
				}
			}
			//ans[i]=min(ans[i],save);
			//ans[i+1]=0;
		}
	}
	for (int i=1;i<=q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
 } 
