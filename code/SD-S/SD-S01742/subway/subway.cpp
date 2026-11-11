#include<iostream>
#include<cstdio>
#include<utility>
#include<vector>
#include<queue>
#define lint long long
using namespace std;
int c,n,m,d,q;
lint a[500050];
vector<pair<lint,int> > v[500550];
int k,x,y;
lint f[505][505];
int vis[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			v[x].push_back(make_pair(y,i));
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=(i-j?0x3f3f3f3f3f3f3f3f:0);
	for(int i=1;i<=m;i++)
	{
		for(auto x : v[i]) for(auto y : v[i]) if(x.second-y.second)
		{
			f[x.second][y.second]=min(f[x.second][y.second],x.first+y.first);
			//cerr<<x.second<<' '<<y.second<<' '<<f[x.second][y.second]<<'\n';
		}
	}/*¿ªÏúÆ¿¾±
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cerr<<f[i][j]<<' ';
		cerr<<'\n';
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) vis[j]=0;
		priority_queue<pair<lint,int> > q;
		for(int j=1;j<=n;j++) q.push(make_pair(-f[i][j],j));
		while(!q.empty())
		{
			x=q.top().second;
			q.pop();
			if(vis[x]) continue;
			//cerr<<"---"<<i<<' '<<x<<'\n';
			vis[x]=1;
			for(int j=1;j<=n;j++)
			{
				if(f[i][j]>f[i][x]+f[x][j])
				{
					f[i][j]=f[i][x]+f[x][j];
					q.push(make_pair(-f[i][j],j));
				}
			}
		}
	}/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cerr<<f[i][j]<<' ';
		cerr<<'\n';
	}*/
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		lint ans=0x7f7f7f7f7f7f7f7f;
		for(auto j : v[x]) for(auto l : v[y]) ans=min(ans,j.first+l.first+f[j.second][l.second]);
		cout<<a[x]+a[y]+ans<<'\n';
		//cerr<<a[x]+a[y]+ans<<'\n';
	}
	return 0;
}
