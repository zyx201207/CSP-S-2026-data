#include<bits/stdc++.h>
using namespace std;

long long w[500010],c,n,m,d,q,cn=INT_MAX,t2[510][510];
bool vis[510];
vector<long long> g[510],a[510];

void dfs(long long x,long long y,long long wh,long long b)
{
	if(x==y)
	{
		cn=min(cn,t2[wh][x]+b);
		return ;
	}
	if(b) b+=t2[wh][x];
	for(long long tt:g[x])
	{
		if(tt==wh) continue;
		b+=t2[tt][x];
		for(long long xx:a[tt])
		{
			if(xx==x) continue;
			if(vis[xx]==0)
			{
				vis[xx]=1;
				dfs(xx,y,tt,b);
				vis[xx]=0;
			}
		}
		b-=t2[tt][x];
	}
}

long long calc(long long x,long long y)
{
	long long ans=0;
	ans+=w[x]+w[y];
	cn=INT_MAX;
	memset(vis,0,sizeof vis);
	vis[x]=1;
	dfs(x,y,0,0);
	return ans+cn;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			long long x,y;
			cin>>x>>y;
			t2[i][x]=y;
			a[i].push_back(x);
			g[x].push_back(i);
		}
	}
	while(q--)
	{
		long long x,y;
		cin>>x>>y;
		cout<<calc(x,y)<<"\n";
	}
	return 0;
}