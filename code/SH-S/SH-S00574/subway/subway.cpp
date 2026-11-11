#include<bits/stdc++.h>
using namespace std;
//thinking 2:40~2:55 15min
//input>=10^6->cin instead of scanf!!!!!!!!!
//coding: 2:55~3:10 15min
//hope to be->100
long long a[500011];
long long d[511][511];
vector<pair<long long,long long> > edges[500011];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,dd,q;
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)d[i][j]=(1LL<<60);
		d[i][i]=0;
	}
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int y,z;
			cin>>y>>z;
			edges[y].push_back({i,z});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto x:edges[i])
		{
			for(auto y:edges[i])
			{
				d[x.first][y.first]=min(d[x.first][y.first],x.second+y.second);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int s,t;
		cin>>s>>t;
		long long ans=(1LL<<60);
		for(auto x:edges[s])
		{
			for(auto y:edges[t])
			{
				ans=min(ans,x.second+y.second+d[x.first][y.first]);
			}
		}
		ans+=a[s]+a[t];
		cout<<ans<<"\n";
	}
}
