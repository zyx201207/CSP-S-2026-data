#include<bits/stdc++.h>
using namespace std;
#define int long long
//bool st;
int w[500005],f[505][505];
vector<pair<int,int> > c[500005];
//bool ed; 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int z,n,m,d,q;
	cin>>z>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1e18;
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int xx,yy;
			cin>>xx>>yy;
			c[xx].push_back({i,yy});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(pair<int,int> t1:c[i])
			for(pair<int,int> t2:c[i])
			{
				if(f[t1.first][t2.first]<=t1.second+t2.second)
					continue;
				f[t1.first][t2.first]=f[t2.first][t1.first]=t1.second+t2.second;
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int xx,yy,ans=1e18;
		cin>>xx>>yy;
		for(pair<int,int> t1:c[xx])
			for(pair<int,int> t2:c[yy])
			{
				ans=min(ans,t1.second+t2.second+f[t1.first][t2.first]+w[xx]+w[yy]);
			}	
		cout<<ans<<"\n";
	}
	return 0;
 } 
