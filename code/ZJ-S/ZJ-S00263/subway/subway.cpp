#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int c,n,m,d,q,w[500050],book[500512];
int ans,mins[500050],mp[1600][1600];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=m+n;i++)
		for(int j=1;j<=m+n;j++)
			mp[i][j]=inf;
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;cin>>a>>t;
			mp[a][m+i]=t;
			mp[m+i][a]=t;
		}
	}
	for(int i=1;i<=m+n;i++)
		mp[i][i]=0;
	for(int k=1;k<=m+n;k++)
		for(int i=1;i<=m+n;i++)
			for(int j=1;j<=m+n;j++)
				if(mp[i][j]>mp[i][k]+mp[k][j])
					mp[i][j]=mp[i][k]+mp[k][j];
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<0LL+mp[u][v]+w[u]+w[v]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
