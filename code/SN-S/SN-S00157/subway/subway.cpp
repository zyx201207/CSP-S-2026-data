#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define int long long
using namespace std;

const int M=5e5+5,N=505,inf=1e18;

int c,n,m,d,q;
int a[M],f[N][N];
vector<pair<int,int> > g[M];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int s,t;
			cin>>s>>t;
			g[s].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=inf;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			for(int k=j+1;k<g[i].size();k++)
			{
				int x=g[i][j].first,y=g[i][k].first,u=g[i][j].second,v=g[i][k].second;
				f[x][y]=f[y][x]=min(f[x][y],u+v);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[j][k]); 
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(int j=0;j<g[x].size();j++)
		{
			for(int k=0;k<g[y].size();k++)
			{
				pair<int,int> u=g[x][j],v=g[y][k];
				ans=min(ans,a[x]+a[y]+u.second+v.second+f[u.first][v.first]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
