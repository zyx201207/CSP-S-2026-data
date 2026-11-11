#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int c, n, m, d, q,sum[1e5+5];
	cin>>c>>n>>m>>d>>q;
	int w[m],k[d],x[q],y[q],a[m][100005],t[m][100005];
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
	}
	for(int i=1;i<=q;i++)
	{
		int b=1
		sum[i]=w[x[i]]+w[y[i]];
		for(int j=1;j<=k[i];j++)
		{
			int g=0;
			if(a[b][j]==y[i])
			{
				g=1;
			}
		}
		for(int j=1;j<=k[i];j++) 
		{
			sum+=t[i][j];
		}
	}
	cout<<sum;
	return 0;
}

