#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,c,d,q;
int w[N];
int f[505][505];
vector<pair<int,int>>b[N];
void solve()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=1e16;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			b[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<b[i].size();j++)
		{
			for(int k=j+1;k<b[i].size();k++)
			{
				int lx1=b[i][j].first,lx1w=b[i][j].second;
				int lx2=b[i][k].first,lx2w=b[i][k].second;
				f[lx1][lx2]=f[lx2][lx1]=min(f[lx1][lx2],lx1w+lx2w);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int st,ed;
		cin>>st>>ed;
		int ans=1e18;
		for(int i=0;i<b[st].size();i++)
		{
			for(int j=0;j<b[ed].size();j++)
			{
				int stlx=b[st][i].first,stlxw=b[st][i].second;
				int edlx=b[ed][j].first,edlxw=b[ed][j].second;
				int sum=0;
				if(stlx==edlx)sum=0;
				else sum=f[stlx][edlx];
				ans=min(ans,sum+w[st]+w[ed]+stlxw+edlxw);
			}
		}
		cout<<ans<<"\n";
	}
	return;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
