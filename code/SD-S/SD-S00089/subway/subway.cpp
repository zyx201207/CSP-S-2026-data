#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long f[505][505],w[505],a[505][505],t[505][505];
struct node
{
	long long u,v,val,jie;
};
vector<node> e;
vector<pair<long long,long long> > p[500005];
map<pair<long long,long long>,long long> ma;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int aa,tt;
			cin>>aa>>tt;
			a[i][j]=aa;
			t[i][j]=tt;
			p[aa].push_back({i,tt});
			ma[{i,aa}]=tt;
			if(p[aa].size()>=2)
			{
				long long siz=p[aa].size();
				for(int asd=0;asd<=siz-2;asd++)
				{
					e.push_back({p[aa][siz-1].first,p[aa][asd].first,p[aa][siz-1].second+p[aa][asd].second,aa});
				}
			}
		}
	}
	long long MAXX=1e16;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				f[i][j]=0;
			}
			f[i][j]=MAXX;
		}
	}
	for(int i=0;i<e.size();i++)
	{
		if(e[i].val<f[e[i].u][e[i].v])
		{
			f[e[i].u][e[i].v]=e[i].val;
			f[e[i].v][e[i].u]=e[i].val;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][k]+f[k][j]<f[i][j])
				{
					f[i][j]=f[i][k]+f[k][j];
				}
				if(i==j)
				{
					f[i][j]=0;
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		long long x,y;
		cin>>x>>y;
		long long ans=1e16+10;
		for(int j=0;j<p[x].size();j++)
		{
			for(int k=0;k<p[y].size();k++)
			{
				long long sum;
				if(p[x][j].first==p[y][k].first)
				{
					sum=ma[{p[x][j].first,x}]+ma[{p[y][k].first,y}]+w[x]+w[y];
				}
				else
				{
					sum=f[p[x][j].first][p[y][k].first]+ma[{p[x][j].first,x}]+ma[{p[y][k].first,y}]+w[x]+w[y];
				}
				
				ans=min(sum,ans);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
 }

