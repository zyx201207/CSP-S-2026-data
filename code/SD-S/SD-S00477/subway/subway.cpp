#include <bits/stdc++.h>
using namespace std;
struct Z
{
	long long v,w;
}h;
struct G
{
	long long bh,dis;
	bool operator<(const G& ot)const
	{
		return dis>ot.dis;
	}
}d,o;
int k[505];
long long s[500500];
vector<long long> a[505],t[505];
long long b[1010][1010];
vector<Z> f[1010];
bool vis[1010];
priority_queue<G> q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d1,q1,l,r,p1,p2;
	long long sum;
	cin>>c>>n>>m>>d1>>q1;
	for(int i=1;i<=m;i++)
	{
		cin>>s[i];
	}
	if(c<=6)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				b[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>l>>r;
				a[i].push_back(l);
				t[i].push_back(r);
			}
			for(int j=0;j<k[i];j++)
			{
				for(int o=0;o<k[i];o++)
				{
					b[a[i][j]][a[i][o]]=min(b[a[i][j]][a[i][o]],t[i][j]+t[i][o]);
				}
			}
		}
		for(int z=1;z<=m;z++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					b[i][j]=min(b[i][j],b[i][z]+b[z][j]);
				}
			}
		}
		for(int i=1;i<=q1;i++)
		{
			cin>>l>>r;
			sum=s[l]+s[r]+b[l][r];
			cout<<sum<<'\n';
		}
	}
	else if(c<=11)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				b[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			if(k[i]==1)
			{
				cin>>l>>r;
				continue;
			}
			cin>>l>>r>>p1>>p2;
			h.v=p1;
			h.w=r+p2;
			f[l].push_back(h);
			h.v=l;
			f[p1].push_back(h);
		}
		for(int z=1;z<=m;z++)
		{
			for(int i=1;i<=m;i++)
			{
				vis[i]=0;
			}
			d.bh=z;
			d.dis=0;
			q.push(d);
			b[z][z]=0;
			while(!q.empty())
			{
				o=q.top();
				q.pop();
				if(vis[o.bh]==1)
				{
					continue;
				}
				vis[o.bh]=1;
				int e=f[o.bh].size();
				for(int i=0;i<e;i++)
				{
					if(b[z][f[o.bh][i].v]>(b[z][o.bh]+f[o.bh][i].w))
					{
						b[z][f[o.bh][i].v]=b[z][o.bh]+f[o.bh][i].w;
						d.bh=f[o.bh][i].v;
						d.dis=b[z][f[o.bh][i].v];
						q.push(d);
					}
				}
			}
		}
		for(int i=1;i<=q1;i++)
		{
			cin>>l>>r;
			sum=s[l]+s[r]+b[l][r];
			cout<<sum<<'\n';
		}
	}
	return 0;
}
