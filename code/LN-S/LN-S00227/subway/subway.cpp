#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,s,a[1010],f[1010][1010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(f,0x7f,sizeof f);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n+m;i++)
	{
		f[i][i]=0;
	}
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			long long u,v;
			cin>>u>>v;
			f[u][m+i]=min(f[u][m+i],v);
			f[m+i][u]=min(f[m+i][u],v);
		}
	}
	for(long long k=1;k<=n+m;k++)
	{
		for(long long i=1;i<=n+m;i++)
		{
			for(long long j=1;j<=n+m;j++)
			{
				if((f[i][k]+f[k][j])>=0) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		long long u,v;
		cin>>u>>v;
		cout<<f[u][v]+a[u]+a[v]<<endl;
	}
	return 0;
}
