#include<bits/stdc++.h>
#define ll long long
#define PI pair<ll,int>
using namespace std;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const ll INF=1e18;
ll bh,m,n,d,T,a[500010],dist[500010],ans[100010];
vector<PI>g[505],f[500005];
bool st[500010];
struct sub
{
	int u,v,id;
	bool operator<(const sub &e)const
	{
		return u<e.u;
	}
}q[500010];
void Dij(int u)
{
	for(int i=1;i<=n;i++)
	{
		dist[i]=INF;
		st[i]=0;
	}
	dist[u]=a[u];
	priority_queue<PI,vector<PI>,greater<PI> >q;
	q.push({a[u],u});
	while(!q.empty())
	{
		u=q.top().second;
		q.pop();
		if(st[u])continue;
		st[u]=1;
		for(int i=0;i<f[u].size();i++)
		{
			for(int j=0;j<g[f[u][i].second].size();j++)
			{
				int v=g[f[u][i].second][j].second;
				ll w=f[u][i].first+g[f[u][i].second][j].first+dist[u];
				if(w<dist[v])
				{
					dist[v]=w;
					q.push({w,v});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	bh=read();m=read();n=read();d=read();T=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)
	{
		int l=read();
		for(int j=1;j<=l;j++)
		{
			int id=read();
			ll w=read();
			g[i].push_back({w,id});
			f[id].push_back({w,i});
		}
	}
	for(int i=1;i<=T;i++)
	{
		q[i].u=read();
		q[i].v=read();
		q[i].id=i;
	}
	sort(q+1,q+T+1);
	for(int i=1;i<=T;i++)
	{
		if(q[i].u==q[i-1].u)ans[q[i].id]=dist[q[i].v]+a[q[i].v];
		else
		{
			Dij(q[i].u);
			ans[q[i].id]=dist[q[i].v]+a[q[i].v];
		}
	}
	for(int i=1;i<=T;i++)
	{
		write(ans[i]);
		puts("");
	}
	return 0;
}
