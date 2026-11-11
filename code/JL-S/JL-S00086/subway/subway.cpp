#include <bits/stdc++.h>
using namespace std;
const int N=1005,M=5e5+5;
#define int long long
int a[M],b[N],dist[N][N];
vector<pair<int,int> >v[M];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		for(int j=1;j<=b[i];j++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int sz=v[i].size();
		for(int j=0;j<sz-1;j++)
		{
			for(int k=j+1;k<sz;k++)
			{
				int xx1=v[i][j].first,xx2=v[i][k].first,yy1=v[i][j].second,yy2=v[i][k].second;
				dist[xx1][xx2]=min(dist[xx1][xx2],yy1+yy2);
				dist[xx2][xx1]=min(dist[xx2][xx1],yy1+yy2);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}
	while(q--)
	{
		int ans=1e18;
		int x,y;
		cin>>x>>y;
		for(int i=0;i<v[x].size();i++)
		{
			for(int j=0;j<v[y].size();j++)
			{
				int xx1=v[x][i].first,xx2=v[y][j].first,yy1=v[x][i].second,yy2=v[y][j].second;
				ans=min(ans,a[x]+a[y]+dist[xx1][xx2]+yy1+yy2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
