#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5,N=505,INF=0x3f3f3f3f3f3f3f3f;
struct st
{
	vector<pair<int,int> >v;
}a[N];
int c,n,m,d,q,w[M],dis[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			int aij,tij;
			cin>>aij>>tij;
			a[aij].v.push_back(make_pair(i,tij));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=INF;
	for(int i=1;i<=n;i++)	dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int x=0;x<a[i].v.size();x++)
		{
			for(int y=x+1;y<a[i].v.size();y++)
			{
				int u=a[i].v[x].first,v=a[i].v[y].first,w=a[i].v[x].second+a[i].v[y].second;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&i!=k&&j!=k)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y,ans=INF,s,t;
		cin>>x>>y;
		for(int i=0;i<a[x].v.size();i++)
		{
			for(int j=0;j<a[y].v.size();j++)
			{
				int u=a[x].v[i].first,v=a[y].v[j].first;
				int tmp=dis[u][v]+a[x].v[i].second+a[y].v[j].second;
				if(tmp<ans)	ans=tmp,s=u,t=v;
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
